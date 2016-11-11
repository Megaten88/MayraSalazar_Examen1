#pragma once
#include <iostream>
class Tablero{
private:
	char** board;
	bool player;
	bool end;
	void setEnd(bool);
public:
	Tablero();
	~Tablero();
	void move(int,int,int,int);
	void ganar();
	bool turn();
	void printBoard();
	void atax(int,int,int,int,char);
	bool getEnd();

}