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

#include "sx_mouse_interaction.h"

SxMouseInteraction::SxMouseInteraction(int x_input, int y_input,
                                       int height_input, int width_input) {
    Area_.x = x_input;
    Area_.y = y_input;
    Area_.height = height_input;
    Area_.width = width_input;
    
    pressed_ = false;
}

void SxMouseInteraction::Update(Vector2 mouse_position_input)
{
    // Checks if the left mouse button has been pressed.
    if(IsMouseButtonDown(MOUSE_LEFT_BUTTON) == true) {
        // Checks the collision with the tracking area.
        if(CheckCollisionPointRec(mouse_position_input, Area_)) {
            pressed_ = true;
        } else {
            pressed_ = false;
        }
    } else {
        pressed_ = false;
    }
}
