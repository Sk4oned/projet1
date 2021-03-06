#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controleur.h"
#include <QString>
#include <QStringList>
#include <QStringListModel>
#include <QDialog>
#include <QStandardItem>
#include <QPlainTextEdit>
#include "fraction.h"
#include "atome.h"
#include <windows.h>
#include "dialog.h"
#include "ui_dialog.h"


MainWindow::MainWindow(Controleur c,QWidget *parent) : control(c),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    control.chargePile();
    control.chargeVarEtProg();

    if(control.getBipStatut()==true)
    {
        ui->pushButton_27->setText("Activer");
    }
    else
    {
        ui->pushButton_27->setText("Désactiver");
    }

    if(control.getClavierStatut()==true)
    {
      ui->gridLayoutWidget->show();
    }
    else
    {
        ui->gridLayoutWidget->hide();
    }

    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit->setReadOnly(true);
    ui->textEdit_2->setReadOnly(true);
    //ui->lineEdit->setReadOnly(true);
    ui->lineEdit->backspace();




    //QTABLEVIEW-VARIABLE
    QStringList nomColonne;
    nomColonne << "Nom" << "Valeur";
    QStandardItemModel* modele= new QStandardItemModel(1,2);
    modele->setHorizontalHeaderLabels(nomColonne);
    ui->tableView->setModel(modele);

    //QTABLEVIEW-PROGRAMME
    QStringList nomColonne2;
    nomColonne << "Nom" << "Implémentation";
    QStandardItemModel* modele2= new QStandardItemModel(1,2);
    modele2->setHorizontalHeaderLabels(nomColonne2);
    ui->tableView_2->setModel(modele2);


}

MainWindow::~MainWindow()
{
    control.clear();
    delete ui;
}

void MainWindow::on_pushButton_17_clicked()
{
    control.enregistrePile();
    control.enregistreVarEtProg();
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
        control.Bip();
    }
    catch(Exp::FractionException& a)
    {
        ui->textEdit_2->append(a.affiche());
        control.Bip();
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
        control.Bip();
    }
    catch(Exp::FractionException& a)
    {
        ui->textEdit_2->append(a.affiche());
        control.Bip();
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
        control.Bip();
    }
    catch(Exp::FractionException& a)
    {
        ui->textEdit_2->append(a.affiche());
        control.Bip();
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
        control.Bip();
    }
    catch(Exp::FractionException& a)
    {
        ui->textEdit_2->append(a.affiche());
        control.Bip();
    }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    try{
        if(!arg1.isEmpty())
        {

            if(arg1[0]!='[' && arg1[0]!='\'')
            {

                if(control.getchaine()=="EDIT")
                {
                    ui->textEdit->clear();
                    ui->textEdit_2->clear();
                    ui->lineEdit->clear();
                    on_lineEdit_editingFinished();
                }
                else if(arg1.contains('+') || arg1.contains('-') || arg1.contains('*') || arg1.contains('/'))
                {
                    if(arg1.contains('/'))
                    {
                        control.constructionchaine2("[ " + arg1 + " ]");
                        control.checkString();
                        control.evaluer();
                        ui->textEdit_2->clear();
                        ui->textEdit_2->append(control.affiche2());
                        ui->textEdit->clear();
                        ui->textEdit->append(control.affiche());
                        ui->lineEdit->clear();
                    }
                    else
                    {
                        control.constructionchaine2("[ " + arg1 + "]");
                        control.checkString();
                        control.evaluer();
                        ui->textEdit_2->clear();
                        ui->textEdit_2->append(control.affiche2());
                        ui->textEdit->clear();
                        ui->textEdit->append(control.affiche());
                        ui->lineEdit->clear();
                    }


                }
                else
                {
                    control.constructionchaine2(arg1);
                    ui->textEdit_2->clear();
                    ui->textEdit_2->append(control.affiche2());
                }
            }
            else
            {
                control.constructionchaine2(arg1);
                ui->textEdit_2->clear();
                ui->textEdit_2->append(control.affiche2());
            }
        }

    }catch(Exp::PileException& a)
    {
        ui->textEdit_2->append(a.affiche());
        control.Bip();
    }
    catch(Exp::FractionException& a)
    {
        ui->textEdit_2->append(a.affiche());
        control.Bip();
    }
}

