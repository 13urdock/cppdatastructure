#include <iostream>
using namespace std;

template <class T>
T bigger(T a, T b){
	if(a>b) return a;
	else return b;
}

int main(void){
	int a = 50, b= 40;
	double c = 3.4, d = 4.5;

	cout << "(" <<  a << "," << b << "): " << bigger(a,b) << endl;
	cout << "(" <<  c << "," << d << "): " << bigger(c,d) << endl;

	return 0;
}
