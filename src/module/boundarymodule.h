/*
 *   RapCAD - Rapid prototyping CAD IDE (www.rapcad.org)
 *   Copyright (C) 2010-2019 Giles Bathgate
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

#ifndef BOUNDARYMODULE_H
#define BOUNDARYMODULE_H

#include "module.h"
#include "onceonly.h"

class BoundaryModule : public Module
{
	Q_DECLARE_TR_FUNCTIONS(BoundaryModule)
public:
	BoundaryModule(Reporter&, bool);
	Node* evaluate(const Context&) const override;
private:
	static OnceOnly depricateWarning;
	bool legacy;
};

#endif // BOUNDARYMODULE_H
