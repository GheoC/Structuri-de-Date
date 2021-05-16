////Exercitiul 4. Fractia (4p)
//
//
//#include<iostream>
//#include<iomanip>
//#include<cmath>
//
//
////returneaza cel mai mare divizor comun al doua numere;
//int cmmdc(int number1, int number2)
//{
//	//pentru a evita bucla infinita din while-ul de mai jos
//	if (!number1 or !number2)
//	{
//		return 0;
//	}
//
//
//	//fara acest if functia cmmdc intra intr-o bucla infinita avand in vedere continutul while-ului de mai jos
//	int sign;
//	if (number1 < 0 || number2 < 0)
//	{
//		sign = (-1);
//		number1 = abs(number1);
//		number2 = abs(number2);
//	}
//
//
//	while (number1 != number2)
//	{
//		if (number1 > number2)
//			number1 = number1 - number2;
//		else
//			number2 = number2 - number1;
//	}
//	return  number1;
//}
//
////returneaza cel mai mic multiplu comun al doua numere;
//int cmmmc(int number1, int number2)
//{
//	int minNUmber = number1;
//
//	while ((minNUmber % number2) != 0)
//	{
//		minNUmber += number1;
//	}
//	return minNUmber;
//}
//
////structura Fractiei
//struct Fractie
//{
//	int numarator;
//	int numitor;
//
//	void inputFractie() 
//	{
//		std::cout << "Introdu numaratorul: ";
//		std::cin >> numarator;
//		std::cout << "Introdu numitorul: ";
//		do
//		{
//			std::cin >> numitor;
//			if (!numitor) //se invalideaza fractia cu numitor 0;
//			{
//				std::cout << "Nu e bine! Incearca din nou un numar nenul: ";
//			}
//		} while (!numitor);
//	}
//
//	void toString()
//	{
//		if (!numarator) {
//			std::cout << "0 (zero)";
//			return;
//		}
//		if (numitor == 1)
//		{
//			std::cout << numarator;
//			return;
//		}
//		std::cout << numarator << "/" << numitor;
//	}
//
//	Fractie generateReductie()
//	{
//		int nrCmmdc = cmmdc(numarator, numitor);
//		Fractie result;
//		if (!nrCmmdc)
//		{
//			result.numarator = 0;
//			result.numitor = 1;
//			return result;
//		}
//		result.numarator = numarator / nrCmmdc;
//		result.numitor = numitor / nrCmmdc;
//		return result;
//	}
//
//	//calculeaza si returneaza numarul real al fractiei
//	double calculateRationalNumber()
//	{
//		return (double)numarator / numitor;
//	}
//
//	//varianta 1 de adunare a doua fractii
//	Fractie addTo(Fractie fractie)
//	{
//		int nrCmmmc = cmmmc(numitor, fractie.numitor);
//		Fractie result;
//		result.numitor = nrCmmmc;
//		result.numarator = numarator * (nrCmmmc / numitor) + fractie.numarator * (nrCmmmc / fractie.numitor);
//		return result;
//	}
//
//	//varianta 1 de scadere a doua fractii
//	Fractie minus(Fractie fractie)
//	{
//		int nrCmmmc = cmmmc(numitor, fractie.numitor);
//		Fractie result;
//		result.numitor = nrCmmmc;
//		result.numarator = numarator * (nrCmmmc / numitor) - fractie.numarator * (nrCmmmc / fractie.numitor);
//		return result;
//	}
//
//	Fractie multiplyWith(Fractie fractie) 
//	{
//		Fractie rezult;
//		rezult.numarator = numarator * fractie.numarator;
//		rezult.numitor = numitor * fractie.numitor;
//		return rezult;
//	}
//
//	Fractie divedeBy(Fractie fractie) 
//	{
//		Fractie rezult;
//		rezult.numarator = numarator * fractie.numitor;
//		rezult.numitor = numitor * fractie.numarator;
//		return rezult;
//	}
//
//	//varianta 1 de comparare a doua fractii;
//	void compareTo(Fractie fractie)
//	{
//		int nrCmmmc = cmmmc(numitor, fractie.numitor);
//		int num1 = numarator * (nrCmmmc / numitor);
//		int num2 = fractie.numarator * (nrCmmmc / fractie.numitor);
//		if (num1 == num2)
//		{
//			std::cout << "Fractiile sunt egale si anume: ";
//			fractie.generateReductie().toString();
//			return;
//		}
//		if (num1 > num2)
//		{
//			std::cout << "Fractia " << numarator << "/" << numitor << " este mai care ca fractia " << fractie.numarator << "/" << fractie.numitor;
//		}
//		else
//		{
//			std::cout << "Fractia " << fractie.numarator << "/" << fractie.numitor << " este mai care ca fractia " << numarator << "/" << numitor;
//		}
//	}
//};
//
//
////citirea unei Fractii;
//void inputFractie(Fractie& fractie)
//{
//	std::cout << "Introdu numaratorul: ";
//	std::cin >> fractie.numarator;
//	std::cout << "Introdu numitorul: ";
//	do
//	{
//		std::cin >> fractie.numitor;
//		if (!fractie.numitor) //se invalideaza fractia cu numitor 0;
//		{
//			std::cout << "Nu e bine! Incearca din nou un numar nenul: ";
//		}
//	} while (!fractie.numitor);
//}
//
////citirea dinamica a unui vector
//void inputVector(Fractie*& vector, int& length)
//{
//	std::cout << "introdu numarul de fractii: ";
//	std::cin >> length;
//	vector = new Fractie[length];
//
//	for (int i = 0; i < length; i++)
//	{
//		inputFractie(vector[i]);
//	}
//}
//
//void displayFractii(Fractie* vector, int length)
//{
//	for (int i = 0; i < length; i++)
//	{
//		std::cout << "Elementul " << i + 1 << ":  ";
//		vector[i].generateReductie().toString();
//		std::cout << std::setw(20) << std::setiosflags(std::ios::right) << std::setprecision(4) << vector[i].calculateRationalNumber() << "\n";
//	}
//}
//
////sortare quickSort cu complexitate O(n*log(n))
//void quicksort(Fractie* vector, int stanga, int dreapta)
//{
//	int index1 = stanga;
//	int index2 = dreapta;
//	double pivot = vector[(stanga + dreapta) / 2].calculateRationalNumber();
//	do
//	{
//		while (vector[index1].calculateRationalNumber() < pivot)
//		{
//			index1++;
//		}
//		while (vector[index2].calculateRationalNumber() > pivot)
//		{
//			index2--;
//		}
//		if (index1 <= index2)
//		{
//			Fractie temp = vector[index1];
//			vector[index1] = vector[index2];
//			vector[index2] = temp;
//			index1++;
//			index2--;
//		}
//	} while (index1 <= index2);
//	if (stanga < index2)
//	{
//		quicksort(vector, stanga, index2);
//	}
//	if (dreapta > index1)
//	{
//		quicksort(vector, index1, dreapta);
//	}
//}
//
//
////varianta 2 de adunarea doua fractii; varianta 1 este metoda de adunare a structurii 
//Fractie sum(Fractie fractie1, Fractie fractie2)
//{
//	int nrCmmmc = cmmmc(fractie1.numitor, fractie2.numitor);
//	Fractie result;
//	result.numitor = nrCmmmc;
//	result.numarator = fractie1.numarator * (nrCmmmc / fractie1.numitor) + fractie2.numarator * (nrCmmmc / fractie2.numitor);
//	return result;
//}
//
////adunarea Fractiilor stocate intr-un vector
//Fractie sum(Fractie* vector, int length)
//{
//	Fractie suma;
//	suma.numarator = 0;
//	suma.numitor = 1;
//
//	for (int i = 0; i < length; i++)
//	{
//		suma = sum(suma, vector[i]); //Compilatorul alege metoda sum(Fractie fractie1, Fractie fractie2);
//	}
//	return suma;
//}
//
//
//void main()
//{
//	/*Comlexitatea aplicatiei este de O(n*log(n)) determinata de algoritmul de sortare quickSort.
//	Folosirea quickSort respecta cerinta problemei si anume "sa se sorteze vectorul cat mai efecient; */
//
//	Fractie* vectorFractii;
//	int length;
//
//	inputVector(vectorFractii, length);
//	std::cout << "\nFractiile simplificate: \n";
//	displayFractii(vectorFractii, length);
//
//	quicksort(vectorFractii, 0, length - 1);
//
//	std::cout << "\nRezultat sortare: \n";
//	displayFractii(vectorFractii, length);
//
//	std::cout << "\nSuma fractiilor din vector este: ";
//	sum(vectorFractii, length).generateReductie().toString();
//	std::cout << " echivalent cu: " << std::setprecision(4) << sum(vectorFractii, length).calculateRationalNumber()<<"\n";
//
//	std::cout << std::endl;
//
//	//variabile fr1 si fr2 pentru testarea/exemplificarea operatiilor de scadere, inmultire si impartire
//	Fractie fr1;
//	fr1.inputFractie();
//	fr1.toString(); 
//	std::cout << " care inseamna: ";
//	fr1.generateReductie().toString();
//	
//	std::cout <<std::endl;
//
//	Fractie fr2;
//	fr2.inputFractie();
//	fr2.toString();
//	std::cout << " care inseamna: ";
//	fr2.generateReductie().toString();
//	
//	//exemplificare scadere:
//	std::cout << "\n\nRezultatul scaderii primei fractii la a doua fractie este: ";
//	fr1.minus(fr2).generateReductie().toString();
//	std::cout << std::endl;
//	
//	//exemplificare inmultire:
//	std::cout << "Rezultatul inmultirii fractiilor de mai sus este: ";
//	fr1.multiplyWith(fr2).generateReductie().toString();
//	std::cout << std::endl;
//
//	//exemplificare impartire:
//	std::cout << "Rezultatul impartirii primei fracti la a doua fractie este: ";
//	fr1.divedeBy(fr2).generateReductie().toString();
//	std::cout << std::endl;
//
//	//exemplificare comparatie:
//	std::cout << "Comparatia celor doua fractii: ";
//	fr1.compareTo(fr2);
//	std::cout << std::endl;
//
//}