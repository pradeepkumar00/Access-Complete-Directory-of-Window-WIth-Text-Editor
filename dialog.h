#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
        void setText(const QString &text);
        //void setTextL2(const QString &text);
        //void setTextL3(const QString &text);
       // void lineEdit(const QString &text);
    ~Dialog();

private slots:

        void on_new_2_pressed();

        void on_open_clicked();

        void on_copy_clicked();

        void on_paste_clicked();

        void on_cut_clicked();

        void on_save_clicked();

        void on_save_as_clicked();

        void on_undo_clicked();

        void on_redo_clicked();

        void on_print_clicked();

        void on_font_clicked();

        void on_color_clicked();

        void on_t_background_clicked();

        void on_w_back_clicked();

        void on_zoom_in_clicked();

        void on_zoom_out_clicked();

private:
    Ui::Dialog *ui;
    QString file_path;
};

#endif // DIALOG_H
