///*Exercitiul 7
//Se considera un numar natural cu n cifre. Sa se taie p cifre, p<n, astfel incat numarul ramas
//sa fie cel mai mare posibil. Nu este permisa schimbarea ordinii cifrelor in numar.
//Se stocheaza numarul intr-un vector. (3p)
//*/
//
//#include<iostream>
//#include<iomanip>
//
//int countDigits(int number)
//{
//	int counter = 0;
//	while (number)
//	{
//		number = number / 10;
//		counter++;
//	}
//	return counter;
//}
//
////Functia de citire a datelor de intrare: Numarul si numarul de cifre ce vor fi trunchiate din numarul initial.
//void readNumber(int& number, int& cutLength)
//{
//	int nrDigits;
//	do
//	{
//		std::cout << "Introdu numarul: ";
//		std::cin >> number;
//		number = std::abs(number);
//		nrDigits = countDigits(number);
//		if (nrDigits < 1)
//		{
//			std::cout << "\nIntrodu un numar cu cel putin 1 cifra! \n";
//		}
//	} while (nrDigits < 1);
//
//	do
//	{
//		std::cout << "Cate cifre taiem din numarul introdus?  ";
//		std::cin >> cutLength;
//		if (cutLength<0)
//		{
//			std::cout << "Numarul de cifre taiate trebuie sa fie > 0!\n";
//		}
//		if (cutLength>=nrDigits)
//		{
//			std::cout << "Numarul de cifre taiate este prea mare! Alege un numar intre 0 si "<<nrDigits-1<<" inclusiv\n";
//		}
//
//	} while (cutLength >= nrDigits || cutLength < 0);
//}
//
////generare vector care are ca elemente fiecare cifra din numarul introdus de utilizator
//void generateVector(int*&vector, int number,int nrDigits) 
//{
//	vector = new int[nrDigits];
//	int i = 0;
//	while (number)
//	{
//		vector[i] = (number % 10);
//		i++;
//		number = number / 10;	
//	}
//}
//
////sortare quickSort descrescator
//void quicksort(int* vector, int stanga, int dreapta)
//{
//	int index1 = stanga;
//	int index2 = dreapta;
//	int pivot = vector[(stanga + dreapta) / 2];
//	do
//	{
//		while (vector[index1] > pivot)
//		{
//			index1++;
//		}
//		while (vector[index2] < pivot)
//		{
//			index2--;
//		}
//		if (index1 <= index2)
//		{
//			int temp = vector[index1];
//			vector[index1] = vector[index2];
//			vector[index2] = temp;
//			index1++;
//			index2--;
//		}
//	} while (index1 <= index2);
//	if (stanga < index2)
//	{
//		quicksort(vector, stanga, index2);
//	}
//	if (dreapta > index1)
//	{
//		quicksort(vector, index1, dreapta);
//	}
//}
//
////Metoda returneaza numarul cel mai mare obtinut dupa trunchierea numarului introdus de utilizatr cu un numar de cifre (si acesta introdus de utilizator)
//int generateMaxNumber(int number, int cutDigits) 
//{
//	int nrDigits = countDigits(number);
//	int* vector = new int[nrDigits];
//	generateVector(vector, number, nrDigits);
//	quicksort(vector, 0, nrDigits - 1);
//
//	int cutNumber = 0;
//
//	for (int i = 0; i < (nrDigits-cutDigits); i++)
//	{
//		cutNumber = cutNumber * 10 + vector[i];
//	}
//	free(vector);
//	return cutNumber;
//}
//
//
//
//void main()
//{
//	//Complexitarea aplicatiei este O(n*log(n)) determinata de algoritmul de sortare quickSort.
//
//	int number;
//	int cutDigits;
//
//	readNumber(number, cutDigits);
//
//	std::cout<<"\nNumber cel mai mare dupa trunchierea cu "<<cutDigits<<" cifre este: "
//		<<generateMaxNumber(number, cutDigits);
//
//	std::cout << std::endl;
//}