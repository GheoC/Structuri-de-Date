/*Arbore pentru statistici de ordine*/
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#define SPACE 5


std::ifstream fin("inputEx02.txt");

struct Nod {

	int punctaj;
	Nod* parent, * left, * right;
	std::vector<std::string> nume;

	
	Nod(int puncte, std::string nume)
	{
		this->punctaj = puncte;
		this->nume.push_back(nume);
		this->parent = nullptr;
		this->left = nullptr;
		this->right = nullptr;
	}
};

struct Arbore
{
	Nod* root;

	Arbore()
	{
		root = nullptr;
	}

	//insereaza un cheie in arbore
	void insert(int punctaj, std::string nume)
	{
		if (root != nullptr)
		{
			if (search(punctaj) != NULL)
			{
				search(punctaj)->nume.push_back(nume);
				return;
			}

			insertImplementation(punctaj,nume, root);
		}
		else
		{
			root = new Nod(punctaj, nume);
		}
	}

	//insereaza un vector de chei in arbore (Metoda Construct din enunt)
	void insert(std::vector< std::pair<int, std::string>> vector)
	{
		for (int i = 0; i < vector.size(); i++)
		{
			insert(vector.at(i).first, vector.at(i).second);
		}
	}


	//printeaza arborele in stil grafic
	void printTree()
	{
		print2D(this->root, 0);
	}

	//printeaza Stanga Radacina Dreapta 
	void printInOrder()
	{
		printInOrderImplementation(root);
		std::cout << "\n";
	}


	//cauta in arbore; dac ase gaseste cheia se returneaza Nodul; altfel se returneaza NULL; 
	Nod* search(int cheie)
	{
		Nod* iterator = root;
		while (iterator != nullptr)
		{
			if (cheie == iterator->punctaj)
			{
				return iterator;
			}

			if (cheie < iterator->punctaj)
			{
				iterator = iterator->left;
			}

			if (cheie > iterator->punctaj)
			{
				iterator = iterator->right;
			}
		}
		return nullptr;
	}


	//returneaza succesorul unui nod
	Nod* getSuccesor(Nod* node)
	{
		Nod* result;
		if (node->right != nullptr)
		{
			result = getMinimImplementation(node->right);
		}
		else
		{
			result = node->parent;
			while (result != nullptr && node == result->right)
			{
				node = result;
				result = result->parent;
			}
		}
		return result;
	}
	//returneaza predecesorul unui nod
	Nod* getPredecesor(Nod* node)
	{
		Nod* result;
		if (node->left != nullptr)
		{
			result = getMaximImplementation(node->left);
		}
		else
		{
			result = node->parent;
			while (result != nullptr && node == result->left)
			{
				node = result;
				result = result->parent;
			}
		}
		return result;
	}

	//verifica daca arborele este gol
	bool empty()
	{
		if (root == nullptr)
		{
			return true;
		}
		return false;
	}

	//sterge Arborele
	void clear()
	{
		clearImplementation(root);
	}


	//returneaza un vector 
	std::vector<Nod*> calculatePosition()
	{
		std::vector<Nod*> position;
		calculatePositionImplementation(root, position);

		return position;

	}


	//adaptare a codului din curs
	void deleteNod(int cheie)
	{
		Nod* sters = search(cheie);

		if (sters->left == nullptr)
		{
			transplant(sters, sters->right);
		}
		else
		{
			if (sters->right == nullptr)
			{
				transplant(sters, sters->left);
			}
			else
			{
				Nod* succesor = getSuccesor(sters);

				if (succesor != sters->right)
				{
					transplant(succesor, succesor->right);
					succesor->right = sters->right;
					sters->right->parent = succesor;
				}
				transplant(sters, succesor);
				succesor->left = sters->left;
				sters->left->parent = succesor;
			}
		}
	}

	Nod* getMinim()
	{
		return getMinimImplementation(root);
	}

	Nod* getMaxim()
	{
		return getMaximImplementation(root);
	}


private:

	void calculatePositionImplementation(Nod* root, std::vector<Nod*>& position)
	{

		if (root == nullptr)
		{
			return;
		}

		calculatePositionImplementation(root->left, position);

		position.push_back(root);


		calculatePositionImplementation(root->right, position);

	}

	//returneaza minimul din subarborele nodului introdus ca parametru
	Nod* getMinimImplementation(Nod* node)
	{
		Nod* iterator = node;
		while (iterator != nullptr)
		{
			if (iterator->left == nullptr)
			{
				return iterator;
			}
			iterator = iterator->left;
		}
		return nullptr;
	}


	//returneaza maximul din subarborele nodului introdus ca parametru
	Nod* getMaximImplementation(Nod* node)
	{
		Nod* iterator = node;
		while (iterator != nullptr)
		{
			if (iterator->right == nullptr)
			{
				return iterator;
			}
			iterator = iterator->right;
		}
		return nullptr;
	}


