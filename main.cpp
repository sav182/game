#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QString>
QString loadStyleSheetFromFileAndReplaceUrlPath(QString file, QString folderForUrl);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString stylSheet = loadStyleSheetFromFileAndReplaceUrlPath(a.applicationDirPath() + QString("/qss/style.css"), a.applicationDirPath());
    qDebug() << stylSheet;
    a.setStyleSheet(stylSheet);

    MainWindow w;
    w.show();

    return a.exec();
}

QString loadStyleSheetFromFileAndReplaceUrlPath(QString file, QString folderForUrl)
{
    QFile f(file);
    f.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(f.readAll());
    f.close();
    styleSheet.replace("url(","url("+folderForUrl+"/");
    return styleSheet;
}
