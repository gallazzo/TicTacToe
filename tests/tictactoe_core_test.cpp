#include "./src/tictactoe_game.h"

#include <iostream>
using namespace std;

TicTacToeGame Test;

Coordinate **ptr, Input;

unsigned short int row, column, result_turn, victory_result;

void Graphics()
{
	cout<<"\n\t  0   1   2\n";
	cout<<"\t0 "<<Test.get_status(0, 0) <<" | "<< Test.get_status(0, 1) <<" | ";
	cout<< Test.get_status(0, 2) <<"\n\t  --|---|--\n";
	cout<<"\t1 "<<Test.get_status(1, 0) <<" | "<< Test.get_status(1, 1) <<" | ";
	cout<< Test.get_status(1, 2) << "\n\t  --|---|--\n";
	cout<<"\t2 "<<Test.get_status(2, 0) <<" | "<< Test.get_status(2, 1) <<" | ";
    cout << Test.get_status(2, 2) <<"\n";
}

int main()
{
    Graphics();
    do {
        do {
            // Attenzione: non filtra le posizioni sbagliate, quindi attenzione
            // durante l'esecuzione!
            cout << "Inserisci la riga e colonna\nriga: ";
            cin >> Input.row;
            cout << "colonna: ",
            cin >> Input.column;
            
            result_turn = Test.DoTurn(Input);
            
            cout << endl << "Test.DoTurn(row, column): " << result_turn << endl;
        }
        while(result_turn != 1);
        
        cout << "Test.get_turn(): " << Test.get_turn() << endl;
        cout << "Test.get_player(): " << Test.get_player() << endl;
        
        cout << "Test.get_won(): " << Test.get_won() << endl;
        
        Graphics();
    }
    while(Test.get_won() == 0);
    
    switch(victory_result) {
        case(1): {
            cout << "Il giocatore 1 (X) ha vinto.\n";
            break;
        }
        case(2): {
            cout << "Il giocatore 2 (Y) ha vinto.\n";
            break;
        }
        case(3): {
            cout << "Pareggio.\n";
            break;
        }
    }
    
    return 0;
}
