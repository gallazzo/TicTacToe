// "TicTacToe" using Raylib library
// 
// This file is part of TicTacToe, a software under the MIT License
//
// Copyright (c) 2016 Emanuele Petriglia (also known as LelixSuper)
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

#include "tictactoe_game.h"

TicTacToeGame::TicTacToeGame()
{
    turn_ = 0;
    score_ = 0;
    sign_ = 0;
    
    win_ = 0;
    
    player_ = true; // Inizia sempre il giocatore 1 (X).
    
    // Inizializza la griglia riempendola con zeri.
    for (row_ = 0; row_ < 3; row_++)
        for (column_ = 0; column_ < 3; column_++)
            grid_[row_][column_] = 0;
}

bool TicTacToeGame::DoTurn(Coordinate Input)
{
    // Verifica se la cella selezionata è già occupata.
    if (grid_[Input.row][Input.column] != 0) return false;
    
    turn_++;
    
    // Scambio giocatore
    if (player_ == true) {
        player_ = false; // Tocca al giocatore 1 (X).
        sign_ = 3;
    } else {
        player_ = true; // Tocca al giocatore 2 (Y).
        sign_ = 10;
    }
    
    // Assegnazione valore nella griglia
    grid_[Input.row][Input.column] = sign_;
    
    win_ = WinnerTest();
    
    return true;
}

unsigned short int TicTacToeGame::WhereHeWon()
{
    if (win_ != 0 && win_ != 3)
    {
        AnalyzesGrid();
        return trace_;
    } else {
        return 8; // Errore generale.
    }
}

unsigned short int TicTacToeGame::AnalyzesGrid()
{
    // Nota: l'attributo 'counter2_' è relativo per tracciare la combinazione di
    // vittoria.
    
    // Controllo righe.
    // -------------------------------------------------------------------------
    for (row_ = 0, counter2_ = 0; row_ < 3; row_++, counter2_++) {
        score_ = 0;
        for (column_ = 0, counter_ = 0; column_ < 3; column_++, counter_++) {
            score_ += grid_[row_][column_];
        }
        
        // I valori 0-1-2 corrispondono alle righe della griglia.
        trace_ = counter2_;
        
        // La somma 9 indica che il giocatore 1 (X) ha vinto, mentre la somma 
        // 30 indica che il giocatore 2 (Y) ha vinto.
        if (score_ == 9)
            return 1;
        else if (score_ == 30)
            return 2;
    }
    
    // Controllo colonne.
    // -------------------------------------------------------------------------
    for (column_ = 0, counter2_ = 3; column_ < 3; column_++, counter2_++) {
        score_ = 0;
        for (row_ = 0, counter_ = 0; row_ < 3; row_++, counter_++) {
            score_ += grid_[row_][column_];
        }
        
        // I valori 3-4-5 corrispondono alle colonne (ecco perchè parte da 3).
        trace_ = counter2_;
        
        if (score_ == 9)
            return 1;
        else if (score_ == 30)
            return 2;
    }
    
    // Controllo diagonali.
    // -------------------------------------------------------------------------
    // Seconda diagonale.
    score_ = 0;
    for (row_ = 0, column_ = 0, counter_ = 0; row_ < 3; row_++, column_++,
        counter_++) {
        score_ += grid_[row_][column_];
    }

    trace_ = 7; // 6 corrisponde alla seconda diagonale.

    if (score_ == 9)
        return 1;
    else if (score_ == 30)
        return 2;

    // Prima diagonale.
    score_ = 0;
    for (row_ = 0, column_ = 2, counter_ = 0; row_ < 3; row_++, column_--,
        counter_++) {
        score_ += grid_[row_][column_];
    }
    
    trace_ = 6;
    
    if (score_ == 9)
        return 1;
    else if (score_ == 30)
        return 2;
    
    // Mancano dei turni.
    // -------------------------------------------------------------------------
    if (turn_ < MAX_TURNS)
        return 0;
    else
        return 3; // Pareggio
}
