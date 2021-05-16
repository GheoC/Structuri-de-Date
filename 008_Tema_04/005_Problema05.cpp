///* Codificarea Huffmnan (5p)
//*
//* Se citeste un text dintr-un fisier. Sa se construiasca arborele de codificare Huffman.
//* Sa se afiseze codul corespunzator fiecarui caracter si sa se codifice textul.
//* Utilizati o coada de prioritate.
//*/
//
//#include<iostream>
//#include<fstream>
//#include<vector>
//#include<string>
//#include<queue>
//#include<map>
//#define SPACE 5
//
//std::ifstream fin("inputEx05.txt");
//
//struct HuffNode
//{
//	char c;
//	int freq;
//	HuffNode* left;
//	HuffNode* right;
//};
//
//
////https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/
//struct CompareFreq
//{
//	bool operator()(HuffNode* node1, HuffNode* node2)
//	{
//		return node1->freq > node2->freq;
//	}
//};
//
//HuffNode* createNode(char c, int f, HuffNode* left, HuffNode* right)
//{
//	HuffNode* newNode = new HuffNode;
//	newNode->c = c;
//	newNode->freq = f;
//	newNode->left = left;
//	newNode->right = right;
//
//	return newNode;
//}
//
////se citeste textul din fisier;
//void readTextFromFile(std::string& text)
//{
//	std::getline(fin, text);
//}
//
////se mapeaza caracterele in functie de frecventa de aparatie a lor in text;
//void mapText(std::string text, std::vector<HuffNode*>& mapper)
//{
//	for (int i = 0; i < text.size(); i++) //cat timp gasim charactere in fisier...
//	{
//		bool isChar = false;
//		for (int j = 0; j < mapper.size(); j++) //verificam daca caracterul citit este mapat in vectorul "mapper"
//		{
//			if (text.at(i) == mapper.at(j)->c)
//			{
//				isChar = true;
//				mapper.at(j)->freq++;			//in cazul in care exista deja in fisier, ii crestem frecventa de aparitie (pair.freq)
//			}
//		}
//
//		if (isChar == false)						//daca caracterul nu apare in vectorul mapper, il adaugam cu frecventa 1;
//		{
//			HuffNode* newPair = createNode(text.at(i), 1, nullptr, nullptr);
//			mapper.push_back(newPair);
//		}
//	}
//}
//
////se afiseaza vectorul de frecventa a caracterelor
//void printMapper(std::vector<HuffNode*> mapper)
//{
//	for (int i = 0; i < mapper.size(); i++)
//	{
//		std::cout << mapper.at(i)->c << " - " << mapper.at(i)->freq;
//		std::cout << "\n";
//	}
//}
//
////Se construieste Arborele Huffman folosing un priority_queue; se returneaza radacina arborelui.
//HuffNode* createHuffTree(std::vector<HuffNode*> mapper)
//{
//	std::priority_queue<HuffNode*, std::vector<HuffNode*>, CompareFreq> HuffPriorityQ;
//
//	for (int i = 0; i < mapper.size(); i++)
//	{
//		HuffPriorityQ.push(mapper.at(i));
//	}
//
//	while (HuffPriorityQ.size() != 1)
//	{
//		HuffNode* left = HuffPriorityQ.top();
//		HuffPriorityQ.pop();
//		HuffNode* right = HuffPriorityQ.top();
//		HuffPriorityQ.pop();
//
//		int sum = left->freq + right->freq;
//
//		HuffNode* temp = createNode('*', sum, left, right);
//		HuffPriorityQ.push(temp);
//	}
//
//	return HuffPriorityQ.top();
//
//}
////metoda de afisare a arborelui Huffman generat mai sus;
//void print2D(HuffNode* root, int space)
//{
//	if (root == NULL)
//		return;
//	space += SPACE;
//
//	print2D(root->right, space);
//	std::cout << std::endl;
//
//	for (int i = SPACE; i < space; i++)
//		std::cout << " ";
//
//	std::cout << root->c;
//	std::cout << "\n";
//
//	print2D(root->left, space);
//}
//
////metoda care genereaza codurile pentru fiecare caracter
//void generateCodes(HuffNode* root, std::string code, std::map<char, std::string>& huffCode)
//{
//	if (root == nullptr)
//	{
//		return;
//	}
//
//	if (root->left == NULL && root->right == NULL)
//	{
//		huffCode[root->c] = code;
//	}
//	generateCodes(root->left, code + '0', huffCode);
//	generateCodes(root->right, code + '1', huffCode);
//
//}
//
////metoda care afiseaza codurile carecterelor
//void printCodes(std::map<char, std::string>& huffCodes)
//{
//	for (auto pair : huffCodes) {
//		std::cout << pair.first << " " << pair.second << '\n';
//	}
//}
//
////metoda de codificare a textului conform codificarii de mai sus a fiecarui caracter regasit in text
//std::string codingText(std::string text, std::map<char, std::string> codes)
//{
//	std::string huffmanEncodedText;
//	for (int i = 0; i < text.size(); i++)
//	{
//		huffmanEncodedText = huffmanEncodedText + codes.at(text.at(i));
//	}
//
//	return huffmanEncodedText;
//
//}
//
////metoda de decodificare a textului Huffman folosint arborele Huffman
//void decodingText(std::string text, HuffNode* root)
//{
//
//	HuffNode* temp = root;
//
//	for (int i = 0; i < text.size(); i++)
//	{
//		if (text.at(i) == '0')
//		{
//			temp = temp->left;
//		}
//		if (text.at(i) == '1')
//		{
//			temp = temp->right;
//		}
//		
//		if (temp->c != '*')
//		{
//			std::cout << temp->c;
//			temp = root;
//		}
//	}
//}
//
//
//
//
//
//void main()
//{
//
//	//am studiat: 
//	//https://www.youtube.com/watch?v=co4_ahEDCho&t=929s
//	//https://www.youtube.com/watch?v=_Kl3TtBXxq8
//
//	std::string text;
//	readTextFromFile(text);
//	std::cout << "Textul citit din fisier este: \"" << text << "\"\n";
//
//	std::vector<HuffNode*> mapper;
//	mapText(text, mapper);
//	//printMapper(mapper); //afisarea frecvetei fiecarui caracter din text
//
//	std::priority_queue<HuffNode*, std::vector<HuffNode*>, CompareFreq> pq;
//	HuffNode* huffRoot = createHuffTree(mapper);
//	//print2D(huffRoot, 0);  //daca dorim sa afisam si arborele Huffman creat;
//
//	std::string code;
//	std::cout << "\nCodificarea Huffman a caracterelor este: \n";
//	std::map<char, std::string> huffCodes;
//	generateCodes(huffRoot, code, huffCodes);
//
//	printCodes(huffCodes);
//
//	std::cout << "\nCodificarea Huffman a textului este: \n";
//
//	std::string huffmanText = codingText(text, huffCodes);
//	std::cout << huffmanText;
//
//	std::cout << "\n";
//
//
//	std::cout << "\nDecodificarea textului Huffman este: \n";
//	decodingText(huffmanText, huffRoot);
//
//	std::cout << "\n\n\n\n";
//
//
//}