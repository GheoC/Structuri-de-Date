///*Exercitiul 10. Se considera o matrice mat cu dimensiunile m*n. Sa se afiseze indicii
//acelor coloane, care au toate elementele nenule si sa se construiasca o a
//doua matrice rezult care sa aiba exact coloanele din mat gasite anterior*/
//
//#include <iostream>
//#include <fstream>
//#include<iomanip>
//
//struct Matrix {
//	int rows, columns;
//	int** elemente;
//	int* mappingVector;
//
//	void readMatrix()
//	{
//		std::ifstream fin("matriceEx10.txt");
//		fin >> rows;
//		fin >> columns;
//
//		elemente = new int* [rows];
//		for (int i = 0; i < rows; i++)
//		{
//			elemente[i] = new int[columns];
//			for (int j = 0; j < columns; j++)
//			{
//				fin >> elemente[i][j];
//			}
//		}
//	}
//
//	void toString()
//	{
//		for (int i = 0; i < rows; i++)
//		{
//			for (int j = 0; j < columns; j++)
//			{
//				std::cout << std::setw(4) << std::setiosflags(std::ios::right) << elemente[i][j];
//			}
//			std::cout << std::endl;
//		}
//		std::cout << std::endl;
//	}
//
//	/*/metoda populeaza vectorul de frecventa mappingVector[] cu:
//	- mappingVector[i] = 0 => pe coloana i NU sunt elemente nule.
//	- mappingVector[i] = 1 => pe coloana i sunt elemente nule.
//	- i se parcurge de la 0 la numarul de coloane ale matricei (informatia este stocata in variabila "columns" a structurii);
//	*/
//	void mapMatrix()
//	{
//		mappingVector = new int[columns];
//		for (int i = 0; i < columns; i++)
//		{
//			mappingVector[i] = 0;
//		}
//
//		for (int j = 0; j < columns; j++)
//		{
//			bool checker = 0;
//			for (int i = 0; i < rows; i++)
//			{
//				if (elemente[i][j] == 0)
//				{
//					checker = 1;
//				}
//			}
//			if (checker)
//			{
//				mappingVector[j] = 1;
//			}
//		}
//	}
//
//	//afiseze indicii acelor coloane, care au toate elementele nenule. Afisarea indicilor se face de la (1) la (numarul de coloane)
//	void displayNonZeroColumns() 
//	{
//		std::cout << "Coloanele nenule din matrice sunt: ";
//		for (int i = 0; i < columns; i++)
//		{
//			if (mappingVector[i] != 1)
//			{
//				std::cout <<i+1<<", ";
//			}
//		}
//		std::cout << std::endl;
//	}
//
//	/*Returneaza numarul de coloane cu toate elementele nenule din matricea initiala.
//	Aceata metoda se foloseste in dimensionarea matricei nou create.
//	NOTA: Daca ar mai fi fost si alte operatiuni pe matricea 
//	
//	*/
//
//	int countNonZeroColumns()
//	{
//		int counter = 0;
//		for (int i = 0; i < columns; i++)
//		{
//			if (mappingVector[i] == 0)
//			{
//				counter++;
//			}
//		}
//		return counter;
//	}
//
//	//creaza matricea noua care contine doar coloanele cu toate elementele nenule ale matricei initiale .
//	Matrix extractNonZeroColumns()
//	{
//		Matrix rezult;
//		rezult.columns = countNonZeroColumns();
//		rezult.rows = rows;
//		rezult.elemente = new int*[rows];
//		for (int i = 0; i < rows; i++)
//		{
//			rezult.elemente[i] = new int[rezult.columns];
//		}
//
//		int k;
//		for (int i = 0; i < rows; i++)
//		{
//			k = 0;
//			for (int j = 0; j < columns; j++)
//			{
//				if (mappingVector[j]==0)
//				{
//					rezult.elemente[i][k] = elemente[i][j];
//					k++;
//				}
//			}
//		}
//		return rezult;
//	}
//};
//
//
//void main()
//{
//	//Complexitate O(n^m) determinata de parcurgerea matricei (doua for-uri imbricate)
//
//	Matrix matr;
//	matr.readMatrix(); //citire matrice
//	matr.toString();   //afisare pe ecran a matricei citite
//	
//
//	//maparea coloanelor respectand conditia (toate elemente[coloana]!=0)
//	matr.mapMatrix();  
//
//	matr.displayNonZeroColumns(); //se afiseaza coloanele care respecta conditia problemei
//	
//
//	std::cout << "Noua matricea cu coloane care nu contine 0 este:\n";
//	//matr.extractNonZero().toString();
//	Matrix rezult;
//	rezult = matr.extractNonZeroColumns(); //se creaza noua matrice cu Elemente nenule
//	rezult.toString();
//
//}