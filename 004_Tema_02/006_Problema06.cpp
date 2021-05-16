///*Bucket sort utilizand o lista dublu inlantuita (2p)
//  Metode obligatorii:
//  - insert(key) pe pozitia potrivita;
//  - merge(L) uneste lista curenta cu lista L, rezultand o lista sortata;
//  - clear() - goleste lista;
//  - empty() - verifica daca lista e vida;
//  - print() - afiseaza elementele stocate in lista;
//*/
//
//#include<iostream>;
//#include<vector>
//
//
//struct Node
//{
//	Node* prev;
//	Node* next;
//	double info;
//};
//
//struct DoubleLinkedList
//{
//	Node* first;
//	Node* last;
//	int size;
//
//	DoubleLinkedList()
//	{
//		first = NULL;
//		last = NULL;
//		size = 0;
//	}
//
//
//	//insert an element into a sorted pozition;
//	void insert(double key)
//	{
//		size++;
//		Node* newNod = new Node;
//		newNod->info = key;
//
//		if (first == NULL)
//		{
//			newNod->prev = NULL;
//			newNod->next = NULL;
//
//			first = newNod;
//			last = newNod;
//		}
//		else
//
//			if (key < first->info)
//			{
//				Node* temp = first;
//				newNod->next = temp;
//				first = newNod;
//				temp->prev = newNod;
//
//			}
//			else
//			{
//				Node* iteratorNode;
//				iteratorNode = first;
//				int counter = 0;
//
//
//				while ((iteratorNode->next != NULL) && (newNod->info > iteratorNode->next->info))
//				{
//					iteratorNode = iteratorNode->next;
//					counter++;
//				}
//
//				newNod->next = iteratorNode->next;
//
//
//				if (iteratorNode->next != NULL)
//				{
//					newNod->next->prev = newNod;
//				}
//
//				if (iteratorNode->next == NULL)
//				{
//					last = newNod;
//					last->prev = iteratorNode;
//				}
//
//				iteratorNode->next = newNod;
//				newNod->prev = iteratorNode;
//			}
//	}
//
//	//Uneste lista curenta cu lista myList
//	void merge(DoubleLinkedList& myList)
//	{
//		Node* iterator = myList.first;
//		while (iterator != NULL)
//		{
//			insert(iterator->info);
//			iterator = iterator->next;
//		}
//
//		myList.first = NULL;
//		myList.last = NULL;
//	}
//
//	//Metoda suplimentara fata de enuntul problemei
//	//Metoda returneaza valoarea unui element din lista aflat pe o pozitie solicitata de utilizator
//	void at(int pozition)
//	{
//		Node* iterator = first;
//
//		int i = 0;
//		while (iterator != NULL)
//		{
//			if (i == pozition)
//			{
//				std::cout << "Elementul pe pozitia " << pozition << " este: " << iterator->info;
//				std::cout << "\n";
//				return;
//			}
//			i++;
//			iterator = iterator->next;
//		}
//
//		//daca se ajunge aici incseamna ca iteratorul "i" a depasit marimea listei;
//		std::cout << "Nu exista asa multe elemente\n";
//	}
//
//	//verifica daca lista e goala; returneaza true daca e goala;
//	bool isEmpty()
//	{
//		if (first == nullptr)
//		{
//			return true;
//
//		}
//
//		return false;
//	}
//
//
//	//se afiseaza lista;
//	void printList()
//	{
//		Node* iterator = first;
//
//		int i = 0;
//
//		if (isEmpty() == true)
//		{
//			std::cout << "Lista e GOALA! ";
//		}
//		else
//		{
//			while (iterator != NULL)
//			{
//				std::cout << "Elementul " << i << " este:  " << iterator->info << "\n";
//				iterator = iterator->next;
//				i++;
//			}
//		}
//	}
//
//	void clear()
//	{
//
//		first = NULL;
//		last = NULL;
//	}
//};
//
//
//int getMaximFrom(std::vector<double> lista)
//{
//	int maxim = lista.at(0);
//
//	for (int i = 0; i < lista.size(); i++)
//	{
//		if (lista.at(i) > maxim)
//		{
//			maxim = lista.at(i);
//		}
//	}
//
//	return maxim;
//}
//
//int getMinFrom(std::vector<double> lista)
//{
//	int minim = lista.at(0);
//
//	for (int i = 0; i < lista.size(); i++)
//	{
//		if (lista.at(i) < minim)
//		{
//			minim = lista.at(i);
//		}
//	}
//
//	return minim;
//}
//
////DISCLAIMER: Pe langa algoritmul de la pag 200 din Cormen 
////m-a ajutat si acest videoclip https://www.youtube.com/watch?v=vfIoJMsqJ74 pentru a intelege bucketSortul
//void bucketSort(std::vector<double>& lista)
//{
//	if (lista.empty())
//	{
//		std::cout << "Lista este goala!";
//		return;
//	}
//	//algoritmul pentru a functiona si cu numere negative se foloseste o 
//	int bazaDeShiftare = getMaximFrom(lista);
//	int shiftingNumber = std::abs(getMinFrom(lista));
//	int length = bazaDeShiftare + std::abs(shiftingNumber) + 1;
//
//
//	DoubleLinkedList* bucketVector = new DoubleLinkedList[length];
//
//	for (int i = 0; i < lista.size(); i++)
//	{
//		bucketVector[(int)(lista.at(i) + shiftingNumber)].insert(lista.at(i));
//	}
//
//	std::vector<double> result;
//	for (int i = 0; i < length; i++)
//	{
//		if (bucketVector[i].isEmpty() == false)
//		{
//			Node* iterator = bucketVector[i].first;
//			while (iterator != NULL)
//			{
//				result.push_back(iterator->info);
//				iterator = iterator->next;
//			}
//		}
//	}
//
//	lista = result;
//
//}
//
//void printVector(std::vector<double> lista)
//{
//	if (lista.empty())
//	{
//		std::cout << "\nLista este goala!\n";
//		return;
//	}
//
//	for (int i = 0; i < lista.size(); i++)
//	{
//		std::cout << lista.at(i) << ", ";
//	}
//	std::cout << "\n";
//}
//
//void main()
//{
//	DoubleLinkedList lista1;
//	lista1.insert(5);
//	lista1.insert(11.9);
//	lista1.insert(11.5);
//	lista1.insert(-6);
//	lista1.insert(-9);
//	lista1.insert(20);
//
//	std::cout << "Lista 1: \n";
//	lista1.printList();
//
//	std::cout << std::endl;
//
//	DoubleLinkedList lista2;
//	lista2.insert(7);
//	lista2.insert(-2);
//	lista2.insert(11.8);
//	lista2.insert(23);
//	lista2.insert(11.1);
//
//	std::cout << "Lista 2: \n";
//	lista2.printList();
//
//	lista1.merge(lista2);
//	std::cout << "\nLista 1 = Lista 1 + Lista 2: \n";
//	lista1.printList();
//
//	std::cout << "\nS-a apelat clear() pe Lista1 => ";
//	lista1.clear();
//	lista1.printList();
//
//
//	std::cout << std::endl;
//	std::cout << "\nSortam v1: ";
//	std::vector<double> v1 = { 6.9, 6.2 , 707.7, 109.5, 109.2, 6.5, 15.3, 15.1, 15.7, 6.7, 707.5, 109.9 };
//
//	printVector(v1); //before bucketSort
//	bucketSort(v1);
//	printVector(v1); //after bucketSort
//
//
//	std::cout << "\n";
//	std::cout << "Sortam v2, vector ce contine numere negative: ";
//	std::vector<double> v2 = { 7.05, -4544, -976.2, -976.6, -976.8, 0, 998, -787, 7.06, 8 };
//	printVector(v2); //before bucketSort
//	bucketSort(v2);
//	printVector(v2); //after bucketSort;
//
//}