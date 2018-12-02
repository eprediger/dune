#ifndef __TIMERVIEW_H__
#define __TIMERVIEW_H__

// #include <SDL_render.h>
#include "SdlWindow.h"
#include <Area.h>

#define POS_Q 30
#define FACTOR 10

#define X_POSITIONS { \
5, 6, 7, 8, 9,10,10,10,10,10, \
10, 9, 8, 7, 6, 5, 4, 3, 2, 1,\
0, 0, 0, 0, 0, 0, 1, 2, 3, 4}

#define Y_POSITIONS { \
0, 0, 0, 0, 0, 0, 2, 4, 6, 8, \
10,10,10,10,10,10,10,10,10,10,\
10, 8, 6, 4, 2, 0, 0, 0, 0, 0}

class TimerView {
public:
    TimerView(const SdlWindow &window, int number_steps);
    // TimerView(SDL_Renderer *renderer, int number_steps);

    ~TimerView();

    void render(const Area &dest, int complete_percentage);

private:
    SDL_Renderer* renderer;
    int actual_position;
    int actual_step;
    const int number_steps;
    int remaining_steps;
    const int x_pos[POS_Q] = X_POSITIONS;
    const int y_pos[POS_Q] = Y_POSITIONS;
    const int factor = FACTOR;
};

#endif //DUNE_TIMERVIEW_H
