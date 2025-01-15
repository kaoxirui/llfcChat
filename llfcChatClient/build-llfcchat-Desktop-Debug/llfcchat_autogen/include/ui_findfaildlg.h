/********************************************************************************
** Form generated from reading UI file 'findfaildlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDFAILDLG_H
#define UI_FINDFAILDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <clickedbtn.h>

QT_BEGIN_NAMESPACE

class Ui_FindFailDlg
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *fail_tip;
    QLabel *fail_tip2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    ClickedBtn *fail_sure_btn;

    void setupUi(QDialog *FindFailDlg)
    {
        if (FindFailDlg->objectName().isEmpty())
            FindFailDlg->setObjectName(QString::fromUtf8("FindFailDlg"));
        FindFailDlg->resize(260, 163);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FindFailDlg->sizePolicy().hasHeightForWidth());
        FindFailDlg->setSizePolicy(sizePolicy);
        FindFailDlg->setMinimumSize(QSize(260, 163));
        FindFailDlg->setMaximumSize(QSize(260, 163));
        verticalLayout = new QVBoxLayout(FindFailDlg);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        fail_tip = new QLabel(FindFailDlg);
        fail_tip->setObjectName(QString::fromUtf8("fail_tip"));
        fail_tip->setMinimumSize(QSize(0, 25));
        fail_tip->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(fail_tip);

        fail_tip2 = new QLabel(FindFailDlg);
        fail_tip2->setObjectName(QString::fromUtf8("fail_tip2"));
        fail_tip2->setMinimumSize(QSize(0, 25));
        fail_tip2->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(fail_tip2);

        widget = new QWidget(FindFailDlg);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fail_sure_btn = new ClickedBtn(widget);
        fail_sure_btn->setObjectName(QString::fromUtf8("fail_sure_btn"));
        fail_sure_btn->setMinimumSize(QSize(100, 30));
        fail_sure_btn->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(fail_sure_btn);


        verticalLayout->addWidget(widget);


        retranslateUi(FindFailDlg);

        QMetaObject::connectSlotsByName(FindFailDlg);
    } // setupUi

    void retranslateUi(QDialog *FindFailDlg)
    {
        FindFailDlg->setWindowTitle(QApplication::translate("FindFailDlg", "Dialog", nullptr));
        fail_tip->setText(QApplication::translate("FindFailDlg", "\346\227\240\346\263\225\346\211\276\345\210\260\350\257\245\347\224\250\346\210\267", nullptr));
        fail_tip2->setText(QApplication::translate("FindFailDlg", "\350\257\267\346\243\200\346\237\245\344\275\240\345\241\253\345\206\231\347\232\204\350\264\246\345\217\267\346\230\257\345\220\246\346\255\243\347\241\256", nullptr));
        fail_sure_btn->setText(QApplication::translate("FindFailDlg", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FindFailDlg: public Ui_FindFailDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDFAILDLG_H