	//din curs
	void transplant(Nod* sters, Nod* succesor)
	{
		if (sters->parent == nullptr)
		{
			root = succesor;
		}
		else
		{
			if (sters == sters->parent->left)
			{
				sters->parent->left = succesor;
			}
			else
			{
				sters->parent->right = succesor;
			}
		}

		if (succesor != nullptr)
		{
			succesor->parent = sters->parent;
		}
	}

	void insertImplementation(int punctaj, std::string nume, Nod* nodCurent)
	{
		


		if (punctaj < nodCurent->punctaj)
		{
			if (nodCurent->left != nullptr)
			{
				insertImplementation(punctaj, nume, nodCurent->left);
			}
			else
			{
				nodCurent->left = new Nod(punctaj,nume);
				nodCurent->left->parent = nodCurent;
			}
		}

		if (punctaj >= nodCurent->punctaj)
		{
			if (nodCurent->right != nullptr)
			{
				insertImplementation(punctaj, nume, nodCurent->right);
			}
			else
			{
				nodCurent->right = new Nod(punctaj,nume);
				nodCurent->right->parent = nodCurent;
			}
		}
	}

	void print2D(Nod* root, int space)
	{
		if (root == nullptr)
			return;
		space += SPACE;

		print2D(root->right, space);

		std::cout << std::endl;

		for (int i = SPACE; i < space; i++)
			std::cout << " ";

		std::cout << root->punctaj;
		std::cout << "\n";

		print2D(root->left, space);
	}

	void printInOrderImplementation(Nod* root)
	{
		if (root == nullptr)
		{
			return;
		}
		printInOrderImplementation(root->left);
		std::cout << root->punctaj;
		for (int i = 0; i < root->nume.size(); i++)
		{
			std::cout << "----- Nume:" << root->nume.at(i);
		}
		std::cout << "\n";

		printInOrderImplementation(root->right);
	}

	void printPostOrdImplementation(Nod* root)
	{
		if (root == nullptr)
		{
			return;
		}
		printPostOrdImplementation(root->left);
		printPostOrdImplementation(root->right);
		std::cout << root->punctaj << " ";
	}

	void printPreOrderImplementation(Nod* root)
	{
		if (root == nullptr)
		{
			return;
		}
		std::cout << root->punctaj << " ";
		printPreOrderImplementation(root->left);
		printPreOrderImplementation(root->right);

	}

	void clearImplementation(Nod* root)
	{
		if (root == nullptr)
		{
			return;
		}
		clearImplementation(root->left);
		clearImplementation(root->right);
		delete(root);
	}

};

void readVector(std::vector<std::pair<int, std::string>>& vector)
{
	int punctaj;
	std::string nume;
	while (fin >> punctaj)
	{

		std::pair<int, std::string> pair;
		pair.first = punctaj;
		fin >> nume;
		pair.second = nume;
		vector.push_back(pair);


	}
}


