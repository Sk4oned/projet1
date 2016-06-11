#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <controleur.h>
#include <QLabel>
#include "dialog.h"




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    friend class Dialog;

    explicit MainWindow(Controleur c,QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton_17_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_editingFinished();

    void on_pushButton_22_clicked();

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_lineEdit_5_editingFinished();

    void on_tabWidget_tabBarClicked(int index);

    void on_pushButton_19_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_23_clicked();

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_selectionChanged();

    void on_lineEdit_returnPressed();

    void on_pushButton_45_clicked();

    void on_lineEdit_2_returnPressed();

    void on_pushButton_46_clicked();

    void on_lineEdit_7_returnPressed();

    void on_pushButton_24_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_27_clicked();

    void actualiser();


private:
    Controleur control;
    Ui::MainWindow* ui;



};

#endif // MAINWINDOW_H
