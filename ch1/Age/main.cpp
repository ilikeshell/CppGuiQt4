#include <QApplication>
#include <QSpinBox>
#include <QSlider>
#include <QWidget>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSpinBox* spinbox = new QSpinBox;
    spinbox->setRange(0, 130);


    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 130);

    QObject::connect(spinbox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)), spinbox, SLOT(setValue(int)));
    spinbox->setValue(35);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(spinbox);
    layout->addWidget(slider);

    QWidget *widget = new QWidget;
    widget->setWindowTitle("Please input your age: ");
    widget->setLayout(layout);

    widget->show();
    return a.exec();
}
