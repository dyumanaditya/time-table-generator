#include "time-table-generator/mainwindow.h"
#include "time-table-generator/time_table_generator.h"
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

std::string MainWindow::getTeacherDataPath()
{
    return ui->teacher_data_path->text().toStdString();
}

std::string MainWindow::getStudentDataPath()
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
    // the Time Table has to be generated before going to this page.
    ui->stackedWidget->setCurrentIndex(3);

    std::string teacher_data_path = getTeacherDataPath();
    std::string student_data_path = getStudentDataPath();
    TimeTableGenerator time_table_generator(teacher_data_path, student_data_path);
    time_table_generator.generateTimeTable();
}




void MainWindow::on_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_back_to_upload_page_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_search_tt_button_clicked()
{
    // Search and find specific Time Table.
}


void MainWindow::on_back_button_2_clicked()
{

}


void MainWindow::on_done_button_clicked()
{

}

