//main.cpp
#include <iostream>
#include "RaffleActivity.h"
using namespace std;
int main987HJ3234(int argc, char* argv[])
{
	RaffleActivity* activity = new RaffleActivity(1);

	for (int i = 0; i < 50; i++)
	{
		cout << "µÚ" << i << "´Î³é½±" << endl;
		activity->deductMoney();
		activity->raffle();
		cout << endl;
	}
	return 0;
}