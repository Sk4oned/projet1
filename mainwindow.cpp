#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controleur.h"
#include <QString>
#include <QDialog>
#include "fraction.h"

MainWindow::MainWindow(Controleur c,QWidget *parent) : control(c),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    control.clear();
    delete ui;
}

void MainWindow::on_pushButton_17_clicked()
{
    control.enregistrePile();
    close();
}

void MainWindow::on_pushButton_clicked()
{

    QString a="1";
    control.constructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
    ui->lineEdit->setText(control.affiche2());
}

void MainWindow::on_pushButton_2_clicked()
{
    QString a="2";
    control.constructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
    ui->lineEdit->setText(control.affiche2());
}

void MainWindow::on_pushButton_6_clicked()
{
    QString a="3";
    control.constructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
    ui->lineEdit->setText(control.affiche2());
}



void MainWindow::on_pushButton_3_clicked()
{
    QString a="4";
    control.constructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
    ui->lineEdit->setText(control.affiche2());
}

void MainWindow::on_pushButton_5_clicked()
{
    QString a="5";
    control.constructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
    ui->lineEdit->setText(control.affiche2());
}

void MainWindow::on_pushButton_7_clicked()
{
    QString a="6";
    control.constructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
    ui->lineEdit->setText(control.affiche2());
}



void MainWindow::on_pushButton_4_clicked()
{
    QString a="7";
    control.constructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
    ui->lineEdit->setText(control.affiche2());
}

void MainWindow::on_pushButton_8_clicked()
{
    QString a="8";
    control.constructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
    ui->lineEdit->setText(control.affiche2());
}

void MainWindow::on_pushButton_9_clicked()
{
    QString a="9";
    control.constructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
    ui->lineEdit->setText(control.affiche2());
}

void MainWindow::on_pushButton_10_clicked()
{
    QString a="0";
    control.constructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
    ui->lineEdit->setText(control.affiche2());
}

void MainWindow::on_pushButton_14_clicked()
{
    try{
    control.plus();
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
    ui->lineEdit->setText(control.affiche2());
    }catch(Exp::PileException& a)
    {
        ui->textEdit_2->append(a.affiche());
    }
    catch(Exp::FractionException& a)
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
    ui->lineEdit->setText(control.affiche2());
}

void MainWindow::on_pushButton_18_clicked()
{
    QString a=".";
    control.constructionchaine(a);
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
    ui->lineEdit->setText(control.affiche2());
}

void MainWindow::on_pushButton_13_clicked()
{
    try{
    control.moins();
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
    ui->lineEdit->setText(control.affiche2());
    }catch(Exp::PileException& a)
    {
        ui->textEdit_2->append(a.affiche());
    }
    catch(Exp::FractionException& a)
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
    ui->lineEdit->setText(control.affiche2());
    }catch(Exp::PileException& a)
    {
        ui->textEdit_2->append(a.affiche());
    }
    catch(Exp::FractionException& a)
    {
        ui->textEdit_2->append(a.affiche());
    }

}

void MainWindow::on_pushButton_12_clicked()
{
    try{
    control.multiplier();
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
    ui->lineEdit->setText(control.affiche2());
    }catch(Exp::PileException& a)
    {
        ui->textEdit_2->append(a.affiche());
    }
    catch(Exp::FractionException& a)
    {
        ui->textEdit_2->append(a.affiche());
    }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    try{

    control.constructionchaine2(arg1);
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());

    }catch(Exp::PileException& a)
    {
        ui->textEdit_2->append(a.affiche());
    }
    catch(Exp::FractionException& a)
    {
        ui->textEdit_2->append(a.affiche());
    }
}

void MainWindow::on_lineEdit_editingFinished()
{   if(control.chaineIsValide())
    {
        try{


        control.checkString();
        ui->textEdit->clear();
        ui->textEdit->append(control.affiche());
        ui->textEdit_2->clear();
        ui->textEdit_2->append(control.affiche2());
        ui->lineEdit->setText(control.affiche2());

        }catch(Exp::PileException& a)
        {
            ui->textEdit_2->append(a.affiche());
        }
        catch(Exp::FractionException& a)
        {
            ui->textEdit_2->append(a.affiche());
        }
    }
}


void MainWindow::on_pushButton_22_clicked()
{
    if(ui->gridLayoutWidget->isHidden()== true)
    {
        ui->gridLayoutWidget->show();
    }
    else
    {
        ui->gridLayoutWidget->hide();

    }

}

void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)
{
    if(arg1!="")
    {
        control.ChangeNombrePileAffiche(arg1.toInt());
    }


}

void MainWindow::on_lineEdit_5_editingFinished()
{
    ui->lineEdit_5->clear();
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
}

void MainWindow::on_pushButton_21_clicked()
{

    control.creerProgramme(ui->lineEdit_3->text(),ui->lineEdit_6->text());
    ui->textEdit_4->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_3->clear();
    ui->textEdit_4->append(control.afficheNomProgramme());
    ui->textEdit_6->append(control.afficheProgramme());
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    ui->lineEdit_2->clear();
    ui->textEdit_3->clear();
    ui->textEdit_3->append(control.afficheVariable());
    ui->textEdit_3->setReadOnly(true);
}

void MainWindow::on_pushButton_19_clicked()
{

}

void MainWindow::on_spinBox_valueChanged(const QString &arg1)
{
    ui->spinBox->setSuffix(control.afficheVariable());

}
