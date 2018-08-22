/*******************************************************************************
 * Copyright [2018] <赵楠林>
 * All rights reserved.
 *
 * version:     1.0
 * author:      zhaonanlin
 * brief:       全局截屏器
*******************************************************************************/
#include <QDebug>
#include <QString>
#include <QPixmap>
#include <QDateTime>
#include <QApplication>
#include <QDesktopWidget>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    char s_month[5];
    static const char month_names[] = "JanFebMarAprMayJunJulAugSepOctNovDec";
    int month, day, year;
    sscanf((__DATE__), "%s %d %d", s_month, &day, &year);
    month = (strstr(month_names, s_month)-month_names)/3+1;
    QDate makeDate;
    makeDate.setDate(year, month, day);
    static const QTime makeTime = QTime::fromString(__TIME__, "hh:mm:ss");
    QDateTime makeDateTime(makeDate, makeTime);
    qDebug() << "app show:" << QString("V-1.0.%1").arg(makeDateTime.toString("yyMMdd-hhmm"));

    QString fileTime = QTime::currentTime().toString("hhmmss");
    QString fileName = fileTime.append(".png");
    QPixmap picture = QPixmap::grabWindow(QApplication::desktop()->winId());

    picture.save(fileName, "png");

    qDebug() << "app show:" << QString("%1 save ok").arg(fileName);

    app.exit();

    return 0;
}

