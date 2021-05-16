/*
Implementati un arbore binat de cautare cu chei numere intregi. Utilizati o structura  NOD,
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


	//returneaza minimul din subarborele nodului introdus ca parametru
	Nod* getMinim(Nod* node)
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
	Nod* getMaxim(Nod* node)
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


	//returneaza succesorul unui nod
	Nod* getSuccesor(Nod* node)
	{
		Nod* result;
		if (node->right != nullptr)
		{
			result = getMinim(node->right);
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
			result = getMaxim(node->left);
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

	void deleteNod(int cheie) 
	{

	}


private:
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



void main()
{
	Arbore arbore;

	std::vector<int> vector;
	readVector(vector);

	arbore.insert(vector);
	arbore.printTree();

	arbore.printInOrder();
	arbore.printPostOrder();
	arbore.printPreOrder();

	std::cout << "\n" << arbore.root->cheie << "\n";

	arbore.search(89) == nullptr ? std::cout << "Not found\n" : std::cout << "Found\n";
	arbore.search(189) == nullptr ? std::cout << "Not found\n" : std::cout << "Found\n";

	arbore.getMinim(arbore.search(189)) == nullptr ? std::cout << "Not found" : std::cout << arbore.getMinim(arbore.search(189))->cheie;
	arbore.getMinim(arbore.search(63)) == nullptr ? std::cout << "Not found" : std::cout << arbore.getMaxim(arbore.search(63))->cheie;


	Nod* testSuccesor = arbore.getSuccesor(arbore.search(92));
	testSuccesor == nullptr ? std::cout << "\nNu exista" : std::cout << "\n" << testSuccesor->cheie;

	Nod* testPredecesor = arbore.getPredecesor(arbore.search(75));
	testPredecesor == nullptr ? std::cout << "\nNu exista" : std::cout << "\n" << testPredecesor->cheie;


	Arbore arbore2;

	std::cout << "Clearing: \n";
	std::cout << "\n" << arbore.empty();
	std::cout << arbore.root->cheie;
	arbore.clear();

	std::cout << "\n" << arbore.empty();

	std::cout << arbore.root->cheie;
}