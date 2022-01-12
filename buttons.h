/**
 * BUTTONS.H
 */

#ifndef BUTTONS_H
#define BUTTONS_H
#include "BITS.h"

enum buttons { B, Y, SELECT, START, UP, DOWN, LEFT, RIGHT, A, X, L, R } but;

void button_process(unsigned button)
{
    //pc.printf("%d \n",button);
    
    for(int i=0; i<16; i++) {
        but = IsMemb(button,i) ? buttons(i) : buttons(-1);
        switch(but) {
            case UP:
                pc.printf("UP\n");
                break;
            case DOWN:
                pc.printf("DOWN\n");
                break;
            case LEFT:
                pc.printf("LEFT\n");
                break;
            case RIGHT:
                pc.printf("RIGHT\n");
                break;
            case A:
                pc.printf("A\n");
                break;
            case B:
                pc.printf("B\n");
                break;
            case X:
                pc.printf("X\n");
                break;
            case Y:
                pc.printf("Y\n");
                break;
        }
    }
}

#endif /* BUTTONS_H */
