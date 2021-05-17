/*
Implementati un arbore binar de cautare cu chei numere intregi. Utilizati o structura  NOD,
care are un camp de tip int, ce stocheaza cheia nodului si trei campuri de tip pointer la NOD
pentru fiul stang, fiul drept si parintele nodului.De asemenea structura NOD dispune de un constructor
care seteaza  campul int la o valoare transmisa  prin parametru si campurile de tip pointer la NOD le
initializeaza cu NULL. Utilizati apoi o structura de tip ARBORE_CAUT, care are ca membru RADACINA de tip
pointer la NOD. In plus structura trebuie sa aiba metodele:

- INSERT - insereaz  un nou nod In arbore (0.25 p)
- MAXIM(NOD *x) / MINIM(NOD *x)- returneaza nodul cu cheia maxima / minima  din subarborele de radacina x (0.25 p ambele functii)
- SUCCESOR(NOD *x) / PREDECESOR(NOD *x) - returneaza nodul care este succesorul / predecesorul nodului x (0.25 p ambele functii)
- SEARCH(int val) - returneaz  nodul cu valoarea val dac  exist  sau NULL altfel. (0.25 p)
- DELETE(NOD *x) - sterge din arbore nodul x (care a fost mai Intai identificat prin SEARCH) (0.25 p)
- PRINT_TREE(int opt) - afiseza arborele in preordine (daca opt=1), inordine (daca opt=2),
  in postordine (daca opt=3), pe niveluri (daca opt=4). (0.5 p dintre care 0.25 pentru primele 3 afisari si 0.25 pentru a 4-a).
- CONSTRUCT - construieste un AB cautare pornind de la un vector de chei. (0.25p)
- EMPTY() - verifica daca arborele este vid. (0.25 p)
- CLEAR() - sterge toate nodurile din arbore (0.25 p)

*/

#include<iostream>
#include<fstream>
#include<vector>
#define SPACE 5

std::ifstream fin("inputEx01.txt");

struct Nod {

	int cheie;
	Nod* parent, * left, * right;

