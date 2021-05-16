///*Exercitiul 11. Matrice patratica nxn, subdiagonala.
//	a) transformare in vector; (1p);
//	b) inmultirea a doi vectori rezultati din matrici subdiagonale; (3p);
//*/
//#include<iostream>
//#include<fstream>
//#include<string>
//#include<iomanip>
//
//
//struct Vector
//{
//	int* elemente;
//	int length; //lungimea vectorului elemente[];
//	int rows;   //lungimea dimensiunii matricei
//
//
//	//afisare vector
//	void toString()
//	{
//		std::cout << "\nVectorul este:  ";
//		for (int i = 0; i < length; i++)
//		{
//			std::cout <<std::setw(4)<<std::setprecision(std::ios::right)<< elemente[i];
//		}
//		std::cout << std::endl;
//		for (int i = 0; i < rows; i++)
//		{
//			for (int j = 0; j <= i; j++)
//			{
//				std::cout << std::setw(4) << std::setiosflags(std::ios::right) << elemente[((i + 1) * i) / 2 + j];
//			}
//			std::cout << std::endl;
//		}
//	}
//	
//	//scrierea vectorului in fisierul vectorRezultat.txt
//	void toFile() 
//	{
//		char denumireFisier[20]="vectorRezultat.txt";
//		std::ofstream fout(denumireFisier);
//
//		for (int i = 0; i < length; i++)
//		{
//			fout << std::setw(4) << std::setprecision(std::ios::right) << elemente[i];
//		}
//		fout << std::endl;
//		for (int i = 0; i < rows; i++)
//		{
//			for (int j = 0; j <= i; j++)
//			{
//				fout << std::setw(4) << std::setiosflags(std::ios::right) << elemente[((i + 1) * i) / 2 + j];
//			}
//			fout<< std::endl;
//		}
//	}
//};
//
//
//struct Matrix {
//	int** elemente; //matricea propriu-zisa
//	int rows;		//dimensiunea matricei
//
//	//afisare Matrice
//	void toString()
//	{
//		std::cout << std::endl;
//		for (int i = 0; i < rows; i++)
//		{
//			for (int j = 0; j < rows; j++)
//			{
//				std::cout << std::setw(4) << std::setiosflags(std::ios::right) << elemente[i][j];
//			}
//			std::cout << std::endl;
//		}
//	}
//
//	//scrierea matricii intr-un fisierul matriceC.txt
//	void toFile() 
//	{
//		char denumireFisier[20] = "matriceC.txt";
//		std::ofstream fout(denumireFisier);
//		
//		fout<< rows<<"\n";
//
//		for (int i = 0; i < rows; i++)
//		{
//			for (int j = 0; j < rows; j++)
//			{
//				fout << std::setw(4) << std::setiosflags(std::ios::left) << elemente[i][j];
//			}
//			fout << std::endl;
//		}
//	}
//
//	//citire matrice
//	void readMatrix()
//	{
//		char path[20];
//		std::cout << "\nIntroduceti calea fisierului: ";
//		std::cin >> path;
//		std::ifstream fin(path);
//		fin >> rows;
//
//		elemente = new int* [rows];
//		for (int i = 0; i < rows; i++)
//		{
//			elemente[i] = new int[rows];
//			for (int j = 0; j < rows; j++)
//			{
//				fin >> elemente[i][j];
//			}
//		}
//	}
//};
//
//void readMatrice(int**& matrice, int& length)
//{
//	char* path;
//	path = new char[15];
//	std::cout << "Introduceti calea fisierului: ";
//	std::cin >> path;
//	std::ifstream fin(path);
//	fin >> length;
//
//	matrice = new int* [length];
//	for (int i = 0; i < length; i++)
//	{
//		matrice[i] = new int[length];
//		for (int j = 0; j < length; j++)
//		{
//			fin >> matrice[i][j];
//		}
//	}
//}
//
////se genereaza vectorul 1D dintr-o matrice n x n  
//Vector convertToVector(Matrix matrice)
//{
//	Vector vector;
//	vector.rows = matrice.rows;
//	vector.length = (matrice.rows * matrice.rows - matrice.rows) / 2 + matrice.rows;
//	vector.elemente = new int[vector.length];
//
//	int counter = 0;
//
//	for (int i = 0; i < matrice.rows; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			vector.elemente[counter] = matrice.elemente[i][j];
//			counter++;
//		}
//	}
//	return vector;
//}
//
////se genereaza matricea subdiagonala n x n dintr-un vector unidimensional  
//Matrix convertToMatrix(Vector vector)
//{
//	Matrix matrice;
//	matrice.elemente = new int* [vector.rows];
//	matrice.rows = vector.rows;
//	for (int i = 0; i < vector.rows; i++)
//	{
//		matrice.elemente[i] = new int[vector.rows];
//		for (int j = 0; j < vector.rows; j++)
//		{
//			if (j <= i)
//			{
//				matrice.elemente[i][j] = vector.elemente[(i + 1) * i / 2 + j];
//			}
//			else 
//			{
//				matrice.elemente[i][j] = 0; }
//		}
//	}
//	return matrice;
//}
//
////inmultire a doi vectori derivati din matrici subdiagonale.
//Vector multiply(Vector vectorA, Vector vectorB)
//{
//	Vector vRezultat;
//	vRezultat.rows = vectorA.rows;
//	vRezultat.length = vectorA.length;
//	vRezultat.elemente = new int[vRezultat.length];
//	for (int i = 0; i < vRezultat.rows; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			int sum = 0;
//			for (int k = j; k <= i; k++)
//			{
//				sum = sum + vectorA.elemente[((i + 1) * i) / 2 + k] * vectorB.elemente[((k + 1) * k) / 2 + j];
//			}
//			vRezultat.elemente[((i + 1) * i) / 2 + j] = sum;
//		}
//	}
//	return vRezultat;
//}
//
//
//
//
//void main()
//{   /*Complexitatea este O(n^3) determinata de metoda multiply(Vector v1, Vector v2) incare sunt 3 for-uri imbricate.
//	Documentare: https://math.stackexchange.com/questions/3027390/product-of-two-lower-triangular-matrices-is-a-lower-triangular-matrix
//
//	Disclaimer:
//	1. Va rog sa introduceti denumiri valide de fisiere. Nu s-a implementat metoda de "File not exist"
//	*/
//	
//	Matrix matriceA;
//	matriceA.readMatrix();
//	matriceA.toString();
//	
//	
//	Matrix matriceB;
//	matriceB.readMatrix();
//	matriceB.toString();
//
//	std::cout << "\nVectorul A este: ";
//	Vector vectorA = convertToVector(matriceA);
//	vectorA.toString();
//
//	std::cout << "\nVectorul B este: ";
//	Vector vectorB = convertToVector(matriceB);
//	vectorB.toString();
//
//	std::cout << "\nRezultatul inmultirii celor doua matrici este: \n";
//	Vector vRezultat;
//
//	//se verifica ca matricile sa aiba aceleasi dimensiuni n x n
//	if (vectorA.rows==vectorB.rows)
//	{
//		vRezultat = multiply(vectorA, vectorB);
//		vRezultat.toString();
//		vRezultat.toFile();
//
//		//am zis sa si convertesc vectorul rezultat inapoi intr-o matrice n x n
//		Matrix matriceRezultat;
//		matriceRezultat = convertToMatrix(vRezultat);
//		matriceRezultat.toString();
//		matriceRezultat.toFile();
//	} else
//	{
//		std::cout << "NU se poate procesa inmultirea. Matricile sunt de dimensiuni diferite.";
//	}
//	
//	
//
//}
//
//
//
