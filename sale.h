#ifndef SALE_H
#define SALE_H

#include <QWidget>
#include "buy.h"

namespace Ui {
class sale;
}

class sale : public QWidget
{
    Q_OBJECT

public:
    explicit sale(QWidget *parent = nullptr);
    ~sale();

    int circlenum=-1, pignum=-1;
    int safe = 0;
protected:
    void closeEvent(QCloseEvent*event);
private slots:
    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_pushButton_clicked();
private:
    Ui::sale *ui;
};

#endif // SALE_H
