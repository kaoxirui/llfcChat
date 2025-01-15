/********************************************************************************
** Form generated from reading UI file 'applyfrienditem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLYFRIENDITEM_H
#define UI_APPLYFRIENDITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clickedbtn.h"

QT_BEGIN_NAMESPACE

class Ui_ApplyFriendItem
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *icon_lb;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QLabel *user_name_lb;
    QLabel *user_chat_lb;
    ClickedBtn *addBtn;
    QLabel *already_add_lb;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *ApplyFriendItem)
    {
        if (ApplyFriendItem->objectName().isEmpty())
            ApplyFriendItem->setObjectName(QString::fromUtf8("ApplyFriendItem"));
        ApplyFriendItem->resize(451, 80);
        ApplyFriendItem->setMinimumSize(QSize(0, 80));
        ApplyFriendItem->setMaximumSize(QSize(16777215, 80));
        horizontalLayout = new QHBoxLayout(ApplyFriendItem);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(9, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        icon_lb = new QLabel(ApplyFriendItem);
        icon_lb->setObjectName(QString::fromUtf8("icon_lb"));
        icon_lb->setMinimumSize(QSize(45, 45));
        icon_lb->setMaximumSize(QSize(45, 45));

        horizontalLayout->addWidget(icon_lb);

        widget = new QWidget(ApplyFriendItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 2, -1, 2);
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 0));
        widget_2->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 2, -1, 2);
        user_name_lb = new QLabel(widget_2);
        user_name_lb->setObjectName(QString::fromUtf8("user_name_lb"));
        user_name_lb->setMinimumSize(QSize(100, 30));
        user_name_lb->setMaximumSize(QSize(200, 30));

        verticalLayout->addWidget(user_name_lb);

        user_chat_lb = new QLabel(widget_2);
        user_chat_lb->setObjectName(QString::fromUtf8("user_chat_lb"));
        user_chat_lb->setMinimumSize(QSize(100, 30));
        user_chat_lb->setMaximumSize(QSize(500, 30));

        verticalLayout->addWidget(user_chat_lb);


        horizontalLayout_2->addWidget(widget_2);

        addBtn = new ClickedBtn(widget);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        addBtn->setMinimumSize(QSize(80, 30));
        addBtn->setMaximumSize(QSize(80, 30));

        horizontalLayout_2->addWidget(addBtn);

        already_add_lb = new QLabel(widget);
        already_add_lb->setObjectName(QString::fromUtf8("already_add_lb"));
        already_add_lb->setMinimumSize(QSize(40, 0));
        already_add_lb->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_2->addWidget(already_add_lb);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        horizontalLayout->addWidget(widget);


        retranslateUi(ApplyFriendItem);

        QMetaObject::connectSlotsByName(ApplyFriendItem);
    } // setupUi

    void retranslateUi(QWidget *ApplyFriendItem)
    {
        ApplyFriendItem->setWindowTitle(QApplication::translate("ApplyFriendItem", "Form", nullptr));
        icon_lb->setText(QApplication::translate("ApplyFriendItem", "TextLabel", nullptr));
        user_name_lb->setText(QApplication::translate("ApplyFriendItem", "TextLabel", nullptr));
        user_chat_lb->setText(QApplication::translate("ApplyFriendItem", "TextLabel", nullptr));
        addBtn->setText(QApplication::translate("ApplyFriendItem", "\346\267\273\345\212\240", nullptr));
        already_add_lb->setText(QApplication::translate("ApplyFriendItem", "\345\267\262\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ApplyFriendItem: public Ui_ApplyFriendItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLYFRIENDITEM_H
