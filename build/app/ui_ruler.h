/********************************************************************************
** Form generated from reading UI file 'ruler.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULER_H
#define UI_RULER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ruler
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QProgressBar *progressBar;

    void setupUi(QWidget *Ruler)
    {
        if (Ruler->objectName().isEmpty())
            Ruler->setObjectName(QString::fromUtf8("Ruler"));
        Ruler->resize(192, 70);
        Ruler->setMinimumSize(QSize(192, 70));
        Ruler->setMaximumSize(QSize(192, 16777215));
        verticalLayout = new QVBoxLayout(Ruler);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Ruler);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 18pt \"\351\273\221\344\275\223\";\n"
"color:gray;"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label);

        progressBar = new QProgressBar(Ruler);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"          border: 1px solid #b6b6b6;\n"
"          border-radius: 5px;\n"
"          background-color: white;\n"
"        }\n"
"        QProgressBar::chunk {\n"
"           background-color: #787878;\n"
"           width: 10px;\n"
"           margin: 0px;\n"
"        }"));
        progressBar->setMaximum(40);
        progressBar->setValue(20);
        progressBar->setTextVisible(false);

        verticalLayout->addWidget(progressBar);


        retranslateUi(Ruler);

        QMetaObject::connectSlotsByName(Ruler);
    } // setupUi

    void retranslateUi(QWidget *Ruler)
    {
        Ruler->setWindowTitle(QApplication::translate("Ruler", "Form", nullptr));
        label->setText(QApplication::translate("Ruler", "20um", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ruler: public Ui_Ruler {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULER_H
