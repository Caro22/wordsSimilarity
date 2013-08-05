#include "mainwindow.h"
#include <QApplication>
#include <QtSQL>
#include <QMessageBox>
#include <iostream>

#include "porter_stemmer.h"

using namespace std;

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("1234");

    w.show();

    if(!db.open()) {
        QMessageBox::critical(0, QObject::tr("Database Error"), "Imposible to open database");
    }

    return a.exec();*/
    string word = "doggy";
    cout << Porter2Stemmer::stem(word) << endl;
    return 0;
}
