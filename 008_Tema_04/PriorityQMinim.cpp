#include"PriorityQMinim.h"
#include<iostream>
#include<fstream>

PriorityQMinim::PriorityQMinim()
{
}

int PriorityQMinim::getSize()
{
	return this->size;
}

bool PriorityQMinim::isEmpty()
{
	if (data.empty())
	{
		return true;
	};

	return false;
}

void PriorityQMinim::readDataFromFile()
{

	std::ifstream fin("inputEx01.txt");
	int element;
	while (fin >> element)
	{
		insertElement(element);
	}

	this->size = this->data.size();
}

void PriorityQMinim::printQ()
{
	if (size == 0)
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

void PriorityQMinim::insertElement(int element)
{
	this->data.push_back(element);
	this->size++;

	int i = size - 1;

	siftUpMinim(i);
}

int PriorityQMinim::getMinElement()
{
	if (!data.empty())
	{
		return data.at(0);
	}
}

void PriorityQMinim::removeMin()
{
	if (size == 0)
	{
		return;
	}
	std::swap(data.at(0), data.at(size - 1));
	data.erase(data.begin() + size - 1);
	size--;
	minHeapify(size, 0);
}

void PriorityQMinim::minHeapify(int size, int i)
{

	int min = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	// daca copilul stang este mai mic, il retinem in variabila "min"
	if (left < size && data[left] < data[min])
		min = left;

	// daca copilul drept este mai mic, il retinem in variabila "mic"
	if (right < size && data[right] < data[min])
		min = right;

	// aici este breakpoint-ul de apelare recursiva a "heapify"
	// daca maximul se afla pe nodul radacina al heapului curent sau al sub-heapului, apelarea recursiva se opreste
	if (min != i) {
		// swap
		int temp = data[i];
		data[i] = data[min];
		data[min] = temp;

		// se reapeleaza metoda heapify pe sub-heapul
		minHeapify(size, min);

	}

}

void PriorityQMinim::siftUpMinim(int position)
{
	int parent;
	while (position >= 0)
	{
		parent = (position - 1) / 2;
		if (data.at(parent) > data.at(position))
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

