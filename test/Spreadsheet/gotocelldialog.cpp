#include "gotocelldialog.h"
#include "ui_gotocelldialog.h"
#include <QtWidgets>

GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    QRegExp regRxp("[a-zA-Z][1-9][0-9]{0,2}");
    lineEdit->setValidator(new QRegExpValidator(regRxp, this));

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(reject()));
}


void GoToCellDialog::lineEdit_textChanged()
{
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(lineEdit->hasAcceptableInput());
}
