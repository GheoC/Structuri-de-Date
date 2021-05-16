///*Exercitiul 9. Se considera o matrice matr cu nRow si nCol coloane ale carei elemente sunt numere naturale formate dintr-o singura cifra.
//Se considera ca fiecarelinie reprezinta un numar in baza "base" apartinand {2,3,4,...,10}. Sa se plaseze numerele transformate
//in baza zece intr-un vector numbers si sa se afiseze acest vector. (1p)
//*/
//
//#include<iostream>
//#include<iomanip>
//#include<fstream>
//#include<math.h>
//
////citeste matricea din fisierul "matriceEx9.txt"
//void readMatrix(int**& matrice, int& nRow, int& nCol)
//{
//	std::ifstream fin("matriceEx9.txt");
//	fin >> nRow;
//	fin >> nCol;
//
//	matrice = new int* [nRow];
//	for (int i = 0; i < nRow; i++)
//	{
//		matrice[i] = new int[nCol];
//		for (int j = 0; j < nCol; j++)
//		{
//			fin >> matrice[i][j];
//		}
//	}
//}
//
////afiseaza matricea
//void displayMatrix(int** matrix, int nRow, int nCol)
//{
//	for (int i = 0; i < nRow; i++)
//	{
//		for (int j = 0; j < nCol; j++)
//		{
//			std::cout << std::setw(4) << std::setiosflags(std::ios::left) << matrix[i][j];
//		}
//		std::cout << std::endl;
//	}
//}
//
///*Metoda returnzeaza cifra maxima din matrice. 
//Este folosita pentru a valida baza cifrelor, introdusa de utilizator; 
//Baza nu poate fi mai mica sau egala cu cea mai mare cifra din matrice */
//int getMax(int** matrix, int nRow, int nCol)
//{
//	int max = matrix[0][0];
//
//	for (int i = 0; i < nRow; i++)
//	{
//		for (int j = 0; j < nCol; j++)
//		{
//			if (matrix[i][j] > max)
//			{
//				max = matrix[i][j];
//			}
//		}
//	}
//	return max;
//}
//
///*Metoda returneaza numarul de cifre al unui numar; 
// Este folosita in validarea elementelor matricei. Elementele trebuie sa fie cifre*/
//int getNumberOfDigits(int number) {
//
//	int counter = 0;
//	while (number)
//	{
//		number = number / 10;
//		counter++;
//	}
//	return counter;
//}
//
////metoda de validare a matricei
//bool checkValidMatrix(int** matrix, int nRow, int nCol) 
//{
//	bool checker = true;
//
//	for (int i = 0; i < nRow; i++)
//	{
//		for (int j = 0; j < nCol; j++)
//		{
//			if (matrix[i][j]<0) // numere/cifre negative => nu e buna matricea
//			{
//				checker = false;
//			}
//
//			if (getNumberOfDigits(matrix[i][j])>1) // elemente ale matricei care nu sunt cifre => nu e buna matricea
//			{
//				checker = false;
//			}
//		}
//	}
//	return checker;
//}
//
////metoda care returneaza numarul in baza 10 pentru numarul ce se formeaza din fiecare rand al matricei
//int* generateNumbers(int** matrix, int nRow, int nCol, int base)
//{
//	int* vector;
//	vector = new int[nRow];
//	for (int i = 0; i < nRow; i++)
//	{
//		int number = 0;
//		for (int j = 0; j < nCol; j++)
//		{
//			number = number + matrix[i][j] * pow(base, nCol - j - 1);
//		}
//		vector[i] = number;
//	}
//	return vector;
//}
//
//void main()
//{
//	//Complexitate O(nRow*nCol) determinat de algoritmul de parcurgere al unei matrici;
//
//	int** matrix;
//	int* numbers;
//	int nRow, nCol;
//	readMatrix(matrix, nRow, nCol);
//	std::cout << "Matricea este: \n";
//	displayMatrix(matrix, nRow, nCol);
//
//	if (!checkValidMatrix(matrix,nRow,nCol))
//	{
//		std::cout << "NU e buna matricea!";
//		return;
//	}
//
//	int base;
//	int maxMatrix = getMax(matrix, nRow, nCol);
//	std::cout << "Introdu baza cifrelor din matrice: ";
//	do
//	{
//		std::cin >> base;
//		if (base <= maxMatrix)
//		{
//			std::cout << "Baza introdusa este prea mica. Reintrodu baza: ";
//		}
//		if (base>10)
//		{
//			std::cout << "Baza introdusa este prea mare. Reintrodu baza : ";
//		}
//	} while (base <= maxMatrix || base>10);
//
//
//	std::cout << "Numerele in baza 10 sunt: {";
//	numbers = generateNumbers(matrix, nRow, nCol, base);
//
//	for (int i = 0; i < nRow; i++)
//	{
//		std::cout << numbers[i]<<", ";
//	}
//	std::cout << "}";
//}
