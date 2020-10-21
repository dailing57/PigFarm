#include "pig_info.h"

void Pigclass:: addpig(int circle_num, QString c, double w)
{
    pig* ptr = new pig(c, w);
    ptr->num = circles[circle_num].sum_pig;
    if (circles[circle_num].sum_pig == 0)
    {
        circles[circle_num].head = ptr;
    }
    else
    {
        pig* cur = circles[circle_num].head;
        pig* nxt = circles[circle_num].head->next;
        while (nxt != NULL)
        {
            cur = nxt;
            nxt = nxt->next;
        }
        cur->next = ptr;
    }
    circles[circle_num].sum_pig++;
}

void Pigclass:: subpig(int circle_num,int pig_num)
{
    if (pig_num == 0)
    {
        circles[circle_num].head = circles[circle_num].head->next;
        circles[circle_num].sum_pig--;
    }
    else
    {
        pig* ptr = circles[circle_num].head;
        for (int i = 0; i < pig_num-1; i++)
        {
            if (ptr->next != NULL)
                ptr = ptr->next;
            else
            {
                //cout << "there's no such a pig" << endl;
                return;
            }
        }
        ptr->next = ptr->next->next;
        ptr = ptr->next;
        while(ptr!=NULL)
        {
            ptr->num--;
            ptr=ptr->next;
        }
        circles[circle_num].sum_pig--;
    }
}

void Pigclass:: grow()
{
    for(int i=0;i<100;i++)
    {
        pig * pigptr = circles[i].head;
        while(pigptr != NULL)
        {
            double d = qrand()%13;
            d/=10;
            pigptr->weight+=d;
            pigptr = pigptr->next;
        }
    }
}

Pigclass::pig Pigclass:: n_circle_m_pig(int n,int m)
{
    pig *t = circles[n].head;
    for(int i=0; i<m;i++)
    {
        t=t->next;
    }
    pig tmp;
    tmp.num=t->num;
    tmp.color=t->color;
    tmp.weight=t->weight;
    return tmp;
}

int Pigclass:: getsum()
{
    int res=0;
    for(int i=0;i<100;i++)
        res+=circles[i].sum_pig;
    return res;
}

double Pigclass:: pigval(QString c,double w)
{
    double sval;
    if(c=="黑")
        sval=15;
    if(c=="白")
        sval=6;
    else
        sval=7;
    return w*sval;
}

Pigclass::Pigclass()
{

}
