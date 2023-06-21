#include "sortdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SortDialog w;
    w.setColumnRange('D', 'Z');
    w.show();
    return a.exec();
}
