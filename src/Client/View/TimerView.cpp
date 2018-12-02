#include "TimerView.h"
#include <Area.h>

// TimerView::TimerView(SDL_Renderer *renderer, int number_steps) :
TimerView::TimerView(const SdlWindow &window, int number_steps) :
    renderer(window.getRenderer()),
    actual_position(0),
    actual_step(0),
    number_steps(number_steps),
    remaining_steps(number_steps) {}

TimerView::~TimerView() {}
#include <iostream>

void TimerView::render(const Area &dest,int complete_percentage) {
    SDL_Rect rectangle;
    rectangle.x = dest.getX();
    rectangle.y = dest.getY();
    rectangle.w = dest.getWidth();
    rectangle.h = dest.getHeight();

    actual_position = complete_percentage / (100/POS_Q);
    if (actual_position >= POS_Q)
        actual_position = POS_Q - 1;
    SDL_RenderDrawRect(renderer, &rectangle);
    SDL_RenderDrawLine(renderer,
                       dest.getX() + dest.getWidth() / 2,
                       dest.getY() + dest.getHeight() / 2,
                       dest.getX() + dest.getWidth()*x_pos[actual_position] / factor,
                       dest.getY() + dest.getHeight()*y_pos[actual_position] / factor);

}
