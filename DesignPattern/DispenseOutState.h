//RaffleActivity.h
#pragma once
#include "State.h"
class RaffleActivity;
//��Ʒ�������״̬
class DispenseOutState :public State
{
public:
	DispenseOutState(RaffleActivity* activity);
	void deductMeney() override;
	bool raffle() override;
	//���Ž�Ʒ
	void dispensePrize() override;

private:
	RaffleActivity* activity;
};