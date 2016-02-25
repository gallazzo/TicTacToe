// This file is part of TicTacToe, a software under the MIT License.
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
    
    player_ = true; // Player 1 (X) always begins the game.
    
    // Initialize the grid filling it with zeros.
    for (row_ = 0; row_ < 3; row_++)
        for (column_ = 0; column_ < 3; column_++)
            grid_[row_][column_] = 0;
}

bool TicTacToeGame::DoTurn(Coordinate Input)
{
    // Check if the box selected is already filled.
    if (grid_[Input.row][Input.column] != 0) return false;
    
    turn_++;
    
    // Switch player
    if (player_ == true) {
        player_ = false; // Player 1 turn (X).
        sign_ = 3;
    } else {
        player_ = true; // Player 2 turn (Y).
        sign_ = 10;
    }
    
    grid_[Input.row][Input.column] = sign_; // Assign the value in the grid.
    
    win_ = WinnerTest(); // Update the "win_" member.
    
    return true;
}

unsigned short int TicTacToeGame::WhereHeWon()
{
    if (win_ != 0 && win_ != 3)
    {
        AnalyzesGrid();
        return trace_;
    } else {
        return 8; // General error.
    }
}

unsigned short int TicTacToeGame::AnalyzesGrid()
{
    // NB: the attribute 'counter2_' tracks the combination of moves needed for 
    // the victory.
    
    // Check rows.
    // -------------------------------------------------------------------------
    for (row_ = 0, counter2_ = 0; row_ < 3; row_++, counter2_++) {
        score_ = 0;
        for (column_ = 0, counter_ = 0; column_ < 3; column_++, counter_++) {
            score_ += grid_[row_][column_];
        }
        
        // Values 0-1-2 matches the rows into the grid.
        trace_ = counter2_;
        
        // The score 9 means that Player 1 (X) won, while the score
        // 30 means that Player 2 (Y) won instead.
        if (score_ == 9)
            return 1;
        else if (score_ == 30)
            return 2;
    }
    
    // Check columns.
    // -------------------------------------------------------------------------
    for (column_ = 0, counter2_ = 3; column_ < 3; column_++, counter2_++) {
        score_ = 0;
        for (row_ = 0, counter_ = 0; row_ < 3; row_++, counter_++) {
            score_ += grid_[row_][column_];
        }
        
        // Values 3-4-5 matches the columns (that's why values start from 3).
        trace_ = counter2_;
        
        if (score_ == 9)
            return 1;
        else if (score_ == 30)
            return 2;
    }
    
    // Check diagonals.
    // -------------------------------------------------------------------------
    // Second diagonal.
    score_ = 0;
    for (row_ = 0, column_ = 0, counter_ = 0; row_ < 3; row_++, column_++,
        counter_++) {
        score_ += grid_[row_][column_];
    }

    trace_ = 7; // 7 matches the second diagonal.

    if (score_ == 9)
        return 1;
    else if (score_ == 30)
        return 2;

    // First diagonal.
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
    
    // Missing turns.
    // -------------------------------------------------------------------------
    if (turn_ < MAX_TURNS)
        return 0;
    else
        return 3; // Draw
}
