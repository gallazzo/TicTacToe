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

#ifndef SRC_BASE_SX_MOUSE_INTERACTION_H
#define SRC_BASE_SX_MOUSE_INTERACTION_H

#include <raylib.h>

// This is a general class thath you can use for other project that use Raylib.
// This class manages an interaction of the mouse with the game. You can create
// a rectangular area for tracking the user that clicks (and keeps pressed) with
// the left button in this area.
class SxMouseInteraction {
 public:
    // Methods
    // -------------------------------------------------------------------------
    
    // It creates the tracking area.
    // Parameters:
    //     x_input = position x of the top left angle;
    //     y_input = position y of the top left angle;
    //     height_input = area's height;
    //     width_input = area's width.
    SxMouseInteraction(int x_input, int y_input, int height_input,
                       int width_input);
    
    // It updates "pressed_" attribute, that shows if it pressed or not.
    // Parameter: mouse coordinates.
    void Update(Vector2 mouse_position_input);
    
    // It returns "pressed_" attribute. It returns 'true' if in the user clicks
    // and keeps pressed the left button of the mouse in the tracking area.
    bool is_pressed() { return pressed_; }
    
    // It returns the rectangle of the tracking area.
    Rectangle get_area() { return Area_; }
    
 private:
    // Attributes
    // -------------------------------------------------------------------------
    
    // It's the tracking area.
    Rectangle Area_;
    
    // It indicates if the area is pressed (true) or not (false).
    bool pressed_;
};

#endif // SRC_BASE_SX_MOUSE_INTERACTION
