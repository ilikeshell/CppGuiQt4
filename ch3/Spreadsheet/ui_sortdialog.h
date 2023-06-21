/********************************************************************************
** Form generated from reading UI file 'sortdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTDIALOG_H
#define UI_SORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SortDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *tertiaryGroupBox;
    QGridLayout *gridLayout_5;
    QLabel *label_9;
    QComboBox *tertiaryColumnComBo;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_10;
    QComboBox *tertiaryOrderComBo;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *secondaryGroupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QComboBox *secondaryColumnComBo;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QComboBox *secondaryOrderComBo;
    QVBoxLayout *verticalLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *verticalSpacer;
    QPushButton *moreButton;
    QGroupBox *primaryGroupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QComboBox *primaryColumnComBo;
    QSpacerItem *horizontalSpacer;
    QComboBox *primaryOrderComBo;

    void setupUi(QDialog *SortDialog)
    {
        if (SortDialog->objectName().isEmpty())
            SortDialog->setObjectName(QString::fromUtf8("SortDialog"));
        SortDialog->resize(284, 307);
        gridLayout_3 = new QGridLayout(SortDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        tertiaryGroupBox = new QGroupBox(SortDialog);
        tertiaryGroupBox->setObjectName(QString::fromUtf8("tertiaryGroupBox"));
        gridLayout_5 = new QGridLayout(tertiaryGroupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_9 = new QLabel(tertiaryGroupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_5->addWidget(label_9, 0, 0, 1, 1);

        tertiaryColumnComBo = new QComboBox(tertiaryGroupBox);
        tertiaryColumnComBo->addItem(QString());
        tertiaryColumnComBo->setObjectName(QString::fromUtf8("tertiaryColumnComBo"));

        gridLayout_5->addWidget(tertiaryColumnComBo, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(37, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        label_10 = new QLabel(tertiaryGroupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_5->addWidget(label_10, 1, 0, 1, 1);

        tertiaryOrderComBo = new QComboBox(tertiaryGroupBox);
        tertiaryOrderComBo->addItem(QString());
        tertiaryOrderComBo->addItem(QString());
        tertiaryOrderComBo->setObjectName(QString::fromUtf8("tertiaryOrderComBo"));

        gridLayout_5->addWidget(tertiaryOrderComBo, 1, 1, 1, 2);


        gridLayout_3->addWidget(tertiaryGroupBox, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 1, 0, 1, 1);

        secondaryGroupBox = new QGroupBox(SortDialog);
        secondaryGroupBox->setObjectName(QString::fromUtf8("secondaryGroupBox"));
        gridLayout_2 = new QGridLayout(secondaryGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(secondaryGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        secondaryColumnComBo = new QComboBox(secondaryGroupBox);
        secondaryColumnComBo->addItem(QString());
        secondaryColumnComBo->setObjectName(QString::fromUtf8("secondaryColumnComBo"));

        gridLayout_2->addWidget(secondaryColumnComBo, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(37, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        label_4 = new QLabel(secondaryGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        secondaryOrderComBo = new QComboBox(secondaryGroupBox);
        secondaryOrderComBo->addItem(QString());
        secondaryOrderComBo->addItem(QString());
        secondaryOrderComBo->setObjectName(QString::fromUtf8("secondaryOrderComBo"));

        gridLayout_2->addWidget(secondaryOrderComBo, 1, 1, 1, 2);


        gridLayout_3->addWidget(secondaryGroupBox, 2, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        okButton = new QPushButton(SortDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        verticalLayout->addWidget(okButton);

        cancelButton = new QPushButton(SortDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        verticalLayout->addWidget(cancelButton);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        moreButton = new QPushButton(SortDialog);
        moreButton->setObjectName(QString::fromUtf8("moreButton"));
        moreButton->setCheckable(true);

        verticalLayout->addWidget(moreButton);


        gridLayout_3->addLayout(verticalLayout, 0, 1, 2, 1);

        primaryGroupBox = new QGroupBox(SortDialog);
        primaryGroupBox->setObjectName(QString::fromUtf8("primaryGroupBox"));
        gridLayout = new QGridLayout(primaryGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(primaryGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(primaryGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        primaryColumnComBo = new QComboBox(primaryGroupBox);
        primaryColumnComBo->addItem(QString());
        primaryColumnComBo->setObjectName(QString::fromUtf8("primaryColumnComBo"));
        primaryColumnComBo->setInsertPolicy(QComboBox::InsertAtBottom);
        primaryColumnComBo->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        gridLayout->addWidget(primaryColumnComBo, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        primaryOrderComBo = new QComboBox(primaryGroupBox);
        primaryOrderComBo->addItem(QString());
        primaryOrderComBo->addItem(QString());
        primaryOrderComBo->setObjectName(QString::fromUtf8("primaryOrderComBo"));

        gridLayout->addWidget(primaryOrderComBo, 1, 1, 1, 2);


        gridLayout_3->addWidget(primaryGroupBox, 0, 0, 1, 1);


        retranslateUi(SortDialog);
        QObject::connect(okButton, SIGNAL(clicked()), SortDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), SortDialog, SLOT(reject()));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), secondaryGroupBox, SLOT(setVisible(bool)));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), tertiaryGroupBox, SLOT(setVisible(bool)));

        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(SortDialog);
    } // setupUi

    void retranslateUi(QDialog *SortDialog)
    {
        SortDialog->setWindowTitle(QCoreApplication::translate("SortDialog", "Sort", nullptr));
        tertiaryGroupBox->setTitle(QCoreApplication::translate("SortDialog", "&Tertiary key", nullptr));
        label_9->setText(QCoreApplication::translate("SortDialog", "<html><head/><body><p>column:</p></body></html>", nullptr));
        tertiaryColumnComBo->setItemText(0, QCoreApplication::translate("SortDialog", "None", nullptr));

        label_10->setText(QCoreApplication::translate("SortDialog", "order:", nullptr));
        tertiaryOrderComBo->setItemText(0, QCoreApplication::translate("SortDialog", "Ascending", nullptr));
        tertiaryOrderComBo->setItemText(1, QCoreApplication::translate("SortDialog", "Descending", nullptr));

        secondaryGroupBox->setTitle(QCoreApplication::translate("SortDialog", "&Secondary key", nullptr));
        label_3->setText(QCoreApplication::translate("SortDialog", "<html><head/><body><p>column:</p></body></html>", nullptr));
        secondaryColumnComBo->setItemText(0, QCoreApplication::translate("SortDialog", "None", nullptr));

        label_4->setText(QCoreApplication::translate("SortDialog", "order:", nullptr));
        secondaryOrderComBo->setItemText(0, QCoreApplication::translate("SortDialog", "Ascending", nullptr));
        secondaryOrderComBo->setItemText(1, QCoreApplication::translate("SortDialog", "Descending", nullptr));

        okButton->setText(QCoreApplication::translate("SortDialog", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("SortDialog", "Cancel", nullptr));
        moreButton->setText(QCoreApplication::translate("SortDialog", "&More", nullptr));
        primaryGroupBox->setTitle(QCoreApplication::translate("SortDialog", "&Primary key", nullptr));
        label->setText(QCoreApplication::translate("SortDialog", "<html><head/><body><p>column:</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("SortDialog", "order:", nullptr));
        primaryColumnComBo->setItemText(0, QCoreApplication::translate("SortDialog", "None", nullptr));

        primaryOrderComBo->setItemText(0, QCoreApplication::translate("SortDialog", "Ascending", nullptr));
        primaryOrderComBo->setItemText(1, QCoreApplication::translate("SortDialog", "Descending", nullptr));

    } // retranslateUi

};

namespace Ui {
    class SortDialog: public Ui_SortDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTDIALOG_H