	Nod(int cheie)
	{
		this->cheie = cheie;
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
	void insert(int cheie)
	{
		if (root != nullptr)
		{
			insertImplementation(cheie, root);
		}
		else
		{
			root = new Nod(cheie);
		}
	}

	//insereaza un vector de chei in arbore (Metoda Construct din enunt)
	void insert(std::vector<int> vector)
	{
		for (int i = 0; i < vector.size(); i++)
		{
			insert(vector.at(i));
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

	//printeaza Stanga Dreapta Radacina
	void printPostOrder()
	{
		printPostOrdImplementation(root);
		std::cout << "\n";
	}

	//printeaza Radacina Stanga Dreapta
	void printPreOrder()
	{
		printPreOrderImplementation(root);
		std::cout << "\n";
	}

	//cauta in arbore; dac ase gaseste cheia se returneaza Nodul; altfel se returneaza NULL; 
	Nod* search(int cheie)
	{
		Nod* iterator = root;
		while (iterator != nullptr)
		{
			if (cheie == iterator->cheie)
			{
				return iterator;
			}

			if (cheie < iterator->cheie)
			{
				iterator = iterator->left;
			}

			if (cheie > iterator->cheie)
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

	void insertImplementation(int cheie, Nod* nodCurent)
	{
		if (cheie < nodCurent->cheie)
		{
			if (nodCurent->left != nullptr)
			{
				insertImplementation(cheie, nodCurent->left);
			}
			else
			{
				nodCurent->left = new Nod(cheie);
				nodCurent->left->parent = nodCurent;
			}
		}

		if (cheie >= nodCurent->cheie)
		{
			if (nodCurent->right != nullptr)
			{
				insertImplementation(cheie, nodCurent->right);
			}
			else
			{
				nodCurent->right = new Nod(cheie);
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

		std::cout << root->cheie;
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
		std::cout << root->cheie << " ";
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
		std::cout << root->cheie << " ";
	}

	void printPreOrderImplementation(Nod* root)
	{
		if (root == nullptr)
		{
			return;
		}
		std::cout << root->cheie << " ";
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

void readVector(std::vector<int>& vector)
{
	int element;
	while (fin >> element)
	{
		vector.push_back(element);
	}
}


//something for git testing
void main()
{
	Arbore arbore;
	std::vector<int> vector;
	readVector(vector);


	int choice;
	std::cout << "Doresti sa lucrezi pe un arbore gol sau predefinit din fisier?\n";
	std::cout << " - arbore gol:         press 1\n";
	std::cout << " - arbore predefinit:  press 2\n";
	do
	{
		std::cin >> choice;
		if (choice == 2)
		{
			arbore.insert(vector);
			std::cout << "\nArborele este incarcat: \n";
			arbore.printTree();
		}

		if (choice == 1)
		{
			std::cout << "\nAi ales varianta cu arbore gol!";
		}

		if (choice != 1 && choice != 2)
		{
			std::cout << "Wrong choice! Try again: \n";
		}

	} while (choice != 1 && choice != 2);


	int menuChoice, element;

	do
	{
		std::cout << "\n\n\n\n\n\n\=========================================";
		std::cout << "\nMENU";
		std::cout << "\n1. Adauga un nod in arbore";
		std::cout << "\n2. Cauta un element in arbore";
		std::cout << "\n3. Sterge un element din arbore";
		std::cout << "\n4. Afiseaza minimul din arbore";
		std::cout << "\n5. Afiseaza maximul din arbore: ";
		std::cout << "\n6. Afiseaza succesorul unui nod din arbore: ";
		std::cout << "\n7. Afiseaza predecesorul unui nod din arbore: ";
		std::cout << "\n8. Afiseaza arborele: ";
		std::cout << "\n\n9. Exit";
		std::cout << "\n=========================================";
		std::cout << "\n    Introdu optiunea: ";
		std::cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:
		{
			system("CLS");
			int element;
			std::cout << "Introdu elementul de introdus in arbore: ";
			std::cin >> element;
			arbore.insert(element);

			break;
		}
		case 2:
		{
			system("CLS");
			int element;
			std::cout << "Introdu elementul pe care-l cauti in arbore: ";
			std::cin >> element;
			arbore.search(element) == nullptr ? std::cout << element << " not found\n" : std::cout << element << " found\n";
			break;
		}
		case 3:
		{
			system("CLS");
			int element;
			std::cout << "Introdu elementul pe care doresti sa-l stergi din arbore: ";
			std::cin >> element;

			if (arbore.search(element) != nullptr)
			{
				arbore.deleteNod(element);
				std::cout << element << " sters cu succes!";
			}
			else
			{
				std::cout << element << " not found in arbore";
			}

			break;
		}
		case 4:
		{
			system("CLS");
			std::cout << "Minimul din arbore este: ";
			arbore.getMinim() == nullptr ? std::cout << "Arbore empty" : std::cout << arbore.getMinim()->cheie;

			break;
		}
		case 5:
		{
			system("CLS");
			std::cout << "Maximul din arbore este: ";
			arbore.getMaxim() == nullptr ? std::cout << "Arbore empty" : std::cout << arbore.getMaxim()->cheie;
			break;
		}
		case 6:
		{
			system("CLS");
			std::cout << "Introdu elementul pentru care doresti sa afli succesorul: ";
			std::cin >> element;

			if (!arbore.empty())
			{
				Nod* succesor = arbore.getSuccesor(arbore.search(element));
				succesor == nullptr ? std::cout << "\nNu exista succesor pentru " << element : std::cout << "\n" << "Succesorul pentru " << element << " este " << succesor->cheie;
			}
			else
			{
				std::cout << "Arbore is empty!";
			}
			

			break;
		}

		case 7:
		{
			system("CLS");
			std::cout << "Introdu elementul pentru care doresti sa afli predecesorul: ";
			std::cin >> element;

			if (!arbore.empty())
			{
				Nod* predecesor = arbore.getPredecesor(arbore.search(element));
				predecesor == nullptr ? std::cout << "\nNu exista predecesor pentru " << element : std::cout << "\n" << "Predecesorul pentru " << element << " este " << predecesor->cheie;
			}
			else
			{
				std::cout << "Arbore is empty!";
			}

			break;
		}

		case 8:
		{
			system("CLS");
			int displayChoice;
			do
			{
				std::cout << "\n\n\n\n\n\n\=========================================";
				std::cout << "\n***** Modul afisare ******\n";
				std::cout << "1. Afisare inOrdine (S.R.D.)\n";
				std::cout << "2. Afisare preOrdine (R.S.D.)\n";
				std::cout << "3. Afisare postOrdine (S.D.R.)\n";
				std::cout << "4. Afisare 2-D\n";
				std::cout << "\n5. Inapoi la meniul principal\n";

				std::cout << "Introdu optiunea: ";

				std::cin >> displayChoice;

				switch (displayChoice)
				{
				case 1:
				{
					system("CLS");
					arbore.printInOrder();
					break;
				}
				case 2:
				{
					system("CLS");
					arbore.printPreOrder();
					break;
				}
				case 3:
				{
					system("CLS");
					arbore.printPostOrder();
					break;
				}
				case 4:
				{
					system("CLS");
					arbore.printTree();
					break;
				}

				default: 
				{
					system("CLS");
					std::cout << "\nOptiune invalida! Alege din nou: ";
					break;
				}
					
				}

			} while (displayChoice != 5);

			break;
		}

		case 9:
		{
			system("CLS");
			std::cout << "\nPe curand!\n\n";
			break;
		}
		default:
		{
			system("CLS");
			std::cout << "\nOptiune invalida! Alege din nou: ";
		}
		}
	} while (menuChoice != 9);
}