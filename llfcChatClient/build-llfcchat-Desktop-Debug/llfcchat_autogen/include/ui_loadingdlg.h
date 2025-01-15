/********************************************************************************
** Form generated from reading UI file 'loadingdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADINGDLG_H
#define UI_LOADINGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoadingDlg
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *loading_lb;

    void setupUi(QDialog *LoadingDlg)
    {
        if (LoadingDlg->objectName().isEmpty())
            LoadingDlg->setObjectName(QString::fromUtf8("LoadingDlg"));
        LoadingDlg->resize(400, 300);
        verticalLayout = new QVBoxLayout(LoadingDlg);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        loading_lb = new QLabel(LoadingDlg);
        loading_lb->setObjectName(QString::fromUtf8("loading_lb"));
        loading_lb->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(loading_lb);


        retranslateUi(LoadingDlg);

        QMetaObject::connectSlotsByName(LoadingDlg);
    } // setupUi

    void retranslateUi(QDialog *LoadingDlg)
    {
        LoadingDlg->setWindowTitle(QApplication::translate("LoadingDlg", "Dialog", nullptr));
        loading_lb->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoadingDlg: public Ui_LoadingDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADINGDLG_H
