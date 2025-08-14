#pragma once
#include"Context.h"
class State
{
	virtual void DoAction(Context* context) = 0;
};
