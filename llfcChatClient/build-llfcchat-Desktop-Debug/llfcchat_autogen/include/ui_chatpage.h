/********************************************************************************
** Form generated from reading UI file 'chatpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATPAGE_H
#define UI_CHATPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MessageTextEdit.h"
#include "chatview.h"
#include "clickedbtn.h"
#include "clickedlabel.h"

QT_BEGIN_NAMESPACE

class Ui_ChatPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *chat_data_wid;
    QVBoxLayout *verticalLayout_2;
    QWidget *title_wid;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *title_lb;
    ChatView *chat_data_list;
    QWidget *tool_wid;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    ClickedLabel *emo_lb;
    QSpacerItem *horizontalSpacer_6;
    ClickedLabel *file_lb;
    QSpacerItem *horizontalSpacer_5;
    MessageTextEdit *chatEdit;
    QWidget *send_wid;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    ClickedBtn *receive_btn;
    QSpacerItem *horizontalSpacer_3;
    ClickedBtn *send_btn;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *ChatPage)
    {
        if (ChatPage->objectName().isEmpty())
            ChatPage->setObjectName(QString::fromUtf8("ChatPage"));
        ChatPage->resize(555, 531);
        verticalLayout = new QVBoxLayout(ChatPage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        chat_data_wid = new QWidget(ChatPage);
        chat_data_wid->setObjectName(QString::fromUtf8("chat_data_wid"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chat_data_wid->sizePolicy().hasHeightForWidth());
        chat_data_wid->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(chat_data_wid);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        title_wid = new QWidget(chat_data_wid);
        title_wid->setObjectName(QString::fromUtf8("title_wid"));
        title_wid->setMinimumSize(QSize(0, 60));
        title_wid->setMaximumSize(QSize(16777215, 60));
        verticalLayout_3 = new QVBoxLayout(title_wid);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(11, 2, 2, 2);
        widget = new QWidget(title_wid);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(2, 2, 2, 2);
        title_lb = new QLabel(widget);
        title_lb->setObjectName(QString::fromUtf8("title_lb"));

        horizontalLayout_3->addWidget(title_lb);


        verticalLayout_3->addWidget(widget);


        verticalLayout_2->addWidget(title_wid);

        chat_data_list = new ChatView(chat_data_wid);
        chat_data_list->setObjectName(QString::fromUtf8("chat_data_list"));

        verticalLayout_2->addWidget(chat_data_list);

        tool_wid = new QWidget(chat_data_wid);
        tool_wid->setObjectName(QString::fromUtf8("tool_wid"));
        tool_wid->setMinimumSize(QSize(0, 40));
        tool_wid->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_5 = new QHBoxLayout(tool_wid);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(2, 2, 2, 2);
        horizontalSpacer_7 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        emo_lb = new ClickedLabel(tool_wid);
        emo_lb->setObjectName(QString::fromUtf8("emo_lb"));
        emo_lb->setMinimumSize(QSize(25, 25));
        emo_lb->setMaximumSize(QSize(25, 25));

        horizontalLayout_5->addWidget(emo_lb);

        horizontalSpacer_6 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        file_lb = new ClickedLabel(tool_wid);
        file_lb->setObjectName(QString::fromUtf8("file_lb"));
        file_lb->setMinimumSize(QSize(30, 30));
        file_lb->setMaximumSize(QSize(30, 30));

        horizontalLayout_5->addWidget(file_lb);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_2->addWidget(tool_wid);

        chatEdit = new MessageTextEdit(chat_data_wid);
        chatEdit->setObjectName(QString::fromUtf8("chatEdit"));
        chatEdit->setMinimumSize(QSize(0, 150));
        chatEdit->setMaximumSize(QSize(16777215, 150));
        chatEdit->setFrameShape(QFrame::NoFrame);

        verticalLayout_2->addWidget(chatEdit);

        send_wid = new QWidget(chat_data_wid);
        send_wid->setObjectName(QString::fromUtf8("send_wid"));
        send_wid->setMinimumSize(QSize(0, 40));
        send_wid->setMaximumSize(QSize(16777215, 40));
        horizontalLayout_4 = new QHBoxLayout(send_wid);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 2, -1, 2);
        horizontalSpacer_2 = new QSpacerItem(36, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        receive_btn = new ClickedBtn(send_wid);
        receive_btn->setObjectName(QString::fromUtf8("receive_btn"));
        receive_btn->setMinimumSize(QSize(100, 30));
        receive_btn->setMaximumSize(QSize(100, 30));

        horizontalLayout_4->addWidget(receive_btn);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        send_btn = new ClickedBtn(send_wid);
        send_btn->setObjectName(QString::fromUtf8("send_btn"));
        send_btn->setMinimumSize(QSize(100, 30));
        send_btn->setMaximumSize(QSize(100, 30));

        horizontalLayout_4->addWidget(send_btn);

        horizontalSpacer_4 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_2->addWidget(send_wid);


        verticalLayout->addWidget(chat_data_wid);


        retranslateUi(ChatPage);

        QMetaObject::connectSlotsByName(ChatPage);
    } // setupUi

    void retranslateUi(QWidget *ChatPage)
    {
        ChatPage->setWindowTitle(QApplication::translate("ChatPage", "Form", nullptr));
        title_lb->setText(QApplication::translate("ChatPage", "\347\207\203\347\203\247\347\232\204\350\203\270\346\257\233", nullptr));
        emo_lb->setText(QString());
        file_lb->setText(QString());
        receive_btn->setText(QApplication::translate("ChatPage", "\346\216\245\346\224\266", nullptr));
        send_btn->setText(QApplication::translate("ChatPage", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatPage: public Ui_ChatPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATPAGE_H
