#pragma once
#include <iostream>
#include "State.h"
using namespace std;
class RaffleActivity;
//�ܳ齱״̬
class CanRaffleState :public State
{
public:
	CanRaffleState(RaffleActivity* activity);
	//�Ѿ��۳������ˣ������ٿ���
	void deductMeney() override;
	//���Գ齱�����ݳ齱����ĳ��µ�״̬
	bool raffle() override;
	void dispensePrize() override;
private:
	RaffleActivity* activity;
};