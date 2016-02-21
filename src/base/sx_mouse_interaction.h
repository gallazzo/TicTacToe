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

#ifndef SRC_BASE_SX_MOUSE_INTERACTION_H
#define SRC_BASE_SX_MOUSE_INTERACTION_H

#include <raylib/raylib.h>

class SxMouseInteraction {
 public:
    // Methods
    // -------------------------------------------------------------------------
    
    // Constructor.
    // Input:
    //     x_input = position x of the top left angle;
    //     y_input = position y of the top left angle;
    //     height_input = area height;
    //     width_input = area width.
    SxMouseInteraction(int x_input, int y_input, int height_input,
                       int width_input);
    
    // Updates pressed attribute, that shows if it has been pressed or not.
    // Input: mouse coordinates.
    void Update(Vector2 mouse_position_input);
    
    // Returns pressed attribute. If 'true' in the area there was an interation
    // with mouse coordinates managed by 'Update()'.
    bool is_pressed() { return pressed_; }
    
    // Returns interation area attribute.
    Rectangle get_area() { return Area_; }
    
 private:
    // Attributes
    // -------------------------------------------------------------------------
    
    // Shows interation area with the mouse.
    Rectangle Area_;
    
    // Shows if the area has been pressed (true) or not (false).
    bool pressed_;
};

#endif // SRC_BASE_SX_MOUSE_INTERACTION
