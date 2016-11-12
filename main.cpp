#include "Tablero.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
int main(int argc, char const *argv[])
{
	int lastfil;
	int lastcol;
	int fil;
	int col;
	Tablero* board = new Tablero();
	do{
		if (board-> turn())
		{
			cout<<"Turno del Player 1"<<endl;
		}else{
			cout<<"Turno del Player 2"<<endl;
		}
		board-> printBoard();
		cout<<"Ingrese la cordenada de la pieza a mover de manera =  Fil Col: ";
		cin>>lastfil;
		cin>>lastcol;
		cout<< "Ingrese la nueva cordenada de la pieza = Fil Col: ";
		cin>>fil;
		cin>>col;
		board-> move(lastfil,lastcol,fil,col);
		board-> ganar(board->getEnd());
	}while(board->getEnd() != true);
	board-> ~Tablero();
	return 0;	
}