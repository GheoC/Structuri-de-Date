#pragma once
#include<vector>

class PriorityQ
{
private:
	std::vector<int> data;
	int size;

public:
	PriorityQ();
	
	int getSize();
	bool isEmpty();

	void readDataFromFile();
	void printQ();
	void insertElement(int element);
	int getMaxElement();
	void removeMax();
	void increasePriority(int position);

private:
	void heapSort(); //nu este folosit in problema 2
	void maxHeapify(int size, int i);
	void siftUp(int position);

};

