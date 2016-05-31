#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controleur.h"
#include <QString>
#include "expression.h"

using namespace Exp;

MainWindow::MainWindow(Controleur c,QWidget *parent) : control(c),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_17_clicked()
{
    close();
}

void MainWindow::on_pushButton_clicked()
{

    QString a="1";
    control.contructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
}

void MainWindow::on_pushButton_2_clicked()
{
    QString a="2";
    control.contructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
}

void MainWindow::on_pushButton_6_clicked()
{
    QString a="3";
    control.contructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
}



void MainWindow::on_pushButton_3_clicked()
{
    QString a="4";
    control.contructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
}

void MainWindow::on_pushButton_5_clicked()
{
    QString a="5";
    control.contructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
}

void MainWindow::on_pushButton_7_clicked()
{
    QString a="6";
    control.contructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
}



void MainWindow::on_pushButton_4_clicked()
{
    QString a="7";
    control.contructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
}

void MainWindow::on_pushButton_8_clicked()
{
    QString a="8";
    control.contructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
}

void MainWindow::on_pushButton_9_clicked()
{
    QString a="9";
    control.contructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
}

void MainWindow::on_pushButton_10_clicked()
{
    QString a="0";
    control.contructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
}

void MainWindow::on_pushButton_14_clicked()
{
    try{
    control.plus();
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
    }catch(Exp::PileException& a)
    {
        ui->textEdit_2->append(a.affiche());
    }
}



void MainWindow::on_pushButton_16_clicked()
{
    control.checkString();
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
}

void MainWindow::on_pushButton_18_clicked()
{
    QString a=".";
    control.contructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
}

void MainWindow::on_pushButton_13_clicked()
{
    try{
    control.moins();
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
    }catch(Exp::PileException& a)
    {
        ui->textEdit_2->append(a.affiche());
    }
}

void MainWindow::on_pushButton_11_clicked()
{
    try{
    control.diviser();
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
    }catch(Exp::PileException& a)
    {
        ui->textEdit_2->append(a.affiche());
    }
}
