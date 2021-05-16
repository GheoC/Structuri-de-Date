///*Arbore sintactic (2p)
//
//*/
//
//#include<iostream>
//#include<fstream>
//#include<string>
//#include<vector>
//#include<stack>
//#include<string>
//#define SPACE 10
//
//std::ifstream fin("inputEx04.txt");
//
//
////randul 20 - 286 sunt extrase din Tema 2 pentru generarea formei postFixate
//struct Simbol
//{
//	double numar;
//	char litera;
//	bool checker; //0 for letter; 1 for number 
//
//	void toString()
//	{
//		if (checker == 1)
//		{
//			std::cout << numar;
//		}
//		else
//		{
//			std::cout << litera;
//		}
//
//	}
//};
//
//struct Node
//{
//	Simbol info;
//	Node* left;
//	Node* right;
//};
//
//void readFromFile(std::string& s)
//{
//	std::getline(fin, s);
//	s.erase(remove(s.begin(), s.end(), ' '), s.end());
//}
//
//bool validCharacter(char element)
//{
//	switch (element)
//	{
//	case'+': break;
//	case'*': break;
//	case'-':break;
//	case'/':break;
//	case'(':break;
//	case ')':break;
//	case'^': break;
//	default:
//	{
//		return false;
//		break;
//	}
//	}
//	return true;
//}
//
//bool isOperator(char element)
//{
//	switch (element)
//	{
//	case'+': break;
//	case'*': break;
//	case'-':break;
//	case'/':break;
//	case'^': break;
//	default:
//	{
//		return false;
//		break;
//	}
//	}
//	return true;
//}
//
////se converteste Expresia intr-un sir de Simboluri
//std::vector<Simbol> convertExpresion(std::string s)
//{
//	std::vector<Simbol> rezultat;
//	Simbol simbol;
//
//	int i = 0;
//	while (i < s.size())
//	{
//		if (validCharacter(s.at(i)))
//		{
//			simbol.litera = s.at(i);
//			simbol.numar = NULL;
//			simbol.checker = 0;
//
//			rezultat.push_back(simbol);
//		}
//		if (std::isdigit(s.at(i)))
//		{
//			int number = (int)s.at(i) - 48;
//			int j = i + 1;
//			bool isNumber = true;
//			while (j < (s.size()) && isNumber)
//			{
//				if (std::isdigit(s.at(j)))
//				{
//					number = number * 10 + ((int)s.at(j) - 48);
//					j++;
//				}
//				else { isNumber = false; };
//			}
//
//			i = j - 1;
//			simbol.litera = NULL;
//			simbol.numar = number;
//			simbol.checker = 1;
//
//			rezultat.push_back(simbol);
//		}
//		i++;
//	}
//	return rezultat;
//}
//
//
////se afiseaza expresia matematica stocata intr-un vector de Simboluri;
//void printExpresion(std::vector<Simbol> s)
//{
//
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s.at(i).checker == 0)
//		{
//			std::cout << s.at(i).litera;
//		}
//		else
//		{
//			std::cout << s.at(i).numar;
//		}
//	}
//}
//
////Metoda returneaza validarea expresiei
//bool validateExpresion(std::string expr)
//{
//	//se verifica primul si ultimul caracter al expresiei astfel inca sa nu operator aritmetic
//
//	if (isOperator(expr.at(0)) || isOperator(expr.at(expr.size() - 1)))
//	{
//		std::cout << "Eroare de sintaxa; Nu sunt permisi operatori aritmetici la inceputul expresiei sau la sfarsit! ";
//		return false;
//	}
//
//	//se verifica corectitudinea parantezelor;
//	std::stack<char> stivaParanteze;
//	for (int i = 0; i < expr.size(); i++)
//	{
//		if (expr.at(i) == '(')
//		{
//			stivaParanteze.push(expr.at(i));
//		}
//
//		if (expr.at(i) == ')')
//		{
//			if (stivaParanteze.empty())
//			{
//				std::cout << "Paranteze incorecte; Una din paranteze ) nu este deschisa inainte! ";
//				return false;
//			}
//			else
//			{
//				stivaParanteze.pop();
//			}
//		}
//	}
//	if (!stivaParanteze.empty())
//	{
//		std::cout << "Paranteze incorecte; Parantezele deschise nu se inchid in totalitate! ";
//		return false;
//	}
//
//	//se verifica continutul expresiei astfel incat expresia sa nu contina caractere nepermise
//	for (int i = 0; i < expr.size(); i++)
//	{
//
//		if ((validCharacter(expr.at(i)) || (std::isdigit(expr.at(i)) > 0)) == false) {
//
//			std::cout << "Eroare de continut; Expresia contine caractere nepermise! ";
//			return false;
//		}
//	}
//
//	//se verifica sa nu existe doi operatori aritmetici consecutivi;
//	std::stack<char> stivaOperatori;
//	for (int i = 0; i < expr.size(); i++)
//	{
//		if (isOperator(expr.at(i)))
//		{
//			if (stivaOperatori.empty())
//			{
//				stivaOperatori.push(expr.at(i));
//			}
//			else
//			{
//				std::cout << "Eroare de sintaxa; Operatori aritmetici consecutivi! ";
//				return false;
//			}
//		}
//		if (std::isdigit(expr.at(i)) && !stivaOperatori.empty())
//		{
//			stivaOperatori.pop();
//		}
//	}
//	return true;
//}
//
////Metoda folosita in stabilerea oridii de efectuare a operatiilor.
//int precedence(char c)
//{
//	if (c == '^')
//	{
//		return 3;
//	}
//
//	if (c == '*' || c == '/')
//	{
//		return 2;
//	}
//	if (c == '+' || c == '-')
//	{
//		return 1;
//	}
//	return -1;
//}
//
//
////metoda de generare a formei postfix conform algoritm prezentat in "FormaPoloneza.pdf"
//std::vector<Simbol> generatePostFix(std::vector<Simbol> s)
//{
//	std::stack<Simbol> stivaCaractere;
//	std::vector<Simbol> postFixResult;
//
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s.at(i).checker == 1)
//		{
//			postFixResult.push_back(s.at(i));
//		}
//		else
//		{
//			if (s.at(i).litera == '(')
//			{
//				stivaCaractere.push(s.at(i));
//			}
//			else
//			{
//				if (s.at(i).litera == ')')
//				{
//					while (!stivaCaractere.empty() && stivaCaractere.top().litera != '(')
//					{
//						Simbol tempSimbol = stivaCaractere.top();
//						postFixResult.push_back(tempSimbol);
//						stivaCaractere.pop();
//					}
//					if (stivaCaractere.top().litera == '(')
//					{
//						stivaCaractere.pop();
//					}
//				}
//				else
//				{
//					while (!stivaCaractere.empty() && (precedence(s.at(i).litera) <= precedence(stivaCaractere.top().litera)))
//					{
//						Simbol tempSimbol = stivaCaractere.top();
//						postFixResult.push_back(tempSimbol);
//						stivaCaractere.pop();
//					}
//					stivaCaractere.push(s.at(i));
//				}
//			}
//		}
//	}
//	while (!stivaCaractere.empty())
//	{
//		postFixResult.push_back(stivaCaractere.top());
//		stivaCaractere.pop();
//	}
//	return postFixResult;
//
//}
//
////Una din sursele studiului individual este: https://www.youtube.com/watch?v=WHs-wSo33MM
////codul este foarte similar cu metoda mea "evaluatePostFix(std::vector<Simbol> postfix)" din Tema 2 care returneaza valoarea expresiei
//Node* generateTree(std::vector<Simbol> expresiePostFixata)
//{
//	std::stack<Node*> stackNodes;
//	Node* top;
//	Node* left, * right;
//
//	for (int i = 0; i < expresiePostFixata.size(); i++)
//	{
//		//daca checker==1 (adica numar), creem nodul si facem push in stiva;
//		if (expresiePostFixata.at(i).checker == 1)
//		{
//			top = new Node;
//			top->info = expresiePostFixata.at(i);
//			top->left = nullptr;
//			top->right = nullptr;
//			stackNodes.push(top);
//		}
//		else
//		{	//daca este operator atunci el devine nod radacina pentru primele doua elemente din stiva
//			//primul element scos din stiva devine nodul drept
//			//al doilea element scos din stiva devine nodul stang
//			right = stackNodes.top();
//			stackNodes.pop();
//
//			left = stackNodes.top();
//			stackNodes.pop();
//
//			top = new Node;
//			top->info = expresiePostFixata.at(i);
//			top->left = left;
//			top->right = right;
//
//			////dupa ce facem legaturile pentru nodul radacina al subarborelui (in cazul de fata noul "top"), ii dam push inapoi in stiva
//			stackNodes.push(top);
//		}
//	}
//	//Dupa ce s-au parcurs toate elementele expresiei postfixate, in stiva ramane nodul radacina al arborelui pe care il scoate si-l returnam;
//	top = stackNodes.top();
//	stackNodes.pop();
//	return top;
//}
//
//void printInorder(Node* root)
//{
//	if (root)
//	{
//		printInorder(root->left);
//		if (root->info.checker == 1)
//		{
//
//			std::cout << root->info.numar;
//			std::cout << "\n";
//		}
//		else
//		{
//			std::cout << root->info.litera;
//			std::cout << "\n";
//		}
//		printInorder(root->right);
//	}
//}
//
//
////Pentru metoda de mai jos am studiat: https://www.youtube.com/watch?v=xhkSiIeTKQo&t=422s
//void print2D(Node* r, int space)
//{
//	if (r == NULL)
//		return;
//	space += SPACE;
//	print2D(r->right, space);
//	std::cout << std::endl;
//	for (int i = SPACE; i < space; i++)
//		std::cout << " ";
//	r->info.toString();
//	std::cout << "\n";
//	print2D(r->left, space);
//}
//
//void main()
//{
//	std::string s;
//	readFromFile(s);
//	std::cout << s << "\n";
//	std::vector<Simbol> postFix;
//
//	if (validateExpresion(s))
//	{
//		postFix = generatePostFix(convertExpresion(s));
//	}
//	std::cout << "Postfix expresion: ";
//	printExpresion(postFix);
//	std::cout << "\n";
//	Node* root = generateTree(postFix);
//
//	std::cout << "\n";
//
//	//afisarea este rotita cu 90* in stanga
//	print2D(root, 0);
//
//
//}