#include "dialog.h"
#include "ui_dialog.h"
#include<QFile>
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>
#include<QPrinter>
#include<QPrintDialog>
#include<QFont>
#include<QFontDialog>
#include<QColorDialog>
#include<QColor>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}
Dialog::~Dialog()
{
    delete ui;
}
void Dialog::setText(const QString &text)
{
   file_path = text;
   QFile file(file_path);
   if(!file.open(QFile::ReadOnly | QFile::Text)){
          QMessageBox::warning(this,"warning","Open a valid text file");
          return;
   }
   else{
       QTextStream in(&file);
       QString text=in.readAll();
       ui->textEdit->setText(text);
       file.close();
   }
}

//void Dialog::setTextL2(const QString &text){
    //ui->label_2->setText(text);
//}
//void Dialog::setTextL3(const QString &text){
    //ui->label_3->setText(text);
//}
//void Dialog::lineEdit(const QString &text){
    //ui->label_4->setText(text);
//}

void Dialog::on_new_2_pressed()
{
    file_path="";
    ui->textEdit->setText("");
}

void Dialog::on_open_clicked()
{
    QString file_name = QFileDialog::getOpenFileName();
    QFile file(file_name);
    file_path=file_name;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
           QMessageBox::warning(this,"warning","Open a valid text file");
           return;
    }
    else{
        QTextStream in(&file);
        QString text=in.readAll();
        ui->textEdit->setText(text);
        file.close();
    }

}

void Dialog::on_copy_clicked()
{
    ui->textEdit->copy();
}

void Dialog::on_paste_clicked()
{
    ui->textEdit->paste();
}

void Dialog::on_cut_clicked()
{
    ui->textEdit->cut();
}

void Dialog::on_save_clicked()
{
    QFile file(file_path);
    if(!file.exists()){
        on_save_as_clicked();
    }
    else{
        if(!file.open(QFile::WriteOnly | QFile::Text)){
            QMessageBox::warning(this,"warning","Open a valid text file");
             return;
        }
        else {
             QTextStream out(&file);
             QString text=ui->textEdit->toPlainText();
             out << text;
             file.flush();
             file.close();
        }

    }
}

void Dialog::on_save_as_clicked()
{
    QString file_name = QFileDialog::getSaveFileName();
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"warning","Open a valid text file");
         return;
    }
    else {
         QTextStream out(&file);
         QString text=ui->textEdit->toPlainText();
         out << text;
         file.flush();
         file.close();

    }
}

void Dialog::on_undo_clicked()
{
    ui->textEdit->undo();
}

void Dialog::on_redo_clicked()
{
    ui->textEdit->redo();
}

void Dialog::on_print_clicked()
{
    QPrinter print;
    print.setPrinterName("Choose  your desired printer");
    QPrintDialog dialog(&print, this);
    if(dialog.exec() == QPrintDialog::Rejected)return;
    ui->textEdit->print(&print);
}

void Dialog::on_font_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,this);
    if(ok){
         ui->textEdit->setFont(font);
    }
    else{
        return;
    }
}

void Dialog::on_color_clicked()
{
    QColor color= QColorDialog::getColor(Qt::white,this,"Choose Colour");
    if(color.isValid()){
        ui->textEdit->setTextColor(color);
    }
}

void Dialog::on_t_background_clicked()
{
    QColor color= QColorDialog::getColor(Qt::white,this,"Choose Colour");
    if(color.isValid()){
        ui->textEdit->setTextBackgroundColor(color);
    }
}

void Dialog::on_w_back_clicked()
{
    QColor color= QColorDialog::getColor(Qt::white,this,"Choose Colour");
    if(color.isValid()){
        ui->textEdit->setPalette(QPalette(color));
    }
}

void Dialog::on_zoom_in_clicked()
{
    ui->textEdit->zoomIn(2);
}

void Dialog::on_zoom_out_clicked()
{
    ui->textEdit->zoomOut(2);
}
