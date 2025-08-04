#pragma once
//DispenseState.h
#pragma once
#include <iostream>
#include "State.h"

using namespace std;

class RaffleActivity;

//���Ž�Ʒ��״̬
class DispenseState :public State
{
public:
	DispenseState(RaffleActivity* activity);
	void deductMeney() override;
	bool raffle() override;
	//���Ž�Ʒ
	void dispensePrize() override;

private:
	RaffleActivity* activity;
};