////Parantezare corecta (1p)
//
//#include<iostream>;
//#include<fstream>
//#include<string>
//
//std::ifstream fin("inputEx2.txt");
//
//struct Node
//{
//	char info;
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
//	void push(char element)
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
//	char top()
//	{
//		if (varf)
//		{
//			return varf->info;
//		}
//
//		return -1; //returneaza -1 cand nu sunt elemente in stiva
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
///*citirea expresiei din fisierul "inputEx2.txt"
//dupa citirea din fisier se elimina caracterele "spatiu"
//*/
//void readFromFile(std::string& s)
//{
//	std::getline(fin, s);
//
//	//disclaimer: https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/
//	s.erase(remove(s.begin(), s.end(), ' '), s.end());
//}
//
//
////verifica caracterele expresiei; Returneaza "True" daca sirul este compus doar din paranteze.
//bool checkCharacters(std::string s)
//{
//
//	for (int i = 0; i < s.length(); i++)
//	{
//		switch (s.at(i))
//		{
//		case '}': break;
//		case ']': break;
//		case ')': break;
//		case'{': break;
//		case '[': break;
//		case '(':break;
//		default:
//		{
//			return false;
//			break;
//		}
//		}
//	}
//	return true;
//}
//
////verifica ca inchiderea parantezelor sa se efectueze corect: ( se inchide cu ), [ se inchide cu ] si { se inchide cu }
//bool checkParanteze(char parantezaTopStiva, char paranteza2)
//{
//	if (parantezaTopStiva == '(' && paranteza2 == ')')
//	{
//		return true;
//	}
//	if (parantezaTopStiva == '[' && paranteza2 == ']')
//	{
//		return true;
//	}
//	if (parantezaTopStiva == '{' && paranteza2 == '}')
//	{
//		return true;
//	}
//
//	return false;
//}
//
////verifica ordinea parantezelor
//bool checkOrder(char parantezaTopStiva, char paranteza2)
//{
//	if (parantezaTopStiva == '(' && (paranteza2 == '[' || paranteza2 == '{'))
//	{
//		return false;
//	}
//	if (parantezaTopStiva == '[' && paranteza2 == '{')
//	{
//		return false;
//	}
//
//	return true;
//}
//
////verificarea expresie
//bool checkExpression(std::string s)
//{
//
//	if (s.at(0) == '}' || s.at(0) == ']' || s.at(0) == ')')   //daca expresia incepe cu paranteze inchise => expresia este gresita.
//	{
//		std::cout << "Expresia incepe cu o paranteza inchisa\n";
//		return false;
//	}
//
//	if (checkCharacters(s)==false) //daca expresia contine si alte caractere decat paranteze => expresia este gresita
//	{
//		std::cout << "Expresia contine si alte caractere decat paranteze\n";
//		return false;
//	}
//
//	Stiva stiva;
//
//	for (int i = 0; i < s.length(); i++)
//	{
//
//		if (s.at(i) == '{' || s.at(i) == '[' || s.at(i) == '(')
//		{
//			if (!checkOrder(stiva.top(), s.at(i))) //daca ordinea parantezelor nu este de natura {, [, ( => expresia este gresita
//			{
//				std::cout << "Eroare generata de ordinea parantezelor. Ordinea parantezelor este { , [ si ( \n";
//				return false;
//			}
//			stiva.push(s.at(i));
//		}
//		else {
//
//			if (stiva.empty())			//daca stiva este deja goala, dar mai sunt paranteze de scos => expresia este gresita
//			{
//				std::cout << "Eroare... Prea multe paranteze de inchidere\n";
//				return false;
//			}
//
//			if (!checkParanteze(stiva.top(), s.at(i))) // daca paranteza pe care o scot nu este de acelasi tip => expresia este gresita
//			{
//				std::cout << "Eroare pe checkParanteze. Nu se grupeaza la inchidere cum trebuie\n";
//				return false;
//			}
//
//			stiva.pop();
//		}
//	}
//
//	if (!stiva.empty()) // daca sirul este parcurs integral, dar au mai ramas paranteze in stiva => expresia este gresita
//	{
//		return false;
//	}
//
//	return true; //daca firul executiei pana aici, inseamna ca expresia este corecta.
//}
//
//
//void main()
//{
//	//S-a utilizat structura Stiva de la exercitiul 1
//
//	std::string s;
//	readFromFile(s);
//	std::cout << "Expresia prelucrata este: " << s << "\n";
//
//	checkExpression(s) ? std::cout << "Paranteze valide\n" : std::cout << "Paranteze Invalide\n";
//
//
//	////Testam exemplele din enuntul problemei + altele
//	//std::cout << "\nAnalizam expresia: " << "[()()]" << "\n";
//	//checkExpression("[()()]") ? std::cout << "Paranteze valide\n" : std::cout << "Paranteze Invalide\n";
//
//	//std::cout << "\nAnalizam expresia: " << "([])" << "\n";
//	//checkExpression("([])") ? std::cout << "Paranteze valide\n" : std::cout << "Paranteze Invalide\n";
//
//	//std::cout << "\nAnalizam expresia: " << "()]" << "\n";
//	//checkExpression("()]") ? std::cout << "Paranteze valide\n" : std::cout << "Paranteze Invalide\n";
//
//	//std::cout << "\nAnalizam expresia: " << "]{[(]}" << "\n";
//	//checkExpression("]{[(]}") ? std::cout << "Paranteze valide\n" : std::cout << "Paranteze Invalide\n";
//	//
//	//
//	//std::cout << "\nAnalizam expresia: " << "{[`(]}" << "\n";
//	//checkExpression("{[`(]}") ? std::cout << "Paranteze valide\n" : std::cout << "Paranteze Invalide\n";
//
//}