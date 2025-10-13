#include<iostream>
using  namespace  std;

typedef struct
{
	int grade;
	string arm;
	string corps;
}GameValue;

class Memento
{
public:
	Memento()
	{

	}
	Memento(GameValue gamevalue) :m_gameValue(gamevalue)
	{

	}
	GameValue getValue()
	{
		return m_gameValue;
	}
private:
	GameValue m_gameValue;
};

class Game
{
public:
	Game(GameValue gamevalue) :m_gameValue(gamevalue)
	{

	}

	void addGrade()
	{
		m_gameValue.grade++;
	}

	void replaceArm(string arm)
	{
		m_gameValue.arm = arm;
	}

	void replaceCorps(string corps)
	{
		m_gameValue.corps = corps;
	}
	Memento saveValue()
	{
		Memento mem(m_gameValue);
		return mem;
	}
	void load(Memento mem)
	{
		m_gameValue = mem.getValue();
	}
	void showValue()
	{
		cout << "Grade: " << m_gameValue.grade << endl;
		cout << "Arm: " << m_gameValue.arm << endl;
		cout << "Corps: " << m_gameValue.corps << endl;
	}
private:
	GameValue m_gameValue;
};

class Caretake
{
public:
	void save(Memento mem)
	{
		m_mem = mem;
	}
	Memento load()
	{
		return m_mem;
	}
private:
	Memento m_mem;
};
int  main_Memento1(void)
{
	GameValue v1 = { 0, "Ak", "3K" };
	Game game(v1);    //初始值
	game.addGrade();
	game.showValue();
	cout << "----------" << endl;
	Caretake care;
	Memento mem;
	care.save(game.saveValue());  //保存当前值
	game.addGrade();          //修改当前值
	game.replaceArm("M16");
	game.replaceCorps("123");
	game.showValue();
	cout << "----------" << endl;
	game.load(care.load());   //恢复初始值
	game.showValue();
	return 0;
}