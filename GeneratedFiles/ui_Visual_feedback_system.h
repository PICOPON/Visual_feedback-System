/********************************************************************************
** Form generated from reading UI file 'Visual_feedback_system.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUAL_FEEDBACK_SYSTEM_H
#define UI_VISUAL_FEEDBACK_SYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Visual_feedback_systemClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Visual_feedback_systemClass)
    {
        if (Visual_feedback_systemClass->objectName().isEmpty())
            Visual_feedback_systemClass->setObjectName(QStringLiteral("Visual_feedback_systemClass"));
        Visual_feedback_systemClass->resize(1093, 837);
        centralWidget = new QWidget(Visual_feedback_systemClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(410, 300, 93, 28));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(420, 270, 72, 15));
        Visual_feedback_systemClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Visual_feedback_systemClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1093, 26));
        Visual_feedback_systemClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Visual_feedback_systemClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Visual_feedback_systemClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Visual_feedback_systemClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Visual_feedback_systemClass->setStatusBar(statusBar);

        retranslateUi(Visual_feedback_systemClass);
        QObject::connect(pushButton, SIGNAL(clicked()), Visual_feedback_systemClass, SLOT(on_AddButton_Clicked()));

        QMetaObject::connectSlotsByName(Visual_feedback_systemClass);
    } // setupUi

    void retranslateUi(QMainWindow *Visual_feedback_systemClass)
    {
        Visual_feedback_systemClass->setWindowTitle(QApplication::translate("Visual_feedback_systemClass", "Visual_feedback_system", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Visual_feedback_systemClass", "PushButton", Q_NULLPTR));
        label->setText(QApplication::translate("Visual_feedback_systemClass", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Visual_feedback_systemClass: public Ui_Visual_feedback_systemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUAL_FEEDBACK_SYSTEM_H
