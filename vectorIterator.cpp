#include <iostream>
#include <vector>
#include <list>
using namespace std;

void initVector(vector<int> &v){
	v.push_back(1);
	v.push_back(2); 
	v.push_back(3); 
}

void doubleVector(vector<int> &v){
	vector<int>::iterator it;
	for(it = v.begin(); it < v.end(); it++){
		int n = *it;
		n *= 2;
		*it = n;
	}
}

void printVector(vector<int> &v){
	vector<int>::iterator it;
	for (it = v.begin(); it < v.end(); it++)
		cout << *it << " ";
	cout << endl;
}

int main(void){ 
	vector<int> v; 
	initVector(v);
	printVector(v);

	doubleVector(v);
	printVector(v);

	return 0;
}
