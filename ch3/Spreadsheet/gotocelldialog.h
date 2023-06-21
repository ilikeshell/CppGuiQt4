#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include "ui_gotocelldialog.h"
#include <QDialog>


class GoToCellDialog : public QDialog, public Ui::GoToCellDialog
{
    Q_OBJECT

public:
    GoToCellDialog(QWidget *parent = nullptr);


private slots:
    void lineEdit_textChanged();

};
#endif // GOTOCELLDIALOG_H
