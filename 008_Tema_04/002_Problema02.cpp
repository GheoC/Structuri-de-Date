///* implementare PriorityQueue folosind o structura/clasa care sa aiba:
//*  - camp Data de tip vector care stocheaza elementele sub forma unui maxHeap;
//*  - camp size - nr. de  elemente stocate in coada
//* Metode:
//*  - Insert - insereaza un nou nod in coada (0.5p)
//*  - ExtractMax - extrage elementul de prioritate maxima din coada (0.5p)
//*  - MaxElement - returneaza elementul de prioritate maxima (0.25p)
//*  - IncreaseKey - creste prioritatea unui nod (0.5p)
//*  - MaxHeapify - functie care coboara o cheie pe pozitia corespunzatoare din heap (0.5p)
//*
//* In main: se implementeaza un MENIU cu SWITCH (0.75p)
//*
//* Total puncte: 3p
//*
//*/
//
//#include<iostream>
//#include"PriorityQ.h"
//#include<fstream>
//
//
//void main()
//{
//
//	//Studiat: https://www.youtube.com/watch?v=NEtwJASLU8Q
//
//	PriorityQ priorityQ;
//
//	
//	int choice;
//	std::cout << "Doresti sa lucrezi pe o lista goala sau predefinita din fisier?\n";
//	std::cout << " - lista goala:        press 1\n";
//	std::cout << " - lista predefinita:  press 2\n";
//	do
//	{
//		std::cin >> choice;
//		if (choice == 2)
//		{
//			priorityQ.readDataFromFile();
//			std::cout << "\nLista este incarcata: \n";
//			priorityQ.printQ();
//		}
//
//		if (choice == 1)
//		{
//			std::cout << "\nAi ales varianta cu lista goala!";
//		}
//
//		if (choice != 1 && choice != 2)
//		{
//			std::cout << "Wrong choice! Try again: \n";
//		}
//
//	} while (choice != 1 && choice != 2);
//
//
//	int menuChoice, element;
//
//	do
//	{
//		std::cout << "\n\n\n\n\n\n\=========================================";
//		std::cout << "\nMENU";
//		std::cout << "\n1. Adauga in coada de prioritati";
//		std::cout << "\n2. Afiseaza maximul din coada";
//		std::cout << "\n3. Extrage maximul din coada";
//		std::cout << "\n4. Creste prioritatea unui element";
//		std::cout << "\n5. Afiseaza lista: ";
//		std::cout << "\n\n9. Exit";
//		std::cout << "\n=========================================";
//		std::cout << "\n    Introdu optiunea: ";
//		std::cin >> menuChoice;
//
//		switch (menuChoice)
//		{
//		case 1:
//		{
//			system("CLS");
//			std::cout << "\nAceasta este lista de prioritati curenta: ";
//			priorityQ.printQ();
//			std::cout << "\nIntrodu elementul pe care doresti sa-l adaugi in lista: ";
//			std::cin >> element;
//			priorityQ.insertElement(element);
//			std::cout << "\nAceasta este lista de prioritati dupa introducerea lui " << element << ":\n";
//			priorityQ.printQ();
//
//			break;
//		}
//		case 2:
//		{
//			system("CLS");
//			if (!priorityQ.isEmpty())
//			{
//				std::cout << "\nElementul maxim al cozii este: " << priorityQ.getMaxElement();
//			}
//			else
//			{
//				std::cout << "Lista este goala!";
//			}
//			break;
//		}
//		case 3:
//		{
//			system("CLS");
//			std::cout << "Stergem maximul din lista...\n ";
//			priorityQ.removeMax();
//			std::cout << "\n...rezultat: ";
//			priorityQ.printQ();
//			break;
//		}
//		case 4:
//		{
//			system("CLS");
//			int position;
//
//			if (priorityQ.isEmpty())
//			{
//				std::cout << "Lista e goala";
//			}
//			else
//			{
//				std::cout << "HINT: lista are un numar de " << priorityQ.getSize() << " elemente!\n";
//				std::cout << "Introdu pozitia pe care doresti sa o prioritizezi: ";
//				std::cin >> position;
//				priorityQ.increasePriority(position);
//			}
//
//			
//			break;
//		}
//		case 5:
//		{
//			system("CLS");
//			priorityQ.printQ();
//			break;
//		}
//		case 9:
//		{
//			system("CLS");
//			std::cout << "\nPe curand!\n\n";
//			break;
//		}
//		default:
//		{
//			system("CLS");
//			std::cout << "\nOptiune invalida! Alege din nou: ";
//		}
//		}
//	} while (menuChoice != 9);
//
//}