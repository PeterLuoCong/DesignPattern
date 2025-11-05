#include<iostream>
using namespace  std;

enum RequestLevel
{
	Level_One = 0,
	Level_Two,
	Level_Three,
	Level_Num
};

class Leader
{
public:
	Leader(Leader* leader) :m_leader(leader)
	{

	}

	virtual ~Leader()
	{

	}
	virtual void handleRequest(RequestLevel level) = 0;


protected:
	Leader* m_leader;
};

class Monitor : public Leader
{
public:
	Monitor(Leader* leader) :Leader(leader)
	{

	}
	void handleRequest(RequestLevel level)
	{
		if (level < Level_Two)
		{
			cout << "Monitor handle request : " << level + 1<< endl;
		}
		else
		{
			m_leader->handleRequest(level);
		}
	}
};

class Captain : public Leader
{
public:
	Captain(Leader* leader) :Leader(leader)
	{

	}
	void handleRequest(RequestLevel level)
	{
		if (level < Level_Three)
		{
			cout << "Captain handle request : " << level  + 1<< endl;
		}
		else
		{
			m_leader->handleRequest(level);
		}
	}
};

class General : public Leader
{
public:
	General(Leader* leader) :Leader(leader)
	{

	}
	void handleRequest(RequestLevel level)
	{
		cout << "General handle request : " << level + 1 << endl;
	}
};
int  main_ChainResponsibility(void)
{
	General* general = new General(nullptr);
	Captain* captain = new Captain(general);
	Monitor* monitor = new Monitor(captain);
	/*monitor->handleRequest(Level_Three);
	monitor->handleRequest(Level_Two);*/
	monitor->handleRequest(Level_Three);

	delete general;
	general = nullptr;

	delete captain;
	captain = nullptr;

	delete monitor;
	monitor = nullptr;
	return 0;
}