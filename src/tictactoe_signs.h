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

#ifndef SRC_TICTACTOE_SIGNS_H
#define SRC_TICTACTOE_SIGNS_H

#include <raylib.h>

#include "base/graphic_element.h"

#define MAXSIGNS 5

// This class manages the signs of each players. It is used by TicTacToeGrid
// as a normal istance of GraphicElement, the difference is that TicTacToeSigns
// manages ten textures instead of one.
class TicTacToeSigns {
 public:
    // Methods
    // -------------------------------------------------------------------------
    
    // It initializes the object and sets up the default values.
    TicTacToeSigns();
    
    // It initializes "GraphicElement" objects.
    void Initializes();
    
    // It draws the correct sign.
    // Parameters:
    //     pos_input -> the position where you want to draw the sign;
    //     player -> 'X' or 'O' player.
    void Draw(Vector2 pos_input, char player);
    
    // It resets the counters for another draw.
    void NewDraw() { counter_o_ = 0, counter_x_ = 0; }
    
    // It clears texture memory.
    void DeInitializes();
    
 private:
    // Attributes
    // -------------------------------------------------------------------------
    
    // Each one sets the variation of signs to draw.
    short int counter_x_, counter_o_;
    
    // Each array contain every variaton of the signs of two players.
    GraphicElement *x_sign_[MAXSIGNS], *o_sign_[MAXSIGNS];
};

#endif // SRC_TICTACTOE_SIGNS_H
