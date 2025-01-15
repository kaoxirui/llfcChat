/********************************************************************************
** Form generated from reading UI file 'resetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETDIALOG_H
#define UI_RESETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <timerbtn.h>

QT_BEGIN_NAMESPACE

class Ui_ResetDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *err_tip;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *user_lb;
    QLineEdit *user_edit;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *email_lb;
    QLineEdit *email_edit;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *varify_lb;
    QLineEdit *varify_edit;
    TimerBtn *varify_btn;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *pwd_lb;
    QLineEdit *pwd_edit;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *sure_btn;
    QPushButton *return_btn;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *ResetDialog)
    {
        if (ResetDialog->objectName().isEmpty())
            ResetDialog->setObjectName(QString::fromUtf8("ResetDialog"));
        ResetDialog->resize(354, 538);
        verticalLayout = new QVBoxLayout(ResetDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        err_tip = new QLabel(ResetDialog);
        err_tip->setObjectName(QString::fromUtf8("err_tip"));
        err_tip->setMinimumSize(QSize(0, 25));
        err_tip->setMaximumSize(QSize(16777215, 25));
        err_tip->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(err_tip);

        widget = new QWidget(ResetDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        user_lb = new QLabel(widget);
        user_lb->setObjectName(QString::fromUtf8("user_lb"));
        user_lb->setMinimumSize(QSize(0, 25));
        user_lb->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(user_lb);

        user_edit = new QLineEdit(widget);
        user_edit->setObjectName(QString::fromUtf8("user_edit"));
        user_edit->setMinimumSize(QSize(0, 25));
        user_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(user_edit);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(ResetDialog);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        email_lb = new QLabel(widget_2);
        email_lb->setObjectName(QString::fromUtf8("email_lb"));
        email_lb->setMinimumSize(QSize(48, 25));
        email_lb->setMaximumSize(QSize(48, 25));

        horizontalLayout_2->addWidget(email_lb);

        email_edit = new QLineEdit(widget_2);
        email_edit->setObjectName(QString::fromUtf8("email_edit"));
        email_edit->setMinimumSize(QSize(0, 25));
        email_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(email_edit);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(ResetDialog);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        varify_lb = new QLabel(widget_3);
        varify_lb->setObjectName(QString::fromUtf8("varify_lb"));
        varify_lb->setMinimumSize(QSize(0, 25));
        varify_lb->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(varify_lb);

        varify_edit = new QLineEdit(widget_3);
        varify_edit->setObjectName(QString::fromUtf8("varify_edit"));
        varify_edit->setMinimumSize(QSize(0, 25));
        varify_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(varify_edit);

        varify_btn = new TimerBtn(widget_3);
        varify_btn->setObjectName(QString::fromUtf8("varify_btn"));
        varify_btn->setMinimumSize(QSize(0, 25));
        varify_btn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(varify_btn);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(ResetDialog);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pwd_lb = new QLabel(widget_4);
        pwd_lb->setObjectName(QString::fromUtf8("pwd_lb"));
        pwd_lb->setMinimumSize(QSize(0, 25));
        pwd_lb->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(pwd_lb);

        pwd_edit = new QLineEdit(widget_4);
        pwd_edit->setObjectName(QString::fromUtf8("pwd_edit"));
        pwd_edit->setMinimumSize(QSize(0, 25));
        pwd_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(pwd_edit);


        verticalLayout->addWidget(widget_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        widget_5 = new QWidget(ResetDialog);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        sure_btn = new QPushButton(widget_5);
        sure_btn->setObjectName(QString::fromUtf8("sure_btn"));
        sure_btn->setMinimumSize(QSize(0, 25));
        sure_btn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(sure_btn);

        return_btn = new QPushButton(widget_5);
        return_btn->setObjectName(QString::fromUtf8("return_btn"));
        return_btn->setMinimumSize(QSize(0, 25));
        return_btn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(return_btn);


        verticalLayout->addWidget(widget_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        retranslateUi(ResetDialog);

        QMetaObject::connectSlotsByName(ResetDialog);
    } // setupUi

    void retranslateUi(QDialog *ResetDialog)
    {
        ResetDialog->setWindowTitle(QApplication::translate("ResetDialog", "Dialog", nullptr));
        err_tip->setText(QString());
        user_lb->setText(QApplication::translate("ResetDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        email_lb->setText(QApplication::translate("ResetDialog", "\351\202\256\347\256\261\357\274\232", nullptr));
        varify_lb->setText(QApplication::translate("ResetDialog", "\351\252\214\350\257\201\347\240\201\357\274\232", nullptr));
        varify_btn->setText(QApplication::translate("ResetDialog", "\350\216\267\345\217\226", nullptr));
        pwd_lb->setText(QApplication::translate("ResetDialog", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        sure_btn->setText(QApplication::translate("ResetDialog", "\347\241\256\350\256\244", nullptr));
        return_btn->setText(QApplication::translate("ResetDialog", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResetDialog: public Ui_ResetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETDIALOG_H
