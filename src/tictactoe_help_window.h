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

#ifndef SRC_TICTACTOE_HELP_WINDOW_H
#define SRC_TICTACTOE_HELP_WINDOW_H

#include <raylib/raylib.h>

#include "base/graphic_element.h"
#include "base/button.h"

class TicTacToeHelpWindow {
 public:
    // Methods
    // -------------------------------------------------------------------------
    
    // Constructor that creates elements but they aren't initialized by Raylib.
    TicTacToeHelpWindow();
    
    // Initialize elements.
    void Initialize();
    
    // Clears element memory.
    void DeInitialize();
    
    // Draws the window with the elements.
    // NB: part of drawing phase.
    void Draw();
    
    // Updates istances basing on the parameter.
    // Input: mouse position.
    // NB: part of updating phase.
    void Update(Vector2 mouse_position_input);

    // Returns true if the button is pressed.
    bool close_button_is_pressed() { return BackButton_->is_pressed(); }
    
 private:
    // Attributes
    // -------------------------------------------------------------------------
    
    // Pointer that points 'GraphicElement' istance, shows backgroung window
    // wallpaper.
    GraphicElement *Background_;
    
    // Pointer that pints 'GraphicElement' istance, shows the text that must
    // be displayed.
    GraphicElement *InfoText_;
    
    // Pointer that points a 'Button' istance, in this case the button that 
    // closes the window.
    Button *BackButton_;
};

#endif // SRC_TICTACTOE_HELP_WINDOW_H
