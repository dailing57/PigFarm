#ifndef RECORDS_H
#define RECORDS_H

#include <QList>
class records
{
public:
    records();
    int currecord;
    QList<int> recordnum,circlenum,pignum,date;
    QList<double> weight;
    QList<QString> color,state;
    void addrecord(int recordnum,int circlenum,int pignum,double weight,QString color,QString state,int date);
};

#endif // RECORDS_H
