///*
//* Problema medianului (4p)
//Se considera un vector de n numere intregi. Se numeste median acel element din vector,
//care s-ar afla pe pozitia din mijloc in vcectorul sortat. Daca n este par, atunci medianul este media aritmetica
//a celor 2 numere aflate pe pozitiile din centru.
//
//NU se sorteaza elementele.
//*/
//
//#include<iostream>
//#include<fstream>
//#include<vector>
//#include"PriorityQ.h"
//#include"PriorityQMinim.h"
//
//std::ifstream fin("inputEx04.txt");
//
//
//void printVector(std::vector<int> vector)
//{
//	for (int i = 0; i < vector.size(); i++)
//	{
//		std::cout << vector.at(i) << " ";
//	}
//}
//
////balansam cele doua liste de prioritate astfel incat intre ele sa nu fie o diferenta de marime mai mare decat 1
//void rebalanceQ(PriorityQMinim& qMinim, PriorityQ& qMaxim)
//{
//	if ((qMinim.getSize() - qMaxim.getSize()) > 1 || (qMaxim.getSize() - qMinim.getSize()) > 1)
//	{
//		if (qMinim.getSize() > qMaxim.getSize())
//		{
//			qMaxim.insertElement(qMinim.getMinElement());
//			qMinim.removeMin();
//
//		}
//
//		if (qMinim.getSize() < qMaxim.getSize())
//		{
//			qMinim.insertElement(qMaxim.getMaxElement());
//			qMaxim.removeMax();
//		}
//	}
//}
////imaginati-va ca qMaxim (maxHeap) e in partea stanga si qMinim (minHeap) e in partea dreapta
//void insertNumber(int number, PriorityQMinim& qMinim, PriorityQ& qMaxim)
//{
//	//daca numarul curent este mai mare decat elementul maxim din lista stanga, atunci el trebuie introdus in lista din dreapta
//	//lista din dreapta find un minHeap, el se va pozitiona in varful listei de prioritate
//	if (number > qMaxim.getMaxElement())
//	{
//		qMinim.insertElement(number);
//	}
//
//	//daca numarul curent este mai mic sau egal decat elementul maxim din lista stinga, atunci el trebuie introdus in lista din stanga
//	//lista din stanga find un maxHeap, el se va pozitiona in varful listei de prioritate
//	if (number <= qMaxim.getMaxElement())
//	{
//		qMaxim.insertElement(number);
//	}
//
//	//vom rebalansa listele pentru a nu exista mai mult decat 1 element diferenta intre ele
//	rebalanceQ(qMinim, qMaxim);
//}
//
////returneaza medianul
//double getMedian(PriorityQMinim qMinim, PriorityQ qMaxim)
//{
//	double median;
//
//	if (qMinim.getSize() == qMaxim.getSize())
//	{
//		median = (double)(qMinim.getMinElement() + qMaxim.getMaxElement()) / 2;
//	}
//
//	if (qMinim.getSize() > qMaxim.getSize())
//	{
//		median = qMinim.getMinElement();
//	}
//
//	if (qMinim.getSize() < qMaxim.getSize())
//	{
//		median = qMaxim.getMaxElement();
//	}
//
//	return median;
//}
//
//
//// se citeste cate un element din fisier; acest element se introduce intr-un vector
//// pentru a afla medianul dupa fiecare noua introducere, fara sortarea vectorului, folosim doua priority_queue: una maxHeap si cealalta minHeap
//// ideea algorimului este de a "inghesui" medianul intre cele doua priority_queues (care sunt balansate)
//// medianul se va afla pe pozitia de getMaxElement() din heap-ul maxim sau pe pozitia de getMinElement() din heap-ul minim
//// sau media aritmetica a getMaxElement() si getMinElement() in cazul in care cele doua heap-uri au aceasi marime;
//// 
//void readVector(std::vector<int>& vector)
//{
//	PriorityQ qMaxim;
//	PriorityQMinim qMinim;
//	int element;
//
//	while (fin >> element)
//	{
//		std::cout << "\nIntroducem " << element << "\n";
//		vector.push_back(element);
//
//		std::cout << "Vectorul este: ";
//		printVector(vector);
//
//		insertNumber(element, qMinim, qMaxim);
//		std::cout << "\nMedianul pentru acest vector este: " << getMedian(qMinim, qMaxim) << "\n";
//	}
//
//}
//
//
//
//
//void main()
//{
//	//Am studiat: https://www.youtube.com/watch?v=756_8C9YBZQ&t=307s
//
//	std::vector<int> vector;
//	readVector(vector);
//
//}