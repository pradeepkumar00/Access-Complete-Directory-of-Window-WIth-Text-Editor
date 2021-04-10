#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDir>
#include<QDebug>
#include<QMessageBox>
#include<QDateTime>
QString g="C:/";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
//ui->listWidget->addItem(item);
{
    ui->setupUi(this);
    //if(dir.exists()){
    //    QMessageBox::information(this,"My app","True");
    //}
    //else{
    //    QMessageBox::information(this,"My app","False");
    //}
    QString f="C:/";
    QDir dir(f);
    MainWindow::open_dir(dir);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(t_function()));
    timer->start(1000);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::open_dir(QDir S){
    //foreach (QFileInfo var,dir.drives()){
     ui->comboBox->addItem(S.absolutePath());
    foreach(QFileInfo var,S.entryInfoList()){
        if(var.isDir()){
            QString name = var.absoluteFilePath();
                ui->listWidget->addItem(name);
        }
        if(var.isFile()){
            QString name = var.absoluteFilePath();
            ui->listWidget->addItem(name);
        }
    }
}
void MainWindow::on_pushButton_clicked()
{
    g=ui->listWidget->currentItem()->text();
    QDir dir_2(g);
    if(dir_2.exists()){
        while(ui->listWidget->count()!=0){
            delete ui->listWidget->takeItem(ui->listWidget->count()-1);
        }
        MainWindow::open_dir(g);
    }
    else{
        secdialog = new Dialog(this);
        secdialog->show();
        secdialog->setText(g);
        //secdialog->setTextL2("vector[1]");
        //secdialog->setTextL3("vector[1]");
        //secdialog->lineEdit("vector[1]");

    }
}
void MainWindow::on_pushButton_2_clicked()
{
    if(g=="C:/"){
        QMessageBox::warning(this,"Warning","You are already in home page");
    }else{
        QString d=g+"/../";
        QDir dir(d);
        g=dir.absolutePath();
        while(ui->listWidget->count()!=0){
            delete ui->listWidget->takeItem(ui->listWidget->count()-1);
        }
        MainWindow::open_dir(dir);
    }
}
void MainWindow::on_pushButton_1_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_4_clicked()
{
    QString p=ui->lineEdit->text();
    QDir dir(g+"/"+p);
    if(dir.exists()){
        QMessageBox::warning(this,"Warning","Please change directory name. Same name directory already here");
    }
    else{
        dir.mkpath(g+"/"+p);
        QMessageBox::about(this,"Success","Folder name "+p+" is created successfuly");
    }

}
void MainWindow::t_function()
{
    QTime time= QTime::currentTime();
    QDate date=QDate::currentDate();
    QString date_t= date.toString("dd : MM : yyyy");
    ui->label_5->setText(date_t);
    QString time_t= time.toString("hh : mm : ss AP");
    QString hr(3);
    hr[0]=time_t[0];
    hr[1]=time_t[1];
    hr[2] = ':';
    QString mn(3);
    mn[0]=time_t[5];
    mn[1]=time_t[6];
    mn[2] = ':';
    QString se(2);
    se[0]=time_t[10];
    se[1]=time_t[11];
    QString ar(2);
    ar[0]=time_t[13];
    ar[1]=time_t[14];
    if(time.second()%2==0){
        hr[2]=' ';
        mn[2]=' ';
    }
    ui->label_3->setText(hr);
    ui->label_4->setText(mn);
    ui->label_2->setText(se);
    ui->label_6->setText(ar);
}

void MainWindow::on_pushButton_5_clicked()
{
    secdialog = new Dialog(this);
    secdialog->show();
    secdialog->setText(g);
    //secdialog->setTextL2("vector[1]");
    //secdialog->setTextL3("vector[1]");
    //secdialog->lineEdit("vector[1]");
}

void MainWindow::on_pushButton_6_clicked()
{
    g="C:/";
    QDir dir_2(g);
    if(dir_2.exists()){
        while(ui->listWidget->count()!=0){
            delete ui->listWidget->takeItem(ui->listWidget->count()-1);
        }
        MainWindow::open_dir(g);
    }
    else{
        secdialog = new Dialog(this);
        secdialog->show();
        secdialog->setText(g);
        //secdialog->setTextL2("vector[1]");
        //secdialog->setTextL3("vector[1]");
        //secdialog->lineEdit("vector[1]");

    }
}

void MainWindow::on_pushButton_7_clicked()
{
    g="F:/";
    QDir dir_2(g);
    if(dir_2.exists()){
        while(ui->listWidget->count()!=0){
            delete ui->listWidget->takeItem(ui->listWidget->count()-1);
        }
        MainWindow::open_dir(g);
    }
    else{
        secdialog = new Dialog(this);
        secdialog->show();
        secdialog->setText(g);
        //secdialog->setTextL2("vector[1]");
        //secdialog->setTextL3("vector[1]");
        //secdialog->lineEdit("vector[1]");

    }
}

void MainWindow::on_pushButton_8_clicked()
{
    g="C:/users/pradeep Kumar/desktop";
    QDir dir_2(g);
    if(dir_2.exists()){
        while(ui->listWidget->count()!=0){
            delete ui->listWidget->takeItem(ui->listWidget->count()-1);
        }
        MainWindow::open_dir(g);
    }
    else{
        secdialog = new Dialog(this);
        secdialog->show();
        secdialog->setText(g);
        //secdialog->setTextL2("vector[1]");
        //secdialog->setTextL3("vector[1]");
        //secdialog->lineEdit("vector[1]");

    }
}
