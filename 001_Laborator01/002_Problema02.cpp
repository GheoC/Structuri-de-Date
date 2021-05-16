//#include <iostream>
//#include<fstream>
//#include<iomanip>
///*
//Se consider o matrice de dimensiuni m x n.
//fiecare element este o cifra zecimala
//fiecare colana reprezinta un numar
//sa afisam numerele si sa calculam media
//
//1 3 4 5
//1 2 0 3
//3 1 2 1
//
//113  321 402 531
//*/
//
//using namespace std;
//
//struct Vector {
//	int size;
//	int* data;
//	void afisare()
//	{
//		for (int index = 0; index < size; index++)
//		{
//			cout << setw(3) << data[index];
//		}
//		cout << endl;
//	}
//	void init(int* v, int dim)
//	{
//		size = dim;
//		data = new int[size];
//		for (int i = 0; i < size; i++)
//		{
//			data[i] = v[i];
//		}
//	}
//
//};
//
//int** citireMatrice(string fisier, int& m, int& n)
//{
//	ifstream file;
//	file.open(fisier);
//
//	int** matrice;
//	//cout << "nrnrlinii =";
//	file >> m;
//	//cout << "coloane=";
//	file >> n;
//	matrice = new int* [m];
//	for (int linii = 0; linii < m; linii++)
//	{
//		matrice[linii] = new int[n];
//		for (int col = 0; col < n; col++)
//		{
//			file >> matrice[linii][col];
//		}
//	}
//	file.close();
//	return matrice;
//}
//
//void citireMatrice(int**& matrice, int& m, int& n)
//{
//	cout << "nrnrlinii =";
//	cin >> m;
//	cout << "coloane=";
//	cin >> n;
//	matrice = new int* [m];
//	for (int linii = 0; linii < m; linii++)
//	{
//		matrice[linii] = new int[n];
//		for (int col = 0; col < n; col++)
//		{
//			cin >> matrice[linii][col];
//		}
//	}
//}
//
//void afisareMatrice(int** matrice, int m, int n)
//{
//	for (int lin = 0; lin < m; lin++)
//	{
//		for (int col = 0; col < n; col++)
//		{
//			cout << setw(4) << matrice[lin][col];
//		}
//		cout << endl;
//	}
//}
//
//Vector AfisareInidicColoane(int** matrice, int m, int n)
//{
//	int* indici = new int[n];
//	int indice = 0;
//	for (int col = 0; col < n; col++)
//	{
//		int lin = 0;
//		for (; lin < m && matrice[lin][col] < 0; lin++);
//
//		if (lin == m)
//		{
//			indici[indice++] = col;
//
//		}
//	}
//	Vector v;
//	v.init(indici, indice);
//
//	return v;
//}
//
//void dealocare(int** matr, int m, int n)
//{
//	for (int i = 0; i < m; i++)
//	{
//		delete[]matr[i];
//	}
//	delete[]matr;
//}
//int main()
//{
//
//
//	int** matrice, nrLinii, nrColoane;
//	Vector indici;
//	//citireMatrice(matrice, nrLinii, nrColoane);
//
//	matrice = citireMatrice("matriceEx2.txt", nrLinii, nrColoane);
//	cout << endl;
//	afisareMatrice(matrice, nrLinii, nrColoane);
//
//	indici = AfisareInidicColoane(matrice, nrLinii, nrColoane);
//	indici.afisare();
//
//	dealocare(matrice, nrLinii, nrColoane);
//
//	return 0;
//}