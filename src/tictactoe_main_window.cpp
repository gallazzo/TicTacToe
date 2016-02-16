#include "tictactoe_main_window.h"

TicTacToeMainWindow::TicTacToeMainWindow()
{
    // Creazione e puntamento degli elementi statici.
    Logo_ = new GraphicElement(23, 0, "resources/main_window/logo.png", WHITE);
    Background_ = new GraphicElement(0, 0,
                                     "resources/background.png", WHITE);
    // Creazione e puntamento dei pulsanti.
    SettingsButton_ = new Button(293, 413, 80, 80,
                                 "resources/buttons/settings_button.png",
                                 WHITE);
    NewGameButton_ = new Button(109, 306, 165, 80,
                                "resources/buttons/new_game_button.png", WHITE);
    HelpButton_ = new Button(150, 413, 80, 80,
                             "resources/buttons/help_button.png", WHITE);
    QuitButton_ = new Button(14, 413, 80, 80,
                             "resources/buttons/quit_button.png", WHITE);
    
    // Creazione e puntamento dei testi.
    DrawText_ = new GraphicElement(14, 165, "resources/infobox/draw_text.png",
                                   WHITE);
    Player1Turn_ = new GraphicElement(14, 165,
                                      "resources/infobox/player_1_turn.png",
                                      WHITE);
    Player1Wins_ = new GraphicElement(14, 165,
                                      "resources/infobox/player_1_wins.png",
                                      WHITE);
    Player2Turn_ = new GraphicElement(14, 165,
                                      "resources/infobox/player_2_turn.png",
                                      WHITE);
    Player2Wins_ = new GraphicElement(14, 165,
                                      "resources/infobox/player_2_wins.png",
                                      WHITE);
    
    // NOTA: Grid_ è già stato creato.
}

void TicTacToeMainWindow::Initialize()
{
    Grid_.Initialize();
    
    Logo_->Initializes();
    Background_->Initializes();
    HelpButton_->Initializes();
    SettingsButton_->Initializes();
    NewGameButton_->Initializes();
    QuitButton_->Initializes();
    DrawText_->Initializes();
    Player1Turn_->Initializes();
    Player1Wins_->Initializes();
    Player2Turn_->Initializes();
    Player2Wins_->Initializes();
}

void TicTacToeMainWindow::DeInitialize()
{
    Grid_.DeInitialize();
    
    Logo_->DeInitializes();
    Background_->DeInitializes();
    QuitButton_->DeInitializes();
    HelpButton_->DeInitializes();
    SettingsButton_->DeInitializes();
    NewGameButton_->DeInitializes();
    DrawText_->DeInitializes();
    Player1Turn_->DeInitializes();
    Player1Wins_->DeInitializes();
    Player2Turn_->DeInitializes();
    Player2Wins_->DeInitializes();
}

void TicTacToeMainWindow::SetGame(TicTacToeGame *Game_input)
{
    Game_ = Game_input;
    Grid_.SetGame(Game_input);
}

void TicTacToeMainWindow::Draw()
{
    // Nota: gli elementi sono in sovrapposizione.
    Background_->Show();
    Logo_->Show();
    QuitButton_->Show();
    NewGameButton_->Show();
    HelpButton_->Show();
    SettingsButton_->Show();
    
    // Elementi dinamici.
    DrawInfo();
    Grid_.Draw();
}

void TicTacToeMainWindow::Update(Vector2 mouse_position_input)
{
    Grid_.Update(mouse_position_input);
    QuitButton_->Update(mouse_position_input);
    HelpButton_->Update(mouse_position_input);
    SettingsButton_->Update(mouse_position_input);
    NewGameButton_->Update(mouse_position_input);
}

void TicTacToeMainWindow::DrawInfo()
{
    switch (Game_->get_won()) {
      case 0: {
        if (Game_->get_player() == false) {
            Player2Turn_->Show();
        } else {
            Player1Turn_->Show();
        }
        break;
      }
      case 1: {
        Player1Wins_->Show();
        break;
      }
      case 2: {
        Player2Wins_->Show();
        break;
      }
      case 3: {
        DrawText_->Show();
      }
    }
}
