#include <QLibraryInfo>
#include <QDir>
#include <QMessageBox>
#include "assistant.h"

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
			 << "rapcad.qhc"
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
