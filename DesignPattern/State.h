#pragma once
class State
{
public:
	//�۳�50����
	virtual void deductMeney() = 0;

	//�Ƿ��н�
	virtual bool raffle() = 0;

	//���Ž�Ʒ
	virtual void dispensePrize() = 0;
};
