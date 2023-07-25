#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Attraction{
	public:
		string name;
		Attraction(string name){this->name = name;}
};

class City {
	public:
		string name;
		City(string name){this->name = name;}
		vector<Attraction*> attractionVector;
		void addNewAttraction(Attraction* attraction){
			attractionVector.push_back(attraction);
		}
		void printAttractions(){
			cout << name <<endl;
			for (int i =0; i < attractionVector.size(); i++){
				cout << "  " << attractionVector[i]->name << endl;
			}
			cout << endl;
		}
};

class Program {
	public:
		vector<City*> initVariable(){
			City* busan = new City("Busan");
			City* seoul = new City("Seoul");
			vector<City*> cityVector;
			cityVector.push_back(busan);
			cityVector.push_back(seoul);

			busan->addNewAttraction(new Attraction("Haeundae"));
			busan->addNewAttraction(new Attraction("Gamcheon culture village"));

			seoul->addNewAttraction(new Attraction("Namsan tower"));
			seoul->addNewAttraction(new Attraction("Hongdae"));
			seoul->addNewAttraction(new Attraction("Myeongdong"));

			return cityVector;
		}
		void print(vector<City*> cityVector){
			for(int i = 0; i < cityVector.size(); i++)
				cityVector[i]->printAttractions();
			}
		void run(){
			vector<City*> v = initVariable();
			print(v);
		}

};
int main(void){
	Program* program = new Program;
	program->run();
		
	return 0;
}
