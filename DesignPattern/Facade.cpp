#include<iostream>
using  namespace  std;

class Control
{
public:
	virtual void start() = 0;
	virtual void shutdown() = 0;
};
class Host : public Control
{
public:
	void start()override
	{
		cout << "Host start" << endl;
	}
	void shutdown()override
	{
		cout << "Host shutdown" << endl;
	}
};

class LCDDisplay : public Control
{
public:
	void start()override
	{
		cout << "LCD Display start" << endl;
	}
	void shutdown()override
	{
		cout << "LCD Dispaly shutdown" << endl;
	}
};

class Peripheral : public Control
{
public:
	void start()override
	{
		cout << "Peripheral start" << endl;
	}

	void shutdown()override
	{
		cout << "Peripheral shutdown" << endl;
	}
};

class Computer
{
public:
	Computer()
	{

	}
	~Computer()
	{
		cout << "Computer destructor called" << endl;
	}
	virtual void playingMasterGame()
	{
		cout << endl << "Playing Master Game" << endl << endl;
	}
	virtual void playingAirplaneBattleGame()
	{
		cout << endl << "Playing Airplane Battle Game" << endl << endl;
	}
	void start()
	{
		m_host.start();
		m_display.start();
		m_peripheral.start();
		cout << "Computer start" << endl;
	}

	void shutdown()
	{
		m_host.shutdown();
		m_display.shutdown();
		m_peripheral.shutdown();
		cout << "Computer shutdown" << endl;
	}

private:
	Host m_host;
	LCDDisplay m_display;
	Peripheral m_peripheral;
};

int  main(void)
{
	Computer computer;
	computer.start();

	computer.playingMasterGame();
	computer.playingAirplaneBattleGame();

	computer.shutdown();


	computer.~Computer();
	return 0;
}