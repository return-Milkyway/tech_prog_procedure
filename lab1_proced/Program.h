
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

struct square {
	int b;
	int** a;
};
 
struct diagol {
	int y;
	int** x;
};
  	
struct matr {
	enum  key{SQUARE, DIAGOL};
	key k;    
	union { 
		square s;
		diagol d;
		down_triangle dt;
	};
	enum var_print{POSTROCHNO,POSTOLBZAM,ODNOMERNO,INCORRECT};//1,2,3
	var_print variant;
};

struct down_triangle {
		int y;
		int* x;
};
 

struct container {
 	matr *cont;
 	struct container *next;
 	struct container *prev;
};

struct container* In(container *lst,ifstream &ifst);
void In(square &a, ifstream &ifst);
void In(diagol &p, ifstream &ifst);
void In(down_triangle &dt,ofstream &ofst);
matr* In(ifstream &ifst);
void Out(diagol &p, ofstream &ofst);
void Out(square &a,ofstream &ofst);
void Out(down_triangle &dt,ofstream &ofst);
	
void Out(matr &m, ofstream &ofst);
void Out(container *lst,ofstream &ofst);
struct container *  Init();
struct container *  Init2(matr  *a);
struct container * Clear(container *lst);



int Sum(diagol* d);
int Sum(square* s);
int Sum(matr *m);
void Out_Sum(container *lst,ofstream &ofst);
bool Compare(matr *first, matr *second);
void Sort(container* c);
struct container * swap(struct container *lst1, struct container *lst2, struct container *head);


 