void MainWindow::on_lineEdit_editingFinished()
{   if(control.chaineIsValide())
    {
        try{

            if(control.getchaine()=="EDIT")
            {

                Dialog* dialog=new Dialog(this,control);
                dialog->show();
                ui->textEdit->clear();
                ui->textEdit_2->clear();
                control.constructionchaine2("");

            }
            ui->textEdit->clear();
            ui->textEdit->append(control.affiche());
            ui->textEdit_2->clear();
            ui->textEdit_2->append(control.affiche2());
            ui->lineEdit->setText(control.affiche2());


        }catch(Exp::PileException& a)
        {
            ui->textEdit_2->append(a.affiche());
            control.Bip();
        }
        catch(Exp::FractionException& a)
        {
            ui->textEdit_2->append(a.affiche());
            control.Bip();
        }
    }
}

void MainWindow::actualiser()
{
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
    ui->lineEdit->setText(control.affiche2());
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

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    ui->lineEdit_2->clear();
    ui->textEdit->clear();
    ui->textEdit->append(control.affiche());
    ui->textEdit_2->clear();
    ui->textEdit_2->append(control.affiche2());
    ui->lineEdit->setText(control.affiche2());


    //AFFICHAGE VALEUR

    QStandardItemModel* modele= new QStandardItemModel(1,2);
    QStringList nomColonne;
    nomColonne << "Nom" << "Valeur";
    modele->setHorizontalHeaderLabels(nomColonne);

    QString colonneNom;
    QString colonneValeur;

    QStringList LigneVariable = control.afficheVariable().split("\n");

    for(int i=0; i<LigneVariable.size()-1; i++)
    {
        QStringList Variable = LigneVariable[i].split(" : ");

        for(int j=0; j<Variable.size(); j++)
        {
            colonneNom= Variable[0];
            colonneValeur= Variable[1];

            QStandardItem* item1= new QStandardItem(colonneNom);
            QStandardItem* item2= new QStandardItem(colonneValeur);

            modele->setItem(i,0,item1);
            modele->setItem(i,1,item2);

        }

    }

    ui->tableView->setModel(modele);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();


    //AFFICHAGE Programme

    QStandardItemModel* modele2= new QStandardItemModel(1,2);
    QStringList nomColonne2;
    nomColonne2 << "Nom" << "Programme";
    modele2->setHorizontalHeaderLabels(nomColonne2);

    QString colonneNom2;
    QString colonneProgramme;

    QStringList LigneNom2 = control.afficheNomProgramme().split("\n");
    QStringList LigneProgramme = control.afficheProgramme().split("\n");

    for(int i=0; i<LigneNom2.size()-1; i++)
    {

            colonneNom2= LigneNom2[i];
            colonneProgramme= LigneProgramme[i];

            QStandardItem* item11= new QStandardItem(colonneNom2);
            QStandardItem* item22= new QStandardItem(colonneProgramme);

            modele2->setItem(i,0,item11);
            modele2->setItem(i,1,item22);



    }

    ui->tableView_2->setModel(modele2);
    ui->tableView_2->resizeRowsToContents();
    ui->tableView_2->resizeColumnsToContents();


    //ui->textEdit_3->setReadOnly(true);
}

void MainWindow::on_pushButton_19_clicked()
{

}

void MainWindow::on_pushButton_15_clicked()
{
    ui->gridLayoutWidget->show();
    control.changeClavierStatut(true);
}

void MainWindow::on_pushButton_23_clicked()
{
    ui->gridLayoutWidget->hide();
    control.changeClavierStatut(false);

}

void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    ui->lineEdit->cursorForward(true,arg1);
    ui->lineEdit->deselect();
}

void MainWindow::on_lineEdit_selectionChanged()
{
    ui->lineEdit->deselect();
}

void MainWindow::on_lineEdit_returnPressed()
{
    control.checkString();
    actualiser();
}

