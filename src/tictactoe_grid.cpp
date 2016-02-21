#include "tictactoe_grid.h"

TicTacToeGrid::TicTacToeGrid()
{
    // TODO(LelixSuper) improve implementation.

    // Grid creation.
    Grid_ = new GraphicElement(386, 40, "resources/main_window/grid.png",
                               WHITE);
    
    Trace_ = new TicTacToeTrace;
    
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
    
    Trace_->SetCore(Game_input);
    
    // If this method is called, it means that a new game has been
    // started, so the textures already drawn will be cleaned. 
    for(counter_ = 0; counter_ < 9; counter_++)
        grid_mark_[counter_] = 4; //  max value is 3, so 4 means empty box.
}

void TicTacToeGrid::Initialize()
{
    Grid_->Initializes();
    
    Trace_->Initialize();
    
    x_mark_[0] = LoadTexture("resources/marks/x_mark_1.png");
    x_mark_[1] = LoadTexture("resources/marks/x_mark_1_mirrored.png");
    x_mark_[2] = LoadTexture("resources/marks/x_mark_2.png");
    x_mark_[3] = LoadTexture("resources/marks/x_mark_2_mirrored.png");
    
    o_mark_[0] = LoadTexture("resources/marks/o_mark_1.png");
    o_mark_[1] = LoadTexture("resources/marks/o_mark_1_mirrored.png");
    o_mark_[2] = LoadTexture("resources/marks/o_mark_2.png");
    o_mark_[3] = LoadTexture("resources/marks/o_mark_2_mirrored.png");
}

void TicTacToeGrid::DeInitialize()
{
    Grid_->DeInitializes();
    
    Trace_->DeInitialize();
    
    UnloadTexture(x_mark_[0]);
    UnloadTexture(x_mark_[1]);
    UnloadTexture(x_mark_[2]);
    UnloadTexture(x_mark_[3]);
    
    UnloadTexture(o_mark_[0]);
    UnloadTexture(o_mark_[1]);
    UnloadTexture(o_mark_[2]);
    UnloadTexture(o_mark_[3]);
}
    
void TicTacToeGrid::Draw()
{
    Grid_->Show();
    
    // Drawing of signs.
    for(counter_ = 0; counter_ < 9; counter_++) {
        // Checks if there is a symbol 'X' in the box.
        if (Game_->get_status(CellsPosition_[counter_]) == 3) {
    
            // If a graphic sign hasn't already been assigned so
            // a value will be assigned for the first time, randomly. 
            // Next time the sign assigned before will be drawn.
            if (grid_mark_[counter_] == 4) {
                grid_mark_[counter_] = GetRandomValue(0, 3);
            }
            DrawTextureV(x_mark_[grid_mark_[counter_]],
                         texture_angle_[counter_], WHITE);
            
        } else if (Game_->get_status(CellsPosition_[counter_]) == 10) {
            
            if (grid_mark_[counter_] == 4) {
                grid_mark_[counter_] = GetRandomValue(0, 3);
            }
            DrawTextureV(o_mark_[grid_mark_[counter_]],
                         texture_angle_[counter_], WHITE);
        }
    }
    
    // Drawing of victory traces.
    Trace_->Draw();
}

void TicTacToeGrid::Update(Vector2 mouse_position_input)
{
    // Checks if left mouse button has been pressed.
    if(IsMouseButtonDown(MOUSE_LEFT_BUTTON) == true) {
        // Checks if drawing signs is necessary.
        if (Game_->get_won() == 0) {
            // Repeat for each box.
            for(counter_ = 0; counter_ < 9; counter_++) {
                // Checks if there is a collision between mouse and grid boxes.
                if (CheckCollisionPointRec(mouse_position_input,
                                           InteractionBox_[counter_]->get_area()
                                           )) {
                    // Checks if the position is empty
                    if (Game_->get_status(CellsPosition_[counter_]) == 0) {
                        Game_->DoTurn(CellsPosition_[counter_]);
                    }
                }
            }
        }
    }
    Trace_->Update();
}
