#include <iostream>
#include <sstream>
#include <fstream>
#include "qtest.h"
using namespace std;

void run_tests(){
	test_size_after_add();
	test_read_write_sort_sum();
	test_filter();
}
void test_size_after_add(){
	container *container_test = Init();//head
	container *p;
	matr *m = new matr();
	//Podschet(ne schitaem head)
	p = container_test->next;
	int num=0;
	while(p != container_test){
	    num=num+1;
	    p = p->next; 
	} 
	assert(num == 0);
	//Dobavim v container 1 elem
	struct container *last = Init2(m);
	struct container *tmp;
	tmp = container_test->next; 
	container_test->next = last; 
	last->next = tmp;

	p = container_test->next;
	num=0;
	while(p != container_test){
	    num=num+1;
	    p = p->next; 
	} 
	///////////////////////////
	assert(num == 1);
	
	struct container *newItem = Init2(m);	  
	tmp = last->next; 
	last->next = newItem;
	newItem->next = tmp;
	last=newItem;
	p = container_test->next;
	num=0;
	while(p != container_test){
	    num=num+1;
	    p = p->next; 
	} 
	assert(num == 2);
	
	cout << "Success final - test size after add"<<endl;
}

void test_read_write_sort_sum(){
	ifstream ifst_test("test/in.txt");
	ofstream ofst_test("test/out.txt");
	string input = "test/in.txt";
	string output = "test/out.txt";

	string correct ="Container contains 2 elements.\n"
					"It is Diagol Matrix: len = 3, matr: = \n"
					"4 0 0 \n"
					"0 1 0 \n"
					"0 0 3 \n"
					"Print need POSTROCHNO\n"
					"Sum_matr = 8\n"
					"It is Diagol Matrix: len = 2, matr: = \n"
					"1 0 \n"
					"0 2 \n"
					"Print need ODNOMERNO\n"
					"Sum_matr = 3\n";

	container *container_test = Init();
	In(container_test, ifst_test);
	Sort(container_test);
	Out_Sum(container_test, ofst_test);
	
	ifstream in_file(output);
	stringstream buff;
	buff << in_file.rdbuf();
	string result_in_file = buff.str();
	
	assert(result_in_file == correct);
	cout << "Success final - test sort read sum" << endl;
}

void test_filter(){
	ifstream ifst_test("test/in_filt.txt");
	ofstream ofst_test("test/out_filt.txt");
	string input = "test/in_filt.txt";
	string output = "test/out_filt.txt";

	string correct ="Container contains 3 elements.\n"
					"Only square\n"
					"It is Square matrix: len = 2, matr = \n"
					"1 2 \n"
					"3 4 \n";

	container *container_test = Init();
	In(container_test, ifst_test);
	Sort(container_test);
	Out_Square(container_test, ofst_test);
	
	ifstream in_file(output);
	stringstream buff;
	buff << in_file.rdbuf();
	string result_in_file = buff.str();
	
	assert(result_in_file == correct);
	cout << "Success final - test sort read filt out" << endl;
}
