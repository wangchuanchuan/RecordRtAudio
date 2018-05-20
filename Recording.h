#ifndef RECORDING_H
#define RECORDING_H

#include <QDialog>

#include "Thread.h"

namespace Ui {
class Recording;
}

class Recording : public QDialog
{
    Q_OBJECT

public:
    explicit Recording(QWidget *parent = 0);
    ~Recording();

private slots:
    void on_btnLeftChannel_clicked();

    void on_btnRightChannel_clicked();

    void on_btnSingleChannel_clicked();

    void on_btnStop_clicked();

private:
    Ui::Recording *ui;
    pthread Thread;
};

#endif // RECORDING_H
