#include "TimerView.h"
#include "../../Common/Area.h"

// TimerView::TimerView(SDL_Renderer *renderer, int number_steps) :
TimerView::TimerView(const SdlWindow &window, int number_steps) :
    renderer(window.getRenderer()),
    actual_position(0),
    actual_step(0),
    number_steps(number_steps) {}

TimerView::~TimerView() {}

void TimerView::render(const Area &dest) {
    SDL_Rect rectangle;
    rectangle.x = dest.getX();
    rectangle.y = dest.getY();
    rectangle.w = dest.getWidth();
    rectangle.h = dest.getHeight();

    SDL_RenderDrawRect(renderer, &rectangle);
    SDL_RenderDrawLine(renderer,
                       dest.getX() + dest.getWidth() / 2,
                       dest.getY() + dest.getHeight() / 2,
                       dest.getX() + dest.getWidth()*x_pos[actual_position] / factor,
                       dest.getY() + dest.getHeight()*y_pos[actual_position] / factor);

    if (++actual_step == number_steps / POS_Q) {
        actual_step = 0;
        if (++actual_position == POS_Q) {
            actual_position = 0;
        }
    }
}