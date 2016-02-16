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

#ifndef SRC_TICTACTOE_HELP_WINDOW_H
#define SRC_TICTACTOE_HELP_WINDOW_H

#include <raylib/raylib.h>

#include "base/graphic_element.h"
#include "base/button.h"

class TicTacToeHelpWindow {
 public:
    // Metodi
    // -------------------------------------------------------------------------
    
    // Costruttore che crea gli elementi ma non li inizializza con la raylib.
    TicTacToeHelpWindow();
    
    // Inizializza gli elementi.
    void Initialize();
    
    // Libera dalla memoria gli elementi.
    void DeInitialize();
    
    // Disegna la finestra con gli elementi.
    // Nota: fa parte della fase di disegno.
    void Draw();
    
    // Aggiorna le istanze in base al parametro.
    // Input: la posizione del mouse.
    // Nota: fa parte della fase di aggiornamento.
    void Update(Vector2 mouse_position_input);

    // Restituisce vero se il pulsante è stato premuto.
    bool close_button_is_pressed() { return BackButton_->is_pressed(); }
    
 private:
    // Attributi
    // -------------------------------------------------------------------------
    
    // Puntatore che punta ad una istanza di 'GraphicElement', rappresenta
    // lo sfondo della finestra.
    GraphicElement *Background_;
    
    // Puntatore che punta ad una istanza di 'GraphicElement', rappresenta il
    // testo da mostrare.
    GraphicElement *InfoText_;
    
    // Puntatore che punta ad una istanza di 'Button', in questo caso il
    // pulsante per chiudere la finestra.
    Button *BackButton_;
};

#endif // SRC_TICTACTOE_HELP_WINDOW_H
