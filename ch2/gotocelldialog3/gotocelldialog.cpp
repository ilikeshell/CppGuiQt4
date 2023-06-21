#include "gotocelldialog.h"
#include "ui_gotocelldialog.h"
#include <QtWidgets>

GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GoToCellDialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    QRegExp regRxp("[a-zA-Z][1-9][0-9]{0,2}");
    ui->lineEdit->setValidator(new QRegExpValidator(regRxp, this));

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(reject()));
}

GoToCellDialog::~GoToCellDialog()
{
    delete ui;
}

void GoToCellDialog::lineEdit_textChanged()
{
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(ui->lineEdit->hasAcceptableInput());
}
