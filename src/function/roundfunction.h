#ifndef ROUNDFUNCTION_H
#define ROUNDFUNCTION_H

#include "function.h"
#include "context.h"

class RoundFunction : public Function
{
public:
	RoundFunction();
	Value* evaluate(Context*);
};

#endif // ROUNDFUNCTION_H
