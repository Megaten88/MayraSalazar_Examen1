#include "Tablero.h"
#include <iostream>
using std::cout;
using std::endl;
Tablero::Tablero(){
	end = false;
	player = false;
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
	if ((fil >= 0 && fil <= 10) && (col >= 0 && col <= 10)){
		if (player){
			if (lastfil - fil < 2)
			{
				/* code */
			}else{
				cout<<"Movimiento inválido, solo se puede de dos en dos."<<endl;
			}
		}else{
			Tablero::atax(lastfil,lastcol,fil,col,'#');
		}
	}else{
		cout<<"Ingresó una posición no válida"<<endl;
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
	int play1 = 0;
	int play2 = 0;
	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			if (board[i][j] == ' ')
			{
				spaces++;
			}
			if (board[i][j] = '+')
			{
				play1++;
			}
			if (board[i][j] = '#')
			{
				play2++;
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
void Tablero::atax(int lastfil, int lastcol,int fil, int col, char choice){
	if (board[lastfil][lastcol] == choice) 
	{
		board[fil][col] = choice;
		board[lastfil][lastcol] = ' ';
		if (fil == 0 || fil == 10 || col == 0 || fil == 10)
		{ 
			if (fil == 0) {
	            if (col == 0) {
	                for (int i = 0; i <= fil + 1; i++) {
	                    for (int j = 0; j <= col + 1; j++) {
	                        if (board[i][j] != choice && board[i][j] != ' ')
	                        {
	                        	board[i][j] = choice;
	                        }
	                    }
	                }
	            } else if (col == 10) {
	                for (int i = 0; i <= fil + 1; i++) {
	                    for (int j = col; j >= col - 1; j--) {
	                        if (board[i][j] != choice && board[i][j] != ' ')
	                        {
	                          	board[i][j] = choice;
	                        }
	                    }
	                }
	            } else {
	                for (int i = 0; i <= fil + 1; i++) {
	                    for (int j = col - 1; j <= col + 1; j++) {
	                        if (board[i][j] != choice && board[i][j] != ' ')
	                        {
	                        	board[i][j] = choice;
	                        }
	                    }
	                }
	            }
	        }
	        else if (fil == 10) {
                if (col == 0) {
                    for (int i = fil; i >= fil - 1; i--) {
                        for (int j = 0; j <= col + 1; j++) {
                            if (board[i][j] != choice && board[i][j] != ' ')
	                        {
	                        	board[i][j] = choice;
	                        }
                        }
                    }
                } else if (col == 10) {
                    for (int i = fil; i >= fil - 1; i--) {
                        for (int j = col; j >= col - 1; j--) {
                            if (board[i][j] != choice && board[i][j] != ' ')
	                        {
	                        	board[i][j] = choice;
	                        }
                        }
                    }
                } else {
                    for (int i = fil; i >= fil - 1; i--) {
                        for (int j = col - 1; j <= col + 1; j++) {
                            if (board[i][j] != choice && board[i][j] != ' ')
	                        {
	                        	board[i][j] = choice;
	                        }
                        }
                    }
                }
            }
            else {
                if (fil != 0 && col == 0) {
                    for (int i = fil - 1; i <= fil + 1; i++) {
                        for (int j = 0; j <= col + 1; j++) {
                            if (board[i][j] != choice && board[i][j] != ' ')
	                        {
	                        	board[i][j] = choice;
	                        }
                        }
                    }
                } else if (fil != 0 && col == 10) {
                    for (int i = fil - 1; i <= fil + 1; i++) {
                        for (int j = col; j >= col - 1; j--) {
                            if (board[i][j] != choice && board[i][j] != ' ')
	                        {
	                        	board[i][j] = choice;
	                        }
                        }
                    }
                }
            }
		}else{
			for (int i = fil - 1; i <= fil + 1; i++) {
                for (int j = col - 1; j <= col + 1; j++) {
                    if (board[i][j] != choice && board[i][j] != ' ')
	                {
	                    board[i][j] = choice;
	                }
                }
            }
		}	
	}else{
		cout<<"Debes tomar una pieza propia."<<endl;
	}

}