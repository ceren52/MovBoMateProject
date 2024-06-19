#include "mainwindow.h"
#include "create_tables.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QApplication>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString dbPath = "/Users/cerenyanik/Desktop/MovBoMateProject/db/recommendation.db";

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        QMessageBox::critical(nullptr, "Database Error", db.lastError().text());
        return -1;
    }

    MainWindow w;
    w.show();
    return a.exec();
}
