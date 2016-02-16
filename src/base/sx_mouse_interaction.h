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

#ifndef SRC_BASE_SX_MOUSE_INTERACTION_H
#define SRC_BASE_SX_MOUSE_INTERACTION_H

#include <raylib/raylib.h>

class SxMouseInteraction {
 public:
    // Metodi
    // -------------------------------------------------------------------------
    
    // Costruttore.
    // Input:
    //     x_input = posizione x dell'angolo in alto a sinistra;
    //     y_input = posizione y dell'angolo in alto a destra;
    //     height_input = altezza dell'area;
    //     width_input = larghezza dell'area.
    SxMouseInteraction(int x_input, int y_input, int height_input,
                       int width_input);
    
    // Aggiorna l'attributo pressed, che indica se è stato premuto o meno.
    // Input: le coordinate del mouse.
    void Update(Vector2 mouse_position_input);
    
    // Ritorna l'attributo pressed. Se 'vero' l'area c'è stata l'interazione con
    // le coordinate del mouse passate con 'Update()'.
    bool is_pressed() { return pressed_; }
    
    // Ritorna l'attributo dell'area di interazione.
    Rectangle get_area() { return Area_; }
    
 private:
    // Attributi
    // -------------------------------------------------------------------------
    
    // Indica l'area di interazione con il mouse.
    Rectangle Area_;
    
    // Indica se l'area è stata premuta (vero) o no (falso).
    bool pressed_;
};

#endif // SRC_BASE_SX_MOUSE_INTERACTION
