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

#ifndef SRC_TICTACTOE_MAIN_WINDOW_H
#define SRC_TICTACTOE_MAIN_WINDOW_H

#include <raylib/raylib.h>

#include "tictactoe_game.h"
#include "tictactoe_grid.h"
#include "base/button.h"
#include "base/graphic_element.h"

class TicTacToeMainWindow {
 public:
    // Methods
    // -------------------------------------------------------------------------
    
    // Constructor that creates elements but they are not initialized by Raylib.
    TicTacToeMainWindow();
    
    // Initialize the elements.
    void Initialize();
    
    // Clears elements memory.
    void DeInitialize();
    
    // Input: a pointer of 'TicTacToeGame' istance.
    void SetGame(TicTacToeGame *Game_input);
    
    // Draws the window, including static (buttons, logo, wallpaper) and
    // and dynamic elements (grid with the game, text).
    // NB: part of drawing phase.
    void Draw();
    
    // Updates istances basing on the parameter.
    // Input: mouse position.
    // NB: part of updating phase.
    void Update(Vector2 mouse_position_input);
    
    // Return true if the button has been pressed.
    bool quit_button_is_pressed() { return QuitButton_->is_pressed(); }
    
    bool help_button_is_pressed() { return HelpButton_->is_pressed(); }
    
    bool settings_button_is_pressed() { return SettingsButton_->is_pressed(); }
    
    bool new_game_button_is_pressed() { return NewGameButton_->is_pressed(); }

 public:
    
    // Chooses and draws the texture basing on game status.
    void DrawInfo();
    
    // Attributes
    // -------------------------------------------------------------------------
    
    // Pointer that points a class istance, where gather and load values.
    TicTacToeGame *Game_;
    
    // Grid istance.
    TicTacToeGrid Grid_;
    
    // Static graphic elements.
    // -------------------------
    GraphicElement *Logo_;

    GraphicElement *Background_;
    // -------------------------
    
    // Pointers to game buttons.
    // --------------------------------
    Button *NewGameButton_;
    
    Button *QuitButton_;
    
    Button *HelpButton_;
    
    Button *SettingsButton_;
    // --------------------------------
    
    // Dynamic texts (in texture)
    // ----------------------------------------
    GraphicElement *DrawText_;
    
    GraphicElement *Player1Wins_;
    
    GraphicElement *Player2Wins_;
    
    GraphicElement *Player1Turn_;
    
    GraphicElement *Player2Turn_;
    // ----------------------------------------
};

#endif // SRC_TICTACTOE_MAIN_WINDOW_H
