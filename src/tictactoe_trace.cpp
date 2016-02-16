#include "tictactoe_trace.h"

const Vector2 TicTacToeTrace::trace_position[9] = {
    // Traccie orrizzontali
    {400, 84},
    {400, 234},
    {400, 377},
    
    // Traccie verticali
    {437, 52},
    {584, 52},
    {730, 52},
    
    // Diagonali
    {428, 76},
    {436, 81},
};

TicTacToeTrace::TicTacToeTrace()
{
    Trace_[0] = new GraphicElement("resources/traces/horizontal_trace.png");
    Trace_[1] = new GraphicElement("resources/traces/vertical_trace.png");
    Trace_[2] = new GraphicElement("resources/traces/first_diagonal_trace.png");
    Trace_[3]= new GraphicElement("resources/traces/second_diagonal_trace.png");
}

void TicTacToeTrace::SetCore(TicTacToeGame *Game_input)
{
    Game_ = Game_input;
    
    trace_ = 8;
}

void TicTacToeTrace::Initialize()
{
    for (counter_ = 0; counter_ <= 3; counter_++)
        Trace_[counter_]->Initializes();
}

void TicTacToeTrace::DeInitialize()
{
    for (counter_ = 0; counter_ <= 3; counter_++)
        Trace_[counter_]->DeInitializes();
}

void TicTacToeTrace::Update()
{
    if (Game_->get_won() != 0 && Game_->get_won() != 3) {
        trace_ = Game_->WhereHeWon();
        
        // Assegnazione del colore.
        if (Game_->get_won() == 1)
            trace_color_ = XMARK;
        else
            trace_color_ = OMARK;
        
        // Assegnazione del colore alle traccie.
        for (counter_ = 0; counter_ <= 3; counter_++)
            Trace_[counter_]->set_color(trace_color_);
        
        // Disegno delle traccie.
        if (trace_ >= 0 && trace_ < 3) {
            Trace_[0]->set_position(trace_position[trace_].x, 
                                    trace_position[trace_].y);
        } else if (trace_ >= 3 && trace_ < 6) {
            Trace_[1]->set_position(trace_position[trace_].x, 
                                    trace_position[trace_].y);
        } else if (trace_ == 6) {
            Trace_[2]->set_position(trace_position[trace_].x, 
                                    trace_position[trace_].y);
        } else if (trace_ == 7) {
            Trace_[3]->set_position(trace_position[trace_].x, 
                                    trace_position[trace_].y);
        }
    }
}

void TicTacToeTrace::Draw()
{
    if (trace_ >= 0 && trace_ < 3) {
        Trace_[0]->Show();
    } else if (trace_ >= 3 && trace_ < 6) {
        Trace_[1]->Show();
    } else if (trace_ == 6) {
        Trace_[2]->Show();
    } else if (trace_ == 7) {
        Trace_[3]->Show();
    }
}

