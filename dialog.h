#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "controleur.h"
#include <QAbstractButton>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    explicit Dialog(QWidget *parent, Controleur& control);
    ~Dialog();

signals:

    void on_buttonBox_accepted();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    Controleur c;
};

#endif // DIALOG_H
