//NoRaffleState.h
#pragma once
#include <iostream>
#include "State.h"

using namespace std;
class RaffleActivity;

//���ܳ齱״̬
class NoRaffleState :public State
{
public:
	NoRaffleState(RaffleActivity* activity);
	//�ڲ��ܳ齱״̬�ǿ��Կۻ��ֵģ��۳����ֺ����óɿ��Գ齱״̬
	void deductMeney() override;
	bool raffle() override;
	void dispensePrize() override;

private:
	//��ʼ��ʱ�������۳����ֺ�ı���״̬
	RaffleActivity* activity;
};
