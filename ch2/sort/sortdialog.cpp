#include "sortdialog.h"
#include "ui_sortdialog.h"

SortDialog::SortDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SortDialog)
{
    ui->setupUi(this);
    ui->secondaryGroupBox->hide();
    ui->tertiaryGroupBox->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);
    setColumnRange('A', 'Z');
}

SortDialog::~SortDialog()
{
    delete ui;
}

void SortDialog::setColumnRange(QChar first, QChar last)
{
    ui->primaryColumnComBo->clear();
    ui->secondaryColumnComBo->clear();
    ui->tertiaryColumnComBo->clear();

    ui->secondaryColumnComBo->addItem(tr("None"));
    ui->tertiaryColumnComBo->addItem(tr("None"));
    ui->primaryColumnComBo->setMinimumSize(ui->secondaryColumnComBo->sizeHint());

    QChar ch = first;
    while(ch <= last){
        ui->primaryColumnComBo->addItem(QString(ch));
        ui->secondaryColumnComBo->addItem(QString(ch));
        ui->tertiaryColumnComBo->addItem(QString(ch));
        ch = ch.unicode() + 1;
    }
}

