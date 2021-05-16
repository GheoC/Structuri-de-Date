///*
//Lista simplu inlantuita:
// - push_front(key) (0.2p)
// - push_back(key)  (0.2p)
// - search(key)     (0.2p)
// - erase(node)     (0.2p)
// - empty()         (0.2p)
// - erase_doubles() (0.5p) + punctaj suplimentare pt complexitate buna;
// - erase(lista L)  (0.5p) + punctaj suplimentare pt complexitate buna;
// - clear()         (0.2p)
// - print()         (0.2p)
//
//*/
//
//#include<iostream>
//#include<stdlib.h>
//#include<set>
//
//struct Node
//{
//	int info;
//	Node* next;
//};
//
//struct Lista
//{
//	Node* head, * last;
//	int nrElemente;
//
//	Lista()
//	{
//		head = NULL;
//		last = NULL;
//		nrElemente = 0;
//	}
//
//	void push_front(int key)
//	{
//		Node* newNode = new Node;
//		newNode->info = key;
//
//
//		if (head == NULL)
//		{
//			newNode->next = NULL;
//			head = newNode;
//			last = newNode;
//		}
//		else
//		{
//			newNode->next = head;
//			head = newNode;
//		}
//		nrElemente++;
//
//	}
//
//	void push_back(int key)
//	{
//		Node* newNode = new Node;
//		newNode->info = key;
//		newNode->next = NULL;
//
//		if (head == NULL)
//		{
//			head = newNode;
//			last = head;
//		}
//		else
//		{
//			last->next = newNode;
//			last = newNode;
//			last->next = NULL;
//		}
//		nrElemente++;
//	}
//
//	Node* search(int key)
//	{
//		Node* iterator = head;
//		while (iterator != NULL)
//		{
//			if (iterator->info == key)
//			{
//				return iterator;
//			}
//			iterator = iterator->next;
//		}
//		return NULL;
//	}
//
//	void erase()
//	{
//		if (head == NULL)
//		{
//			std::cout << "\nStergere esuata! Lista e goala";
//			return;
//		}
//		Node* temp = head;
//		head = head->next;
//		nrElemente--;
//		delete(temp);
//	}
//
//	//work in progress
//	void erase(int key) 
//	{
//		Node* iterator=head->next;
//		Node* previous = head;
//
//		while (iterator != NULL)
//		{
//			if (iterator->info!=key)
//			{
//				previous = iterator;
//			}
//			else
//			{
//				previous->next = iterator->next;
//				std::cout << "\nStergem elementul " << iterator->info;
//				delete(iterator);
//				nrElemente--;
//			}
//			
//			iterator = previous->next;
//		}
//		last = previous;
//		if (head->info==key)
//		{
//			previous = head;	//se foloste nodul previous pentru a nu mai defi altul
//			head = head->next;
//			std::cout << "\nStergem elementul " << previous->info;
//			delete(previous);
//			nrElemente--;
//		}
//	}
//
//	bool empty()
//	{
//		return head == NULL;
//	}
//
//
//	// surse de inspiratie pentru metoda erase_doubles:
//	// - www.geeksforgeeks.org
//	// - https://www.youtube.com/watch?v=PCOhUGbv4EU
//	//
//	// S-a utilizat metoda Hashing pentr ua obtine o complexitate O(n);
//	// "We traverse the link list from head to end. For every newly encountered element, 
//	// we check whether it is in the hash table: if yes, we remove it; otherwise we put it in the hash table."
//	void erase_doubles()
//	{
//		if (empty())
//		{
//			std::cout << "Lista e goala!";
//			return;
//		}
//
//		std::set<int> visited;
//		visited.insert(head->info);
//		Node* iterator = head->next;
//		Node* previous = head;
//		while (iterator!=NULL)
//		{
//			//set.find(const g) Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to end.
//			//set.end() Returns an iterator to the theoretical element that follows last element in the set.
//			//
//			//daca iteratorul redurnat de find() este egal cu de iteratorul returnat de end(), inseamna ca set-ul nostru a fost parcurs si ca 
//			//"iterator->info" nu a fost gasit in set; in acest caz valoarea "iterator->info" se adauga in set;
//			if (visited.find(iterator->info)==visited.end())
//			{
//				visited.insert(iterator->info);
//				previous = iterator;
//			}
//			else
//			{
//				previous->next = iterator->next;
//				delete(iterator);
//				nrElemente--;
//			}
//			iterator = previous->next;
//		}
//		last = previous;
//	}
//
//	//Se sterg din lista curenta elementele prezent in lista argument
//	void eraseList(Lista list) 
//	{
//		if (empty())
//		{
//			return;
//		}
//		Node* iterator = list.head;
//		std::set<int> elements;
//		//adaugam intr-un "set" elementele listei pe care le dorim sa le scoate din lista curenta;
//		while (iterator!=NULL)
//		{
//			elements.insert(iterator->info);
//			iterator = iterator->next;
//		}
//		iterator = head->next;
//		Node* previous = head;
//
//		//similar cu metoda erase_doubles()
//		//se parcurge lista curenta, se verifica daca elementul curent se regaste in set-ul de mai sus; 
//		//in cazul in care este prezent se sterge din lista curenta si se trece la verificarea urmatorului element al listei curente;
//		while (iterator!=NULL)
//		{
//			if (elements.find(iterator->info) == elements.end())
//			{
//				previous = iterator;
//			}
//			else
//			{
//				previous->next = iterator->next;
//				std::cout << "\nStergem elementul " << iterator->info;
//				delete(iterator);
//				nrElemente--;
//			}
//			iterator = previous->next;
//		}
//		last = previous;
//
//		//la sfarsit se verifica si primul element din lista curenta
//		if (elements.find(head->info)!=elements.end())
//		{
//			previous = head;	//se foloste nodul previous pentru a nu mai defi altul
//			head = head->next;
//			std::cout << "\nStergem elementul " << previous->info;
//			delete(previous);
//			nrElemente--;
//		}
//	}
//
//	void clear() 
//	{
//		if (empty())
//		{
//			std::cout << "Lista e goala deja!";
//			return;
//		}
//		Node* iterator = head->next;
//		Node* temp;
//		while (iterator!=NULL)
//		{
//			temp = iterator;
//			iterator = iterator->next;
//			delete(temp);
//		}
//		head = NULL;
//		nrElemente = 0;
//	}
//
//	void print()
//	{
//		Node* iterator = head;
//		std::cout << "\n";
//		if (empty())
//		{
//			std::cout << "Lista e goala!";
//		}
//		else
//		{
//			while (iterator != NULL)
//			{
//				std::cout << iterator->info << " ";
//				iterator = iterator->next;
//			}
//		}
//	}
//
//
//};
//
//void main()
//{
//	int choice, element;
//	Lista list;
//	
//	do
//	{
//		std::cout << "\n\n\n\n\n\n\=========================================";
//		std::cout << "\nMENU";
//		std::cout << "\n1. Adauga la inceputul listei";
//		std::cout << "\n2. Adauga la sfarsitul listei";
//		std::cout << "\n3. Cauta in lista";
//		std::cout << "\n4. Sterge din lista";
//		std::cout << "\n5. Sterge un element \"key\" din lista";
//		std::cout << "\n6. Erase duplicates from list";
//		std::cout << "\n7. Erase from list some numbers";
//		std::cout << "\n8. Afiseaza lista";
//		std::cout << "\n9. Clear() lista";
//		std::cout << "\n\n99. Exit";
//		std::cout << "\n=========================================";
//		std::cout << "\n    Introdu optiunea: ";
//		std::cin >> choice;
//
//		switch (choice)
//		{
//		case 1:
//			{
//			system("CLS");
//			std::cout << "\nIntrodu elementul de pus in lista la inceput: ";
//			std::cin >> element;
//			list.push_front(element);
//			break;
//			}
//		case 2:
//			{
//			system("CLS");
//			std::cout << "\nIntrodu elementul de pus in lista la sfarsit: ";
//			std::cin >> element;
//			list.push_back(element);
//			break;
//			}
//		case 3:
//			{
//			system("CLS");
//			std::cout << "\nIntrodu elementul ce doresti sa-l cauti in lista: ";
//			std::cin >> element;
//			list.search(element);
//			if (list.search(element) == NULL)
//			{
//				std::cout << "\nNumarul " << element << " nu este in lista\n";
//			}
//			else
//			{
//				std::cout << "\nNumarul " << list.search(element)->info << " este in lista\n";
//			}
//			break;
//			}
//		case 4:
//			{
//			system("CLS");
//			if (!list.empty())
//			{
//				std::cout << "\nA fost eliminat din lista elementul: " << list.head->info;
//			}
//			list.erase();
//			break;
//			}
//		case 5:
//			{
//			system("CLS");
//			int key;
//			list.print();
//			if (!list.empty())
//			{
//				std::cout << "\nIntrodu elementul ce doresti sa-l stergi din lista: ";
//				std::cin >> key;
//				list.erase(key);
//			}
//			break;
//			}
//		case 6:
//		{
//			system("CLS");
//			std::cout << "\nEliminam dublurile din lista...\n";
//			list.erase_doubles();
//			break;
//		}
//		case 7:
//		{
//			system("CLS");
//
//			if (!list.empty())
//			{
//				list.print();
//				int number;
//				std::cout << "\nCate elemente din lista doresti sa elimini\n";
//				std::cin >> number;
//				do
//				{
//					if (number > list.nrElemente)
//					{
//						std::cout << "\nPrea multe elemente; Introdu din nou un numar mai mic decat " << list.nrElemente << ": ";
//						std::cin >> number;
//					}
//				} while (number > list.nrElemente);
//
//				Lista list2;
//				int element;
//				for (int i = 0; i < number; i++)
//				{
//					std::cout << "Introdu elementul: " << i + 1 << ": ";
//					std::cin >> element;
//					list2.push_front(element);
//				}
//
//				list.eraseList(list2);
//
//			}
//			else
//			{
//				std::cout << "\nNu poti sterge dintr-o lista goala";
//			}
//			break;
//		}
//		case 8:
//			{
//			system("CLS");
//			std::cout << "\nLista este: ";
//			list.print();
//			break;
//			}
//
//		case 9:
//		{
//			system("CLS");
//			std::cout << "\nS-a apelat clear(); Lista a fost golita!\n";
//			list.clear();
//			break;
//		}
//		case 99:
//			{
//			system("CLS");
//			std::cout << "\nPe curand!\n\n";
//			break;
//			}
//		default:
//			{
//			system("CLS");
//			std::cout << "\nOptiune invalida! Alege din nou: ";
//			}
//		}
//	} while (choice != 99);
//}