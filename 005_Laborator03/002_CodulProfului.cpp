//
//#include<iostream>
//#include <fstream>
//
//struct adiac
//{
//	int nr_nod_adiac;
//	int inf;
//	int noduri_adiac[50];
//};
//struct graph
//{
//	int nr_noduri;
//	adiac noduri[50];
//
//	void citire()
//	{
//		std::ifstream f("fis.txt");
//		f >> this->nr_noduri;
//		for (int i = 0; i < this->nr_noduri; i++)
//		{
//			adiac aux;
//			f >> aux.inf;
//			f >> aux.nr_nod_adiac;
//			for (int j = 0; j < aux.nr_nod_adiac; j++)
//			{
//				f >> aux.noduri_adiac[j];
//			}
//			this->noduri[i] = aux;
//		}
//	}
//};
//
//
//void main()
//{
//	graph g;
//	g.citire();
//
//	system("pause");
//}
//
//v3:
//#include<iostream>
//#include <fstream>
//#include<vector>
//
//struct adiac
//{
//	int inf;
//	std::vector<int> noduri_adiac;
//};
//struct graph
//{
//	std::vector<adiac> noduri;
//
//	void citire()
//	{
//		std::ifstream f("fis.txt");
//		int nr_noduri;
//		f >> nr_noduri;
//		for (int i = 0; i < nr_noduri; i++)
//		{
//			adiac aux;
//			f >> aux.inf;
//			int nr_nod_adiac;
//			f >> nr_nod_adiac;
//
//			for (int j = 0; j < nr_nod_adiac; j++)
//			{
//				int nod_adic_aux;
//				f >> nod_adic_aux;
//				aux.noduri_adiac.push_back(nod_adic_aux);
//			}
//			this->noduri.push_back(aux);
//		}
//	}
//};
//
//
//void main()
//{
//	graph g;
//	g.citire();
//
//	system("pause");
//}
//
//
////v3:
//#include<iostream>
//#include <fstream>
//#include<vector>
//
//struct graph
//{
//	std::vector<std::vector<int>> noduri;
//
//	void citire()
//	{
//		std::ifstream f("fis.txt");
//		int nr_noduri;
//		f >> nr_noduri;
//		for (int i = 0; i < nr_noduri; i++)
//		{
//			std::vector<int> aux;
//			int inf;
//			f >> inf;
//			int nr_nod_adiac;
//			f >> nr_nod_adiac;
//
//			for (int j = 0; j < nr_nod_adiac; j++)
//			{
//				int nod_adic_aux;
//				f >> nod_adic_aux;
//				aux.push_back(nod_adic_aux);
//			}
//			this->noduri.push_back(aux);
//		}
//	}
//};
//
//
//void main()
//{
//	graph g;
//	g.citire();
//
//	system("pause");
//}
