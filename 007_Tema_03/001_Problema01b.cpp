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
//#include<stack>
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
//
//	void getPath(int pointA, int pointB) 
//	{
//
//
//	}
//
//	
//	void depthFirstSearch(int root, int goal)
//	{
//		std::stack<int> stack;
//		std::vector<int> children;
//		std::string path = "";
//
//		stack.push(root);
//
//		while (!stack.empty())
//		{
//			int t = stack.top();
//			path = path + ' ' + static_cast<char>(t);
//
//			stack.pop();
//
//			if (t == goal) {
//				//return path;
//
//				while (!stack.empty())
//				{
//					std::cout << stack.top()<<"  ";
//					stack.pop();
//
//				}
//				return;
//			}
//
//			for (int i = 0; i < noduri.size(); i++)
//			{
//				if (t== noduri.at(i).nrNod)
//				{
//					children = noduri.at(i).noduriAdiancete;
//				}
//			}
//
//
//			//std::reverse(children.begin(), children.end());
//
//			for (int i = 0; i < children.size(); ++i) {
//				stack.push(children[i]);
//			}
//		}
//		
//	}
//
//
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
//	Graph g1 = g.createUndirected();
//
//	std::cout << "\n";
//
//	g1.printGraph();
//
//	g.depthFirstSearch(0, 7);
//
//	
//
//}
//
