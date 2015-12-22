/********************************************************************************
** Form generated from reading UI file 'window_qcodec.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_QCODEC_H
#define UI_WINDOW_QCODEC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_window_QCodec
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *button_for_encoding;
    QPushButton *button_decoding;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *window_QCodec)
    {
        if (window_QCodec->objectName().isEmpty())
            window_QCodec->setObjectName(QStringLiteral("window_QCodec"));
        window_QCodec->resize(397, 155);
        centralWidget = new QWidget(window_QCodec);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_5 = new QHBoxLayout(centralWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        button_for_encoding = new QPushButton(centralWidget);
        button_for_encoding->setObjectName(QStringLiteral("button_for_encoding"));

        horizontalLayout_4->addWidget(button_for_encoding);

        button_decoding = new QPushButton(centralWidget);
        button_decoding->setObjectName(QStringLiteral("button_decoding"));

        horizontalLayout_4->addWidget(button_decoding);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        window_QCodec->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(window_QCodec);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 397, 23));
        window_QCodec->setMenuBar(menuBar);
        mainToolBar = new QToolBar(window_QCodec);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        window_QCodec->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(window_QCodec);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        window_QCodec->setStatusBar(statusBar);

        retranslateUi(window_QCodec);

        QMetaObject::connectSlotsByName(window_QCodec);
    } // setupUi

    void retranslateUi(QMainWindow *window_QCodec)
    {
        window_QCodec->setWindowTitle(QApplication::translate("window_QCodec", "window_QCodec", 0));
        button_for_encoding->setText(QApplication::translate("window_QCodec", "encoding", 0));
        button_decoding->setText(QApplication::translate("window_QCodec", "decoding", 0));
    } // retranslateUi

};

namespace Ui {
    class window_QCodec: public Ui_window_QCodec {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_QCODEC_H