void main()
{
	Arbore arbore;
	std::vector<std::pair<int, std::string>> vector;
	readVector(vector);


	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i].first << " + " << vector[i].second << "\n";

	}

	std::vector<Nod*> position;

	arbore.insert(vector);
	position = arbore.calculatePosition();

	for (int i = 0; i < position.size(); i++)
	{
		std::cout << "Pozitia " << i << " punctaj " << position[i]->punctaj;
		for (int j = 0; j < position[i]->nume.size(); j++)
		{
			std::cout << "nume: " << position[i]->nume.at(j)<<"\n";
		}
	}

	arbore.printInOrder();

	arbore.insert(97, "gigi");
	position = arbore.calculatePosition();
	for (int i = 0; i < position.size(); i++)
	{
		std::cout << "Pozitia " << i << " punctaj " << position[i]->punctaj;
		for (int j = 0; j < position[i]->nume.size(); j++)
		{
			std::cout << "nume: " << position[i]->nume.at(j) << "\n";
		}
	}
	

	//
	//int menuChoice, element;

	//do
	//{
	//	std::cout << "\n\n\n\n\n\n\=========================================";
	//	std::cout << "\nMENU";
	//	std::cout << "\n1. Display punctaje";
	//	std::cout << "\n2. Cauta un element in arbore";
	//	std::cout << "\n3. Sterge un element din arbore";
	//	std::cout << "\n4. Afiseaza minimul din arbore";
	//	std::cout << "\n5. Afiseaza maximul din arbore: ";
	//	std::cout << "\n6. Afiseaza succesorul unui nod din arbore: ";
	//	std::cout << "\n7. Afiseaza predecesorul unui nod din arbore: ";
	//	std::cout << "\n8. Afiseaza arborele: ";
	//	std::cout << "\n\n9. Exit";
	//	std::cout << "\n=========================================";
	//	std::cout << "\n    Introdu optiunea: ";
	//	std::cin >> menuChoice;

	//	switch (menuChoice)
	//	{
	//	case 1:
	//	{
	//		system("CLS");
	//		int element;
	//		std::cout << "Introdu elementul de introdus in arbore: ";
	//		std::cin >> element;
	//		arbore.insert(element);

	//		break;
	//	}
	//	case 2:
	//	{
	//		system("CLS");
	//		int element;
	//		std::cout << "Introdu elementul pe care-l cauti in arbore: ";
	//		std::cin >> element;
	//		arbore.search(element) == nullptr ? std::cout << element << " not found\n" : std::cout << element << " found\n";
	//		break;
	//	}
	//	case 3:
	//	{
	//		system("CLS");
	//		int element;
	//		std::cout << "Introdu elementul pe care doresti sa-l stergi din arbore: ";
	//		std::cin >> element;

	//		if (arbore.search(element) != nullptr)
	//		{
	//			arbore.deleteNod(element);
	//			std::cout << element << " sters cu succes!";
	//		}
	//		else
	//		{
	//			std::cout << element << " not found in arbore";
	//		}

	//		break;
	//	}
	//	case 4:
	//	{
	//		system("CLS");
	//		std::cout << "Minimul din arbore este: ";
	//		arbore.getMinim() == nullptr ? std::cout << "Arbore empty" : std::cout << arbore.getMinim()->cheie;

	//		break;
	//	}
	//	case 5:
	//	{
	//		system("CLS");
	//		std::cout << "Maximul din arbore este: ";
	//		arbore.getMaxim() == nullptr ? std::cout << "Arbore empty" : std::cout << arbore.getMaxim()->cheie;
	//		break;
	//	}
	//	case 6:
	//	{
	//		system("CLS");
	//		std::cout << "Introdu elementul pentru care doresti sa afli succesorul: ";
	//		std::cin >> element;

	//		if (!arbore.empty())
	//		{
	//			Nod* succesor = arbore.getSuccesor(arbore.search(element));
	//			succesor == nullptr ? std::cout << "\nNu exista succesor pentru " << element : std::cout << "\n" << "Succesorul pentru " << element << " este " << succesor->cheie;
	//		}
	//		else
	//		{
	//			std::cout << "Arbore is empty!";
	//		}
	//		

	//		break;
	//	}

	//	case 7:
	//	{
	//		system("CLS");
	//		std::cout << "Introdu elementul pentru care doresti sa afli predecesorul: ";
	//		std::cin >> element;

	//		if (!arbore.empty())
	//		{
	//			Nod* predecesor = arbore.getPredecesor(arbore.search(element));
	//			predecesor == nullptr ? std::cout << "\nNu exista predecesor pentru " << element : std::cout << "\n" << "Predecesorul pentru " << element << " este " << predecesor->cheie;
	//		}
	//		else
	//		{
	//			std::cout << "Arbore is empty!";
	//		}

	//		break;
	//	}

	//	case 8:
	//	{
	//		system("CLS");
	//		int displayChoice;
	//		do
	//		{
	//			std::cout << "\n\n\n\n\n\n\=========================================";
	//			std::cout << "\n***** Modul afisare ******\n";
	//			std::cout << "1. Afisare inOrdine (S.R.D.)\n";
	//			std::cout << "2. Afisare preOrdine (R.S.D.)\n";
	//			std::cout << "3. Afisare postOrdine (S.D.R.)\n";
	//			std::cout << "4. Afisare 2-D\n";
	//			std::cout << "\n5. Inapoi la meniul principal\n";

	//			std::cout << "Introdu optiunea: ";

	//			std::cin >> displayChoice;

	//			switch (displayChoice)
	//			{
	//			case 1:
	//			{
	//				system("CLS");
	//				arbore.printInOrder();
	//				break;
	//			}
	//			case 2:
	//			{
	//				system("CLS");
	//				arbore.printPreOrder();
	//				break;
	//			}
	//			case 3:
	//			{
	//				system("CLS");
	//				arbore.printPostOrder();
	//				break;
	//			}
	//			case 4:
	//			{
	//				system("CLS");
	//				arbore.printTree();
	//				break;
	//			}

	//			default: 
	//			{
	//				system("CLS");
	//				std::cout << "\nOptiune invalida! Alege din nou: ";
	//				break;
	//			}
	//				
	//			}

	//		} while (displayChoice != 5);

	//		break;
	//	}

	//	case 9:
	//	{
	//		system("CLS");
	//		std::cout << "\nPe curand!\n\n";
	//		break;
	//	}
	//	default:
	//	{
	//		system("CLS");
	//		std::cout << "\nOptiune invalida! Alege din nou: ";
	//	}
	//	}
	//} while (menuChoice != 9);

}