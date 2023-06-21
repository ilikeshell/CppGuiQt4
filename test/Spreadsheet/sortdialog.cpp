#include "sortdialog.h"
#include "ui_sortdialog.h"

SortDialog::SortDialog(QWidget *parent)
    : QDialog(parent)

{
    setupUi(this);
    secondaryGroupBox->hide();
    tertiaryGroupBox->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);
    setColumnRange('A', 'Z');
}


void SortDialog::setColumnRange(QChar first, QChar last)
{
    primaryColumnComBo->clear();
    secondaryColumnComBo->clear();
    tertiaryColumnComBo->clear();

    secondaryColumnComBo->addItem(tr("None"));
    tertiaryColumnComBo->addItem(tr("None"));
    primaryColumnComBo->setMinimumSize(secondaryColumnComBo->sizeHint());

    QChar ch = first;
    while(ch <= last){
        primaryColumnComBo->addItem(QString(ch));
        secondaryColumnComBo->addItem(QString(ch));
        tertiaryColumnComBo->addItem(QString(ch));
        ch = ch.unicode() + 1;
    }
}

