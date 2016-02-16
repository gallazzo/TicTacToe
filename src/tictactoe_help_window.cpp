#include "tictactoe_help_window.h"

TicTacToeHelpWindow::TicTacToeHelpWindow()
{
    Background_ = new GraphicElement(0, 0,
                                     "resources/background.png", WHITE);
    InfoText_ = new GraphicElement(6, 20, "resources/infobox/info_text.png",
                                   WHITE);
    BackButton_ = new Button(238, 413, 389, 56,
                             "resources/buttons/back_button.png", WHITE);
}

void TicTacToeHelpWindow::Initialize()
{
    Background_->Initializes();
    InfoText_->Initializes();
    BackButton_->Initializes();
}

void TicTacToeHelpWindow::DeInitialize()
{
    Background_->DeInitializes();
    InfoText_->DeInitializes();
    BackButton_->DeInitializes();
}

void TicTacToeHelpWindow::Update(Vector2 mouse_position_input)
{
    BackButton_->Update(mouse_position_input);
}

void TicTacToeHelpWindow::Draw()
{
    Background_->Show();
    InfoText_->Show();
    BackButton_->Show();
}
