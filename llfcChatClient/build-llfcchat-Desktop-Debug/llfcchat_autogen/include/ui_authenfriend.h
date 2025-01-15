/********************************************************************************
** Form generated from reading UI file 'authenfriend.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHENFRIEND_H
#define UI_AUTHENFRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clickedbtn.h"
#include "clickedoncelabel.h"
#include "customizeedit.h"

QT_BEGIN_NAMESPACE

class Ui_AuthenFriend
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollcontent;
    QVBoxLayout *verticalLayout_6;
    QLabel *apply_lb;
    QWidget *apply_wid;
    QVBoxLayout *verticalLayout_2;
    QFrame *h_line;
    QLabel *label_2;
    CustomizeEdit *back_ed;
    QLabel *label_3;
    QWidget *lb_group_wid;
    QVBoxLayout *verticalLayout_4;
    QWidget *gridWidget;
    CustomizeEdit *lb_ed;
    QWidget *input_tip_wid;
    QVBoxLayout *verticalLayout_5;
    ClickedOnceLabel *tip_lb;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *lb_list;
    QWidget *more_lb_wid;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    ClickedOnceLabel *more_lb;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QWidget *apply_sure_wid;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    ClickedBtn *sure_btn;
    QSpacerItem *horizontalSpacer_3;
    ClickedBtn *cancel_btn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *AuthenFriend)
    {
        if (AuthenFriend->objectName().isEmpty())
            AuthenFriend->setObjectName(QString::fromUtf8("AuthenFriend"));
        AuthenFriend->resize(361, 621);
        AuthenFriend->setMinimumSize(QSize(361, 621));
        AuthenFriend->setMaximumSize(QSize(361, 621));
        verticalLayout = new QVBoxLayout(AuthenFriend);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(AuthenFriend);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(0, 500));
        scrollArea->setWidgetResizable(true);
        scrollcontent = new QWidget();
        scrollcontent->setObjectName(QString::fromUtf8("scrollcontent"));
        scrollcontent->setGeometry(QRect(0, 0, 359, 498));
        verticalLayout_6 = new QVBoxLayout(scrollcontent);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, -1, 0, -1);
        apply_lb = new QLabel(scrollcontent);
        apply_lb->setObjectName(QString::fromUtf8("apply_lb"));
        apply_lb->setMinimumSize(QSize(0, 25));
        apply_lb->setMaximumSize(QSize(16777215, 25));
        apply_lb->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(apply_lb);

        apply_wid = new QWidget(scrollcontent);
        apply_wid->setObjectName(QString::fromUtf8("apply_wid"));
        verticalLayout_2 = new QVBoxLayout(apply_wid);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        h_line = new QFrame(apply_wid);
        h_line->setObjectName(QString::fromUtf8("h_line"));
        h_line->setFrameShape(QFrame::HLine);
        h_line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(h_line);

        label_2 = new QLabel(apply_wid);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 25));
        label_2->setMaximumSize(QSize(16777215, 25));

        verticalLayout_2->addWidget(label_2);

        back_ed = new CustomizeEdit(apply_wid);
        back_ed->setObjectName(QString::fromUtf8("back_ed"));
        back_ed->setMinimumSize(QSize(0, 35));
        back_ed->setMaximumSize(QSize(16777215, 35));

        verticalLayout_2->addWidget(back_ed);

        label_3 = new QLabel(apply_wid);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 25));
        label_3->setMaximumSize(QSize(16777215, 25));

        verticalLayout_2->addWidget(label_3);

        lb_group_wid = new QWidget(apply_wid);
        lb_group_wid->setObjectName(QString::fromUtf8("lb_group_wid"));
        lb_group_wid->setMinimumSize(QSize(0, 50));
        verticalLayout_4 = new QVBoxLayout(lb_group_wid);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        gridWidget = new QWidget(lb_group_wid);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setMinimumSize(QSize(0, 40));
        gridWidget->setMaximumSize(QSize(16777215, 40));
        lb_ed = new CustomizeEdit(gridWidget);
        lb_ed->setObjectName(QString::fromUtf8("lb_ed"));
        lb_ed->setGeometry(QRect(2, 2, 108, 35));
        lb_ed->setMinimumSize(QSize(0, 0));
        lb_ed->setMaximumSize(QSize(16777215, 35));

        verticalLayout_4->addWidget(gridWidget);

        input_tip_wid = new QWidget(lb_group_wid);
        input_tip_wid->setObjectName(QString::fromUtf8("input_tip_wid"));
        input_tip_wid->setMinimumSize(QSize(0, 35));
        verticalLayout_5 = new QVBoxLayout(input_tip_wid);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        tip_lb = new ClickedOnceLabel(input_tip_wid);
        tip_lb->setObjectName(QString::fromUtf8("tip_lb"));
        tip_lb->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_5->addWidget(tip_lb);


        verticalLayout_4->addWidget(input_tip_wid);


        verticalLayout_2->addWidget(lb_group_wid);

        widget = new QWidget(apply_wid);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 60));
        widget->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lb_list = new QWidget(widget);
        lb_list->setObjectName(QString::fromUtf8("lb_list"));
        lb_list->setMinimumSize(QSize(287, 50));
        lb_list->setMaximumSize(QSize(287, 16777215));

        horizontalLayout->addWidget(lb_list);

        more_lb_wid = new QWidget(widget);
        more_lb_wid->setObjectName(QString::fromUtf8("more_lb_wid"));
        more_lb_wid->setMinimumSize(QSize(30, 0));
        more_lb_wid->setMaximumSize(QSize(30, 16777215));
        verticalLayout_3 = new QVBoxLayout(more_lb_wid);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        more_lb = new ClickedOnceLabel(more_lb_wid);
        more_lb->setObjectName(QString::fromUtf8("more_lb"));
        more_lb->setMinimumSize(QSize(25, 25));
        more_lb->setMaximumSize(QSize(25, 25));

        verticalLayout_3->addWidget(more_lb);

        verticalSpacer_4 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_4);


        horizontalLayout->addWidget(more_lb_wid);


        verticalLayout_2->addWidget(widget);


        verticalLayout_6->addWidget(apply_wid);

        scrollArea->setWidget(scrollcontent);

        verticalLayout->addWidget(scrollArea);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        apply_sure_wid = new QWidget(AuthenFriend);
        apply_sure_wid->setObjectName(QString::fromUtf8("apply_sure_wid"));
        apply_sure_wid->setMinimumSize(QSize(0, 50));
        horizontalLayout_2 = new QHBoxLayout(apply_sure_wid);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(39, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        sure_btn = new ClickedBtn(apply_sure_wid);
        sure_btn->setObjectName(QString::fromUtf8("sure_btn"));
        sure_btn->setMinimumSize(QSize(100, 30));
        sure_btn->setMaximumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(sure_btn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        cancel_btn = new ClickedBtn(apply_sure_wid);
        cancel_btn->setObjectName(QString::fromUtf8("cancel_btn"));
        cancel_btn->setMinimumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(cancel_btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(apply_sure_wid);

        verticalSpacer = new QSpacerItem(20, 55, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(AuthenFriend);

        QMetaObject::connectSlotsByName(AuthenFriend);
    } // setupUi

    void retranslateUi(QDialog *AuthenFriend)
    {
        AuthenFriend->setWindowTitle(QApplication::translate("AuthenFriend", "Dialog", nullptr));
        apply_lb->setText(QApplication::translate("AuthenFriend", "\351\200\232\350\277\207\346\234\213\345\217\213\351\252\214\350\257\201", nullptr));
        label_2->setText(QApplication::translate("AuthenFriend", "\345\244\207\346\263\250\345\220\215", nullptr));
        label_3->setText(QApplication::translate("AuthenFriend", "\346\240\207\347\255\276", nullptr));
        tip_lb->setText(QApplication::translate("AuthenFriend", "TextLabel", nullptr));
        more_lb->setText(QString());
        sure_btn->setText(QApplication::translate("AuthenFriend", "\347\241\256\350\256\244", nullptr));
        cancel_btn->setText(QApplication::translate("AuthenFriend", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthenFriend: public Ui_AuthenFriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHENFRIEND_H
