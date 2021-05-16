///*Forma Poloneza:
//
//a) Sa se construiasca forma poloneza postfixata si sa se afiseze    (1p)
//b) Sa se evalueze expresia si sa se afiseze rezultatul              (1p)   
//c) Sa se semnaleze erori in expresie                                (1p)
//d) algoritm cu numere intregi de mai multe cifre                    (1p)
//e) algoritm nu numere reale                                         NOT AVAILABLE...sorry, work in progress
//
//*/
//
//#include<iostream>
//#include<stack>
//#include<fstream>
//#include<vector>
//#include<string>
//
//std::ifstream fin("inputEx3.txt");
//
//struct Simbol
//{
//	double numar;
//	char litera;
//	bool checker; //0 for letter; 1 for number 
//
//	void toString()
//	{
//		std::cout << numar << ", " << litera << "\n";
//	}
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
//
//
//
//
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
//
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
//
//	while (!stivaCaractere.empty())
//	{
//		postFixResult.push_back(stivaCaractere.top());
//		stivaCaractere.pop();
//	}
//
//	return postFixResult;
//
//}
//
////metoda care returneaza rezultatul operatiilor matematice dintre doua numere
//double operatie(double numarBaza, double numarSecund, char op)
//{
//	if (op == '^')
//	{
//		return pow(numarBaza, numarSecund);
//	}
//
//	if (op == '*')
//	{
//		return numarBaza * numarSecund;
//	}
//
//	if (op == '/')
//	{
//		return numarBaza/numarSecund;
//	}
//
//	if (op == '+')
//	{
//		return numarBaza + numarSecund;
//	}
//
//	if (op == '-')
//	{
//		return numarBaza - numarSecund;
//	}
//}
//
//
////metoda returneaza rezultatul evaluarii expresiei in forma poloneza
//double evaluatePostFix(std::vector<Simbol> postfix)
//{
//	std::stack<double> numere;
//
//	for (int i = 0; i < postfix.size(); i++)
//	{
//		if (postfix.at(i).checker == 1)
//		{
//			numere.push(postfix.at(i).numar);
//		}
//		else
//		{
//			if (isOperator(postfix.at(i).litera))
//			{
//				double numar2 = numere.top();
//				numere.pop();
//				double numar1 = numere.top();
//				numere.pop();
//				numere.push(operatie(numar1, numar2, postfix.at(i).litera));
//			}
//		}
//	}
//	return numere.top();
//}
//
//
//
//
//void main()
//{
//	std::string s;
//		
//	if (validateExpresion(s))
//	{
//		std::vector<Simbol> sirExpresie = convertExpresion(s);
//
//		std::cout << "Expresia citita din fisier este: \n";
//		printExpresion(sirExpresie);
//		std::cout << "\n";
//
//		std::vector<Simbol> postFix = generatePostFix(sirExpresie);
//
//
//		std::cout << "...and the post fix form is: \n";
//		printExpresion(postFix);
//		std::cout << "\n";
//
//		std::cout << "Rezultatul expresiei este: \n";
//		std::cout << evaluatePostFix(postFix);
//		std::cout << "\n";
//	}
//
//	std::cout << "\n";
//
//
//
//
//
//
//
//
//	////testarea expresiilor din enuntul problemei:
//	////NU introdu spatii in expressile introduse in modul acesta!!! 
//	////Eliminarea spatiilor se face la citirea din fisier.
//
//	//std::cout << "Evaluam expresia 2+++3: ";
//	//validateExpresion("2+++3") ? std::cout << " Expresie corecta\n" : std::cout << " Expresie eronata\n";
//	//
//	//std::cout << "Evaluam expresia 2*((3+4): ";
//	//validateExpresion("2*((3+4)") ? std::cout << " Expresie corecta\n" : std::cout << " Expresie eronata\n";
//
//	//std::cout << "Evaluam expresia 23#+a: ";
//	//validateExpresion("23#+a") ? std::cout << " Expresie corecta\n" : std::cout << " Expresie eronata\n";
//
//	//std::cout << "Evaluam expresia 3*4-3*(24-12)-7: ";
//	//validateExpresion("3*4-3*(24-12)-7") ? std::cout << " Expresie corecta\n" : std::cout << " Expresie eronata\n";
//
//
//}
