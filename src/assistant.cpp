/*
 *   RapCAD - Rapid prototyping CAD IDE (www.rapcad.org)
 *   Copyright (C) 2010-2012 Giles Bathgate
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <QLibraryInfo>
#include <QCoreApplication>
#include <QDir>
#include <QMessageBox>
#include "assistant.h"
#include "stringify.h"

Assistant::Assistant()
{
	proc=NULL;
}

Assistant::~Assistant()
{
	if(proc && proc->state() == QProcess::Running) {
		proc->terminate();
		proc->waitForFinished(3000);
	}
	delete proc;
}


bool Assistant::startAssistant()
{
	if(!proc)
		proc = new QProcess();

	if(proc->state() != QProcess::Running) {
		QString app = QLibraryInfo::location(QLibraryInfo::BinariesPath) + QDir::separator();
#if !defined(Q_OS_MAC)
		app += "assistant";
#else
		app += "Assistant.app/Contents/MacOS/Assistant";
#endif

		QStringList args;
		args << "-collectionFile"
#if defined(Q_OS_UNIX)
			 << QSTRINGIFY(DOCDIR) + "/rapcad.qhc"
#else
			 << QCoreApplication::applicationDirPath() + QDir::separator() + "rapcad.qhc"
#endif
			 << "-enableRemoteControl";

		proc->start(app, args);

		if(!proc->waitForStarted()) {
			QMessageBox::critical(0, QObject::tr("RapCAD"),
								  QObject::tr("Unable to launch Qt Assistant (%1)").arg(app));
			return false;
		}
	}
	return true;
}

void Assistant::showDocumentation(const QString& page)
{
	if(!startAssistant())
		return;

	QByteArray ba("SetSource ");
	ba.append("qthelp://org.rapcad/doc/");

	proc->write(ba + page.toLocal8Bit() + '\n');
}
