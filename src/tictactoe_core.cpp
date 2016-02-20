#include "tictactoe_core.h"

TicTacToeCore::TicTacToeCore()
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
            // Aggiornamento
            // -----------------------------------------------------------------
            Update();
            // -----------------------------------------------------------------
        
            // Disegno
            // -----------------------------------------------------------------
            BeginDrawing(); // Preparazione al disegno
            
            Draw();
            
            EndDrawing(); // Fine disegno
            // -----------------------------------------------------------------
        }
        while(!MainWindow_.new_game_button_is_pressed() &&
              !WindowShouldClose() &&
              !MainWindow_.quit_button_is_pressed());
        // Il ciclo interno permette di creare un nuovo gioco senza uscire dal
        // gioco.
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

        if (MainWindow_.help_button_is_pressed()) { // Cambio finestra
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
        // TODO(LelixSuper) fare il caso "SETTINGS".
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
        // TODO(LelixSuper) fare il caso "SETTINGS".
        break;
      }
    }
}