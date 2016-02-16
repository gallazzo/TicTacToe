#include "graphic_element.h"

GraphicElement::GraphicElement(int x_input, int y_input,
                               string path_input, Color Color_input) {
    x_ = x_input;
    y_ = y_input;
    path_ = path_input;
    Color_ = Color_input;
}

GraphicElement::GraphicElement(string path_input)
{
    path_ = path_input;
}

void GraphicElement::Initializes()
{
    Texture_ = LoadTexture(path_.c_str());
}

void GraphicElement::DeInitializes()
{
    UnloadTexture(Texture_);
}

void GraphicElement::Show()
{
    DrawTexture(Texture_, x_, y_, Color_);
}
