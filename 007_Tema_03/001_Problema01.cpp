///*
//Graf orientat memorat prin liste de adiacenta
//	a) functie care verifica pentru orice varfuri x,y exista frum de la x la y
//	   si sa se afiseze drumul (1p)
//	b) functie care verifica dac aexista lant de la x la y si sa se afiseze; (2p)
//	c) functie care returneaza numarul de componente conexe ale grafului si pentru fiecare
//	   dintre acestea afiseaza nodurile sale (1p)
//*/
//
//#include<iostream>
//#include<vector>
//#include<fstream>
//#include<stack>
//#include<list>
//#include<set>
//#include<algorithm>
//
//std::ifstream fin("inputEx01.txt");
//
//struct Node
//{
//	int nrNod;
//	std::vector<int> noduriAdiancete;
//};
//
//struct Graph
//{
//	std::vector<Node> noduri;
//
//
//	void addVertex(int x, int y)
//	{
//		noduri[x].noduriAdiancete.push_back(y);
//	}
//
//	void inputGraph()
//	{
//		int nr_noduri;
//		fin >> nr_noduri;
//		for (int i = 0; i < nr_noduri; i++)
//		{
//			Node aux;
//			fin >> aux.nrNod;
//			int nr_nod_adiac;
//			fin >> nr_nod_adiac;
//
//			for (int j = 0; j < nr_nod_adiac; j++)
//			{
//				int nod_adic_aux;
//				fin >> nod_adic_aux;
//				aux.noduriAdiancete.push_back(nod_adic_aux);
//			}
//			this->noduri.push_back(aux);
//		}
//	}
//
//	void printGraph()
//	{
//		for (int i = 0; i < noduri.size(); i++)
//		{
//			std::cout << "Nodul " << i << ": ";
//			for (int j = 0; j < noduri[i].noduriAdiancete.size(); j++)
//			{
//				std::cout << "(" << noduri.at(i).nrNod << ", " << noduri.at(i).noduriAdiancete.at(j) << "), ";
//			}
//			std::cout << "\n";
//		}
//	}
//
//	void printDrumuri(int s, int d)
//	{
//		int v = noduri.size();
//		bool* visited = new bool[v];
//
//		int* path = new int[v];
//		int path_index = 0;
//
//		for (int i = 0; i < v; i++)
//			visited[i] = false;
//
//		printAllPathsUtil(s, d, visited, path, path_index);
//	}
//
//	//Am mers pe ideea de a transforma graficul orientat intr-unul neorientat; a se vedea metoda createUndirected();
//	//Dupa care aplicam metoda printDrumuri()
//	void printLanturi(int s, int d)
//	{
//		Graph result = this->createUndirected();
//		result.printDrumuri(s, d);
//	}
//
//	void printConnectedComponents()
//	{
//		Graph result = this->createUndirected();
//		result.numberOfconnectedComponents();
//
//	}
//
//private:
//	void numberOfconnectedComponents()
//	{
//		int v = noduri.size();
//		bool* visited = new bool[v];
//
//		int count = 0;
//		for (int i = 0; i < v; i++)
//			visited[i] = false;
//
//		for (int i = 0; i < v; i++) {
//			if (visited[i] == false) {
//				dfsUtil(i, visited);
//				std::cout << "\n";
//				count += 1;
//			}
//		}
//
//
//		std::cout << "Numarul de componente conexe din graf este: " << count;
//	}
//
//private:
//	void dfsUtil(int v, bool visited[])
//	{
//
//		visited[v] = true;
//		std::cout << v << " ";
//
//		std::vector<int>::iterator i;
//
//		for (i = noduri[v].noduriAdiancete.begin(); i != noduri[v].noduriAdiancete.end(); ++i)
//			if (!visited[*i])
//				dfsUtil(*i, visited);
//	}
//
//private:
//	void printAllPathsUtil(int u, int d, bool visited[],
//		int path[], int& path_index)
//	{
//		visited[u] = true;
//		path[path_index] = u;
//		path_index++;
//
//		if (u == d) {
//			for (int i = 0; i < path_index; i++)
//				std::cout << path[i] << " ";
//			std::cout << std::endl;
//		}
//		else
//		{
//			std::vector<int>::iterator i;
//
//			for (i = noduri[u].noduriAdiancete.begin(); i != noduri[u].noduriAdiancete.end(); ++i)
//				if (!visited[*i])
//					printAllPathsUtil(*i, d, visited, path, path_index);
//		}
//
//		path_index--;
//		visited[u] = false;
//	}
//
//private:
//	Graph createUndirected()
//	{
//		Graph result;
//		result.noduri = this->noduri;
//
//		for (int i = 0; i < noduri.size(); i++)
//		{
//
//			for (int j = 0; j < noduri[i].noduriAdiancete.size(); j++)
//			{
//				result.addVertex(noduri[i].noduriAdiancete.at(j), i);
//			}
//		}
//
//
//		//se elimina duplicatele din fiecare lista de adiacenta;
//		//https://stackoverflow.com/questions/1041620/whats-the-most-efficient-way-to-erase-duplicates-and-sort-a-vector
//		for (int i = 0; i < noduri.size(); i++)
//		{
//			std::sort(result.noduri.at(i).noduriAdiancete.begin(), result.noduri.at(i).noduriAdiancete.end());
//			result.noduri.at(i).noduriAdiancete.erase(std::unique(result.noduri.at(i).noduriAdiancete.begin(), result.noduri.at(i).noduriAdiancete.end()), result.noduri.at(i).noduriAdiancete.end());
//		}
//
//		return result;
//	}
//};
//
//
//
//void main()
//{
//	//Una din sursele de documentare: https://www.youtube.com/watch?v=pcKY4hjDrxk&t=14s 
//
//
//	Graph g;
//	g.inputGraph();
//	std::cout << "Graful este: \n";
//	g.printGraph();
//
//	std::cout << "\n";
//
//	int start = 5;
//	int end = 1;
//
//	std::cout << "Punctul a):";
//	std::cout << "\nDrumuri intre " << start << " si " << end << ": ";
//	g.printDrumuri(start, end);
//
//	start = 0;
//	end = 4;
//	std::cout << "Drumuri intre " << start << " si " << end << ": ";
//	g.printDrumuri(start, end);
//
//
//	std::cout << "\nPunctul b):";
//	std::cout << "\nDrum intre 4 si 0: ";
//	g.printDrumuri(4, 0);
//	std::cout << "\nLanturi intre 4 si 0:\n";
//	g.printLanturi(4, 0);
//
//	std::cout << "\nPunctul c):";
//	std::cout << "\nComponentele conexe:\n";
//	g.printConnectedComponents();
//	//incercati si cu graful din fisierul "inputEx01b.txt"; s-au rupt legaturile de nodul 7; nodul 7 a ramas componenta disjuncta;
//	std::cout << "\n\n\n\n\n";
//
//
//}
//
