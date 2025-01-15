/********************************************************************************
** Form generated from reading UI file 'friendinfopage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDINFOPAGE_H
#define UI_FRIENDINFOPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clickedbtn.h"

QT_BEGIN_NAMESPACE

class Ui_FriendInfoPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *icon_lb;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *name_lb;
    QLabel *sex_lb;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *nick_tip;
    QLabel *nick_lb;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *bak_tip;
    QLabel *bak_lb;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    ClickedBtn *msg_chat;
    QSpacerItem *horizontalSpacer_5;
    ClickedBtn *voice_chat;
    QSpacerItem *horizontalSpacer_6;
    ClickedBtn *video_chat;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *FriendInfoPage)
    {
        if (FriendInfoPage->objectName().isEmpty())
            FriendInfoPage->setObjectName(QString::fromUtf8("FriendInfoPage"));
        FriendInfoPage->resize(789, 511);
        verticalLayout = new QVBoxLayout(FriendInfoPage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(120, 120, 120, 120);
        widget = new QWidget(FriendInfoPage);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        icon_lb = new QLabel(widget);
        icon_lb->setObjectName(QString::fromUtf8("icon_lb"));
        icon_lb->setMinimumSize(QSize(85, 85));
        icon_lb->setMaximumSize(QSize(85, 85));

        horizontalLayout->addWidget(icon_lb);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_4 = new QWidget(widget_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(0, 40));
        widget_4->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        name_lb = new QLabel(widget_4);
        name_lb->setObjectName(QString::fromUtf8("name_lb"));
        name_lb->setMinimumSize(QSize(40, 0));
        name_lb->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(name_lb);

        sex_lb = new QLabel(widget_4);
        sex_lb->setObjectName(QString::fromUtf8("sex_lb"));
        sex_lb->setMinimumSize(QSize(40, 40));
        sex_lb->setMaximumSize(QSize(40, 40));

        horizontalLayout_2->addWidget(sex_lb);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(widget_4);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(0, 40));
        widget_2->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        nick_tip = new QLabel(widget_2);
        nick_tip->setObjectName(QString::fromUtf8("nick_tip"));
        nick_tip->setMinimumSize(QSize(0, 30));
        nick_tip->setMaximumSize(QSize(50, 30));

        horizontalLayout_3->addWidget(nick_tip);

        nick_lb = new QLabel(widget_2);
        nick_lb->setObjectName(QString::fromUtf8("nick_lb"));

        horizontalLayout_3->addWidget(nick_lb);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget_2);

        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setMinimumSize(QSize(0, 40));
        widget_5->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        bak_tip = new QLabel(widget_5);
        bak_tip->setObjectName(QString::fromUtf8("bak_tip"));
        bak_tip->setMinimumSize(QSize(0, 30));
        bak_tip->setMaximumSize(QSize(50, 30));

        horizontalLayout_4->addWidget(bak_tip);

        bak_lb = new QLabel(widget_5);
        bak_lb->setObjectName(QString::fromUtf8("bak_lb"));

        horizontalLayout_4->addWidget(bak_lb);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        verticalLayout_2->addWidget(widget_5);


        horizontalLayout->addWidget(widget_3);


        verticalLayout->addWidget(widget);

        widget_6 = new QWidget(FriendInfoPage);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        msg_chat = new ClickedBtn(widget_6);
        msg_chat->setObjectName(QString::fromUtf8("msg_chat"));
        msg_chat->setMinimumSize(QSize(50, 50));
        msg_chat->setMaximumSize(QSize(50, 50));

        horizontalLayout_5->addWidget(msg_chat);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        voice_chat = new ClickedBtn(widget_6);
        voice_chat->setObjectName(QString::fromUtf8("voice_chat"));
        voice_chat->setMinimumSize(QSize(50, 50));
        voice_chat->setMaximumSize(QSize(50, 50));

        horizontalLayout_5->addWidget(voice_chat);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        video_chat = new ClickedBtn(widget_6);
        video_chat->setObjectName(QString::fromUtf8("video_chat"));
        video_chat->setMinimumSize(QSize(50, 50));
        video_chat->setMaximumSize(QSize(50, 50));

        horizontalLayout_5->addWidget(video_chat);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(FriendInfoPage);

        QMetaObject::connectSlotsByName(FriendInfoPage);
    } // setupUi

    void retranslateUi(QWidget *FriendInfoPage)
    {
        FriendInfoPage->setWindowTitle(QApplication::translate("FriendInfoPage", "Form", nullptr));
        icon_lb->setText(QString());
        name_lb->setText(QApplication::translate("FriendInfoPage", "\347\220\263\347\220\263", nullptr));
        sex_lb->setText(QString());
        nick_tip->setText(QApplication::translate("FriendInfoPage", "\346\230\265\347\247\260\357\274\232", nullptr));
        nick_lb->setText(QApplication::translate("FriendInfoPage", "\347\220\263\347\220\263", nullptr));
        bak_tip->setText(QApplication::translate("FriendInfoPage", "\345\244\207\346\263\250\357\274\232", nullptr));
        bak_lb->setText(QApplication::translate("FriendInfoPage", "\347\220\263\347\220\263", nullptr));
        msg_chat->setText(QString());
        voice_chat->setText(QString());
        video_chat->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FriendInfoPage: public Ui_FriendInfoPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDINFOPAGE_H
