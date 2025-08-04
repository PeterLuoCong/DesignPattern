//����ģʽ
#include <iostream>
#include <queue>
#include <Windows.h>
using namespace std;

//Э�鴦����    �������ࣩ
class HandleClientProtocal
{
public:
	//�������ӽ��
	void AddMoney()
	{
		cout << "��������ӽ��" << endl;
	}
	//����������ʯ
	void AddDiamond()
	{
		cout << "�����������ʯ" << endl;
	}
	//�������װ��
	void AddEquipment()
	{
		cout << "����Ҵ�װ��" << endl;
	}
	//�������
	void AddLevel()
	{
		cout << "���������" << endl;
	}
};

//����ӿ�  
class AbstractCommand
{
public:
	//�൱��execute����
	virtual void handle() = 0;
};


//�����ǰ�ÿ�����ܶ���װΪһ���������
//�������ӽ������
class AddMoneyCommand :public AbstractCommand
{
public:
	AddMoneyCommand(HandleClientProtocal* protocal)
	{
		this->pProtocol = protocal;
	}
	virtual void handle()
	{
		this->pProtocol->AddMoney();
	}
public:
	HandleClientProtocal* pProtocol;
};

//����������ʯ����
class AddDiamondCommand :public AbstractCommand
{
public:
	AddDiamondCommand(HandleClientProtocal* protocal)
	{
		this->pProtocol = protocal;
	}
	virtual void handle()
	{
		this->pProtocol->AddDiamond();
	}
public:
	HandleClientProtocal* pProtocol;
};

//�������װ������
class AddEquipmentCommand :public AbstractCommand
{
public:
	AddEquipmentCommand(HandleClientProtocal* protocal)
	{
		this->pProtocol = protocal;
	}
	virtual void handle()
	{
		this->pProtocol->AddEquipment();
	}
public:
	HandleClientProtocal* pProtocol;
};

//���������������
class AddLevelCommand :public AbstractCommand
{
public:
	AddLevelCommand(HandleClientProtocal* protocal)
	{
		this->pProtocol = protocal;
	}
	virtual void handle()
	{
		this->pProtocol->AddLevel();
	}
public:
	HandleClientProtocal* pProtocol;
};

//����������   ����������ࣩ
class Server
{
public:
	//�����������봦�����
	void addRequest(AbstractCommand* command)
	{
		mCommands.push(command);
	}

	//�����������
	void startHandle()
	{
		while (!mCommands.empty())
		{
			Sleep(2000);
			AbstractCommand* command = mCommands.front();
			command->handle();
			mCommands.pop();
		}
	}
	queue<AbstractCommand*> mCommands;
};

void test01()
{
	HandleClientProtocal* protocal = new HandleClientProtocal;
	//�ͻ������ӽ�ҵ�����
	AbstractCommand* addmoney = new AddMoneyCommand(protocal);
	//�ͻ���������ʯ������
	AbstractCommand* adddiamond = new AddDiamondCommand(protocal);
	//�ͻ��˴�װ��������
	AbstractCommand* addequipment = new AddEquipmentCommand(protocal);
	//�ͻ�����������
	AbstractCommand* addlevel = new AddLevelCommand(protocal);

	//���ͻ��˵�������뵽���������
	Server* server = new Server;
	server->addRequest(addmoney);
	server->addRequest(adddiamond);
	server->addRequest(addequipment);
	server->addRequest(addlevel);

	//��������ʼ��������
	server->startHandle();
}


int main_Command()
{
	test01();
	return 0;
}
