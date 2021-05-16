///*Exercitiul 5: Se considera o matrice patratica de dimensiuni n*n.
//Sa se determine cate elemente prime se afla sub diagonala principala. De asemenea sa se
//interschimbe cele doua diagonale. (1p).
//*/
//#include<iostream>
//#include<iomanip>
//#include<fstream>
//
//
////citeste matricea din fisierul "matriceEx5.txt"
//void readMatrix(int**& matrice, int& rows)
//{
//	std::ifstream fin("matriceEx5.txt");
//	fin >> rows;
//
//	matrice = new int* [rows];
//	for (int i = 0; i < rows; i++)
//	{
//		matrice[i] = new int[rows];
//		for (int j = 0; j < rows; j++)
//		{
//			fin >> matrice[i][j];
//		}
//	}
//}
//
////afiseaza matricea
//void displayMatrix(int** matrix, int rows)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < rows; j++)
//		{
//			std::cout << std::setw(4) << std::setiosflags(std::ios::right) << matrix[i][j];
//		}
//		std::cout << std::endl;
//	}
//}
//
////returneaza daca un numar este prim sa nu
//bool checkPrimeNumber(int number) {
//	bool isPrime = true;
//
//	if (number == 0 || number == 1) {
//		isPrime = false;
//	}
//	else {
//		for (int i = 2; i <= sqrt(number); ++i) {
//			if (number % i == 0) {
//				isPrime = false;
//			}
//		}
//	}
//	return isPrime;
//}
//
////returneaza numarul de numere prime aflate sub diagonala principala;
////afiseaza sumele prime gasite
//int getPrimesUnderDiagonal(int** matrix, int rows)
//{
//	int counter = 0;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (checkPrimeNumber(matrix[i][j]))
//			{
//				std::cout << matrix[i][j] << ", ";
//				counter++;
//			}
//		}
//	}
//	return counter;
//}
//
////interschimbarea celor doua diagonale
//void swapDiagonals(int**&matrix, int rows)
//{
//	int temp;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < rows/2; j++)
//		{
//			if (i==j || (i+j)==(rows-1))
//			{
//				temp = matrix[i][j];
//				matrix[i][j] = matrix[i][rows - j - 1];
//				matrix[i][rows - j - 1] = temp;
//			}
//		}
//	}
//}
//
//void main()
//{
//	//Complexitate O(n^2) determinata de parcurgerea matricei;
//
//	int** matrix;
//	int rows;
//
//	readMatrix(matrix, rows);
//	displayMatrix(matrix, rows);
//
//	std::cout<<"\nNumerele prime sub diagonala sunt: ";
//	std::cout <<"\nNumarul de elemente prime sub diagonala principala este: "<< getPrimesUnderDiagonal(matrix, rows);
//	std::cout << std::endl;
//
//	swapDiagonals(matrix, rows);
//
//	std::cout << "\nMatricea rezultata dupa schimbarea diagonalelor: \n";
//	displayMatrix(matrix, rows);
//}