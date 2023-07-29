#include <iostream>
#include <string>
using namespace std;

class Point{
	public:
	int x, y;
	Point(int x=0, int y=0) : x{x}, y{y} {}
	void setPoint(int x, int y){
		this->x = x;
		this->y = y;	
	}
	void showPoint(){
		cout << "(" << x << ", " << y << ")" << endl;
	}
};

class ColorPoint : public Point{
	public:
	string color;
	ColorPoint(string color="transparent", int x=0, int y=0) : color{color}, Point{x, y} {}
	void setColor (string color){
		this->color = color;
	}
	void showColorPoint(){
		cout << color << " (" << x << ", " << y << ")" << endl;
	}
};

int main(void){
	//upcasting
	Point *p = new ColorPoint;
	p->showPoint();
	//downcasting
	//ColorPoint *c = new Point;
	//c->showPoint();
}
