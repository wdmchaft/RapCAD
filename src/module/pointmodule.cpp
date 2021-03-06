/*
 *   RapCAD - Rapid prototyping CAD IDE (www.rapcad.org)
 *   Copyright (C) 2010-2013 Giles Bathgate
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

#include "pointmodule.h"
#include "node/pointnode.h"
#include "vectorvalue.h"

PointModule::PointModule() : Module("point")
{
	addParameter("location");
}

Node* PointModule::evaluate(Context* ctx)
{
	VectorValue* location=dynamic_cast<VectorValue*>(getParameterArgument(ctx,0));

	PointNode* p=new PointNode();
	Point pt;
	if(location)
		pt = location->getPoint();
	p->setPoint(pt);
	return p;
}
