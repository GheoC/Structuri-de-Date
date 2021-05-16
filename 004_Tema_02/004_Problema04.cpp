////Eliminarea parantezelor redundante (1p).
//
//#include<iostream>
//#include<string>
//#include<fstream>
//#include<stack>
//#include<vector>
//
//std::ifstream fin("inputEx4.txt");
//
//
////Ne folosim de aceasta structura pentru a mapa parantezele redundante din expresia introdusa:
//struct Litera
//{
//	char c;
//	int position;
//	bool redundant;
//};
//
//
////Compomenta stivei este de tipul "Litera"
////Este aceasi stiva de la Exercitiul 1, doar am modificat tipul de data ce il contine si anume "Litera"
//struct Node
//{
//	Litera info;
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
//	void push(Litera element)
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
//	Litera top()
//	{
//		if (varf)
//		{
//			return varf->info;
//		}
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
//
////citirea din fisier intr-o variabila de tip string si eliminarea caracterelor "spatiu"
//void readFromFile(std::string& s)
//{
//	std::getline(fin, s);
//	// disclaimer: https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/
//	s.erase(remove(s.begin(), s.end(), ' '), s.end());
//}
//
//
////se transpun literele citite prin readFromFile() intr-un vector de tip "Litera"
//// se initializeaza cu 0 toate literele ca fiind neredundante (adica redundant = false);
//std::vector<Litera> convertExpresion(std::string s)
//{
//	std::vector<Litera> rezultat;
//	Litera	litera;
//	for (int i = 0; i < s.size(); i++)
//	{
//		litera.c = s.at(i);
//		litera.position = i;
//		litera.redundant = 0;
//
//		rezultat.push_back(litera);
//	}
//	return rezultat;
//}
//// functia returneaza TRUE pentru caractere care sunt '+','*','-',
//bool checkCharacter(char element)
//{
//	switch (element)
//	{
//	case'+': break;
//	case'*': break;
//	case'-':break;
//	case'/':break;
//	case'(':break;
//	default:
//	{
//		return false;
//		break;
//	}
//	}
//	return true;
//}
//
//
//// Metoda identifica acele litere din expresie care sunt redundante si le marcheaza ca atare. 
//void findRedundant(std::vector<Litera>& s)
//{
//	//std::stack<Litera> stiva;
//	Stiva stiva;
//	Litera checker;
//
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (checkCharacter(s.at(i).c))
//		{
//			stiva.push(s.at(i));
//		}
//
//		if (s.at(i).c == ')')
//		{
//			checker = stiva.top();
//			stiva.pop();
//
//			// daca primul element care se scoate din stiva este '(' atunci perechea '(', ')' gasita este redundanta!
//			// pentru urmatorul if am definit struct Litera pentru a putea identifica pozitia literei scoase din Stiva; 
//			// daca nu as fi retinut si pozitia elementelor intr-o variabila de tip Litera as fi pierdut acasta informatie
//
//			if (checker.c == '(')
//			{
//				s.at(i).redundant = 1;					// marcam Litera.c == ')', gasita pe pozitia i din expresia noastra ca fiind redundanta
//
//				s.at(checker.position).redundant = 1;	// marcam Litera pereche '(' ce este scoasa din stiva ca fiind redunta
//			}
//			else 
//			{
//			//daca am intrat pe else-ul acesta, inseamna ca ce am scos din stiva la precedentul "pop" nu este o '(', ci un operator (+,-,*,/); 
//			//asta inseamna ca acum in stiva pe pozitia top se afla o paranteza valida '('
//			// o scoatem pur si simplu si nu o marcam ca fiind redundanta
//				stiva.pop(); 
//			}
//		}
//	}
//}
////afiseaza elementele neredundante din vectorul de tipul "Litera"
//void printExpresie(std::vector<Litera> s)
//{
//
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s.at(i).redundant == false)
//		{
//			std::cout << s.at(i).c;
//		}
//	}
//}
//
//void main()
//{
//	// Se presupune ca utilizatorul introduce o expresie CORECTA din punct de vedere matematic si ca singura problema este dublarea anumitor paranteze, 
//	// De asemenea cazul in care avem in expresie "(+)"nu este tratat fiind considerat expresie matematica incorecta!
//
//	std::string expresie;
//	readFromFile(expresie);
//	std::vector<Litera> expr = convertExpresion(expresie);
//
//	std::cout << "\nExpresia din fisier: ";
//	printExpresie(expr);
//
//	findRedundant(expr);
//
//	std::cout << "\nExpresia corectata prin eliminarea parantezelor redundante: ";
//	printExpresie(expr);
//
//	std::cout << "\n";
//}