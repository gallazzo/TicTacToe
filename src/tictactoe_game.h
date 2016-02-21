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

// Set max turns of a game.
#define MAX_TURNS 9

// Structure that describe the coordinate on the billboard.
struct Coordinate {
    // Suggest line, could gather values between 0 and 2 included.
    unsigned short int row;
    // Suggest column, could gather values between 0 and 2 included.
    unsigned short int column;
};

// The class manages the game, or rather the management of the billboard and possible
// victory. Warning: there's no control of rows and columns inserted, so avoid
// writing illegal positions!
class TicTacToeGame {
public:
    // Methods.
    // -------------------------------------------------------------------------

    TicTacToeGame();
    
    // Starts the turn of a plauer.
    // Input: row and column of the billboard.
    // Return the following values:
    //     already filled position -> false,
    //     turn successfully ended -> true.
    bool DoTurn(Coordinate Input);
    
    // Returns values between 0 and 7 included, match the winning 
    // combination:
    //    0 - First row combination;
    //    1 - Second row combination;
    //    2 - Third row combination;
    //    3 - First column combination;
    //    4 - Second column combination;
    //    5 - Third column combination;
    //    6 - First diagonal combination;
    //    7 - Second diagonal combination;
    //    8 - General error.
    unsigned short int WhereHeWon();
    
    // Input: row and column of the billboard.
    // Return the following values:
    //     empty -> 0,
    //     symbol 'X' drawn -> 3,
    //     symbol 'O' drawn -> 10,
    unsigned short int get_status(unsigned short int input_row,
                                 unsigned short int input_column) {
        return grid_[input_row][input_column];
    }

    // Input: istance of the structur "Coordinate".
    // Return the following values:
    //     empty -> 0,
    //     symbol 'X' drawn -> 3,
    //     symbol 'O' drawn -> 10,
    unsigned short int get_status(Coordinate input_cell) {
        return grid_[input_cell.row][input_cell.column];
    }
    
    unsigned short int get_turn() { return turn_; }
    
    unsigned short int get_won() { return win_; }
    
    // Return the player that should draw the simbol:
    //     player 1 (X) -> false,
    //     player 2 (Y) -> true.
    bool get_player() { return player_; }
    
private:
    
    // Check the grid and shows who and how won.
    // Used by method WinnerTest, in fact returns same values.
    // Also used by WhereHeWon, throw trace attribute.
    unsigned short int AnalyzesGrid();
    
    // Check if the player won.
    // Return the following value:
    //     missing turns -> 0,
    //     player 1 (X) won -> 1,
    //     player 2 (Y) won -> 2,
    //     draw -> 3.
    // NB: this method is used by method DoTurn(), the returned value is
    // updated in attribute win_.
    unsigned short int WinnerTest() { return AnalyzesGrid(); }

    // Attributes
    // -------------------------------------------------------------------------
    
    // Shows current turn, could have values between 0 and 9 not included.
    int turn_;
    
    // Iterators used for different goals in cicles.
    unsigned short int counter_, counter2_;
    
    //  The 3x3 game grid.
    unsigned short int grid_[3][3];
    
    // Used by cicles and checks in methods.
    unsigned short int row_, column_;
    
    // Shows the player:
    //     player 1 (X) -> false,
    //     player 2 (Y) -> true.
    bool player_;
    
    // Shows the score, with numbers; used in WinnerTest().
    short int score_;
    
    // Shows winning status. Go to WinnerTest comment to read
    // values it could assume.
    unsigned short int win_;
    
    // Needs to input value basing on player in method DoTurn().
    unsigned short int sign_;
    
    // Shows how the player won, go to WhereHeWon comments to read
    // values it could assume.
    unsigned short int trace_;
};

#endif // TICTACTOE_GAME_H
