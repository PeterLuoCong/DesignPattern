#include<iostream>
using  namespace  std;

class App
{
public:
	virtual ~App()
	{
		cout << "~App()" << endl;
	}
	virtual void run() = 0;
};

class GameApp : public App
{
public:
	~GameApp()
	{
		cout << "~GameApp()" << endl;
	}
	void run()
	{
		cout << "GameApp running" << endl;
	}
};

class TranslateApp : public App
{
public:
	~TranslateApp()
	{
		cout << "~TranslateApp" << endl;
	}
	void run()
	{
		cout << "TranslateApp running" << endl;
	}
};

class MobilePhone
{
public:
	virtual ~MobilePhone()
	{
		cout << "~MobilePhone()" << endl;
	}
	virtual void appRun(App* app) = 0;
};

class XiaoMi : public MobilePhone
{
public:
	virtual ~XiaoMi()
	{
		cout << "~XiaoMi()" << endl;
	}
	virtual void appRun(App* app)//将APP与手机桥接起来
	{
		cout << "XiaoMi: ";
		app->run();
	}
};

class HuaWei : public MobilePhone
{
public:
	virtual ~HuaWei()
	{
		cout << "~HuaWei()" << endl;
	}
	virtual void appRun(App* app)
	{
		cout << "HuaWei: ";
		app->run();
	}
};
int  main_Bridge(void)
{
	App* gameApp = new GameApp();
	App* translateApp = new TranslateApp();
	MobilePhone* mi = new XiaoMi();
	MobilePhone* hua = new HuaWei();
	mi->appRun(gameApp);
	mi->appRun(translateApp);
	hua->appRun(gameApp);
	hua->appRun(translateApp);

	delete hua;
	hua = nullptr;
	delete mi;
	mi = nullptr;
	delete translateApp;
	translateApp = nullptr;
	delete gameApp;
	gameApp = nullptr;
	return 0;
}