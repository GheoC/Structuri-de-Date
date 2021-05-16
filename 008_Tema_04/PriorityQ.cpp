#include "PriorityQ.h"
#include<iostream>
#include<fstream>

PriorityQ::PriorityQ()
{
}

int PriorityQ::getSize()
{
	return size;
}

bool PriorityQ::isEmpty()
{
	if (data.empty())
	{
		return true;
	};
	
	return false;
}

//PriorityQ::PriorityQ(std::vector<int> data)
//{
//	this->data = data;
//	size = data.size();
//}
//
//
//void PriorityQ::setData(std::vector<int> data)
//{
//	this->data = data;
//	this->size = data.size();
//}

void PriorityQ::maxHeapify(int size, int i)
{
	int max = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;
	
		// daca copilul stang este mai mare, il retinem in variabila "max"
		if (left < size && data[left] > data[max])
			max = left;
	
		// daca copilul drept este mai mare, il retinem in variabila "max"
		if (right < size && data[right] > data[max])
			max = right;
	
		// aici este breakpoint-ul de apelare recursiva a "heapify"
		// daca maximul se afla pe nodul radacina al heapului curent sau al sub-heapului, apelarea recursiva se opreste
		if (max != i) {
			// swap
			int temp = data[i];
			data[i] = data[max];
			data[max] = temp;

			// se reapeleaza metoda heapify pe sub-heapul
			maxHeapify(size, max);

		}
}


void PriorityQ::readDataFromFile()
{

	std::ifstream fin("inputEx01.txt"); 
	int element;
	while (fin >> element)
	{
		insertElement(element);
	}

	this->size = this->data.size();

	

}

void PriorityQ::heapSort()
{
	int size = this->data.size();

	for (int i = size / 2 - 1; i >= 0; i--) {
		maxHeapify(this->size, i);
	}

	// in acest for se muta elementul 0 (care este elementul cel mai mare din vector) la sfarsitul vectorului 
	// se reaplica metoda heapify pentru vectorul fara ultimul element
	for (int i = size - 1; i >= 0; i--) {

		// interschimbarea primului element cu ultimul
		int temp = data[0];
		data[0] = data[i];
		data[i] = temp;

		// reapelare healpify pentru vectorul fara ultimul element;
		maxHeapify(i, 0);
	}
}



void PriorityQ::printQ()
{
	if (size==0)
	{
		std::cout << "Lista e goala";
		return;
	}

	for (int i = 0; i < data.size(); ++i)
	{
		std::cout << data[i] << " ";
	}
	std::cout << "\n";
}

void PriorityQ::insertElement(int element)
{
	this->data.push_back(element);
	this->size++;
		
	int i = size-1;

	siftUp(i);

}

void PriorityQ::siftUp(int position)
{
	int parent;
	while (position >= 0)
	{
		parent = (position - 1) / 2;
		if (data.at(parent) < data.at(position))
		{
			std::swap(data.at(parent), data.at(position));
			position = parent;
		}
		else
		{
			return;
		}
	}
}

int PriorityQ::getMaxElement()
{	
	if (!data.empty())
	{
		return data.at(0);
	}


}

void PriorityQ::removeMax()
{
	if (size==0)
	{
		return;
	}
	std::swap(data.at(0), data.at(size - 1));
	data.erase(data.begin()+size-1);
	size--;
	maxHeapify(size, 0);

}

void PriorityQ::increasePriority(int position)
{
	if (position<1 || position>size)
	{
		std::cout << "Wrong position! Incearca din nou: ";
		return;
	}

	int priority;
	std::cout << "Prioritatea pentru pozitia " << position << " este " << data.at(position - 1) << ". Cu cat crestem prioritatea: ";
	std::cin >> priority;
	std::cout << "\n Before: ";
	printQ();
	data.at(position - 1) = data.at(position - 1) + priority;
	siftUp(position - 1);
	std::cout << "\n After: ";
	printQ();

}

