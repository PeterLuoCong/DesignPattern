//DispenseState.cpp
#include "DispenseState.h"
#include "RaffleActivity.h"

DispenseState::DispenseState(RaffleActivity* activity)
{
	this->activity = activity;
}

void DispenseState::deductMeney()
{
	cout << "���ܿ۳�����" << endl;
}

bool DispenseState::raffle()
{
	cout << "���ܳ齱��" << endl;
	return false;
}

//���Ž�Ʒ
void DispenseState::dispensePrize()
{
	if (activity->getCount() > 0)
	{
		cout << "�ͳ���Ʒ" << endl;
		activity->setState(activity->getNoRaffleState());
	}
	else
	{
		cout << "���ź�,��Ʒ������" << endl;
		//��Ʒ�Ѿ����꣬������˾Ͳ��ܳ齱��
		activity->setState(activity->getDispenseOutState());
	}
}