// This file is part of TicTacToe, a software under the MIT License.
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

#define MAX_TURNS 9 // Max turns of a game.

// Structure that describe the coordinate on the billboard.
struct Coordinate {
    // They can take values between 0 and 2 included.
    unsigned short int row, column;
};

// The class manages the internal game, it provides an interface for retrieve
// and insert data in the game's billboard.
// Warning: there's no control of rows and columns inserted, so avoid
// writing illegal positions!
class TicTacToeGame {
public:
    // Methods.
    // -------------------------------------------------------------------------

    TicTacToeGame();
    
    // It starts the turn of a plauer.
    // Parameter: row and column of the billboard.
    // It returns false if the coordinates points to an already filled position,
    // or true if the turn is successfully ended.
    bool DoTurn(Coordinate Input);
    
    // It returns values between 0 and 7 included, match the winning 
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
    
    // Parameters: row and column of the billboard.
    // It returns the following values:
    //     empty -> 0,
    //     symbol 'X' present -> 3,
    //     symbol 'O' present -> 10,
    unsigned short int get_status(unsigned short int input_row,
                                 unsigned short int input_column) {
        return grid_[input_row][input_column];
    }
    
    // Parameter: a structure of Coordinate.
    // It returns the same values of other overloaded mathod.
    unsigned short int get_status(Coordinate PositionInput) {
        return grid_[PositionInput.row][PositionInput.column];
    }
    
    
    
    unsigned short int get_turn() { return turn_; }
    
    unsigned short int get_won() { return win_; }
    
    // It returns the player that should insert the simbol:
    //     player 1 (X) -> false,
    //     player 2 (Y) -> true.
    bool get_player() { return player_; }
    
private:
    
    // It checks the grid and shows who and how won.
    // Used by "WinnerTest()" method, in fact returns same values.
    // Also used by "WhereHeWon()", throw trace attribute.
    unsigned short int AnalyzesGrid();
    
    // It checks if the player won.
    // Returns the following value:
    //     missing turns -> 0,
    //     player 1 (X) won -> 1,
    //     player 2 (Y) won -> 2,
    //     draw -> 3.
    // NB: this method is used by method DoTurn(), the returned value is
    // updated in "win_".
    unsigned short int WinnerTest() { return AnalyzesGrid(); }

    // Attributes
    // -------------------------------------------------------------------------
    
    // Shows current turn, could have values between 0 and 9 not included.
    int turn_;
    
    // Iterators used for different goals in cicles.
    unsigned short int counter_, counter2_;
    
    // The 3x3 game grid.
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
