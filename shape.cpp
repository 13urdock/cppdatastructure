#include <iostream>
using namespace std;

class Shape{
	public:
		virtual void draw(){cout << "draw shape" << endl;}
};

class Rectangle : public Shape{
	public:
		virtual void draw(){cout << "draw Rectangle" << endl;}
};

class Triangle : public Shape{
	public:
		virtual void draw(){cout << "draw Triangle" << endl;}
};

class Circle : public Shape{
	public:
		virtual void draw(){cout << "draw Circle" << endl;}
};

void paint(Shape* p){
	p->draw();
}

int main(void){

	Circle* c = new Circle;
	Triangle* t = new Triangle;
	Rectangle* r = new Rectangle;

	paint(c);
	paint(t);
	paint(r);

	return 0;
}
