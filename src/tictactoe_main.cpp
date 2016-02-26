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

#include <iostream>
#include <string>

#include <raylib/raylib.h>

#include "tictactoe_core.h"

TicTacToeCore TicTacToe;

string help_command = "--help";
string version_command = "--version";

string parameter;

int main(int argc, char** argv)
{
    // No parameters.
    if (argc == 1) {
        TicTacToe.Initializes();
        TicTacToe.Game();
        TicTacToe.DeInitializes();
    } else if (argc == 2) {
        parameter = argv[1];
        
        // Output with "--help" parameter.
        if (parameter == help_command) {
            cout << "Usage:\n\ttictactoe [--version] [--help]\n"
                 << "Report bugs, ideas and other to: "
                 << "<emanuele98@openmailbox.org>.\n";
        // Output with "--version" parameter.
        } else if (parameter == version_command) {
            cout << "TicTacToe v0.1.1\nCopyright (C) 2016 Emanuele Petriglia "
                 << "(LelixSuper)\nLicense MIT: "
                 << "<http://opensource.org/licenses/MIT>.\n";
        }
    // General error (the output is like with "--help").
    } else {
            cerr << "Usage:\n\ttictactoe [--version] [--help]\n"
                 << "Report bugs, ideas and other to: "
                 << "<emanuele98@openmailbox.org>.\n";
    }
    
    return 0;
}
