// "TicTacToe" using Raylib library
// 
// This file is part of TicTacToe, a software under the MIT License
//
// Copyright (c) 2016 Emanuele Petriglia (LelixSuper)
// <emanuele98@openmailbox.org>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy 
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights 
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
// copies of the Software, and to permit persons to whom the Software is 
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

// Identifica i turni massimi del gioco.
#define MAX_TURNS 9

// Struttura per descrivere la coordinata nel tabellone.
struct Coordinate {
    // Indica la riga, può assumere valori da 0 a 2 compresi.
    unsigned short int row;
    // Indica la colonna, può assumere valori da 0 a 2 compresi.
    unsigned short int column;
};

// La classe gestisce il gioco, ovvero la gestione del tabellone e l'eventuale
// vincita. Attenzione: non c'è un controllo delle righe e colonne inserite,
// quindi evitare di inserire delle posizioni non corrette!
class TicTacToeGame {
public:
    // Metodi.
    // -------------------------------------------------------------------------

    TicTacToeGame();
    
    // Fa eseguire il turno ad un giocatore.
    // Input: la riga e colonna del tabellone di gioco.
    // Restituisce i seguenti valori:
    //     posizione già occupata -> false,
    //     turno finito con successo -> true.
    bool DoTurn(Coordinate Input);
    
    // Restituisce dei valori numerici da 0 a 7 compresi, indicano la
    // combinazione vincente:
    //    0 - Combinazione della prima riga;
    //    1 - Combinazione della seconda riga;
    //    2 - Combinazione della terza riga;
    //    3 - Combinazione della prima colonna;
    //    4 - Combinazione della seconda colonna;
    //    5 - Combinazione della terza colonna;
    //    6 - Combinazione della prima diagonale;
    //    7 - Combinazione della seconda diagonale;
    //    8 - Errore generale.
    unsigned short int WhereHeWon();
    
    // Input: la riga e colonna del tabellone di gioco.
    // Restituisce i seguenti valori:
    //     vuota -> 0,
    //     simbolo 'X' presente -> 3,
    //     simbolo 'O' presente -> 10,
    unsigned short int get_status(unsigned short int input_row,
                                 unsigned short int input_column) {
        return grid_[input_row][input_column];
    }

    // Input: una instanta della struttura "Coordinate".
    // Restituisce i seguenti valori:
    //     vuota -> 0,
    //     simbolo 'X' presente -> 3,
    //     simbolo 'O' presente -> 10,
    unsigned short int get_status(Coordinate input_cell) {
        return grid_[input_cell.row][input_cell.column];
    }
    
    unsigned short int get_turn() { return turn_; }
    
    unsigned short int get_won() { return win_; }
    
    // Restituisce il giocatore che deve mettere il segno:
    //     giocatore 1 (X) -> false,
    //     giocatore 2 (Y) -> true.
    bool get_player() { return player_; }
    
private:
    
    // Controlla la griglia e vede chi ha vinto e come.
    // È usata dal metodo WinnerTest, infatti restituisce valori uguali.
    // È usata anche da WhereHeWon, tramite l'attributo trace.
    unsigned short int AnalyzesGrid();
    
    // Controlla se un giocatore ha vinto.
    // Restituisce i seguenti valori:
    //     mancano dei turni -> 0,
    //     il giocatore 1 (X) ha vinto -> 1,
    //     il giocatore 2 (Y) ha vinto -> 2,
    //     pareggio -> 3.
    // Nota: il metodo è usato dal metodo DoTurn(), il valore restituito viene
    // aggiornato sull'attributo win_.
    unsigned short int WinnerTest() { return AnalyzesGrid(); }

    // Attributi
    // -------------------------------------------------------------------------
    
    // Indica il turno corrente, può avere valori da 0 a 9 non compresi.
    int turn_;
    
    // Iteratori utilizzati per vari scopi nei cicli.
    unsigned short int counter_, counter2_;
    
    // La griglia di gioco 3x3.
    unsigned short int grid_[3][3];
    
    // Usate per i cicli e per i controlli nei metodi.
    unsigned short int row_, column_;
    
    // Indica il giocatore:
    //     giocatore 1 (X) -> false,
    //     giocatore 2 (Y) -> true.
    bool player_;
    
    // Indica il punteggio, in forma numerica; usato in WinnerTest().
    short int score_;
    
    // Indica lo stato di vittoria. Vedere i commenti di WinnerTest per i
    // valori che può assumere.
    unsigned short int win_;
    
    // Serve per immettere il valore in base al giocatore nel metodo DoTurn().
    unsigned short int sign_;
    
    // Indica come ha vinto uno dei giocatori, vedere i commenti di WhereHeWon
    // per i valori che puà assumere.
    unsigned short int trace_;
};

#endif // TICTACTOE_GAME_H
