#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPushButton* button = new QPushButton("Quit");
    button->show();

    QObject::connect(button, SIGNAL(clicked(bool)), &a, SLOT(quit()));
    return a.exec();
}
