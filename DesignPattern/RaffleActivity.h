//RaffleActivity.h
#pragma once
#include "CanRaffleState.h"
#include "DispenseOutState.h"
#include "DispenseState.h"
#include "State.h"
#include "NoRaffleState.h"

class RaffleActivity
{
public:
	State* getState() const {
		return state;
	}
	void setState(State* const state)
	{
		this->state = state;
	}

	int getCount()
	{
		return count--;
	}

	void setCount(const int count)
	{
		this->count = count;
	}

	State* getNoRaffleState() const
	{
		return noRaffleState;
	}

	void setNoRaffleState(State* const noRaffleState)
	{
		this->noRaffleState = noRaffleState;
	}

	State* getCanRaffleState() const
	{
		return canRaffleState;
	}

	void setCanRaffleState(State* const canRaffleState)
	{
		this->canRaffleState = canRaffleState;
	}

	State* getDispenseState() const
	{
		return dispenseState;
	}

	void setDispenseState(State* const dispenseState)
	{
		this->dispenseState = dispenseState;
	}

	State* getDispenseOutState() const
	{
		return dispenseOutState;
	}

	void setDispenseOutState(State* const dispenseOutState)
	{
		this->dispenseOutState = dispenseOutState;
	}

	RaffleActivity(int count)
	{
		//��ʼ����ǰ״̬Ϊ ���ܳ齱״̬
		this->state = getNoRaffleState();
		//��ʼ����Ʒ����
		this->count = count;
	}

	//�۷֣����õ�ǰ״̬��deductMoney
	void deductMoney()
	{
		state->deductMeney();
	}

	//�齱
	void raffle()
	{
		//������н��ˣ����콱Ʒ
		if (state->raffle())
		{
			state->dispensePrize();
		}
	}

private:
	//state��ʾ���ǰ��״̬
	State* state = nullptr;
	//��Ʒ����
	int count = 0;
	//�ĸ����� ��ʾ����״̬
	State* noRaffleState = new NoRaffleState(this);
	State* canRaffleState = new CanRaffleState(this);
	State* dispenseState = new DispenseState(this);
	State* dispenseOutState = new DispenseOutState(this);
};