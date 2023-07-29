#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Student{	
	public:
		string name;
		int sid;
		int did;
		Student(string n = " ", int s = 000000, int d = 000000):name{n}, sid{s}, did{d}{}
};

class StudentList{
	vector<Student*> stuVector;
	map<int, Student*> stuMap;
	public:
	void AddStudent(Student* student);
	Student* FindStudent(int sid); //linear
	Student* FindStudent2(int sid);//tree
};

void StudentList::AddStudent(Student* student){ 
	stuVector.push_back(student);
	stuMap[student->sid] = student;
}

//using linear search
Student* StudentList::FindStudent(int sid){
	for(int i = 0; i < stuVector.size(); i++){
		if (stuVector[i]->sid == sid)return stuVector[i];
	}
	return NULL;
}

//using map
Student* StudentList::FindStudent2(int sid){
	return stuMap[sid];
} 

class Program{
	StudentList *slist;
	public:
	Program();
	~Program();
	void Run();
	void InitListForTest();
	void FindTest();
};

void Program::InitListForTest(){
	for (int i = 0; i < 100000; i++)
		slist->Addstudent(new Student( i, i, "name");
}

void Program::Run(){
	InitListForTest();
	FindTest();
}

void Program::FindTest(){
	int found = 0;
	for (int i = 0; i < 10000; i++){
		if(i % 100 == 0) cout << i << endl;
		if(slist->FindStudent(i) != NULL)
			found++;
	}
	cout << found << "개의 학생들을 찾았습니다" << endl;
}

void Program::InitListForTest(){
	for (int i = 0; i < 10000; i++)
		slist->AddStudent(new Student(i, i, "name");
}

Program::Program(){slist = new StudentList();}

Program::~Program(){delete slist;}

int main(void){
	Program *program = new Program();
	program->Run();
	
	delete program;
	return 0;
}
