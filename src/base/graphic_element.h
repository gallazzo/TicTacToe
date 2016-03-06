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

#ifndef SRC_BASE_GRAPHIC_ELEMENT_H
#define SRC_BASE_GRAPHIC_ELEMENT_H

#include <string>

#include <raylib.h>

using namespace std;

// This is a general class thath you can use for other project that use Raylib.
// This class manages an graphic element of the screen. It don't provide any
// interaction with user, only the drawing.
class GraphicElement {
 public:
    // Methods
    // -------------------------------------------------------------------------
    
    // It creates the istance but don't initializes the graphic element.
    // Input:
    //     x_input = position x of the top left image's angle;
    //     y_input = position y of the top left image's angle;
    //     path_input = image's path.
    //     Color_input = image's color (set WHITE for default).
    GraphicElement(int x_input, int y_input, string path_input,
                   Color Color_input);
    
    // Alternative constructor. It is used when the graphic element changes
    // coordinates and color. Parameter:
    //     path_input = image's path.
    GraphicElement(string path_input);
    
    // It loads image and turns it into texture.
    // You must use the method after creating the Raylib window (InitWindow)!
    void Initializes();
    
    // It clears space used by texture in GPU memory.
    void DeInitializes();
    
    // Draws the element on the screen.
    void Show();
    
    // Set graphic element's position.
    // Parameters: coordinates x and y of the top left image's angle.
    void set_position(int x_input, int y_input) { x_ = x_input; y_ = y_input; }
    
    // Set graphic element's color.
    // Parameter: element's color.
    void set_color(Color color_input) { Color_ = color_input; }
    
 private:
    // Attributes
    // -------------------------------------------------------------------------
    
    // It indicates the image's path.
    string path_;
    
    // It indicates the abscissa's position of the top left element's.
    int x_;
    
    // It indicates the ordinate position of the top left element's.
    int y_;
    
    // Element texture.
    Texture2D Texture_;
    
    // Element base color.
    Color Color_;
};

#endif // SRC_BASE_GRAPHIC_ELEMENT_H
