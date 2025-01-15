/********************************************************************************
** Form generated from reading UI file 'lineitem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEITEM_H
#define UI_LINEITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LineItem
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *line;

    void setupUi(QWidget *LineItem)
    {
        if (LineItem->objectName().isEmpty())
            LineItem->setObjectName(QString::fromUtf8("LineItem"));
        LineItem->resize(400, 16);
        LineItem->setMinimumSize(QSize(0, 5));
        LineItem->setMaximumSize(QSize(16777215, 16));
        verticalLayout = new QVBoxLayout(LineItem);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(LineItem);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);


        retranslateUi(LineItem);

        QMetaObject::connectSlotsByName(LineItem);
    } // setupUi

    void retranslateUi(QWidget *LineItem)
    {
        LineItem->setWindowTitle(QApplication::translate("LineItem", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LineItem: public Ui_LineItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEITEM_H
