///*Arbore pentru statistici de ordine*/
//#include<iostream>
//#include<vector>
//#include<fstream>
//#include<string>
//#include<algorithm>
//#include <iomanip>
//#define SPACE 5
//
//
//std::ifstream fin("inputEx02.txt");
//
//struct Nod {
//
//	int punctaj;
//	Nod* parent, * left, * right;
//	std::vector<std::string> nume;
//
//
//	Nod(int puncte, std::string nume)
//	{
//		this->punctaj = puncte;
//		this->nume.push_back(nume);
//		this->parent = nullptr;
//		this->left = nullptr;
//		this->right = nullptr;
//	}
//};
//
//struct Arbore
//{
//	Nod* root;
//
//	Arbore()
//	{
//		root = nullptr;
//	}
//
//	//insereaza un cheie in arbore
//	void insert(int punctaj, std::string nume)
//	{
//		if (root != nullptr)
//		{
//
//
//			insertImplementation(punctaj, nume, root);
//		}
//		else
//		{
//			root = new Nod(punctaj, nume);
//		}
//		search(punctaj)->nume.at(0);
//	}
//
//	//insereaza un vector de chei in arbore (Metoda Construct din enunt)
//	void insert(std::vector< std::pair<int, std::string>> vector)
//	{
//		for (int i = 0; i < vector.size(); i++)
//		{
//			insert(vector.at(i).first, vector.at(i).second);
//		}
//	}
//
//
//	//printeaza arborele in stil grafic
//	void printTree()
//	{
//		print2D(this->root, 0);
//	}
//
//	//printeaza Stanga Radacina Dreapta 
//	void printInOrder()
//	{
//		printInOrderImplementation(root);
//		std::cout << "\n";
//	}
//
//
//	//cauta in arbore; daca se gaseste cheia se returneaza Nodul; altfel se returneaza NULL; 
//	Nod* search(int cheie)
//	{
//		Nod* iterator = root;
//		while (iterator != nullptr)
//		{
//			if (cheie == iterator->punctaj)
//			{
//				return iterator;
//			}
//
//			Nod* iterator2 = iterator;
//			if (cheie < iterator->punctaj)
//			{
//				iterator = iterator->left;
//			}
//
//			if (cheie > iterator2->punctaj)
//			{
//				iterator = iterator->right;
//			}
//		}
//		return nullptr;
//	}
//
//
//	//returneaza succesorul unui nod
//	Nod* getSuccesor(Nod* node)
//	{
//		Nod* result;
//		if (node->right != nullptr)
//		{
//			result = getMinimImplementation(node->right);
//		}
//		else
//		{
//			result = node->parent;
//			while (result != nullptr && node == result->right)
//			{
//				node = result;
//				result = result->parent;
//			}
//		}
//		return result;
//	}
//	//returneaza predecesorul unui nod
//	Nod* getPredecesor(Nod* node)
//	{
//		Nod* result;
//		if (node->left != nullptr)
//		{
//			result = getMaximImplementation(node->left);
//		}
//		else
//		{
//			result = node->parent;
//			while (result != nullptr && node == result->left)
//			{
//				node = result;
//				result = result->parent;
//			}
//		}
//		return result;
//	}
//
//	//verifica daca arborele este gol
//	bool empty()
//	{
//		if (root == nullptr)
//		{
//			return true;
//		}
//		return false;
//	}
//
//	//sterge Arborele
//	void clear()
//	{
//		clearImplementation(root);
//	}
//
//
//	//returneaza un vector 
//	std::vector<std::pair<int, std::string>> calculatePosition()
//	{
//		std::vector<std::pair<int, std::string>> position;
//		calculatePositionImplementation(root, position);
//
//		return position;
//
//	}
//
//	//adaptare a codului din curs
//	void deleteNod(int cheie)
//	{
//		Nod* sters = search(cheie);
//
//		if (sters->left == nullptr)
//		{
//			transplant(sters, sters->right);
//		}
//		else
//		{
//			if (sters->right == nullptr)
//			{
//				transplant(sters, sters->left);
//			}
//			else
//			{
//				Nod* succesor = getSuccesor(sters);
//
//				if (succesor != sters->right)
//				{
//					transplant(succesor, succesor->right);
//					succesor->right = sters->right;
//					sters->right->parent = succesor;
//				}
//				transplant(sters, succesor);
//				succesor->left = sters->left;
//				sters->left->parent = succesor;
//			}
//		}
//	}
//
//	Nod* getMinim()
//	{
//		return getMinimImplementation(root);
//	}
//
//	Nod* getMaxim()
//	{
//		return getMaximImplementation(root);
//	}
//
//
//private:
//
//	void calculatePositionImplementation(Nod* root, std::vector<std::pair<int, std::string>>& position)
//	{
//
//		if (root == nullptr)
//		{
//			return;
//		}
//
//		calculatePositionImplementation(root->left, position);
//
//		for (int i = 0; i < root->nume.size(); i++)
//		{
//			std::pair<int, std::string> numePunctaj;
//
//			numePunctaj.first = root->punctaj;
//			numePunctaj.second = root->nume.at(i);
//
//			position.push_back(numePunctaj);
//		}
//
//
//
//		calculatePositionImplementation(root->right, position);
//
//	}
//
//	//returneaza minimul din subarborele nodului introdus ca parametru
//	Nod* getMinimImplementation(Nod* node)
//	{
//		Nod* iterator = node;
//		while (iterator != nullptr)
//		{
//			if (iterator->left == nullptr)
//			{
//				return iterator;
//			}
//			iterator = iterator->left;
//		}
//		return nullptr;
//	}
//
//
//	//returneaza maximul din subarborele nodului introdus ca parametru
//	Nod* getMaximImplementation(Nod* node)
//	{
//		Nod* iterator = node;
//		while (iterator != nullptr)
//		{
//			if (iterator->right == nullptr)
//			{
//				return iterator;
//			}
//			iterator = iterator->right;
//		}
//		return nullptr;
//	}
//
//
//	//din curs
//	void transplant(Nod* sters, Nod* succesor)
//	{
//		if (sters->parent == nullptr)
//		{
//			root = succesor;
//		}
//		else
//		{
//			if (sters == sters->parent->left)
//			{
//				sters->parent->left = succesor;
//			}
//			else
//			{
//				sters->parent->right = succesor;
//			}
//		}
//
//		if (succesor != nullptr)
//		{
//			succesor->parent = sters->parent;
//		}
//	}
//
//	void insertImplementation(int punctaj, std::string nume, Nod* nodCurent)
//	{
//
//		if (punctaj < nodCurent->punctaj)
//		{
//			if (nodCurent->left != nullptr)
//			{
//				insertImplementation(punctaj, nume, nodCurent->left);
//			}
//			else
//			{
//				nodCurent->left = new Nod(punctaj, nume);
//				nodCurent->left->parent = nodCurent;
//			}
//		}
//
//		if (punctaj >= nodCurent->punctaj)
//		{
//			if (nodCurent->right != nullptr)
//			{
//				insertImplementation(punctaj, nume, nodCurent->right);
//			}
//			else
//			{
//				nodCurent->right = new Nod(punctaj, nume);
//				nodCurent->right->parent = nodCurent;
//			}
//		}
//	}
//
//	void print2D(Nod* root, int space)
//	{
//		if (root == nullptr)
//			return;
//		space += SPACE;
//
//		print2D(root->right, space);
//
//		std::cout << std::endl;
//
//		for (int i = SPACE; i < space; i++)
//			std::cout << " ";
//
//		std::cout << root->punctaj;
//		std::cout << "\n";
//
//		print2D(root->left, space);
//	}
//
//	void printInOrderImplementation(Nod* root)
//	{
//		if (root == nullptr)
//		{
//			return;
//		}
//		printInOrderImplementation(root->left);
//		//std::cout <<"cu punctaj: "<< root->punctaj<<" figureaza urmatorii studenti: ";
//		for (int i = 0; i < root->nume.size(); i++)
//		{
//			std::cout << std::resetiosflags(std::ios::adjustfield);
//			std::cout << std::setiosflags(std::ios::right);
//			std::cout << std::setw(7) << root->nume.at(i) << std::setw(8) << root->punctaj << '\n';
//		}
//
//		printInOrderImplementation(root->right);
//	}
//
//	void printPostOrdImplementation(Nod* root)
//	{
//		if (root == nullptr)
//		{
//			return;
//		}
//		printPostOrdImplementation(root->left);
//		printPostOrdImplementation(root->right);
//		std::cout << root->punctaj << " ";
//	}
//
//	void printPreOrderImplementation(Nod* root)
//	{
//		if (root == nullptr)
//		{
//			return;
//		}
//		std::cout << root->punctaj << " ";
//		printPreOrderImplementation(root->left);
//		printPreOrderImplementation(root->right);
//
//	}
//
//	void clearImplementation(Nod* root)
//	{
//		if (root == nullptr)
//		{
//			return;
//		}
//		clearImplementation(root->left);
//		clearImplementation(root->right);
//		delete(root);
//	}
//
//};
//
//void readVector(std::vector<std::pair<int, std::string>>& vector)
//{
//	int punctaj;
//	std::string nume;
//	while (fin >> punctaj)
//	{
//
//		std::pair<int, std::string> pair;
//		pair.first = punctaj;
//		fin >> nume;
//		pair.second = nume;
//		vector.push_back(pair);
//
//
//	}
//}
//
//bool mycomp(std::string nume1, std::string nume2) {
//	return nume1 < nume2;
//}
//
//
//void main()
//{
//	Arbore arbore;
//	std::vector<std::pair<int, std::string>> vector;
//	readVector(vector);
//
//	std::vector<std::pair<int, std::string>> position;
//	arbore.insert(vector);
//	position = arbore.calculatePosition();
//
//
//	int menuChoice;
//	std::string nume;
//	int punctajStudent;
//
//	do
//	{
//		std::cout << "\n\n\n\n\n\n\=========================================";
//		std::cout << "\nMENU";
//		std::cout << "\n1. Display punctaje";
//		std::cout << "\n2. Adauga un student cu punctaj";
//		std::cout << "\n3. Sterge un student";
//		std::cout << "\n4. Afiseaza studentul pe pozitia x?:";
//		std::cout << "\n5. Afla pozitia unui student in clasament:";
//		std::cout << "\n6. Afiseaza stundentii cu punctajul intre intervalul dorit: ";
//
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
//			std::cout << "Nume:        Punctaj:\n";
//			arbore.printInOrder();
//
//			break;
//		}
//		case 2:
//		{
//			system("CLS");
//
//
//			std::cout << "Introdu numele studentului: ";
//			std::cin >> nume;
//			std::cout << "Introdu punctajul obtinut de student: ";
//			std::cin >> punctajStudent;
//
//			if (arbore.search(punctajStudent) != nullptr)
//			{
//				arbore.search(punctajStudent)->nume.push_back(nume);
//				std::sort(arbore.search(punctajStudent)->nume.begin(), arbore.search(punctajStudent)->nume.begin(), mycomp);
//
//			}
//			else
//			{
//				arbore.insert(punctajStudent, nume);
//			}
//						
//			position = arbore.calculatePosition();
//			break;
//		}
//		case 3:
//		{
//			system("CLS");
//			std::cout << "Introdu numele studentului: ";
//			std::cin >> nume;
//			std::cout << "Introdu punctajul obtinut de student: ";
//			std::cin >> punctajStudent;
//			bool found = false;
//
//			Nod* tempNod = arbore.search(punctajStudent);
//			if (tempNod == nullptr)
//			{
//				std::cout << "Nu exista studentul";
//			}
//			else
//			{
//				if (tempNod->nume.size() == 1)
//				{
//					if (tempNod->nume.at(0) == nume)
//					{
//						arbore.deleteNod(punctajStudent);
//						found = true;
//					}
//				}
//				else
//				{
//					for (int i = 0; i < tempNod->nume.size(); i++)
//					{
//						if (tempNod->nume.at(i) == nume)
//						{
//							tempNod->nume.erase(tempNod->nume.begin() + i);
//							found = true;
//						}
//					}
//				}
//
//				if (found == false)
//				{
//					std::cout << "Nu exista studentul";
//				}
//			}
//			position = arbore.calculatePosition();
//			break;
//		}
//		case 4:
//		{
//			system("CLS");
//
//			std::cout << "Afla cine se afla pe o anumita pozitie din clasament. Introdu pozitia: ";
//			int pozitie;
//			std::cin >> pozitie;
//
//			if (pozitie < position.size() && pozitie>0)
//			{
//				int i = position.size() - pozitie;
//				int j = 1;
//
//				std::cout << "\nPe pozitia " << pozitie << " se afla studentul " << position.at(i).second << " cu punctajul de " << position.at(i).first;
//			}
//			else
//			{
//				std::cout << "\nWrong pozitie!";
//			}
//			break;
//		}
//		case 5:
//		{
//			system("CLS");
//			std::cout << "Afla pozitia unui student clasament. Introdu numele studentului: ";
//			std::cin >> nume;
//			bool found = false;
//			for (int i = 0; i < position.size(); i++)
//			{
//				if (nume == position.at(i).second)
//				{
//					std::cout << "\nStudentul " << nume << " se afla pe pozitia " << position.size() - i << " cu punctajul obtinut de " << position.at(i).first;
//					found = true;
//				}
//			}
//			if (!found)
//			{
//				std::cout << "\nStudentul " << nume << " nu exista in evidentele noastre!";
//			}
//
//			break;
//		}
//		case 6:
//		{
//			system("CLS");
//			std::cout << "Afla nr de persoanele cu punctajul aat într-un anumit interval";
//			int limitaInf, limitaSup;
//			std::cout << "\nIntrodu limita inferioara: ";
//			std::cin >> limitaInf;
//			std::cout << "Introdu limita superioara: ";
//			std::cin >> limitaSup;
//			int counter = 0;
//			std::cout << "\n";
//			for (int i = 0; i < position.size(); i++)
//			{
//				if (position.at(i).first>=limitaInf && position.at(i).first<=limitaSup)
//				{
//					std::cout << "Studentul " << position.at(i).second << " cu punctajul de " << position.at(i).first<<"\n";
//					counter++;
//				}
//			}
//			std::cout << "\nNumarul de studenti aflati in interval este: " << counter;
//
//
//
//
//			break;
//		}
//
//	
//		case 8:
//		{
//			system("CLS");
//			arbore.printTree();
//
//			break;
//		}
//
//
//
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