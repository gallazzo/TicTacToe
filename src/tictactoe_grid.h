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

// This class manages the grid of the game. In the software there is one
// istance of this class. If you want to use it, you must call first 
// "Initialize()" method and at the end "DeInitialize()" method.
// The principal methods are "Draw()" and "Update()".
class TicTacToeGrid {
 public:
    // Methods
    // -------------------------------------------------------------------------
    
    // It initializes the object and sets up the default values.
    TicTacToeGrid();
    
    // It sets up the istance from where get the data.
    // Parameter: an istance of "TicTacToeGame".
    void SetGame(TicTacToeGame *Game_input);
    
    // It initializes "GraphicElement" objects.
    void Initialize();
    
    // It clears texture memory.
    void DeInitialize();
    
    // Draws the grid and its content.
    // NB: part of Raylib drawing phase.
    void Draw();
    
    // Updates the grid basing on mouse position.
    // Input: mouse position.
    // NB: part of Raylib input phase.
    void Update(Vector2 mouse_position_input);
    
 private:
    // Attributes
    // -------------------------------------------------------------------------
    
    // Pointer that points a class istance, where load values.
    TicTacToeGame *Game_;
    
    // It indicates the texture of the grid.
    GraphicElement *Grid_;
    
    // They are interation areas (rectangles) in the grid.
    // The numbering matches with the grid logic one:
    //     0 | 1 | 2
    //     ---------
    //     3 | 4 | 5
    //     ---------
    //     6 | 7 | 8
    // Used for input signs.
    SxMouseInteraction *InteractionBox_[9];
    
    // Shows grid logic coordinates, they are numbered basing on
    // "InteractionBox_" and "x/o_sign_".
    // Used for drawing and input.
    Coordinate CellsPosition_[9];
    
    // Shows angles (x, y) of every box.
    // Used for drawing signs.
    Vector2 texture_angle_[9];
    
    GraphicElement *x_sign_[5];
    
    GraphicElement *o_sign_[5];
    
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
