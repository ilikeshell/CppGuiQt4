#include "gotocelldialog.h"
#include "ui_gotocelldialog.h"
#include <QtWidgets>


GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GoToCellDialog)
{
    ui->setupUi(this);

    QRegExp regRxp("[a-zA-Z][1-9][0-9]{0,2}");
    ui->lineEdit->setValidator(new QRegExpValidator(regRxp, this));

    connect(ui->okButton, SIGNAL(clicked(bool)), this, SLOT(accept()));
    connect(ui->cancelButton, SIGNAL(clicked(bool)), this, SLOT(reject()));
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(lineEdit_textChanged()));
   // ui->okButton->setEnabled(false);
}

GoToCellDialog::~GoToCellDialog()
{
    delete ui;
}

void GoToCellDialog::lineEdit_textChanged()
{
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}

