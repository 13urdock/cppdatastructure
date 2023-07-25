#include <iostream>
#include <string>
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
	Car *santafe = new Car("Santafe", 300);
	Car *tico = new Car("Tico", 200);
	Car *grandeur = new Car("Grandeur", 300);

	santafe->run(1);
	tico->run(2);
	grandeur->run(3);

	return 0;
}
