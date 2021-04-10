#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dialog.h"
#include<QTimer>
#include <QMainWindow>
#include<QDir>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void open_dir(QDir);
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();


    void on_pushButton_4_clicked();
    void t_function();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    Dialog *secdialog;
};
#endif // MAINWINDOW_H
