#include "squaremodule.h"
#include "vectorvalue.h"

SquareModule::SquareModule() : PrimitiveModule("square")
{
	addParameter("size");
	addParameter("center");
}

Node* SquareModule::evaluate(Context* ctx)
{
	Value* sizeVal=getParameterArgument(ctx,0);
	Value* centerVal=getParameterArgument(ctx,1);
	double center=false;
	if(centerVal)
		center = centerVal->isTrue();

	double x=1.0,y=1.0;
	if(sizeVal) {
		VectorValue* size=sizeVal->toVector(2);
		Point p = size->getPoint();
		p.getXY(x,y);
	}

	PrimitiveNode* p=new PrimitiveNode();
	double x1, x2, y1, y2;
	if(center) {
		x1 = -x/2;
		x2 = +x/2;
		y1 = -y/2;
		y2 = +y/2;
	} else {
		x1 = y1 = 0;
		x2 = x;
		y2 = y;
	}

	p->createPolygon();
	p->appendVertex(x1, y1, 0);
	p->appendVertex(x2, y1, 0);
	p->appendVertex(x2, y2, 0);
	p->appendVertex(x1, y2, 0);

	return p;
}