void MainWindow::on_pushButton_45_clicked()
{
    try{

        if(ui->lineEdit_2->text().isEmpty() || ui->lineEdit_13->text().isEmpty())
        {
            throw PileException("REMPLISSEZ TOUT LES CHAMPS!");
        }
        else
        {
            ui->textEdit_3->clear();
            QString nom=ui->lineEdit_13->text();
            QString valeur=ui->lineEdit_2->text();

            QString variable = valeur + " " + nom + " STO";
            control.constructionchaine2(variable);
            control.checkString();
            ui->lineEdit_2->clear();
            ui->lineEdit_13->clear();
            on_tabWidget_tabBarClicked(1);
            ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        }

    }catch(Exp::PileException& a)
    {
        ui->textEdit_3->clear();
        ui->textEdit_3->append(a.affiche());
        control.Bip();
    }
    catch(Exp::FractionException& a)
    {
        ui->textEdit_3->clear();
        ui->textEdit_3->append(a.affiche());
        control.Bip();
    }
}

void MainWindow::on_lineEdit_2_returnPressed()
{
    on_pushButton_45_clicked();
}

void MainWindow::on_pushButton_46_clicked()
{
    try{

        if(ui->lineEdit_14->text().isEmpty() || ui->lineEdit_7->text().isEmpty())
        {
            throw PileException("REMPLISSEZ TOUT LES CHAMPS!");
        }
        else
        {
            ui->textEdit_5->clear();
            QString nom=ui->lineEdit_14->text();
            QString implementation=ui->lineEdit_7->text();

            QString variable = implementation + " " + nom + " STO";
            control.constructionchaine2(variable);
            control.checkString();
            ui->lineEdit_14->clear();
            ui->lineEdit_7->clear();
            on_tabWidget_tabBarClicked(1);
            ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
        }

    }catch(Exp::PileException& a)
    {
        ui->textEdit_5->clear();
        ui->textEdit_5->append(a.affiche());
        control.Bip();
    }
    catch(Exp::FractionException& a)
    {
        ui->textEdit_5->clear();
        ui->textEdit_5->append(a.affiche());
        control.Bip();
    }
}

void MainWindow::on_lineEdit_7_returnPressed()
{
    on_pushButton_46_clicked();
}

void MainWindow::on_pushButton_24_clicked()
{
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    QItemSelectionModel * selection2 = ui->tableView->selectionModel();
    QModelIndexList current2 = selection2->selectedRows();

    QVariant data = ui->tableView->model()->data(current2[0]);
    QString text = data.toString();

    control.supprVariable(text);
    on_tabWidget_tabBarClicked(1);

}

void MainWindow::on_pushButton_26_clicked()
{
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    QItemSelectionModel * selection = ui->tableView_2->selectionModel();
    QModelIndexList current = selection->selectedRows();



    QVariant data = ui->tableView_2->model()->data(current[0]);
    QString text = data.toString();

    control.supprProgramme(text);
    on_tabWidget_tabBarClicked(1);
}

void MainWindow::on_pushButton_21_clicked()
{
        QItemSelectionModel * selection2 = ui->tableView->selectionModel();
        int row = selection2->currentIndex().row();
        QModelIndexList current2 = selection2->selectedRows(0);
        QModelIndexList current3 = selection2->selectedRows(1);




        QVariant data = ui->tableView->model()->data(current2[0]);
        QString text = data.toString();
        QVariant data2 = ui->tableView->model()->data(current3[0]);
        QString text2 = data2.toString();



        ui->lineEdit_13->setText(text);
        ui->lineEdit_2->setText(text2);
        control.supprVariable(text);


}

void MainWindow::on_pushButton_25_clicked()
{
    QItemSelectionModel * selection2 = ui->tableView_2->selectionModel();
    int row = selection2->currentIndex().row();
    QModelIndexList current2 = selection2->selectedRows(0);
    QModelIndexList current3 = selection2->selectedRows(1);




    QVariant data = ui->tableView_2->model()->data(current2[0]);
    QString text = data.toString();
    QVariant data2 = ui->tableView_2->model()->data(current3[0]);
    QString text2 = data2.toString();



    ui->lineEdit_14->setText(text);
    ui->lineEdit_7->setText(text2);
    control.supprProgramme(text);
}

void MainWindow::on_pushButton_27_clicked()
{
    control.changeBeepStatut();
    if(ui->pushButton_27->text()=="Désactiver")
    {
        ui->pushButton_27->setText("Activer");
    }
    else if(ui->pushButton_27->text()=="Activer")
    {
        ui->pushButton_27->setText("Désactiver");
    }

}


