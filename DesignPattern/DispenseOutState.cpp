//DispenseOutState.cpp
#include "DispenseOutState.h"
#include "RaffleActivity.h"

DispenseOutState::DispenseOutState(RaffleActivity* activity)
{
	this->activity = activity;
}

void DispenseOutState::deductMeney()
{
	cout << "��Ʒ�Ѿ������ˣ����´��ٲμ�" << endl;
}

bool DispenseOutState::raffle()
{
	cout << "��Ʒ�Ѿ������ˣ����´��ٲμ�" << endl;
	return false;
}

//���Ž�Ʒ
void DispenseOutState::dispensePrize()
{
	cout << "��Ʒ�Ѿ������ˣ����´��ٲμ�" << endl;
}