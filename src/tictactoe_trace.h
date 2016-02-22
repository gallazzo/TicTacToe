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

#ifndef SRC_TICTACTOE_TRACE_H
#define SRC_TICTACTOE_TRACE_H

#include <raylib/raylib.h>

#include "base/graphic_element.h"
#include "tictactoe_game.h"

// Colors of two signs.
#define XMARK (Color){ 255, 15, 1, 255 }
#define OMARK (Color){ 2, 93, 226, 255 }

// This class manages the graphic traces that you see when a player wins the
// game. It's used by "TicTacToeMainGrid".
// It needs an istance of "TicTacToeGame" to retrieve data to draw the traces;
// you can assign an istance with "SetCore" method.
// The class also needs the initialization of graphic objects with "Initialize"
// and after the deinitialization with "DeInitialize".
class TicTacToeTrace {
 private:

    // Constant
    // -------------------------------------------------------------------------
    
    // It's an array that contains the position (x and y with the smaller number) of
    // the traces.
    static const Vector2 trace_position[9];
    
 public:
    
    // Methods
    // -------------------------------------------------------------------------
    
    TicTacToeTrace();
    
    // It sets up the istance from where get the data.
    // Parameter: an istance of "TicTacToeGame".
    void SetCore(TicTacToeGame *Game_input);
    
    // It initializes the graphic elements.
    void Initialize();
    
    // It clears the graphic elements.
    void DeInitialize();
    
    // It updates the state of the istance and it prepares the drawing.
    void Update();
    
    // It draws the traces according to the state of "TicTacToeGame" istance.
    void Draw();
    
 private:

    // Attributes
    // -------------------------------------------------------------------------
    
    // It's an array of graphic elements that contains all traces:
    //     0 - it indicates the horrizontal trace;
    //     1 - it indicates the vertical trace;
    //     2 - it indicates the first diagonal trace;
    //     3 - it indicates the second diagonal trace.
    GraphicElement *Trace_[4];
    
    // Pointer that points a class istance, where gather and load values.
    // This class uses only "WhereHeWon" method of "TicTacToeGame".
    TicTacToeGame *Game_;
    
    // It contains the value of "WhereHeWon".
    unsigned short int trace_;
    
    // It's a counter used in the loops.
    unsigned short int counter_;
    
    // It indicates the color of the trace.
    Color trace_color_;
};

#endif // SRC_TICTACTOE_TRACE_H
