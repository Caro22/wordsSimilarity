#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect_signals();
    ui->result_tableWidget->setColumnCount(2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connect_signals() {
    QObject::connect(ui->find_Button, SIGNAL(clicked()),
                     this, SLOT(find_similar_words()));
    QObject::connect(ui->word_lineEdit, SIGNAL(returnPressed()),
                     this, SLOT(find_similar_words()));
    QObject::connect(ui->result_tableWidget, SIGNAL(cellClicked(int,int)),
                     this, SLOT(update_bar(int,int)));
    QObject::connect(ui->result_tableWidget, SIGNAL(cellActivated(int,int)),
                     this, SLOT(update_bar(int,int)));
    QObject::connect(ui->result_tableWidget, SIGNAL(cellPressed(int,int)),
                     this, SLOT(update_bar(int,int)));
    QObject::connect(ui->result_tableWidget, SIGNAL(),
                     this, SLOT(update_bar(int,int)));
}

void MainWindow::update_bar(int row, int column) {
    QTableWidgetItem *ptr = ui->result_tableWidget->item(row, 0);
    ui->sim_progressBar->setValue(ptr->text().toDouble()*100);
}

void MainWindow::find_similar_words() {
    std::vector<string> res1,
                        res2;
        measurer.find_similar_words(
            ui->word_lineEdit->text().toStdString(), res1, res2);
        ui->result_tableWidget->setRowCount(res1.size());

    int i = 0;

    std::vector<string>::iterator tmp22 = res2.begin();
    for(std::vector<string>::iterator it_i = res1.begin(); it_i != res1.end(); it_i++, i++, tmp22++) {
        QString tmp, tmp2;
        tmp = QString((*it_i).data());
        tmp2 = QString((*tmp22).data());
        ui->result_tableWidget->setItem(i, 0, new QTableWidgetItem(tmp));
        ui->result_tableWidget->setItem(i, 1, new QTableWidgetItem(tmp2));
    }
}
