#include "Tablero.h"
#include <iostream>
int main(int argc, char const *argv[])
{
	Tablero* board = new Tablero();
	board->printBoard();
	board-> ~Tablero();
	return 0;	
}