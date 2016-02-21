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

#ifndef SRC_TICTACTOE_CORE_WINDOW_H
#define SRC_TICTACTOE_CORE_WINDOW_H

#include <raylib/raylib.h>

#include "tictactoe_game.h"
#include "tictactoe_main_window.h"
#include "tictactoe_help_window.h"

class TicTacToeCore {
 private:
    // Constants
    // -------------------------------------------------------------------------
    
    const int screenWidth = 850; // Window width
    const int screenHeight = 500; // Window height
    
 public:
    // Methods
    // -------------------------------------------------------------------------
    
    // It creates the window and set up Raylib and other classes.
    void Initializes();
    
    // Main loop where the game is loaded.
    void Game();
    
    // Clears memory for the exit.
    void DeInitializes();
    
 private:
    
    // Manages game updates.
    void Update();
    
    // Manages game graphic drawing.
    void Draw();
    
    // Deallocates 'TicTacToeGame' istance pointed by Game_ and creates a new 
    // istance for a new game.
    void NewGame();

    // Attributes
    // -------------------------------------------------------------------------
    
    // Istance that shows the main window.
    TicTacToeMainWindow MainWindow_;
    
    // Istance that shows help window.
    TicTacToeHelpWindow HelpWindow_;
    
    // Pointer that directs to a 'TicTacToeGame' istance, that is the game.
    TicTacToeGame *Game_;
    
    // Shows mouse position, updated by 'Update()' method.
    Vector2 mouse_position;
    
    // Shows the windows of the game.
    enum GameScreens { MAIN, SETTINGS, HELP } TicTacToeScreen;
};

#endif // SRC_TICTACTOE_CORE_WINDOW_H
