#include<iostream>
#include"StopStart.h"
#include "StartState.h"
#include "Context.h"
using  namespace  std;

int  main(void)
{
	Context* context = new Context();

	StartState* startstate = new StartState();
	startstate->DoAction(context);
	cout << startstate->ToString() << endl;

	StopState* stopstate = new StopState();
	stopstate->DoAction(context);
	cout << stopstate->ToString() << endl;


	return 0;
}