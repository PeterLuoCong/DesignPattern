#pragma once
#include "State.h"
class State;

class Context
{
private:
	State* state;

public:
	Context()
	{
		state = nullptr;
	}

	void SetState(State* state)
	{
		this->state = state;
	}

	State* GetState()
	{
		return state;
	}
};
