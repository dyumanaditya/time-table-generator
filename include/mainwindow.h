#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>

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
    void on_input_data_button_clicked();

    void on_upload_data_button_clicked();

    void on_teacher_data_browse_button_clicked();

    void on_student_data_browse_button_clicked();

    void on_generate_tt_button_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    std::string get_teacher_data_path();
    std::string get_student_data_path();
};
#endif // MAINWINDOW_H
