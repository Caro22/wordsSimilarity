#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "db_similarity.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();    

    void connect_signals();

public slots:
    void find_similar_words();

    void update_bar(int row, int column);
    
private:
    Ui::MainWindow *ui;
    DB_similarity_measurer measurer;
};

#endif // MAINWINDOW_H
