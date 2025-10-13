//命令模式
#include <iostream>
#include <queue>
#include <Windows.h>
using namespace std;

//协议处理类    （请求类）
class HandleClientProtocal
{
public:
	//处理增加金币
	void AddMoney()
	{
		cout << "给玩家增加金币" << endl;
	}
	//处理增加钻石
	void AddDiamond()
	{
		cout << "给玩家增加钻石" << endl;
	}
	//处理玩家装备
	void AddEquipment()
	{
		cout << "给玩家穿装备" << endl;
	}
	//玩家升级
	void AddLevel()
	{
		cout << "给玩家升级" << endl;
	}
};

//命令接口  
class AbstractCommand
{
public:
	//相当于execute（）
	virtual void handle() = 0;
};


//下面是把每个功能都封装为一个请求对象
//处理增加金币请求
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

//处理增加钻石请求
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

//处理玩家装备请求
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

//处理玩家升级请求
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

//服务器程序   （命令调用类）
class Server
{
public:
	//将请求对象放入处理队列
	void addRequest(AbstractCommand* command)
	{
		mCommands.push(command);
	}

	//启动处理程序
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
	//客户端增加金币的请求
	AbstractCommand* addmoney = new AddMoneyCommand(protocal);
	//客户端增加钻石的请求
	AbstractCommand* adddiamond = new AddDiamondCommand(protocal);
	//客户端穿装备的请求
	AbstractCommand* addequipment = new AddEquipmentCommand(protocal);
	//客户端升级请求
	AbstractCommand* addlevel = new AddLevelCommand(protocal);

	//将客户端的请求加入到请求队列中
	Server* server = new Server;
	server->addRequest(addmoney);
	server->addRequest(adddiamond);
	server->addRequest(addequipment);
	server->addRequest(addlevel);

	//服务器开始处理请求
	server->startHandle();
}


int main_Command1()
{
	test01();
	return 0;
}
