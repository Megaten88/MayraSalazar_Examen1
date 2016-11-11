#pragma once
#include <iostream>
class Tablero{
private:
	char** board;
	bool player;
	bool end;
public:
	Tablero();
	~Tablero();
	void move(int,int);
	void ganar();
	bool turn();
	void printBoard();
	void atax(int,int,int,int,char);
}