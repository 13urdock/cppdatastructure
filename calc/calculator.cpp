#include <iostream>
#include "calculator.h"
#include "adder.h"
using namespace std;

void Calculator:: run(){
	cout << "enter two numbers: ";
	int a, b;
	cin >> a >> b;
	Adder adder(a, b);
	cout << adder.process() << endl;
}
