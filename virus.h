#ifndef VIRUS_H
#define VIRUS_H

#include "watch.h"

namespace Ui {
class virus;
}
extern bool vis[100][10],vis0[100];
extern Pigclass:: pig tmp;
extern int infect;
extern bool sa;
class virus : public QWidget
{
    Q_OBJECT

public:
    explicit virus(QWidget *parent = nullptr);
    ~virus();
    void changed();
private:
    Ui::virus *ui;
};

#endif // VIRUS_H
