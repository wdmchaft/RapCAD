/*
 *   RapCAD - Rapid prototyping CAD IDE (www.rapcad.org)
 *   Copyright (C) 2010-2018 Giles Bathgate
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

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QString>
#include "visitabletree.h"

class Expression : public VisitableTree
{
public:
	enum Operator_e {
		None,
		Exponent,
		Multiply,
		Concatenate,
		Append,
		ComponentwiseMultiply,
		Divide,
		ComponentwiseDivide,
		Increment,
		Decrement,
		AddAssign,
		SubAssign,
		CrossProduct,
		DotProduct,
		Modulus,
		Dot,
		Add,
		Subtract,
		LessThan,
		LessOrEqual,
		Equal,
		NotEqual,
		GreaterOrEqual,
		GreaterThan,
		LogicalAnd,
		LogicalOr,
		Invert,
		Index,
		Length
	};

	Expression();
	~Expression() override;

	Operator_e getOp() const;
	void setOp(Operator_e);
	QString getOpString() const;
	bool postFix() const;

	int getLineNumber() const;
	void setLineNumber(int value);
private:
	Operator_e op;
	int lineNumber;
};

#endif // EXPRESSION_H
