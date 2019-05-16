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
#include <QtWidgets/QHBoxLayout>
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
    QPushButton *setcapture;
    QLabel *cameraCount;
    QLabel *cameraSerial;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *ImageView;
    QLabel *ImgViewLabel;
    QPushButton *StartBtn;
    QPushButton *StopBtn;
    QLabel *label;
    QLineEdit *timeCounts;
    QPushButton *TimeReset;
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
        PortSelectBtn->setGeometry(QRect(930, 30, 93, 28));
        DeviceNum_Label = new QLabel(centralWidget);
        DeviceNum_Label->setObjectName(QStringLiteral("DeviceNum_Label"));
        DeviceNum_Label->setGeometry(QRect(880, 30, 31, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        DeviceNum_Label->setFont(font);
        DeviceNum_Label->setAlignment(Qt::AlignCenter);
        ComboBox_DEVICE_LIST = new QComboBox(centralWidget);
        ComboBox_DEVICE_LIST->setObjectName(QStringLiteral("ComboBox_DEVICE_LIST"));
        ComboBox_DEVICE_LIST->setGeometry(QRect(170, 40, 87, 22));
        TextBox_CAPTURE_COL_START = new QLineEdit(centralWidget);
        TextBox_CAPTURE_COL_START->setObjectName(QStringLiteral("TextBox_CAPTURE_COL_START"));
        TextBox_CAPTURE_COL_START->setGeometry(QRect(190, 86, 113, 21));
        colstart = new QLabel(centralWidget);
        colstart->setObjectName(QStringLiteral("colstart"));
        colstart->setGeometry(QRect(100, 86, 72, 15));
        colsize = new QLabel(centralWidget);
        colsize->setObjectName(QStringLiteral("colsize"));
        colsize->setGeometry(QRect(100, 139, 72, 15));
        rolstart = new QLabel(centralWidget);
        rolstart->setObjectName(QStringLiteral("rolstart"));
        rolstart->setGeometry(QRect(360, 86, 72, 15));
        rowsize = new QLabel(centralWidget);
        rowsize->setObjectName(QStringLiteral("rowsize"));
        rowsize->setGeometry(QRect(360, 139, 72, 15));
        TextBox_CAPTURE_ROW_START = new QLineEdit(centralWidget);
        TextBox_CAPTURE_ROW_START->setObjectName(QStringLiteral("TextBox_CAPTURE_ROW_START"));
        TextBox_CAPTURE_ROW_START->setGeometry(QRect(460, 86, 113, 21));
        TextBox_CAPTURE_COL_SIZE = new QLineEdit(centralWidget);
        TextBox_CAPTURE_COL_SIZE->setObjectName(QStringLiteral("TextBox_CAPTURE_COL_SIZE"));
        TextBox_CAPTURE_COL_SIZE->setGeometry(QRect(190, 139, 113, 21));
        TextBox_CAPTURE_ROW_SIZE = new QLineEdit(centralWidget);
        TextBox_CAPTURE_ROW_SIZE->setObjectName(QStringLiteral("TextBox_CAPTURE_ROW_SIZE"));
        TextBox_CAPTURE_ROW_SIZE->setGeometry(QRect(460, 139, 113, 21));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(710, 139, 93, 28));
        setcapture = new QPushButton(centralWidget);
        setcapture->setObjectName(QStringLiteral("setcapture"));
        setcapture->setGeometry(QRect(690, 86, 161, 28));
        cameraCount = new QLabel(centralWidget);
        cameraCount->setObjectName(QStringLiteral("cameraCount"));
        cameraCount->setGeometry(QRect(760, 30, 111, 31));
        cameraSerial = new QLabel(centralWidget);
        cameraSerial->setObjectName(QStringLiteral("cameraSerial"));
        cameraSerial->setGeometry(QRect(60, 40, 101, 21));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(50, 210, 571, 541));
        ImageView = new QHBoxLayout(horizontalLayoutWidget);
        ImageView->setSpacing(6);
        ImageView->setContentsMargins(11, 11, 11, 11);
        ImageView->setObjectName(QStringLiteral("ImageView"));
        ImageView->setContentsMargins(0, 0, 0, 0);
        ImgViewLabel = new QLabel(horizontalLayoutWidget);
        ImgViewLabel->setObjectName(QStringLiteral("ImgViewLabel"));
        ImgViewLabel->setAlignment(Qt::AlignCenter);

        ImageView->addWidget(ImgViewLabel);

        StartBtn = new QPushButton(centralWidget);
        StartBtn->setObjectName(QStringLiteral("StartBtn"));
        StartBtn->setGeometry(QRect(760, 380, 93, 28));
        StopBtn = new QPushButton(centralWidget);
        StopBtn->setObjectName(QStringLiteral("StopBtn"));
        StopBtn->setGeometry(QRect(760, 510, 93, 28));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(890, 140, 72, 15));
        timeCounts = new QLineEdit(centralWidget);
        timeCounts->setObjectName(QStringLiteral("timeCounts"));
        timeCounts->setGeometry(QRect(980, 140, 71, 21));
        TimeReset = new QPushButton(centralWidget);
        TimeReset->setObjectName(QStringLiteral("TimeReset"));
        TimeReset->setGeometry(QRect(930, 510, 93, 28));
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
        QObject::connect(setcapture, SIGNAL(clicked()), Visual_feedback_systemClass, SLOT(on_SetButton_Clicked()));
        QObject::connect(pushButton, SIGNAL(clicked()), Visual_feedback_systemClass, SLOT(on_TrackButton_Clicked()));
        QObject::connect(StartBtn, SIGNAL(clicked()), Visual_feedback_systemClass, SLOT(on_StartBtn_Clicked()));
        QObject::connect(StopBtn, SIGNAL(clicked()), Visual_feedback_systemClass, SLOT(on_StopBtn_Clicked()));
        QObject::connect(TimeReset, SIGNAL(clicked()), Visual_feedback_systemClass, SLOT(on_TimeRestBtn_Clicked()));

        QMetaObject::connectSlotsByName(Visual_feedback_systemClass);
    } // setupUi

    void retranslateUi(QMainWindow *Visual_feedback_systemClass)
    {
        Visual_feedback_systemClass->setWindowTitle(QApplication::translate("Visual_feedback_systemClass", "Visual_feedback_system", Q_NULLPTR));
        PortSelectBtn->setText(QApplication::translate("Visual_feedback_systemClass", "\346\243\200\346\265\213\347\233\270\346\234\272", Q_NULLPTR));
        DeviceNum_Label->setText(QApplication::translate("Visual_feedback_systemClass", "0", Q_NULLPTR));
        colstart->setText(QApplication::translate("Visual_feedback_systemClass", "col start", Q_NULLPTR));
        colsize->setText(QApplication::translate("Visual_feedback_systemClass", "col size", Q_NULLPTR));
        rolstart->setText(QApplication::translate("Visual_feedback_systemClass", "row start", Q_NULLPTR));
        rowsize->setText(QApplication::translate("Visual_feedback_systemClass", "row size", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Visual_feedback_systemClass", "tracking", Q_NULLPTR));
        setcapture->setText(QApplication::translate("Visual_feedback_systemClass", "set capture field", Q_NULLPTR));
        cameraCount->setText(QApplication::translate("Visual_feedback_systemClass", "\346\243\200\346\265\213\345\207\272\347\232\204\347\233\270\346\234\272\346\225\260\357\274\232", Q_NULLPTR));
        cameraSerial->setText(QApplication::translate("Visual_feedback_systemClass", "\351\200\211\346\213\251\347\233\270\346\234\272\345\272\217\345\217\267:", Q_NULLPTR));
        ImgViewLabel->setText(QApplication::translate("Visual_feedback_systemClass", "TextLabel", Q_NULLPTR));
        StartBtn->setText(QApplication::translate("Visual_feedback_systemClass", "StartBtn", Q_NULLPTR));
        StopBtn->setText(QApplication::translate("Visual_feedback_systemClass", "StopBtn", Q_NULLPTR));
        label->setText(QApplication::translate("Visual_feedback_systemClass", "timeCounts", Q_NULLPTR));
        TimeReset->setText(QApplication::translate("Visual_feedback_systemClass", "TimeReset", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Visual_feedback_systemClass: public Ui_Visual_feedback_systemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUAL_FEEDBACK_SYSTEM_H
