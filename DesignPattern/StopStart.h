#pragma once
#include "State.h"
#include<iostream>
using namespace  std;

class StopState : public State
{
public:
	void DoAction(Context* context)
	{
		cout << "Player is in Stop State" << endl;
		context->SetState(this);
	}

	string ToString()
	{
		return "Stop State";
	}
};
