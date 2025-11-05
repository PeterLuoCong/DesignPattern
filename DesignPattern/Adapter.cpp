#include<iostream>
using  namespace  std;

class Deque
{
public:
	void push_back(int x)
	{
		cout << "Deque push_back:" << x << endl;
	}
	void push_front(int x)
	{
		cout << "Deque push_front:" << x << endl;
	}
	void pop_back()
	{
		cout << "Deque pop_back" << endl;
	}
	void pop_front()
	{
		cout << "Deque pop_front" << endl;
	}
};

class Sequence
{
public:
	virtual void push(int x) = 0;
	virtual void pop() = 0;
};

class Stack : public Sequence
{
public:
	void push(int x)override
	{
		m_deque.push_back(x);
	}
	void pop()override
	{
		m_deque.pop_back();
	}
private:
	Deque m_deque;
};

class Queue : public Sequence
{
public:
	void push(int x)override
	{
		m_deque.push_back(x);
	}
	void pop()override
	{
		m_deque.pop_front();
	}
private:
	Deque m_deque;
};

class Deque1
{
public:
	void push_back(int x)
	{
		cout << "Deque push_back:" << x << endl;
	}
	void push_front(int x)
	{
		cout << "Deque push_front:" << x << endl;
	}
	void pop_back()
	{
		cout << "Deque pop_back" << endl;
	}
	void pop_front()
	{
		cout << "Deque pop_front" << endl;
	}
};

class Sequence1
{
public:
	virtual void push(int x) = 0;
	virtual void pop() = 0;
};

class Stack1 :public Sequence1, private Deque1
{
public:
	void push(int x) override
	{
		push_back(x);
	}
	void pop() override
	{
		pop_back();
	}
};

class Queue1 :public Sequence1, private Deque1
{
public:
	void push(int x) override
	{
		push_back(x);
	}
	void pop() override
	{
		pop_front();
	}

	[[nodiscard]] int GetNum(int num)
	{
		return num * num;
	}
};


template <int N> struct Factorial {
	static const int value = N * Factorial<N - 1>::value;
};


template <>
struct Factorial<0>{
	static const int value = 1;
};
// C++11 ºó£ºconstexpr º¯Êý¸ü¼ò½à
constexpr int fact = Factorial<5>::value;

int  main_Adapter(void)
{
	/*Stack s;
	s.push(3);
	s.pop();
	Queue q;
	q.push(2);
	q.pop();*/

	Stack1 s;
	s.push(1);
	s.pop();

	Queue1 q;
	q.push(9);
	q.pop();
	int num = q.GetNum(7);
	cout << fact << endl;
	
	return 0;
}