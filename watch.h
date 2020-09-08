#ifndef WATCH_H
#define WATCH_H

#include "buy.h"
namespace Ui {
class watch;
}

class watch : public QWidget
{
    Q_OBJECT

public:
    explicit watch(QWidget *parent = nullptr);
    ~watch();

private slots:
    void on_lineEdit_editingFinished();

private:
    Ui::watch *ui;
};

#endif // WATCH_H
