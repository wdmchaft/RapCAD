/*
 *   RapCAD - Rapid prototyping CAD IDE (www.rapcad.org)
 *   Copyright (C) 2010-2017 Giles Bathgate
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
#ifdef USE_INTEGTEST
#ifndef TESTER_H
#define TESTER_H

#include "strategy.h"

class Tester : public Strategy
{
public:
	Tester(QTextStream&);
	~Tester();
	int evaluate() override;
private:
	void writeHeader(QString name, int num);
	bool testFunctionExists(Script*);
	void testModule(Script*, QFileInfo);
	void testFunction(Script*);
	void exportTest(QString);
#if USE_CGAL
	void exportTest(class CGALExport&,QString,QFileInfo,QString);
#endif
	QString* nullout;
	QTextStream* nullstream;
	Reporter* nullreport;
	int testcount;
	int passcount;
	int failcount;

};

#endif // TESTER_H
#endif
