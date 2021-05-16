#include <iostream>
#include <queue>
#include<stack>
#include<queue>

struct nod
{
	int inf;
	nod* next;
};

struct stiva
{
	nod* varf = nullptr;

	void push(int inf)
	{
		nod* new_node = new nod;
		new_node->inf = inf;
		new_node->next = varf;
		varf = new_node;
	}


};

struct coada
{
	nod* prim = nullptr;
	nod* ultim = nullptr;

	void push(int inf)
	{
		nod* new_node = new nod;
		new_node->inf = inf;
		new_node->next = nullptr;

		if (prim == nullptr)
			prim = ultim = new_node;

		ultim->next = new_node;
		ultim = new_node;
	}
};

struct lista {
	nod* first;

	lista()
	{
		first = nullptr;
	}

	void add(int k)
	{
		nod* x = new nod;
		x->inf = k;
		x->next = first;
		first = x;
	}

	void add(nod* x)
	{
		x->next = first;
		first = x;
	}

};



void stack_queue_pair()
{
	std::stack<int> s;
	std::stack<double> sd;

	s.push(3);
	s.push(7);
	s.pop();
	s.push(5);
	std::cout << s.top();


	std::queue<int>  c;
	c.push(5);
	c.push(7);
	c.pop();
	c.push(9);
	std::cout << c.front() << " ";

	std::pair<int, float> p(3, 5.6f);

	std::cout << p.first << " " << p.second << std::endl;

	std::pair<int, int> p2;
	p2 = std::make_pair<int, int>(4, 6);


	std::queue<std::pair<int, int>> q;
	q.push(p);
	q.push(std::make_pair<int, int>(5, 8));



}

void main()
{
	stiva s;
	s.push(5);
	s.push(7);
	s.push(5);
	s.push(53);

	std::cout << s.varf->inf << "\n";

	coada c;
	c.push(5);
	c.push(7);
	c.push(5);
	c.push(53);

	std::cout << c.prim->inf << "\n";

	lista l;
	l.add(5);
	l.add(7);
	l.add(5);
	l.add(53);
	std::cout << l.first->inf;

	stack_queue_pair();

	system("pause");
}

