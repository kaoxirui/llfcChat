/********************************************************************************
** Form generated from reading UI file 'conuseritem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONUSERITEM_H
#define UI_CONUSERITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConUserItem
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QLabel *icon_lb;
    QLabel *red_point;
    QLabel *user_name_lb;

    void setupUi(QWidget *ConUserItem)
    {
        if (ConUserItem->objectName().isEmpty())
            ConUserItem->setObjectName(QString::fromUtf8("ConUserItem"));
        ConUserItem->resize(400, 70);
        ConUserItem->setMinimumSize(QSize(0, 70));
        ConUserItem->setMaximumSize(QSize(16777215, 70));
        horizontalLayout = new QHBoxLayout(ConUserItem);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(6, 2, 6, 2);
        widget = new QWidget(ConUserItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(60, 60));
        widget->setMaximumSize(QSize(60, 60));
        icon_lb = new QLabel(widget);
        icon_lb->setObjectName(QString::fromUtf8("icon_lb"));
        icon_lb->setGeometry(QRect(0, 10, 45, 45));
        icon_lb->setMinimumSize(QSize(45, 45));
        icon_lb->setMaximumSize(QSize(45, 45));
        red_point = new QLabel(widget);
        red_point->setObjectName(QString::fromUtf8("red_point"));
        red_point->setGeometry(QRect(27, 2, 30, 30));
        red_point->setMinimumSize(QSize(30, 30));
        red_point->setMaximumSize(QSize(30, 30));

        horizontalLayout->addWidget(widget);

        user_name_lb = new QLabel(ConUserItem);
        user_name_lb->setObjectName(QString::fromUtf8("user_name_lb"));

        horizontalLayout->addWidget(user_name_lb);


        retranslateUi(ConUserItem);

        QMetaObject::connectSlotsByName(ConUserItem);
    } // setupUi

    void retranslateUi(QWidget *ConUserItem)
    {
        ConUserItem->setWindowTitle(QApplication::translate("ConUserItem", "Form", nullptr));
        icon_lb->setText(QString());
        red_point->setText(QString());
        user_name_lb->setText(QApplication::translate("ConUserItem", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConUserItem: public Ui_ConUserItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONUSERITEM_H
