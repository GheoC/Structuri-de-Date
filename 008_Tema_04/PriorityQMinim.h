#pragma once
#include<vector>

class PriorityQMinim
{
private:
	std::vector<int> data;
	int size;

public:
	PriorityQMinim();

	int getSize();
	bool isEmpty();

	void readDataFromFile();
	void printQ();
	void insertElement(int element);
	int getMinElement();
	void removeMin();

private:
	void minHeapify(int size, int i);
	void siftUpMinim(int position);

};

