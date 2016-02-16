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

#include <iostream>

#include <raylib/raylib.h>

#include "tictactoe_core.h"

TicTacToeCore TicTacToe;

int main(int argc, char** argv)
{
    if (argc == 2) {
        if (argv[1] == "--version") {
            cout << "TicTacToe XX\nCopyright (C) 2016 Emanuele Petriglia "
                 << "(LelixSuper)\n License MIT: "
                 << "<http://opensource.org/licenses/MIT>\n";
        } else {
            cout << "Usage: tictactoe [--version] [--help]\n"
                 << "Report bugs, ideas and other to:"
                 << "<emanuele98@openmailbox.org";
        }
    } else if (argc = 1) {
        TicTacToe.Game();
        TicTacToe.DeInitializes();
    } else {
        cout << "Usage: tictactoe [--version] [--help]\n"
             << "Report bugs, ideas and other to:"
             << "<emanuele98@openmailbox.org";
    }
    
    return 0;
}
