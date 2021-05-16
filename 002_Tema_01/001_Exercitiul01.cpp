///*Exercitiul 1. Se considera  un vector V cu n elemente numere naturate de cel putin 2 cifre.
//Sa  se construiasca un al doilea vector W, cu acelasi numar de elemente si care
//pe fiecare pozitie i sa aiba media cifrelor elementului V[i]. (1p) */
//
//#include<iostream>;
//#include<iomanip>;
//
////metoda returneaza media cifrelor unui numar;
//double getDigitAverage(int number) 
//{
//	int sum = 0, counter=0;
//
//	while (number) 
//	{
//		sum = sum + number % 10;
//		counter++;
//		number = number / 10;
//	}
//	return (double) sum/counter;
//}
//
////metoda returneaza numarul de cifre al unui numar
//int getNumberOfDigits(int number) 
//{
//	int nDigits = 0;
//	while (number)
//	{
//		number = number / 10;
//		nDigits++;
//	}
//	return nDigits;
//}
//
////citirea vector de numere intregi, cu verificare ca fiecare numar introdus are cel putin 2 cifre.
//void inputData(int* &vector, int &length)
//{
//	std::cout << "Introduceti lungimea sirului: ";
//	std::cin >> length;
//	vector = new int[length];
//	int number,digits;
//	for (int i = 0; i < length; i++)
//	{
//		std::cout << "Introdu elementul " << i + 1 << " din vector: ";
//		
//
//		//verificare ca numarul introdus are cel putin 2 cifre.
//		do
//		{
//			std::cin >> number;
//			digits = getNumberOfDigits(number);
//			if (digits<2)
//			{
//				std::cout << "Trebuie introdus un numar cu minim 2 cifre. Reintrodu numarul: ";
//			}
//			else 
//			{
//				vector[i]=number;
//			}
//		} while (digits<2); // sfarsit verificare 2 cifre;
//	}
//}
//
////metoda creaza un sirul cerut prin enuntul problemei
//void createAverageArray(int* vector, double*& rezultat, int length) 
//{
//	rezultat = new double[length];
//
//	for (int i = 0; i < length; i++)
//	{
//		rezultat[i] = getDigitAverage(vector[i]);
//	//	std::cout << rezultat[i];
//	}
//}
//
////afiseaza continutul unui vector cu elemente generice de tip T;
//template<class T>
//void displayArray(T* vector, int length) 
//{
//	for (int i = 0; i < length; i++)
//	{
//		std::cout<<std::setw(10)<<std::fixed<<std::setprecision(2)<< vector[i]<<", ";
//	}
//}
//
//
//void main() 
//{	
//	//Complexitate = O(length); length = lungimea sirului;
//
//	int length;
//	int* vector;
//	double*vectorRezultat;
//
//	inputData(vector, length);
//	createAverageArray(vector, vectorRezultat, length);
//	
//	std::cout << "\nPentru sirul introdus: ";
//	displayArray(vector, length);
//	std::cout << "\n  media cifrelor este: ";
//	displayArray(vectorRezultat, length);
//	
//	std::cout << std::endl;
//}