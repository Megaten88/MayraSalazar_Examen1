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
	board[0][0] = '+';
	board[0][1] = '+';
	board[10][0] = '#';
	board[10][1] = '#';
	board[0][9] = '#';
	board[0][10] = '#';
	board[10][9] = '+';
	board[10][10] = '+';
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
void Tablero::move(int lastfil, int lastcol,int fil, int col){
	if ((x >= 0 && x <= 10) && (y >= 0 && y <= 10)){
		if (player){
			Tablero::ganar(Tablero::getEnd());
			Tablero::atax(lastfil,lastcol,fil,col, '+');
			Tablero::ganar(Tablero::getEnd());
		}else{
			Tablero::ganar(Tablero::getEnd());
			Tablero::atax(lastfil,lastcol,fil,col,'#');
			Tablero::ganar(Tablero::getEnd());
		}	
	}else{
		cout<<"Ingresó una posición no válida"<<endl;
	}
}
void Tablero::atax(int lastfil, int lastcol,int fil, int col, char choice){
	if(board[lastfil][lastcol] == choice){

	}else{
		cout<<"Tienes que mover una pieza tuya."<<endl;
	}
}
void Tablero::printBoard(){
	for (int i = 0; i < 11; ++i){
		for (int j = 0; j < 11; ++j){
			cout<<"[" <<board[i][j]<<"]";
		}
		cout<<endl;
	}
}
void Tablero::ganar(bool end){
	int spaces = 0;
	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			if (board[i][j] == ' ')
			{
				spaces++;
			}
		}
	}
	if (spaces > 0)
	{
		Tablero::setEnd(false);
	}else{
		Tablero::setEnd(true);
	}
}
void Tablero::setEnd(bool gameEnd){
	end = gameEnd;
}
bool Tablero::getEnd(){
	return end;
}