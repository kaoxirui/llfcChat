/********************************************************************************
** Form generated from reading UI file 'applyfriendpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLYFRIENDPAGE_H
#define UI_APPLYFRIENDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <applyfriendlist.h>

QT_BEGIN_NAMESPACE

class Ui_ApplyFriendPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *friend_apply_wid;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_8;
    QLabel *friend_apply_lb;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_7;
    ApplyFriendList *apply_friend_list;

    void setupUi(QWidget *ApplyFriendPage)
    {
        if (ApplyFriendPage->objectName().isEmpty())
            ApplyFriendPage->setObjectName(QString::fromUtf8("ApplyFriendPage"));
        ApplyFriendPage->resize(510, 491);
        verticalLayout = new QVBoxLayout(ApplyFriendPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        friend_apply_wid = new QWidget(ApplyFriendPage);
        friend_apply_wid->setObjectName(QString::fromUtf8("friend_apply_wid"));
        friend_apply_wid->setMinimumSize(QSize(0, 0));
        horizontalLayout_7 = new QHBoxLayout(friend_apply_wid);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_8 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);

        friend_apply_lb = new QLabel(friend_apply_wid);
        friend_apply_lb->setObjectName(QString::fromUtf8("friend_apply_lb"));
        friend_apply_lb->setMinimumSize(QSize(0, 40));
        friend_apply_lb->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_7->addWidget(friend_apply_lb);


        verticalLayout->addWidget(friend_apply_wid);

        widget_3 = new QWidget(ApplyFriendPage);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_7 = new QVBoxLayout(widget_3);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        apply_friend_list = new ApplyFriendList(widget_3);
        apply_friend_list->setObjectName(QString::fromUtf8("apply_friend_list"));

        verticalLayout_7->addWidget(apply_friend_list);


        verticalLayout->addWidget(widget_3);


        retranslateUi(ApplyFriendPage);

        QMetaObject::connectSlotsByName(ApplyFriendPage);
    } // setupUi

    void retranslateUi(QWidget *ApplyFriendPage)
    {
        ApplyFriendPage->setWindowTitle(QApplication::translate("ApplyFriendPage", "Form", nullptr));
        friend_apply_lb->setText(QApplication::translate("ApplyFriendPage", "\346\226\260\347\232\204\346\234\213\345\217\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ApplyFriendPage: public Ui_ApplyFriendPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLYFRIENDPAGE_H
