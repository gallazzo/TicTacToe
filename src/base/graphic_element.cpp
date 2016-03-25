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

#include "graphic_element.h"

GraphicElement::GraphicElement(int x_input, int y_input,
                               string path_input, Color Color_input) {
    x_ = x_input;
    y_ = y_input;
    path_ = path_input;
    Color_ = Color_input;
    
    Image_ = NULL;
}

GraphicElement::GraphicElement(string path_input)
{
    path_ = path_input;
    Color_ = WHITE; // Default color
    
    Image_ = NULL;
}

void GraphicElement::Initializes()
{
    // Raylib's function with paths accetps only C string, so it's necessary
    // convert "path_".
    if (Image_ != NULL) {
        Texture_ = LoadTextureFromImage(*Image_);
    } else {
        Texture_ = LoadTexture(path_.c_str());
    }
}

void GraphicElement::DeInitializes()
{
    UnloadTexture(Texture_);
}

void GraphicElement::Show()
{
    DrawTexture(Texture_, x_, y_, Color_);
}

void GraphicElement::FlipVertical()
{
    Image_ = new Image;
    *Image_ = LoadImage(path_.c_str());
    ImageFlipVertical(Image_);
}

void GraphicElement::FlipHorizontal()
{
    Image_ = new Image;
    *Image_ = LoadImage(path_.c_str());
    ImageFlipHorizontal(Image_);
}
