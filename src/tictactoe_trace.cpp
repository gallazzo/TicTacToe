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

#include "tictactoe_trace.h"

const Vector2 TicTacToeTrace::trace_position[9] = {
    // Horizontal traces.
    {400, 84},
    {400, 234},
    {400, 377},
    
    // Vertical traces.
    {437, 52},
    {584, 52},
    {730, 52},
    
    // Diangonal traces.
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
    
    // Reset of "trace_" member.
    trace_ = 8;

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
        
        // Assign the color.
        if (Game_->get_won() == 1)
            trace_color_ = XMARK;
        else
            trace_color_ = OMARK;
        
        // Assign the color to traces.
        for (counter_ = 0; counter_ <= 3; counter_++)
            Trace_[counter_]->set_color(trace_color_);
        
        // Set up of the trace on the screen (but it's not drawn).
        // "WhereHeWon", a method of "TicTacToeGame", returns a integer value
        // that represents the trace that will have to be drawn.
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
