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

#ifndef SRC_BASE_GRAPHIC_ELEMENT_H
#define SRC_BASE_GRAPHIC_ELEMENT_H

#include <string>

#include <raylib/raylib.h>

using namespace std;

class GraphicElement {
 public:
    // Metodi
    // -------------------------------------------------------------------------
    
    // Costruttore.
    // Input:
    //     x_input = posizione x dell'elemento;
    //     y_input = posizione y dell'elemento;
    //     path_input = percorso dell'immagine.
    //     Color_input = il colore della grafica (mettere WHITE) per default.
    // Nota: la posizione si riferisce all'angolo in alto a sinistra!
    GraphicElement(int x_input, int y_input, string path_input,
                   Color Color_input);
    
    // Costruttore alternativo. Viene usato nel caso l'istanza vari di
    // coordinate e colore. Input:
    //     path_input = il percorso dell'immagine.
    GraphicElement(string path_input);
    
    // Carica l'immagine dell'elemento e lo trasforma in texture.
    // Non restituisce nulla.
    // Nota: usare il metodo solo dopo aver creato la finestra (InitWindow)!
    void Initializes();
    
    // Libera lo spazio occupato dalla texture nella memoria.
    // Non restituisce nulla.
    void DeInitializes();
    
    // Disegna l'elemento in base agli argomenti passati nel costruttore.
    void Show();
    
    // Imposta la posizione dell'elemento grafico.
    // Input: le coordinate x e y dell'elemento.
    void set_position(int x_input, int y_input) { x_ = x_input; y_ = y_input; }
    
    // Imposta il colore dell'elemento grafico.
    // Input: il colore dell'elemento.
    void set_color(Color color_input) { Color_ = color_input; }
    
 private:
    // Attributi
    // -------------------------------------------------------------------------
    
    // Indica il percorso dell'immagine.
    string path_;
    
    // Indica la posizione nelle ascisse dell'angolo in alto a sinistra.
    int x_;
    
    // Indica la posizione nelle coordinate nell'angolo in alto a sinistra.
    int y_;
    
    // La texture dell'elemento.
    Texture2D Texture_;
    
    // Il colore base dell'elemento.
    Color Color_;
};

#endif // SRC_BASE_GRAPHIC_ELEMENT_H
