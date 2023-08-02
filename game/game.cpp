#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void print(int x, int y, const char* str){
	move(y, x);
	printw(str);
}

class SnakeUnit{
	public:
		int x;
		int y;
		char* shape;
		SnakeUnit(int x, int y, char* shape){
			this->x = x;
			this->y = y;
			this->shape = shape;
		}	
};

//멀티 스레드 -> 뱀의 움직임을 분리할 수 있댔나요..?
enum DIRECTION {UP, DOWN, LEFT, RIGHT, QUIT};

class Feed{
	public:
		int x, y;
		char* shape;
		Feed(int x = 30, int y = 30, char* shape = (char*)"@"){
			this->x = x;
			this->y = y;	
		 	this->shape = shape;
		}
		void Display(){print(x, y, shape);};
};

class Snake{
	vector<SnakeUnit*> snakeVector;
	public:
		Snake(int size){
			for(int i = 0; i < size; i++){
				snakeVector.push_back(new SnakeUnit(10, 10-i, (char*)"*"));
			}
		}
		void Draw(){
			for(int i = 0; i < snakeVector.size(); i++){
				print(snakeVector[i]->x, snakeVector[i]->y, snakeVector[i]->shape);
			}
		}
		void Move(DIRECTION direction){	
			for(int i = snakeVector.size()-1; i > 0; i--){
				snakeVector[i]->x = snakeVector[i-1]->x;
				snakeVector[i]->y = snakeVector[i-1]->y;
				snakeVector[i]->shape = snakeVector[i-1]->shape;
			}

			switch(direction){
				case UP: snakeVector[0]->y = snakeVector[0]->y - 1; break;
				case DOWN: snakeVector[0]->y = snakeVector[0]->y + 1; break;
				case LEFT: snakeVector[0]->x = snakeVector[0]->x - 1; break;
				case RIGHT: snakeVector[0]->x = snakeVector[0]->x + 1; break;
			}
		}
		void Eat(){
			if ((snakeVector[0]->x = feed->x) && (snakeVector[0]->y = feed-> y)){
				delete feed;
				Feed* newfeed = new Feed(rand() % 200, rand() % 200, (char*)"@");
				snakeVector.push_back(new SnakeUnit(snakeVector[snakeVector.size()-1]->x, snakeVector[snakeVector.size()-1]->y, (char*)"*"));
			}
		}
		/*
		void die(){
			if snake's each units are in same positon
				game over
		}*/
};

class GameEngine{
	public:
		void RunEngine(Snake* snake, Feed* feed){
				while(1){
				clear();	
				snake->Draw();
				feed->Display();
				refresh();
		 		char userInput = getch();
					
				DIRECTION direction;
				if(userInput == 'q') return; //QUIT을 Move 함수에 넣어서 어떻게 게임을 끝낼지 모르겠음
				else if(userInput == 'h') direction = LEFT;
				else if(userInput == 'l') direction = RIGHT;
				else if(userInput == 'j') direction = DOWN;
				else if(userInput == 'k') direction = UP;
				snake->Move(direction);

				snake->Eat();
			}
		}
};

class Game{
	public:
		Game(){ initscr(); }
		~Game(){ endwin(); }
		void Run(){
			int x = 5;
			int y = 10;
			Snake* snake = new Snake(4);
			Feed* feed = new Feed();
			GameEngine* gameengine = new GameEngine;
			gameengine->RunEngine(snake, feed);
		}
};

int main(void){
	Game* game = new Game();
	game->Run();
	
	delete game;
	return 0;
}
