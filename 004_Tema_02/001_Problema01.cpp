////Implementare Stiva (1p).
//
//
//#include<iostream>
//
//struct Node
//{
//	int info;
//	Node* previous;
//};
//
//struct Stiva
//{
//	Node* varf;
//	int size;
//
//	Stiva()
//	{
//		varf = NULL;
//		size = 0;
//	}
//
//	void push(int element)
//	{
//		Node* newNode = new Node;
//		newNode->info = element;
//		newNode->previous = varf;
//		varf = newNode;
//
//		size++;
//	}
//
//	void pop()
//	{
//		if (varf != nullptr)
//		{
//			Node* removedNode = varf;
//			varf = varf->previous;
//			size--;
//			delete(removedNode);
//		}
//	}
//
//	int top()
//	{
//		if (varf)
//		{
//			return varf->info;
//		}
//
//		return -1; //returneaza -1 cand nu sunt elemente in stiva
//	}
//
//	bool empty()
//	{
//		if (!varf)
//		{
//			return true; //returneaza TRUE daca stiva este goala
//		}
//		return false;
//	}
//
//	void clear()
//	{
//		while (varf != NULL)
//		{
//			pop();
//		}
//
//	}
//};
//
//void main()
//{
//	Stiva s;
//	int number, element;
//	std::cout << "Introdu numarul de elemente: ";
//	std::cin >> number;
//
//	for (int i = 0; i < number; i++)
//	{
//		std::cout << "introdu elementul " << i + 1 << ": ";
//		std::cin >> element;
//		s.push(element);
//	}
//
//	for (int i = 0; i < number; i++)
//	{
//		std::cout << "Elementul " << s.top() << " a fost sters; Stiva mai are alte " << s.size - 1 << " elemente\n";
//		s.pop();
//
//	}
//
//
//	////Alte testari...
//	////doua push-uri
//	//s.push(5);
//	//std::cout << s.top() << " cu marimea de " << s.size << "\n";
//	//s.push(15);
//	//std::cout << s.top() << " cu marimea de " << s.size << "\n";
//
//	////verificam daca stiva este goala
//	//s.empty() ? std::cout << "Stiva is empty\n" : std::cout << "Stiva is Not empty\n";
//
//	////doua pop-uri
//	//s.pop();
//	//std::cout << s.top() << " cu marimea de " << s.size << "\n";
//	//s.pop();
//	//std::cout << s.top() << " cu marimea de " << s.size << "\n";
//
//	////verificam din nou daca stiva este goala
//	//s.empty() ? std::cout << "Stiva is empty\n" : std::cout << "Stiva is Not empty\n";
//
//	////trei push-uri
//	//s.push(10);
//	//s.push(20);
//	//s.push(30);
//	//std::cout << s.top() << " cu marimea de " << s.size << "\n";
//
//	////golim stiva;
//	//s.clear();
//	//std::cout << s.top() << " cu marimea de " << s.size << "\n";
//	//s.empty() ? std::cout << "Stiva is empty\n" : std::cout << "Stiva is Not empty\n";
//}