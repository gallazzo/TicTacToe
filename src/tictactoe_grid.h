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

#ifndef SRC_TICTACTOE_GRID_H
#define SRC_TICTACTOE_GRID_H

#include <raylib/raylib.h>

#include "tictactoe_game.h"
#include "tictactoe_trace.h"

#include "base/sx_mouse_interaction.h"
#include "base/graphic_element.h"

class TicTacToeGrid {
 public:
    // Metodi
    // -------------------------------------------------------------------------
    
    // Costruttore.
    // Punta i puntatori creando le istanze.
    TicTacToeGrid();
    
    // Imposta l'istanza di 'TicTacToeCore' da dove prendere ed immettere i
    // dati.
    // Input: u'istanza di 'TicTacToeCore'.
    void SetGame(TicTacToeGame *Game_input);
    
    // Inizializza le texture.
    void Initialize();
    
    // Libera la memoria dalle texture.
    void DeInitialize();
    
    // Disegna la griglia ed il suo contenuto.
    // Fa parte della fase di disegno.
    void Draw();
    
    // Aggiorna la griglia in base alla posizioe del mouse.
    // Input: la posizione del mouse.
    // Nota: fase di input.
    void Update(Vector2 mouse_position_input);
    
 private:
    
    // Attributi
    // -------------------------------------------------------------------------
    
    // Puntatore che punta ad una istanza di TicTacToeCore, da dove prende ed
    // immette i dati.
    TicTacToeGame *Game_;
    
    // Puntatore che punta ad una istanza di un elmento grafico, in questo caso
    // la griglia.
    GraphicElement *Grid_;
    
    // Puntatori che punta ad ogni aree di interazione (rettangoli)
    // nella griglia. La numerazione corrisponde a quella logica della griglia:
    //     0 | 1 | 2
    //     ---------
    //     3 | 4 | 5
    //     ---------
    //     6 | 7 | 8
    // Usata nell'input.
    SxMouseInteraction *InteractionBox_[9];
    
    // Indicano le coordinate logiche della griglia, sono numerate in accordo
    // a InteractionBox_ e Mark_.
    // Usata sia per il disegno che per l'input.
    Coordinate CellsPosition_[9];
    
    // Indica l'angolo (x, y) di ogni cella.
    // Usata per il disegno.
    Vector2 texture_angle_[9];
    
    // Simbolo 'X' con le sue varianti.
    Texture2D x_mark_[4];
    
    // Simbolo 'O' con le sue varianti.
    Texture2D o_mark_[4];
    
    // Indica il numero che identifica la variante dei simboli
    // che ci sono nelle celle della griglia.
    unsigned short int grid_mark_[9];
    
    // Puntatore che punta ad una istanza di TicTacToeTrace, la classe che
    // gestisce la traccie grafiche della vittoria.
    TicTacToeTrace *Trace_;
    
    // Usata nei cicli.
    unsigned short int counter_;
};

#endif // SRC_TICTACTOE_GRID_H
