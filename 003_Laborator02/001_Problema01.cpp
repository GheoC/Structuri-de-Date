//#include<iostream>;
//
//struct node
//{
//	int inf;
//	node* anterior;
//
//	//aici vine un constructor. uitat-te pe codul profesorului!
//
//	//destructor
//	~node() 
//	{
//
//	}
//};
//
//
//struct stiva
//{
//	node* varf;
//
//	stiva()
//	{
//		varf = NULL;
//	}
//
//	void push(int k)
//	{
//		node* aux = new node;
//		aux->inf = k;
//		aux->anterior = varf;
//		varf = aux;
//	}
//
//	void pop()
//	{
//		node* aux = varf;
//		varf = varf->anterior;
//
//		delete(aux);
//	}
//
//};
//
//void push(stiva& s, int k)
//{
//	node* aux = new node;
//	aux->inf = k;
//	aux->anterior = s.varf;
//	s.varf = aux;
//
//}
//
//void pop(stiva& s)
//{
//	node* aux = s.varf;
//	s.varf = s.varf->anterior;
//
//	delete(aux);
//}
//
//void main()
//{
//	stiva s;
////	s.varf = NULL;    nu mai este nevoie pentru ca s-a creat un constructor in structura stivei!
//
//	push(s, 5);
//	push(s, 7);
//
//	std::cout << s.varf->inf << std::endl;
//
//	pop(s);
//
//	std::cout << s.varf->inf << std::endl;
//
//	s.push(8);
//
//	std::cout << s.varf->inf << std::endl;
//
//	s.pop();
//
//	std::cout << s.varf->inf << std::endl;
//
//	system("pause");
//}