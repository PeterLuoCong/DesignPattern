#pragma once
#include "State.h"
#include<iostream>
using namespace  std;

class StartState : public State
{
public:
	void DoAction(Context* context)
	{
		cout << "Player is in Start State"<<endl;
		context->SetState(this);
	}
	string ToString()
	{
		return "Start State";
	}
};
