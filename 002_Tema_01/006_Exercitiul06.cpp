///* Exercitiul 6. Profesorul si relatiile dintre elevi:
//a) elevii cu cei mai multi prieteni si cati;
//b) relatii de reciprocitae a elevilor fara prieteni;
//c) afisare elevi neagreati de nimeni.
//(1p)
//*/
//#include<iostream>
//#include<fstream>
//#include<iomanip>
//
////citeste matricea din fisierul "matriceEx5.txt"
//void readMatrix(int**& matrice, int& rows)
//{
//	std::ifstream fin("matriceEx6.txt");
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
////crearea unui vector de frecventa + afisarea prietenilor pentru fiecare elev.
//int* mappingFriends(int** matrix, int rows) 
//{
//	int* vector;
//	vector = new int[rows];
//	for (int i = 0; i < rows; i++)
//	{
//		vector[i] = 0;
//	}
//
//	for (int i = 0; i < rows; i++)
//	{
//		std::cout << "Elevul " << i + 1 << " are prieteni pe elevul: ";
//		for (int j = 0; j < rows; j++)
//		{
//			if (matrix[i][j]==1 && matrix[j][i]==1 && i!=j)
//			{
//				std::cout << j+1 << ", ";
//				vector[i]++;
//			}
//		}
//		std::cout << std::endl;
//	}
//	return vector;
//}
//
////returneaza maximul dintr-un vector;
//int getMax(int* vector, int rows) 
//{
//	int max = vector[0];
//	for (int i = 0; i < rows; i++)
//	{
//		if (vector[i]>max)
//		{
//			max = vector[i];
//		}
//	}
//	return max;
//}
//
////afiseaza elevii care au cei mai multi prieteni
//void maxPrieteni(int* vector, int rows) 
//{
//	int max = getMax(vector, rows);
//	std::cout << "\nElevii cu cei mai multi prieteni sunt: \n";
//	for (int i = 0; i < rows; i++)
//	{
//		if (vector[i]==max)
//		{
//			std::cout <<"   - elevul " << i+1 << " cu un numar de " << vector[i] << " prieteni.\n";
//		}
//
//	}
//}
////afiseaza raportul de reciprocitate pentru elevii care nu au prieteni.
//void analizaReciprocitate(int** matrix, int* mapFriends, int rows) 
//{
//	for (int i = 0; i < rows; i++)
//	{
//		if (!mapFriends[i])
//		{
//			std::cout << "Elevul " << i+1 << " nu are prieteni!\n";
//			for (int j = 0; j < rows; j++)
//			{
//				if (matrix[i][j]==1 && matrix[j][i]==0)
//				{
//					std::cout << " - elevul " << i+1 << " il place pe " << j+1 << " dar nu este reciproca.\n";
//				}
//			}
//		}
//	}
//}
//
////afiseaza raportul cu elevii care sunt agreati de nici un alt elev.
//void getEleviNonAgreati(int** matrix, int rows) 
//{
//	for (int j = 0; j < rows; j++)
//	{
//		bool checker = 0;
//		for (int i = 0; i < rows; i++)
//		{
//			if (matrix[i][j]==1 && i!=j)
//			{
//				checker = 1;
//			}
//		}
//		if (checker==0)
//		{
//			std::cout << "- pe elevul " << j + 1 << " nu-l place nimeni.";
//		}
//	}
//}
//
//void main() 
//{
//	//Complexitate O(n^2)
//
//	int** matrix;
//	int rows;
//	readMatrix(matrix, rows);
//	displayMatrix(matrix, rows);
//
//	std::cout << "\nRaport de prietenii: \n";
//	int* mapFriends;
//	mapFriends = mappingFriends(matrix, rows);
//	
//	maxPrieteni(mapFriends, rows);
//
//	std::cout <<"\nAnaliza elevilor fara prieteni: "<< std::endl;
//	analizaReciprocitate(matrix, mapFriends, rows);
//
//	std::cout << "\nRaport elevi neagreati de nimeni:\n ";
//	getEleviNonAgreati(matrix, rows);
//	std::cout << "\n";
//}