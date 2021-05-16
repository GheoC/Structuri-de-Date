///*
//Arbore Huffman (3p)
//*/
//
//
//#include<iostream>
//#include<fstream>
//#include<vector>
//#include<string>
//#define SPACE 10
//
//std::ifstream fin("inputEx05.txt");
//
//struct huffData
//{
//	std::string caracter;
//	std::string cod;
//
//	void toString()
//	{
//		std::cout << caracter << ": " << cod << "\n";
//	}
//};
//
//struct Node
//{
//	std::string info;
//	Node* left;
//	Node* right;
//};
//
//void readFromFile(std::vector<huffData>& data)
//{
//	int n;
//	fin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		huffData nod;
//		fin >> nod.caracter;
//		fin >> nod.cod;
//		data.push_back(nod);
//	}
//}
//
//void printVector(std::vector<huffData> data)
//{
//	for (int i = 0; i < data.size(); i++)
//	{
//		data.at(i).toString();
//	}
//}
//
////metoda de a construi arborele Huffman
//Node* generateHuffmanTree(std::vector<huffData> data)
//{
//	Node* root = new Node;
//	root->info = "ROOT";
//	root->left = nullptr;
//	root->right = nullptr;
//
//	Node* left, * right;
//	Node* iterator;
//
//	for (int i = 0; i < data.size(); i++)
//	{
//		iterator = root;
//		for (int j = 0; j < (data[i].cod.size()); j++)
//		{
//			if (data[i].cod[j] == '0')
//			{
//				if (iterator->left == NULL)
//				{
//					left = new Node;
//					left->left = NULL;
//					left->right = NULL;
//					if (j == (data[i].cod.size() - 1))
//					{
//						left->info = data[i].caracter;
//					}
//					else
//					{
//						left->info = '*';
//					}
//					iterator->left = left;
//				}
//				iterator = iterator->left;
//			}
//			if (data[i].cod[j] == '1')
//			{
//				if (iterator->right == NULL)
//				{
//					right = new Node;
//
//					right->left = NULL;
//					right->right = NULL;
//					if (j == (data[i].cod.size() - 1))
//					{
//						right->info = data[i].caracter;
//					}
//					else
//					{
//						right->info = '*';
//					}
//					iterator->right = right;
//				}
//				iterator = iterator->right;
//			}
//		}
//	}
//	return root;
//}
//
//void print2D(Node* r, int space)
//{
//	if (r == NULL)
//		return;
//	space += SPACE;
//	print2D(r->right, space);
//	std::cout << std::endl;
//	
//	for (int i = SPACE; i < space; i++)
//		std::cout << " ";
//	
//	std::cout << r->info;
//	std::cout << "\n";
//	
//	print2D(r->left, space);
//}
//
//void main()
//{
//	std::vector<huffData> data;
//	readFromFile(data);
//	printVector(data);
//
//	Node* root;
//	root = generateHuffmanTree(data);
//
//	std::cout << "Afisarea este rotita cu 90* in stanga:\n";
//	print2D(root, 0);
//}