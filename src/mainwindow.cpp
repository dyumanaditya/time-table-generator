#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <string>

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
    std::string teacher_csv_path = QFileDialog::getOpenFileName(this, "Select a .csv file", QDir::homePath(), "csv files (*.csv)").toStdString();
    ui->teacher_data_path->setText((teacher_csv_path).c_str());
}


void MainWindow::on_student_data_browse_button_clicked()
{
    std::string student_csv_path = QFileDialog::getOpenFileName(this, "Select a .csv file", QDir::homePath(), "csv files (*.csv)").toStdString();
    ui->student_data_path->setText((student_csv_path).c_str());
}


void MainWindow::on_generate_tt_button_clicked()
{

}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

