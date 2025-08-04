//CanRaffleState.cpp
#include "CanRaffleState.h"
#include "RaffleActivity.h"
CanRaffleState::CanRaffleState(RaffleActivity* activity)
{
	srand(time(NULL));
	this->activity = activity;
}

//�Ѿ��۳������ˣ������ٿ���
void CanRaffleState::deductMeney()
{
	cout << "�Ѿ��۹�������" << endl;
}

//���Գ齱�����ݳ齱����ĳ��µ�״̬
bool CanRaffleState::raffle()
{
	cout << "���ڳ齱" << endl;
	int result = rand() % 10;
	if (0 == result)
	{
		//��activity��״̬����Ϊ���Ž�Ʒ��״̬
		activity->setState(activity->getDispenseState());
		return true;
	}
	else
	{
		cout << "���ź�û�г��н�Ʒ" << endl;
		//��activity��״̬����Ϊ���ܳ齱��״̬
		activity->setState(activity->getNoRaffleState());
		return false;
	}
}

void CanRaffleState::dispensePrize()
{
	cout << "û�н������ܷ��Ž�Ʒ" << endl;
}
