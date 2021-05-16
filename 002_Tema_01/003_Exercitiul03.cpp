///*Exercitiul 3. Se considera doua  multimi de numere naturale A si B, memorate in doi vectori
//distincti (într-o multime fecare element este unic!). Sa se construiasca un al treilea vector,
//care contine elementele din A ∩ B. (1p).
//*/
//
//#include<iostream>
//#include<iomanip>
//#include<vector>
//#include<algorithm>
//#include<iterator>
//
//struct Vector
//{
//	int* elemente;
//	int length;
//
//	void toString()
//	{
//		std::cout << "Elementele vectorului sunt: ";
//		for (int i = 0; i < length; i++)
//		{
//			std::cout << elemente[i] << ", ";
//		}
//	}
//
//	void readVector()
//	{
//		std::cout << "\nIntrodu lungimea vectorului: ";
//		std::cin >> length;
//		elemente = new int[length];
//		for (int i = 0; i < length; i++)
//		{
//			/*Verificare ca elementele introduse sa fie unice.
//			Nu stiam daca trebuie implementata sau avanmd in vedere enuntul problemei, utilizatorul stie sa introduca doar elemente unice.
//			Daca nu trebuia verificata unicitatea elementelor, atunci codul era "std::cin>>elemente[i];"
//			*/
//			bool uniqueChecker;
//			std::cout << " - introdu elementul " << i + 1 << ": ";
//			int number;
//			do
//			{
//				uniqueChecker = true;
//				std::cin >> number;
//				for (int k = 0; k < i; k++)
//				{
//					if (number == elemente[k])
//					{
//						uniqueChecker = false;
//					}
//				}
//				if (uniqueChecker)
//				{
//					elemente[i] = number;
//				}
//				else { 
//					std::cout << "   - numarul exista deja in lista. Introdu alt number: "; 
//				}
//
//			} while (!uniqueChecker); //sfarsit verificare unicitate
//
//		}
//		
//		toString();
//		std::cout << std::endl;
//	}
//
//	Vector intersectWith(Vector vector)
//	{
//		Vector vRezult;
//		vRezult.length = 0;
//
//		for (int i = 0; i < length; i++)
//		{
//			for (int j = 0; j < vector.length; j++)
//			{
//				if (elemente[i] == vector.elemente[j])
//				{
//					vRezult.length++;
//				}
//			}
//		}
//
//		vRezult.elemente = new int[vRezult.length];
//
//		int k = 0;
//		for (int i = 0; i < length; i++)
//		{
//			for (int j = 0; j < vector.length; j++)
//			{
//				if (elemente[i] == vector.elemente[j])
//				{
//					vRezult.elemente[k] = elemente[i];
//					k++;
//				}
//			}
//		}
//		return vRezult;
//	}
//
//	bool checkUnique(int number, int len)
//	{
//		bool checker = 1;
//
//		for (int i = 0; i < len; i++)
//		{
//			if (true)
//			{
//
//			}
//		}
//
//	}
//};
//
//
//void main()
//{   // Complexitate = O(n*m); n = vector1.length, m = vector2.length;
//	Vector vector1, vector2, vectorRezult;
//
//	vector1.readVector();
//	vector2.readVector();
//
//	std::cout << "\nRezultatul intersectiei celor doi vectori este: \n";
//	vector1.intersectWith(vector2).toString();
//
//	std::cout << std::endl;
//}