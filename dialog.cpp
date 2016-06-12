#include "dialog.h"
#include "ui_dialog.h"
#include "controleur.h"
#include "mainwindow.h"
#include "fraction.h"
#include "pile.h"

Dialog::Dialog(QWidget *parent, Controleur& control) :
    QDialog(parent), c(control)
{
    ui=new Ui::Dialog;
    ui->setupUi(this);
    ui->lineEdit->setText(c.top());
    c.constructionchaine2("");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    try{


        c.drop();
        c.constructionchaine2(ui->lineEdit->text());
        int i =c.getchaine().size()-1;
        if(c.getchaine()[0]=='[' && c.getchaine()[i]==']')
        {
            c.checkString();
            close();
        }
        else
        {
            throw PileException("Veuillez mettre [ au début et ] à la fin de votre programme");
        }

    }catch(Exp::PileException& a)
    {
        ui->lineEdit_2->clear();
        ui->lineEdit_2->setText(a.affiche());
        c.Bip();
    }
    catch(Exp::FractionException& a)
    {
        ui->lineEdit_2->clear();
        ui->lineEdit_2->setText(a.affiche());
        c.Bip();
    }
}

void Dialog::on_pushButton_2_clicked()
{
    close();
}
