#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Car{
	string name;
	int maxspeed;
public:
	Car(string name = " ", int maxspeed = 0){this->name = name; this->maxspeed = maxspeed;}
	void run(int x){
		cout << name << "는" << x << "시간 동안" << x * maxspeed << "km를 갑니다."<< endl;	
	}
};
int main(void){
	vector<Car*> carVector;
	list<Car*> carList;

	carVector.push_back( new Car("Santafe", 300));
	carVector.push_back( new Car("Tico", 200));
	carVector.push_back(new Car("Grandeur", 300));
	for (int i = 0; i < carVector.size(); i++)
		car->run(1);
	
	return 0;
}
