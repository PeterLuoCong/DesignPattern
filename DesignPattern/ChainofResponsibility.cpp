#include<iostream>
using namespace  std;

enum RepuestLevel
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
	virtual void handleRequest(RepuestLevel level) = 0;


protected:
	Leader* m_leader;
};

class Monitor : public Leader
{
public:
	Monitor(Leader* leader) :Leader(leader)
	{

	}
	void handleRequest(RepuestLevel level)
	{
		if (level < Level_Two)
		{
			cout << "Monitor handle request : " << level << endl;
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
	void handleRequest(RepuestLevel level)
	{
		if (level < Level_Three)
		{
			cout << "Captain handle request : " << level << endl;
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
	void handleRequest(RepuestLevel level)
	{
		cout << "General handle request : " << level << endl;
	}
};
int  main5563421(void)
{
	General* general = new General(nullptr);
	Captain* captain = new Captain(general);
	Monitor* monitor = new Monitor(captain);
	monitor->handleRequest(Level_Three);

	delete general;
	general = nullptr;

	delete captain;
	captain = nullptr;

	delete monitor;
	monitor = nullptr;
	return 0;
}