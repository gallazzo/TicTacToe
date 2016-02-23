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
