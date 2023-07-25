#include <iostream>
#include "adder.h"
using namespace std;

Adder::Adder(int a = 0, int b = 0) : op1{a}, op2{b}{}

int Adder::process(){
	return op1 + op2;
}

