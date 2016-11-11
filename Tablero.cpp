#include "Tablero.h"
#include <iostream>
using std::cout;
using std::endl;
Tablero::Tablero(){
	board = new char*[11];
	for (int i = 0; i < 11; ++i)
	{
		board[i] = new char[11];
	}
	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			board[i][j] = ' ';
		}
	}
}
Tablero::~Tablero(){
	for (int i = 0; i < 11; ++i)
	{
		delete[] board[i];
	}
	delete[] board;
}
bool Tablero::turn(){
	player = !player;
	return player;
}
void Tablero::move(int fil, int col){
	if ((x >= 0 && x <= 10) && (y >= 0 && y <= 10)){
		if (player){
			Tablero::atax(fil,col, '+');
		}else{
			Tablero::atax(fil,col,'#');
		}	
	}else{
		cout<<"Ingresó una posición no válida"<<endl;
	}
}
void Tablero::atax(int lastfil, int lastcol, int fil, int col, char choice){

}
void Tablero::printBoard(){
	for (int i = 0; i < 11; ++i){
		for (int j = 0; j < 11; ++j){
			/* code */
		}
	}
}
void Tablero::ganar(){

}