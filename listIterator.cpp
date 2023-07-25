#include <iostream>
#include <list>
using namespace std;

void initList(list<int> &l){
	for(int i = 0; i < 5; i++)
		l.push_back(i);
}

void doubleList(list<int> &l){
 	list<int>::iterator it;
	for(it = l.begin(); it != l.end(); it++){
		int n = *it;
		n *= 2;
		*it = n;
	}
}

void printList(list<int> &l){
	list<int>::iterator it;
	for(it = l.begin(); it != l.end(); it++)
		cout << *it << " ";
	cout << endl;
}

int main(void){
	list<int> l;

	initList(l);
	printList(l);

	doubleList(l);
	printList(l);

	return 0;
}
