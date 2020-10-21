#include "record_info.h"
#include <QTime>


record::record()
{
    currecord=0;
    currecord0=0;
}

void record:: addrecord(int recordnum0,int circlenum0,int pignum0,double weight0,QString color0,QString state0,int date0)
{
    haverec++;
    currecord=currecord+1;
    recordnum<<recordnum0;
    circlenum<<circlenum0;
    pignum<<pignum0;
    weight<<weight0;
    color<<color0;
    state<<state0;
    date<<date0;
}

void record:: addrecordv(int recordnum0,int circlenum0,int pignum0,double weight0,QString color0,QString state0,int date0)
{
    currecord0=currecord0+1;
    recordnum<<recordnum0;
    circlenum<<circlenum0;
    pignum<<pignum0;
    weight<<weight0;
    color<<color0;
    infected<<state0;
    date<<date0;
}

void record:: clear()
{
    currecord=0;
    currecord0=0;
    recordnum.clear();
    circlenum.clear();
    date.clear();
    weight.clear();
    infected.clear();
    color.clear();
    pignum.clear();
    state.clear();
}
