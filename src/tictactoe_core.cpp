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

#include "tictactoe_core.h"

const TicTacToeCore::screenWidth = 850;
const TicTacToeCore::screenHeight = 500;

void TicTacToeCore::Initializes()
{
    InitWindow(screenWidth, screenHeight, "TicTacToe");
    SetTargetFPS(60);
    
    MainWindow_.Initialize();
    HelpWindow_.Initialize();
    
    TicTacToeScreen = MAIN;
    
    Game_ = new TicTacToeGame;
}

void TicTacToeCore::Game()
{
    while(!WindowShouldClose() && !MainWindow_.quit_button_is_pressed()) {
        NewGame();

        do {
            // Update
            // -----------------------------------------------------------------
            Update();
            // -----------------------------------------------------------------
        
            // Drawing
            // -----------------------------------------------------------------
            BeginDrawing(); // Prepearing drawing
            
            Draw();
            
            EndDrawing(); // End drawing
            // -----------------------------------------------------------------
        }
        while(!MainWindow_.new_game_button_is_pressed() &&
              !WindowShouldClose() &&
              !MainWindow_.quit_button_is_pressed());
        // The nested do-while permits to create a new game without exiting the
        // game.
    }
}

void TicTacToeCore::DeInitializes()
{
    MainWindow_.DeInitialize();
    HelpWindow_.DeInitialize();
}

void TicTacToeCore::NewGame()
{
    delete Game_;
    Game_ = new TicTacToeGame;
    
    MainWindow_.SetGame(Game_);
}

void TicTacToeCore::Update()
{
    mouse_position = GetMousePosition(); 
    
    switch (TicTacToeScreen) {
      case MAIN: {
        MainWindow_.Update(mouse_position);

        if (MainWindow_.help_button_is_pressed()) { // Change window
            TicTacToeScreen = HELP;
        }
        break;
      }
      case HELP: {
        HelpWindow_.Update(mouse_position);
        
        if (HelpWindow_.close_button_is_pressed()) {
            TicTacToeScreen = MAIN;
        }
        break;
      }
      case SETTINGS: {
        // TODO: Settings window is not yet implemented. View the "README.md"
        // for more information.
        break;
      }
    }
}

void TicTacToeCore::Draw()
{
    switch (TicTacToeScreen) {
      case MAIN: {
        MainWindow_.Draw();
        break;
      }
      case HELP: {
        HelpWindow_.Draw();
        break;
      }
      case SETTINGS: {
        // TODO: Settings window is note yet implemented.
        break;
      }
    }
}
