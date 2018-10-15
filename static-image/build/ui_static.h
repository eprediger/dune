/********************************************************************************
** Form generated from reading UI file 'static.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATIC_H
#define UI_STATIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Static
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLabel *label_img;
    QLabel *label_text;

    void setupUi(QWidget *Static)
    {
        if (Static->objectName().isEmpty())
            Static->setObjectName(QStringLiteral("Static"));
        Static->setEnabled(true);
        Static->resize(640, 480);
        Static->setAutoFillBackground(false);
        horizontalLayout = new QHBoxLayout(Static);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_img = new QLabel(Static);
        label_img->setObjectName(QStringLiteral("label_img"));
        label_img->setPixmap(QPixmap(QString::fromUtf8("../../imgs/imgs/000a0ad1.bmp")));
        label_img->setScaledContents(false);
        label_img->setWordWrap(false);

        gridLayout->addWidget(label_img, 0, 0, 1, 1);

        label_text = new QLabel(Static);
        label_text->setObjectName(QStringLiteral("label_text"));
        label_text->setWordWrap(true);

        gridLayout->addWidget(label_text, 0, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(Static);

        QMetaObject::connectSlotsByName(Static);
    } // setupUi

    void retranslateUi(QWidget *Static)
    {
        Static->setWindowTitle(QApplication::translate("Static", "Form", 0));
        label_img->setText(QString());
        label_text->setText(QApplication::translate("Static", "Image Test", 0));
    } // retranslateUi

};

namespace Ui {
    class Static: public Ui_Static {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATIC_H
