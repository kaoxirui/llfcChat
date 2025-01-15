/********************************************************************************
** Form generated from reading UI file 'adduseritem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSERITEM_H
#define UI_ADDUSERITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddUserItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *add_tip;
    QLabel *message_tip;
    QLabel *right_tip;

    void setupUi(QWidget *AddUserItem)
    {
        if (AddUserItem->objectName().isEmpty())
            AddUserItem->setObjectName(QString::fromUtf8("AddUserItem"));
        AddUserItem->resize(250, 70);
        AddUserItem->setMinimumSize(QSize(250, 70));
        AddUserItem->setMaximumSize(QSize(250, 70));
        horizontalLayout = new QHBoxLayout(AddUserItem);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        add_tip = new QLabel(AddUserItem);
        add_tip->setObjectName(QString::fromUtf8("add_tip"));
        add_tip->setMinimumSize(QSize(40, 40));
        add_tip->setMaximumSize(QSize(40, 40));

        horizontalLayout->addWidget(add_tip);

        message_tip = new QLabel(AddUserItem);
        message_tip->setObjectName(QString::fromUtf8("message_tip"));
        message_tip->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(message_tip);

        right_tip = new QLabel(AddUserItem);
        right_tip->setObjectName(QString::fromUtf8("right_tip"));
        right_tip->setMinimumSize(QSize(30, 30));
        right_tip->setMaximumSize(QSize(30, 30));

        horizontalLayout->addWidget(right_tip);


        retranslateUi(AddUserItem);

        QMetaObject::connectSlotsByName(AddUserItem);
    } // setupUi

    void retranslateUi(QWidget *AddUserItem)
    {
        AddUserItem->setWindowTitle(QApplication::translate("AddUserItem", "Form", nullptr));
        add_tip->setText(QString());
        message_tip->setText(QApplication::translate("AddUserItem", "\346\237\245\346\211\276 uid/name", nullptr));
        right_tip->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddUserItem: public Ui_AddUserItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSERITEM_H
