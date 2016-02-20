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

#ifndef SRC_TICTACTOE_CORE_WINDOW_H
#define SRC_TICTACTOE_CORE_WINDOW_H

#include <raylib/raylib.h>

#include "tictactoe_game.h"
#include "tictactoe_main_window.h"
#include "tictactoe_help_window.h"

class TicTacToeCore {
 private:
    // Costanti
    // -------------------------------------------------------------------------
    
    const int screenWidth = 850; // Larghezza della finestra.
    const int screenHeight = 500; // Altezza della finestra.
    
 public:
    // Metodi
    // -------------------------------------------------------------------------
    
    // It creates the window and set up Raylib and other classes.
    void Initializes();
    
    // Loop principale dove aviene lo svolgimento del gioco.
    void Game();
    
    // Libera la memoria per la chiusura.
    void DeInitializes();
    
 private:
    
    // Gestisce gli aggiornamenti del gioco.
    void Update();
    
    // Gestise il disegno grafico del gioco.
    void Draw();
    
    // Elimina l'istanza di 'TicTacToeGame' puntata da Game_ e crea una nuova
    // istanza per una nuova partita.
    void NewGame();

    // Attributi
    // -------------------------------------------------------------------------
    
    // Istanza che indica la finestra principale.
    TicTacToeMainWindow MainWindow_;
    
    // Istanza che indica la finestra di aiuto.
    TicTacToeHelpWindow HelpWindow_;
    
    // Puntatore che punta ad una istanza di 'TicTacToeGame', che corrisponde al
    // gioco.
    TicTacToeGame *Game_;
    
    // Indica la posizione del mouse, aggiornata nel metodo 'Update()'.
    Vector2 mouse_position;
    
    // Indica le varie finestre del gioco.
    enum GameScreens { MAIN, SETTINGS, HELP } TicTacToeScreen;
};

#endif // SRC_TICTACTOE_CORE_WINDOW_H
