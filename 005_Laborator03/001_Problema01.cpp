#include<iostream>
#include <fstream>
#include <vector>

struct Adiacent 
{
	int informatie;
	std::vector<int> noduriAdiacente;
};

struct Graph 
{
	std::vector<Adiacent> noduri;
	

	void citire()
	{
		std::ifstream fin("input.txt");
		int nrNoduri;
		fin >> nrNoduri;
		for (int i = 0; i < nrNoduri; i++)
		{
			Adiacent aux;
			fin >> aux.informatie;
			
			for (int j = 0; j < aux.noduriAdiacente.size(); j++)
			{
				int nodAdiac;
				fin >> nodAdiac;
				aux.noduriAdiacente.push_back(nodAdiac);
			}
			noduri.push_back(aux);
		}
	}
};

void main ()
{
	Graph g;
	g.citire();

}