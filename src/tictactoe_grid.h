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

#ifndef SRC_TICTACTOE_GRID_H
#define SRC_TICTACTOE_GRID_H

#include <raylib/raylib.h>

#include "tictactoe_game.h"
#include "tictactoe_trace.h"

#include "base/sx_mouse_interaction.h"
#include "base/graphic_element.h"

class TicTacToeGrid {
 public:
    // Methods
    // -------------------------------------------------------------------------
    
    // Constructors.
    // Point the pointers that creates istances.
    TicTacToeGrid();
    
    // Set 'TicTacToeCore' istance to gather and load data
    // Input: 'TicTacToeCore' istance.
    void SetGame(TicTacToeGame *Game_input);
    
    // Initialize textures.
    void Initialize();
    
    // Clears texture memory.
    void DeInitialize();
    
    // Draws the grid and its content.
    // Part of drawing phase.
    void Draw();
    
    // Updates the grid basing on mouse position.
    // Input: mouse position.
    // NB: input phase.
    void Update(Vector2 mouse_position_input);
    
 private:
    
    // Attributes
    // -------------------------------------------------------------------------
    
    // Pointer that points a TicTacToeCore istance, where to gather and load 
	// data
    TicTacToeGame *Game_;
    
    // Pointer that points a graphic element istance, in this case the grid.
    GraphicElement *Grid_;
    
    // Pointers that points every interation areas (rectangles) in the grid.
    // The numbering matches with the grid logic one:
    //     0 | 1 | 2
    //     ---------
    //     3 | 4 | 5
    //     ---------
    //     6 | 7 | 8
    // Used for input.
    SxMouseInteraction *InteractionBox_[9];
    
    // Shows grid logic coordinates, they are numbered basing on
    // InteractionBox_ and Mark_.
    // Used for drawing and input.
    Coordinate CellsPosition_[9];
    
    // Shows angles (x, y) of every box.
    // Used for drawing.
    Vector2 texture_angle_[9];
    
    // Symbol 'X' with its variants.
    Texture2D x_mark_[4];
    
    // Symbol 'O' with its variants.
    Texture2D o_mark_[4];
    
    // Shows the number that identify symbol variants that there are
    // in grid boxes.
    unsigned short int grid_mark_[9];
    
    // Pointer that points a TicTacToeTrace istance, the class that manages
    // the graphic traces of the victory.
    TicTacToeTrace *Trace_;
    
    // Used for cicles.
    unsigned short int counter_;
};

#endif // SRC_TICTACTOE_GRID_H
