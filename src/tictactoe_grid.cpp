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

#include "tictactoe_grid.h"

TicTacToeGrid::TicTacToeGrid()
{
    // TODO: improve implementation here.

    // Grid creation.
    Grid_ = new GraphicElement(386, 40, "resources/main_window/grid.png",
                               WHITE);
    
    Trace_ = new TicTacToeTrace;
    
    Signs_ = new TicTacToeSigns;
    
    // Interation areas creation.
    InteractionBox_[0] = new SxMouseInteraction(406, 54, 136, 136);
    InteractionBox_[1] = new SxMouseInteraction(556, 55, 136, 136);
    InteractionBox_[2] = new SxMouseInteraction(703, 53, 136, 136);
    InteractionBox_[3] = new SxMouseInteraction(406, 202, 136, 136);
    InteractionBox_[4] = new SxMouseInteraction(555, 203, 136, 136);
    InteractionBox_[5] = new SxMouseInteraction(703, 205, 136, 136);
    InteractionBox_[6] = new SxMouseInteraction(409, 350, 136, 136);
    InteractionBox_[7] = new SxMouseInteraction(557, 351, 136, 136);
    InteractionBox_[8] = new SxMouseInteraction(701, 353, 136, 136);
    
    // Grid logic positions creation.
    CellsPosition_[0].row = 0;
    CellsPosition_[0].column = 0;
    CellsPosition_[1].row = 0;
    CellsPosition_[1].column = 1;
    CellsPosition_[2].row = 0;
    CellsPosition_[2].column = 2;
    CellsPosition_[3].row = 1;
    CellsPosition_[3].column = 0;
    CellsPosition_[4].row = 1;
    CellsPosition_[4].column = 1;
    CellsPosition_[5].row = 1;
    CellsPosition_[5].column = 2;
    CellsPosition_[6].row = 2;
    CellsPosition_[6].column = 0;
    CellsPosition_[7].row = 2;
    CellsPosition_[7].column = 1;
    CellsPosition_[8].row = 2;
    CellsPosition_[8].column = 2;
    
    // Boxes angles x, y creation.
    texture_angle_[0].x = 406;
    texture_angle_[0].y = 54;
    texture_angle_[1].x = 556;
    texture_angle_[1].y = 55;
    texture_angle_[2].x = 703;
    texture_angle_[2].y = 53;
    texture_angle_[3].x = 406;
    texture_angle_[3].y = 202;
    texture_angle_[4].x = 555;
    texture_angle_[4].y = 203;
    texture_angle_[5].x = 703;
    texture_angle_[5].y = 205;
    texture_angle_[6].x = 409;
    texture_angle_[6].y = 350;
    texture_angle_[7].x = 557;
    texture_angle_[7].y = 351;
    texture_angle_[8].x = 701;
    texture_angle_[8].y = 353;
}

void TicTacToeGrid::SetGame(TicTacToeGame *Game_input)
{
    Game_ = Game_input;
    
    Signs_->NewDraw();
    
    Trace_->SetCore(Game_input);
}

void TicTacToeGrid::Initialize()
{
    Grid_->Initializes();
    
    Signs_->Initialize();
    
    Trace_->Initialize();
}

void TicTacToeGrid::DeInitialize()
{
    Grid_->DeInitializes();
    
    Signs_->DeInitialize();
    
    Trace_->DeInitialize();
}
    
void TicTacToeGrid::Draw()
{
    Grid_->Show();
    
    Signs_->NewDraw(); // It prepares the drawn of the signs.
    // Drawing of signs.
    for (counter_ = 0; counter_ < 9; counter_++) {
        // Checks if there is a symbol 'X' in the box.
        if (Game_->get_status(CellsPosition_[counter_]) == 3) {
            Signs_->Show(texture_angle_[counter_], 'X');
            
        } else if (Game_->get_status(CellsPosition_[counter_]) == 10) {
            Signs_->Show(texture_angle_[counter_], 'O');
        }
    }
    
    // Drawing of victory traces.
    Trace_->Draw();
}

void TicTacToeGrid::Update(Vector2 mouse_position_input)
{
    // Checks if left mouse button has been pressed.
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) == true) {
        // Checks if drawing signs is necessary.
        if (Game_->get_won() == 0) {
            // Repeat for each box.
            for (counter_ = 0; counter_ < 9; counter_++) {
                // Checks if there is a collision between mouse and grid boxes.
                if (CheckCollisionPointRec(mouse_position_input,
                                           InteractionBox_[counter_]->get_area()
                                           )) {
                    // Checks if the position is empty
                    if (Game_->get_status(CellsPosition_[counter_].row,
                                          CellsPosition_[counter_].column)
                                          == 0) {
                        Game_->DoTurn(CellsPosition_[counter_]);
                    }
                }
            }
        }
    }
    Trace_->Update();
}
