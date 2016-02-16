#include "sx_mouse_interaction.h"

SxMouseInteraction::SxMouseInteraction(int x_input, int y_input,
                                       int height_input, int width_input) {
    Area_.x = x_input;
    Area_.y = y_input;
    Area_.height = height_input;
    Area_.width = width_input;
    
    pressed_ = false;
}

void SxMouseInteraction::Update(Vector2 mouse_position_input)
{
    // Verifica se il tasto sinitro del mouse è stato premuto.
    if(IsMouseButtonDown(MOUSE_LEFT_BUTTON) == true) {
        // Verifica la collisione con l'area.
        if(CheckCollisionPointRec(mouse_position_input, Area_)) {
            pressed_ = true;
        } else {
            pressed_ = false;
        }
    } else {
        pressed_ = false;
    }
}
