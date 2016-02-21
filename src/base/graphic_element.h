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

#ifndef SRC_BASE_GRAPHIC_ELEMENT_H
#define SRC_BASE_GRAPHIC_ELEMENT_H

#include <string>

#include <raylib/raylib.h>

using namespace std;

class GraphicElement {
 public:
    // Methods
    // -------------------------------------------------------------------------
    
    // Constructor.
    // Input:
    //     x_input = position x of the element;
    //     y_input = position y of the element;
    //     path_input = image path.
    //     Color_input = graphic color (set WHITE) by default.
    // NB: the position is refered to top left angle position!
    GraphicElement(int x_input, int y_input, string path_input,
                   Color Color_input);
    
    // Alternative constructor. It is used when the istance changes
    // coordinates and color. Input:
    //     path_input = image path.
    GraphicElement(string path_input);
    
    // Loads element image and turns it into texture.
    // It returns void.
    // NB: use the method only after creating the window (InitWindow)!
    void Initializes();
    
    // Clear space used by texture in memory.
    // It returns void.
    void DeInitializes();
    
    // Draws the element basing on arguments read by constructor.
    void Show();
    
    // Set graphic element position.
    // Input: coordinates x and y of the element.
    void set_position(int x_input, int y_input) { x_ = x_input; y_ = y_input; }
    
    // Set graphic element color.
    // Input: element color.
    void set_color(Color color_input) { Color_ = color_input; }
    
 private:
    // Attributes
    // -------------------------------------------------------------------------
    
    // Shows image path.
    string path_;
    
    // Shows position in abscissa of the top left angle.
    int x_;
    
    // Shows position in coordinates of the top left angle.
    int y_;
    
    // Element texture.
    Texture2D Texture_;
    
    // Element base color.
    Color Color_;
};

#endif // SRC_BASE_GRAPHIC_ELEMENT_H
