///*Exercitiul 2. Se considera  un vector "numere" care contine nr numere naturale. Sa se verifice
//care dintre cifrele de la 0 la 9 apare cel mai des în vector si de câte ori apare.
//(1p)
//Exemplu: numere = { 12, 231, 9012, 34, 8123, 22, 507 }. Atunci cifra care
//apare cel mai des este 2 si apare de 6 ori. */
//
//#include<iostream>
//#include<iomanip>
//
//struct Element
//{
//	int digit;
//	int frequency;
//
//	void toSting()
//	{
//		std::cout << "Cifra " << digit << " apare de " << frequency;
//		std::cout << std::endl;
//	}
//};
//
////citirea dinamica a unui vector
//void inputData(int*& vector, int& length)
//{
//	std::cout << "Introduceti lungimea sirului: ";
//	std::cin >> length;
//	vector = new int[length];
//
//	for (int i = 0; i < length; i++)
//	{
//		std::cout << "Introdu elementul " << i + 1 << " din vector: ";
//		std::cin >> vector[i];
//	}
//}
//
////se genereaza un vector de freqventa pentru toate cifrele numerelor din sirul introdus de utilizator
//Element* generateNumberFrequancy(int* vector, int length)
//{
//	Element* vFreq;
//	vFreq = new Element[10];
//	for (int i = 0; i < 10; i++)
//	{
//		vFreq[i].frequency = 0;
//		vFreq[i].digit = i;
//	}
//
//	for (int i = 0; i < length; i++)
//	{
//		int number = vector[i];
//		while (number)
//		{
//			vFreq[number % 10].frequency++;
//			number = number / 10;
//		}
//	}
//	return vFreq;
//}
//
///*
//Functia returneaza un sir de variabile de tip struct.
//Variabilele de tip "Element" contin doua componente:
//  - cifra cel mai des intalnita printre numerele sirului introdus de utilizator
//  - frecventa de apartiie a acestei cifre
//
//  NOTA: Intr-un sir de numere pot fi mai multe cifre care au frecventa cea mai mare.
//*/
//Element* getMaxFrequancy(Element* vFreq, int& counter)
//{
//	int frecventaMaxima = vFreq[0].frequency;
//
//	//se cauta frecventa maxima
//	for (int i = 1; i < 10; i++)
//	{
//		if (vFreq[i].frequency > frecventaMaxima)
//		{
//			frecventaMaxima = vFreq[i].frequency;
//		}
//	}
//
//	counter = 0;
//	//se cauta de cate ori apare frecventa maxima in sirul de frecvente
//	for (int i = 0; i < 10; i++)
//	{
//		if (frecventaMaxima == vFreq[i].frequency)
//		{
//			counter++;
//		}
//	}
//
//	//se creaza un sir de Element(cifra + frecventa de aparitie);
//	Element* maximAparitii;
//	maximAparitii = new Element[counter];
//	int k = 0;
//
//	/*se populeaza sirul creat mai sus cu:
//	   1. cifrele care apar cel mai des (frecventaMaxima) in sirul de numere introdus de utilizator
//	   2. frecventa de aparitie a cifrelor de mai sus care este egala si anume frecventaMaxima.*/
//	for (int i = 0; i < 10; i++)
//	{
//		if (frecventaMaxima == vFreq[i].frequency)
//		{
//			maximAparitii[k].frequency = vFreq[i].frequency;
//			maximAparitii[k].digit = i;
//			k++;
//		}
//	}
//	return maximAparitii;
//}
//
//void main()
//{
//	//Complexitate = O(length); length = lungimea sirului;
//
//	int length, counterOfMaxFreq;
//	int* numbers;
//	inputData(numbers, length);
//
//	Element* vFreq = generateNumberFrequancy(numbers, length);
//
//	Element* maxFrequencyDigits = getMaxFrequancy(vFreq, counterOfMaxFreq);
//	std::cout << "\nCifrele cu frecventa cea mai mare de aparitie sunt: \n";
//	for (int i = 0; i < counterOfMaxFreq; i++)
//	{
//		maxFrequencyDigits[i].toSting();
//	}
//
//	std::cout << "\nCa fapt divers, numarul de aparitii al tuturur cifrelor din sirul de numere introdus este: \n";
//	//mapare de frecventa a tuturor cifrelor din sirul de numere "numbers"
//	Element* allDigits = generateNumberFrequancy(numbers, length);
//	for (int i = 0; i < 10; i++)
//	{
//		allDigits[i].toSting();
//	}
//}