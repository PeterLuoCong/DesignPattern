//NoRaffleState.cpp
#include "NoRaffleState.h"
#include "RaffleActivity.h";

NoRaffleState::NoRaffleState(RaffleActivity* activity)
{
	this->activity = activity;
}

//�ڲ��ܳ齱״̬�ǿ��Կۻ��ֵģ��۳����ֺ����óɿ��Գ齱״̬
void NoRaffleState::deductMeney()
{
	std::cout << "�۳�50���֣����Գ齱��" << endl;
	activity->setState(activity->getCanRaffleState());
}

bool NoRaffleState::raffle()
{
	cout << "���˻��ֲ��ܳ齱" << endl;
	return false;
}

void NoRaffleState::dispensePrize()
{
	cout << "���ܷ���Ʒ" << endl;
}
