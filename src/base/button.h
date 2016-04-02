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

#ifndef SRC_BASE_BUTTON_H
#define SRC_BASE_BUTTON_H

#include <raylib.h>

#include "sx_mouse_interaction.h"
#include "graphic_element.h"

class Button : public GraphicElement, public SxMouseInteraction {
 public:
    // Methods
    // -------------------------------------------------------------------------
    
    // Constructor.
    // Input:
    //     x_input = position x of the angle on top left button;
    //     y_input = position y of the angle on top left button;
    //     path_input = image position (texture);
    //     height_input = button height;
    //     width_input = button width.
    //     Color_input = graphic color (set WHITE) by default.
    Button(int x_input, int y_input, int width_input,
           int height_input, std::string path_input, Color Color_input)
           : GraphicElement(x_input, y_input, path_input, Color_input),
             SxMouseInteraction(x_input, y_input, height_input, width_input) {}
    
    // TODO(LelixSuper): add animations after a release of a base version 
    // of source code.
};

#endif // SRC_BASE_BUTTON_H
