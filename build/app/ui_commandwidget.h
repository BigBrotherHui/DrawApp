/********************************************************************************
** Form generated from reading UI file 'commandwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMANDWIDGET_H
#define UI_COMMANDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommandWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_wireSpace;
    QPushButton *pushButton_remove;
    QPushButton *pushButton_netPriority;
    QPushButton *pushButton_reroute;
    QPushButton *pushButton_netTopo;
    QLabel *label_3;
    QPushButton *pushButton_wireWidth;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_autoPlace;
    QLabel *label;
    QPushButton *pushButton_autoRoute;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QPushButton *pushButton_move;
    QPushButton *pushButton_space;
    QPushButton *pushButton_swap;
    QPushButton *pushButton_arrayAdd;
    QPushButton *pushButton_symAdd;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *lineEdit;

    void setupUi(QWidget *CommandWidget)
    {
        if (CommandWidget->objectName().isEmpty())
            CommandWidget->setObjectName(QString::fromUtf8("CommandWidget"));
        CommandWidget->resize(540, 769);
        CommandWidget->setStyleSheet(QString::fromUtf8("QPlainTextEdit QScrollBar\n"
"{\n"
"background:#131720;\n"
"}\n"
"QPlainTextEdit QScrollBar::handle\n"
"{\n"
"background:#1167CF;\n"
"min-height:50px;\n"
"}\n"
"QPlainTextEdit QScrollBar::add-line\n"
"{\n"
"border: none;\n"
"background:#131720;\n"
"}\n"
"QPlainTextEdit QScrollBar::sub-line\n"
"{\n"
"border:none;\n"
"background:#131720;\n"
"}\n"
"#plainTextEdit_info QScrollBar::add-page\n"
"{\n"
"background:#131720;\n"
"}\n"
"QPlainTextEdit QScrollBar::sub-page\n"
"{\n"
"background:#131720;\n"
"}\n"
"QPlainTextEdit\n"
"{\n"
"background: #2c313e;\n"
"border:2px solid #a1a1a1;\n"
"font-size: 16px;\n"
"font-family: \"\346\200\235\346\272\220\351\273\221\344\275\223 CN Medium\";\n"
"font-weight: 500;\n"
"color: #ffffff;\n"
"selection-background-color: #1167cf;\n"
"}\n"
"QLabel\n"
"{\n"
"font-size: 18px;\n"
"font-family: \"\346\200\235\346\272\220\351\273\221\344\275\223 CN Medium\";\n"
"font-weight: 500;\n"
"color: #AFB0B3;\n"
"}\n"
"QPushButton{\n"
"border: 2px solid #bbff73;\n"
"border-radius: 22px;\n"
"backgroun"
                        "d-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"stop:0 #e2ffc6,stop:1 #2A3345);\n"
"color: #DFE1E6;\n"
"font-size: 18px;\n"
"font-family: \"\346\200\235\346\272\220\351\273\221\344\275\223 CN Medium\";\n"
"font-weight: 500;\n"
"}\n"
"QPushButton:hover{\n"
"background: #f5ffe9;\n"
"color: #DFE1E6;\n"
"font-size: 18px;\n"
"font-family: \"\346\200\235\346\272\220\351\273\221\344\275\223 CN Medium\";\n"
"font-weight: 500;\n"
"}\n"
".GrayButton:pressed {\n"
"background: #5aff3d;\n"
"color: #DFE1E6;\n"
"font-size: 18px;\n"
"font-family: \"\346\200\235\346\272\220\351\273\221\344\275\223 CN Medium\";\n"
"font-weight: 500;\n"
"}\n"
"QPushButton:disabled {\n"
"border: 2px solid #282E3B;\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"stop:0 #70ff75,stop:1 #6aff49);\n"
"color: #5C6069;\n"
"font-size: 18px;\n"
"font-family: \"\346\200\235\346\272\220\351\273\221\344\275\223 CN Medium\";\n"
"font-weight: 500;\n"
"}\n"
"* {\n"
"    font-family: \"\346\200\235\346\272\220\351\273\221\344\275\223 CN Medium\""
                        ";\n"
"    font-size:15px;\n"
"    /*background-color: #2d2d30;*/\n"
"    color: #c7c7c7;\n"
"}"));
        verticalLayout = new QVBoxLayout(CommandWidget);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(20);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_wireSpace = new QPushButton(CommandWidget);
        pushButton_wireSpace->setObjectName(QString::fromUtf8("pushButton_wireSpace"));
        pushButton_wireSpace->setMinimumSize(QSize(160, 44));

        gridLayout_3->addWidget(pushButton_wireSpace, 2, 1, 1, 1);

        pushButton_remove = new QPushButton(CommandWidget);
        pushButton_remove->setObjectName(QString::fromUtf8("pushButton_remove"));
        pushButton_remove->setMinimumSize(QSize(160, 44));

        gridLayout_3->addWidget(pushButton_remove, 1, 0, 1, 1);

        pushButton_netPriority = new QPushButton(CommandWidget);
        pushButton_netPriority->setObjectName(QString::fromUtf8("pushButton_netPriority"));
        pushButton_netPriority->setMinimumSize(QSize(160, 44));

        gridLayout_3->addWidget(pushButton_netPriority, 3, 0, 1, 1);

        pushButton_reroute = new QPushButton(CommandWidget);
        pushButton_reroute->setObjectName(QString::fromUtf8("pushButton_reroute"));
        pushButton_reroute->setMinimumSize(QSize(160, 44));

        gridLayout_3->addWidget(pushButton_reroute, 1, 1, 1, 1);

        pushButton_netTopo = new QPushButton(CommandWidget);
        pushButton_netTopo->setObjectName(QString::fromUtf8("pushButton_netTopo"));
        pushButton_netTopo->setMinimumSize(QSize(160, 44));

        gridLayout_3->addWidget(pushButton_netTopo, 3, 1, 1, 1);

        label_3 = new QLabel(CommandWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 44));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 2);

        pushButton_wireWidth = new QPushButton(CommandWidget);
        pushButton_wireWidth->setObjectName(QString::fromUtf8("pushButton_wireWidth"));
        pushButton_wireWidth->setMinimumSize(QSize(160, 44));

        gridLayout_3->addWidget(pushButton_wireWidth, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(20);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_autoPlace = new QPushButton(CommandWidget);
        pushButton_autoPlace->setObjectName(QString::fromUtf8("pushButton_autoPlace"));
        pushButton_autoPlace->setMinimumSize(QSize(160, 44));

        gridLayout->addWidget(pushButton_autoPlace, 1, 0, 1, 1);

        label = new QLabel(CommandWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 44));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        pushButton_autoRoute = new QPushButton(CommandWidget);
        pushButton_autoRoute->setObjectName(QString::fromUtf8("pushButton_autoRoute"));
        pushButton_autoRoute->setMinimumSize(QSize(160, 44));

        gridLayout->addWidget(pushButton_autoRoute, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(20);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(CommandWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 44));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 2);

        pushButton_move = new QPushButton(CommandWidget);
        pushButton_move->setObjectName(QString::fromUtf8("pushButton_move"));
        pushButton_move->setMinimumSize(QSize(160, 44));

        gridLayout_2->addWidget(pushButton_move, 1, 0, 1, 1);

        pushButton_space = new QPushButton(CommandWidget);
        pushButton_space->setObjectName(QString::fromUtf8("pushButton_space"));
        pushButton_space->setMinimumSize(QSize(160, 44));

        gridLayout_2->addWidget(pushButton_space, 1, 1, 1, 1);

        pushButton_swap = new QPushButton(CommandWidget);
        pushButton_swap->setObjectName(QString::fromUtf8("pushButton_swap"));
        pushButton_swap->setMinimumSize(QSize(160, 44));

        gridLayout_2->addWidget(pushButton_swap, 1, 2, 1, 1);

        pushButton_arrayAdd = new QPushButton(CommandWidget);
        pushButton_arrayAdd->setObjectName(QString::fromUtf8("pushButton_arrayAdd"));
        pushButton_arrayAdd->setMinimumSize(QSize(160, 44));

        gridLayout_2->addWidget(pushButton_arrayAdd, 2, 0, 1, 1);

        pushButton_symAdd = new QPushButton(CommandWidget);
        pushButton_symAdd->setObjectName(QString::fromUtf8("pushButton_symAdd"));
        pushButton_symAdd->setMinimumSize(QSize(160, 44));

        gridLayout_2->addWidget(pushButton_symAdd, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        plainTextEdit = new QPlainTextEdit(CommandWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(CommandWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        lineEdit = new QLineEdit(CommandWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 44));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CommandWidget);

        QMetaObject::connectSlotsByName(CommandWidget);
    } // setupUi

    void retranslateUi(QWidget *CommandWidget)
    {
        CommandWidget->setWindowTitle(QApplication::translate("CommandWidget", "Form", nullptr));
        pushButton_wireSpace->setText(QApplication::translate("CommandWidget", "wireSpace", nullptr));
        pushButton_remove->setText(QApplication::translate("CommandWidget", "Remove", nullptr));
        pushButton_netPriority->setText(QApplication::translate("CommandWidget", "netPriority", nullptr));
        pushButton_reroute->setText(QApplication::translate("CommandWidget", "Reroute", nullptr));
        pushButton_netTopo->setText(QApplication::translate("CommandWidget", "netTopo", nullptr));
        label_3->setText(QApplication::translate("CommandWidget", "Interactive Routing", nullptr));
        pushButton_wireWidth->setText(QApplication::translate("CommandWidget", "wireWidth", nullptr));
        pushButton_autoPlace->setText(QApplication::translate("CommandWidget", "Auto Place", nullptr));
        label->setText(QApplication::translate("CommandWidget", "Paprika", nullptr));
        pushButton_autoRoute->setText(QApplication::translate("CommandWidget", "Auto Route", nullptr));
        label_2->setText(QApplication::translate("CommandWidget", "Interactive Placement", nullptr));
        pushButton_move->setText(QApplication::translate("CommandWidget", "Move", nullptr));
        pushButton_space->setText(QApplication::translate("CommandWidget", "Space", nullptr));
        pushButton_swap->setText(QApplication::translate("CommandWidget", "Swap", nullptr));
        pushButton_arrayAdd->setText(QApplication::translate("CommandWidget", "arrayAdd", nullptr));
        pushButton_symAdd->setText(QApplication::translate("CommandWidget", "symAdd", nullptr));
        label_4->setText(QApplication::translate("CommandWidget", "Command $", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommandWidget: public Ui_CommandWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMANDWIDGET_H
