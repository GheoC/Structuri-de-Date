//#include<iostream>
//#include<iomanip>
//#include<fstream>
//
///*se considera o matruce de dimensiuni m*n;
//* sase afiseze indicii coloanelor care au toate elementele necgative;
//*/
//
//using namespace std;
//
//void citireMatrice(int**& matrice, int& m, int& n) {
//	cout << "Numar linii =";
//	cin >> m;
//	cout << "Numar coloane =";
//	cin >> n;
//	matrice = new int* [m];
//	for (int i = 0; i < m; i++)
//	{
//		matrice[i] = new int[n];
//		for (int j = 0; j < n; j++)
//		{
//			cin >> matrice[i][j];
//		}
//	}
//}
//
//void main() {
//	int** matrice, nrLinii, nrColoane;
//
//
//	ifstream file("vec.txt");
//	
//	citireMatrice(matrice, nrLinii, nrColoane);
//
//}
