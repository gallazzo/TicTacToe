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

#include "tictactoe_signs.h"

TicTacToeSigns::TicTacToeSigns()
{
    for (counter_o_ = 0; counter_o_ < 3; counter_o_++) {
        x_sign_[counter_o_] = new GraphicElement(
                                                "resources/marks/x_mark_1.png");
        o_sign_[counter_o_] = new GraphicElement(
                                                "resources/marks/o_mark_1.png");
    }
    for (counter_o_ = 3; counter_o_ < 5; counter_o_++) {
        x_sign_[counter_o_] = new GraphicElement(
                                                "resources/marks/x_mark_2.png");
        o_sign_[counter_o_] = new GraphicElement(
                                                "resources/marks/o_mark_2.png");
    }
}

void TicTacToeSigns::Initializes()
{
    // TODO: Improve this method.
    x_sign_[0]->Initializes();

    x_sign_[1]->FlipHorizontal();
    x_sign_[1]->Initializes();
    
    x_sign_[2]->FlipVertical();
    x_sign_[2]->Initializes();
    
    x_sign_[3]->Initializes();
    
    x_sign_[4]->FlipHorizontal();
    x_sign_[4]->Initializes();
    
    o_sign_[0]->Initializes();

    o_sign_[1]->FlipHorizontal();
    o_sign_[1]->Initializes();
    
    o_sign_[2]->FlipVertical();
    o_sign_[2]->Initializes();
    
    o_sign_[3]->Initializes();
    
    o_sign_[4]->FlipHorizontal();
    o_sign_[4]->Initializes();
    
    // The result is:
    // [0] -> normal (first texture);
    // [1] -> flipped (first texture);
    // [2] -> flipped vertically (first texture);
    // [3] -> normal (second texture);
    // [4] -> flipped (second texture).
}

void TicTacToeSigns::Draw(Vector2 pos_input, char player)
{
    // TODO: the signs are changed continously in the grid. This should be a bug
    // or a feature?
    if (player == 'X') {
        x_sign_[counter_x_]->set_position(pos_input);
        x_sign_[counter_x_]->Show();
        
        counter_x_++;
    } else {
        o_sign_[counter_o_]->set_position(pos_input);
        o_sign_[counter_o_]->Show();
        
        counter_o_++;
    }
}

void TicTacToeSigns::DeInitializes()
{
    for (counter_o_ = 0; counter_o_ < 5; counter_o_++) {
        x_sign_[counter_o_]->DeInitializes();
        o_sign_[counter_o_]->DeInitializes();
    }
}
