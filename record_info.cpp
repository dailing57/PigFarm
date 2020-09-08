#include "record_info.h"

record::record()
{
    currecord=0;
}
void record:: addrecord(int recordnum0,int circlenum0,int pignum0,double weight0,QString color0,QString state0,int date0)
{
    currecord=currecord+1;
    recordnum<<recordnum0;
    circlenum<<circlenum0;
    pignum<<pignum0;
    weight<<weight0;
    color<<color0;
    state<<state0;
    date<<date0;
}
