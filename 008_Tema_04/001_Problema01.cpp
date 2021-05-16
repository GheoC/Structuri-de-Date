////implementare Heap-Sort (1p)
//
//#include <iostream>
//#include<vector>
//#include<fstream>
//
//
//std::ifstream fin("inputEx01.txt");
//
//
//
//void readVector(std::vector<int>& vector)
//{
//	int element;
//	while (fin >> element)
//	{
//		vector.push_back(element);
//	}
//
//}
//
//void heapify(std::vector<int>& vector, int size, int i) {
//
//	//initializam pozitiile root, stanga si dreapta
//	int max = i;
//	int left = 2 * i + 1;
//	int right = 2 * i + 2;
//
//	// daca copilul stang este mai mare, il retinem in variabila "max"
//	if (left < size && vector[left] > vector[max])
//		max = left;
//
//	// daca copilul drept este mai mare, il retinem in variabila "max"
//	if (right < size && vector[right] > vector[max])
//		max = right;
//
//	// aici este breakpoint-ul de apelare recursiva a "heapify"
//	// daca maximul se afla pe nodul radacina al heapului curent sau al sub-heapului, apelarea recursiva se opreste
//	if (max != i) {
//		// swap
//		int temp = vector[i];
//		vector[i] = vector[max];
//		vector[max] = temp;
//
//		// se reapeleaza metoda heapify pe sub-heapul
//		heapify(vector, size, max);
//	}
//}
//
//void heapSort(std::vector<int>& vector) {
//	int size = vector.size();
//
//	for (int i = size / 2 - 1; i >= 0; i--) {
//		heapify(vector, size, i);
//	}
//
//	// in acest for se muta elementul 0 (care este elementul cel mai mare din vector) la sfarsitul vectorului 
//	// se reaplica metoda heapify pentru vectorul fara ultimul element
//	for (int i = size - 1; i >= 0; i--) {
//
//		// interschimbarea primului element cu ultimul
//		int temp = vector[0];
//		vector[0] = vector[i];
//		vector[i] = temp;
//
//		// reapelare heapify pentru vectorul fara ultimul element;
//		heapify(vector, i, 0);
//	}
//}
//
//// afisare vector
//void printVector(std::vector<int> vector) {
//
//	for (int i = 0; i < vector.size(); ++i)
//	{
//		std::cout << vector[i] << " ";
//	}
//	std::cout << "\n";
//}
//
//int main() {
//
//	// Am studiat:
//	// despre heapuri:                      https://www.youtube.com/watch?v=WCm3TqScBM8
//	// despre construirea unui MaxHeap:     https://www.youtube.com/watch?v=MiyLo8adrWw
//	// despre heapSort:                     https://www.youtube.com/watch?v=onlhnHpGgC4
//
//	// Comentariu: La slide-ul 9 din powerpointul de prezentare "CoziPrioritate.pdf", initial nu am inteles de se incepe construirea MaxHeap-ului de la "(size/2)-1"
//	// M-am lamurit din filmuletul acesta: https://www.youtube.com/watch?v=WsNQuCa_-PU
//
//	std::vector<int> vector;
//	readVector(vector);
//
//	heapSort(vector);
//
//	std::cout << "Vector sortat: \n";
//	std::cout << "\n";
//
//	printVector(vector);
//}
