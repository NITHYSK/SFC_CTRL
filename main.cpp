/**
 * MAIN.CPP
 */

#include "mbed.h"
#include "BITS.h"

#define DAT D3 //コントローラからの出力 赤
#define PS  D6 //CLKが16週する度に1クロックだけHIGH 橙
#define CLK D7 //黄

Serial pc(USBTX, USBRX);

#include "buttons.h"

DigitalIn  dat(DAT);
DigitalOut ps(PS);
DigitalOut clk(CLK);

unsigned ctrl();

int main()
{
    ps=0;
    clk=0;
    while(1) {
        button_process(ctrl());
        wait(0.2);
    }
}

unsigned ctrl()
{
    unsigned data = 0;

    ps=1;
    clk=1;
    ps=0;
    clk=0;

    for(int i=0; i<16; i++) {
        if(!i) data |= !dat;
        else {
            clk=1;
            clk=0;
            data |= !dat<<i;
        }
    }
    return data;
}
