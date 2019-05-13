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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QPushButton *PortSelectBtn;
    QLabel *DeviceNum_Label;
    QComboBox *ComboBox_DEVICE_LIST;
    QLineEdit *TextBox_CAPTURE_COL_START;
    QLabel *colstart;
    QLabel *colsize;
    QLabel *rolstart;
    QLabel *rowsize;
    QLineEdit *TextBox_CAPTURE_ROW_START;
    QLineEdit *TextBox_CAPTURE_COL_SIZE;
    QLineEdit *TextBox_CAPTURE_ROW_SIZE;
    QPushButton *pushButton;
    QLabel *pic_label;
    QPushButton *setcapture;
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
        PortSelectBtn = new QPushButton(centralWidget);
        PortSelectBtn->setObjectName(QStringLiteral("PortSelectBtn"));
        PortSelectBtn->setGeometry(QRect(90, 90, 93, 28));
        DeviceNum_Label = new QLabel(centralWidget);
        DeviceNum_Label->setObjectName(QStringLiteral("DeviceNum_Label"));
        DeviceNum_Label->setGeometry(QRect(310, 80, 81, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font.setPointSize(11);
        DeviceNum_Label->setFont(font);
        DeviceNum_Label->setAlignment(Qt::AlignCenter);
        ComboBox_DEVICE_LIST = new QComboBox(centralWidget);
        ComboBox_DEVICE_LIST->setObjectName(QStringLiteral("ComboBox_DEVICE_LIST"));
        ComboBox_DEVICE_LIST->setGeometry(QRect(210, 90, 87, 22));
        TextBox_CAPTURE_COL_START = new QLineEdit(centralWidget);
        TextBox_CAPTURE_COL_START->setObjectName(QStringLiteral("TextBox_CAPTURE_COL_START"));
        TextBox_CAPTURE_COL_START->setGeometry(QRect(190, 150, 113, 21));
        colstart = new QLabel(centralWidget);
        colstart->setObjectName(QStringLiteral("colstart"));
        colstart->setGeometry(QRect(100, 150, 72, 15));
        colsize = new QLabel(centralWidget);
        colsize->setObjectName(QStringLiteral("colsize"));
        colsize->setGeometry(QRect(100, 230, 72, 15));
        rolstart = new QLabel(centralWidget);
        rolstart->setObjectName(QStringLiteral("rolstart"));
        rolstart->setGeometry(QRect(360, 150, 72, 15));
        rowsize = new QLabel(centralWidget);
        rowsize->setObjectName(QStringLiteral("rowsize"));
        rowsize->setGeometry(QRect(360, 230, 72, 15));
        TextBox_CAPTURE_ROW_START = new QLineEdit(centralWidget);
        TextBox_CAPTURE_ROW_START->setObjectName(QStringLiteral("TextBox_CAPTURE_ROW_START"));
        TextBox_CAPTURE_ROW_START->setGeometry(QRect(460, 150, 113, 21));
        TextBox_CAPTURE_COL_SIZE = new QLineEdit(centralWidget);
        TextBox_CAPTURE_COL_SIZE->setObjectName(QStringLiteral("TextBox_CAPTURE_COL_SIZE"));
        TextBox_CAPTURE_COL_SIZE->setGeometry(QRect(190, 230, 113, 21));
        TextBox_CAPTURE_ROW_SIZE = new QLineEdit(centralWidget);
        TextBox_CAPTURE_ROW_SIZE->setObjectName(QStringLiteral("TextBox_CAPTURE_ROW_SIZE"));
        TextBox_CAPTURE_ROW_SIZE->setGeometry(QRect(460, 230, 113, 21));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(710, 230, 93, 28));
        pic_label = new QLabel(centralWidget);
        pic_label->setObjectName(QStringLiteral("pic_label"));
        pic_label->setGeometry(QRect(110, 310, 791, 401));
        pic_label->setPixmap(QPixmap(QString::fromUtf8("E:/\345\233\276\347\211\207\350\247\206\351\242\221/1800-1BG.jpg")));
        pic_label->setScaledContents(true);
        pic_label->setAlignment(Qt::AlignCenter);
        pic_label->setWordWrap(false);
        setcapture = new QPushButton(centralWidget);
        setcapture->setObjectName(QStringLiteral("setcapture"));
        setcapture->setGeometry(QRect(690, 150, 161, 28));
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
        QObject::connect(PortSelectBtn, SIGNAL(clicked()), Visual_feedback_systemClass, SLOT(on_AddButton_Clicked()));

        QMetaObject::connectSlotsByName(Visual_feedback_systemClass);
    } // setupUi

    void retranslateUi(QMainWindow *Visual_feedback_systemClass)
    {
        Visual_feedback_systemClass->setWindowTitle(QApplication::translate("Visual_feedback_systemClass", "Visual_feedback_system", Q_NULLPTR));
        PortSelectBtn->setText(QApplication::translate("Visual_feedback_systemClass", "\351\200\211\346\213\251\347\233\270\346\234\272", Q_NULLPTR));
        DeviceNum_Label->setText(QApplication::translate("Visual_feedback_systemClass", "\347\233\270\346\234\272\346\225\260", Q_NULLPTR));
        colstart->setText(QApplication::translate("Visual_feedback_systemClass", "col start", Q_NULLPTR));
        colsize->setText(QApplication::translate("Visual_feedback_systemClass", "col size", Q_NULLPTR));
        rolstart->setText(QApplication::translate("Visual_feedback_systemClass", "row start", Q_NULLPTR));
        rowsize->setText(QApplication::translate("Visual_feedback_systemClass", "row size", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Visual_feedback_systemClass", "tracking", Q_NULLPTR));
        pic_label->setText(QString());
        setcapture->setText(QApplication::translate("Visual_feedback_systemClass", "set capture field", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Visual_feedback_systemClass: public Ui_Visual_feedback_systemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUAL_FEEDBACK_SYSTEM_H
