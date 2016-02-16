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

#ifndef SRC_TICTACTOE_TRACE_H
#define SRC_TICTACTOE_TRACE_H

#include <raylib/raylib.h>

#include "base/graphic_element.h"
#include "tictactoe_game.h"

// Colori dei due segni.
#define XMARK (Color){ 255, 15, 1, 255 }
#define OMARK (Color){ 2, 93, 226, 255 }

class TicTacToeTrace {
 private:

    // È un array che contiene le posizioni X e Y delle traccie da disegnare.
    static const Vector2 trace_position[9];
    
 public:
    
    // Metodi
    // -------------------------------------------------------------------------
    
    // Costruttore.
    TicTacToeTrace();
    
    // Imposta l'istanza da dove prendere i dati.
    // Input: una istanza di TicTacToeGame.
    void SetCore(TicTacToeGame *Game_input);
    
    // Inizializza gli elementi grafici.
    void Initialize();
    
    // Deinizializza gli elementi grafici.
    void DeInitialize();
    
    // Aggiorna lo stato e prepara i membri per il metodo 'Draw'.
    void Update();
    
    // Disegna le traccie in base ai dati di TicTacToeGame.
    void Draw();
    
 private:

    // Attributi
    // -------------------------------------------------------------------------
    
    // Elementi grafici delle traccie:
    //     0 - indica la traccia orrizontale;
    //     1 - indica la traccia verticale;
    //     2 - indica la traccia della prima diagonale;
    //     3 - indica la traccia della seconda diagonale.
    GraphicElement *Trace_[4];
    
    // Indica l'istanza da dove prendere i dati; in questo caso il valore
    // restituito da TicTacToeGame::WhereHeWon().
    TicTacToeGame *Game_;
    
    // Attributo dove si salva il valore restitutito da WhereHeWon().
    unsigned short int trace_;
    
    // Contatore usato nei cicli.
    unsigned short int counter_;
    
    // Indica il colore della traccia.
    Color trace_color_;
};

#endif // SRC_TICTACTOE_TRACE_H
