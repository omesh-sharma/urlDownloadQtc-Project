#include "Widget.h"
#include <QApplication>

// Created by omesh sharma


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}

