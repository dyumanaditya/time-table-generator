#include "include/mainwindow.h"
#include "include/time_table_generator.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <string>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::string MainWindow::get_teacher_data_path()
{
    return ui->teacher_data_path->text().toStdString();
}

std::string MainWindow::get_student_data_path()
{
    return ui->student_data_path->text().toStdString();
}

void MainWindow::on_input_data_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_upload_data_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_teacher_data_browse_button_clicked()
{
    std::string teacher_data_path = QFileDialog::getOpenFileName(this, "Select a .csv file", QDir::homePath(), "csv files (*.csv)").toStdString();
    ui->teacher_data_path->setText((teacher_data_path).c_str());
}


void MainWindow::on_student_data_browse_button_clicked()
{
    std::string student_data_path = QFileDialog::getOpenFileName(this, "Select a .csv file", QDir::homePath(), "csv files (*.csv)").toStdString();
    ui->student_data_path->setText((student_data_path).c_str());
}


void MainWindow::on_generate_tt_button_clicked()
{
    std::string teacher_data_path = get_teacher_data_path();
    std::string student_data_path = get_student_data_path();
    TimeTableGenerator time_table_generator(teacher_data_path, student_data_path);
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

