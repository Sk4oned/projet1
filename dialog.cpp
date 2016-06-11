#include "dialog.h"
#include "ui_dialog.h"
#include "controleur.h"
#include "mainwindow.h"

Dialog::Dialog(QWidget *parent, Controleur& control) :
    QDialog(parent), c(control)
{
    ui=new Ui::Dialog;
    ui->setupUi(this);
    ui->lineEdit->setText(c.getchaine());
    c.constructionchaine2("");
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_buttonBox_clicked(QAbstractButton *button)
{
    c.constructionchaine2(ui->lineEdit->text());
    c.checkString();
}
