///* Implementare coada circulara; (1p)
//Continut: vector DATA, SIZE_MAX, BEGIN, END
//- push(elem)
//- pop()
//- front()
//- empty()
//- clear()
//*/
//
//
//#include<iostream>
//#include<vector>
//
//
//struct circularQ
//{
//
//	int begin, end, maxSize;
//	std::vector<int> data;
//
//	circularQ(int size)
//	{
//		begin = -1;
//		end = -1;
//		maxSize = size;
//		data.reserve(maxSize);
//		for (int i = 0; i < maxSize; i++)
//		{
//			data.push_back(-1);
//		}
//	}
//
//	void push(int element)
//	{
//		if (isFull())
//		{
//			std::cout << "Coada este plina! Elementul " << element << " nu a fost adaugat.\n";
//			return;
//		}
//		else
//		{
//			if (empty())
//			{
//				end = 0;
//				begin = 0;
//				data.at(end) = element;
//			}
//			else
//			{
//				end = (end + 1) % maxSize;
//				data.at(end) = element;
//			}
//		}
//		std::cout << "Am adaugat: " << element << "\n";
//	}
//
//	int pop()
//	{
//		int numberPopped;
//		if (empty())
//		{
//			std::cout << "Coada e goala!";
//			return -1;
//		}
//		else
//		{
//			if (begin == end)
//			{
//				numberPopped = data.at(begin);
//				end = -1;
//				begin = -1;
//			}
//			else
//			{
//				numberPopped = data.at(begin);
//				begin = (begin + 1) % maxSize;
//			}
//
//			std::cout << "Am eliminat: " << numberPopped << "\n";
//			return numberPopped;
//		}
//
//	}
//
//	void display()
//	{
//		std::cout << "\n";
//
//		if (begin == -1)
//		{
//			std::cout << "Coada e goala!";
//			return;
//		}
//		std::cout << "Elemenetele cozii sunt: ";
//		if (begin <= end)
//		{
//			for (int i = begin; i <= end; i++)
//			{
//				std::cout << data.at(i) << ", ";
//			}
//		}
//		else
//		{
//			for (int i = begin; i < maxSize; i++)
//			{
//				std::cout << data.at(i) << ", ";
//			}
//			for (int i = 0; i <= end; i++)
//			{
//				std::cout << data.at(i) << ", ";
//			}
//
//		}
//
//		std::cout << "\n";
//	}
//
//	bool empty()
//	{
//		return begin == -1;
//	}
//
//	bool isFull()
//	{
//		return ((end + 1) % maxSize == begin);
//	}
//
//	int front() 
//	{
//		return begin;
//	}
//
//	int rear() 
//	{
//		return end;
//	}
//
//	void clear() 
//	{
//		begin = -1;
//		end = -1;
//		std::cout << "A fost apelata metoda clear() = > Coada a fost golita!";
//	}
//
//
//};
//
//void main()
//{
//	//Pentru a exemplifica functionarea cozii, te rog introdu "size-ul" de la 1 la 7"
//
//	bool checker = true;
//	int size;
//	std::cout << "Introdu numarul maxim de elemente ale cozii: ";
//	std::cin >> size;
//	if (size<=0)
//	{
//		std::cout << "Dimensiunea cozii trebuie sa fie > 0";
//		return;
//	}
//
//	circularQ q1(size);
//
//	q1.push(65);
//	q1.push(35);
//	q1.push(45);
//	q1.push(25);
//	q1.push(15);
//	q1.push(995);
//	q1.push(996);
//
//	q1.display();
//
//	q1.pop();
//	q1.pop();
//	q1.pop();
//	q1.display();
//
//	q1.push(989);
//	q1.push(1515);
//	q1.display();
//
//	q1.push(5);
//	q1.push(7);
//	q1.pop();
//	q1.display();
//
//	q1.clear();
//	q1.display();
//
//
//}