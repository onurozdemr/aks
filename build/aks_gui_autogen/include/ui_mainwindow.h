/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *connectionGroup;
    QHBoxLayout *connectionLayout;
    QHBoxLayout *hboxLayout;
    QLabel *ansLedLabel;
    QLabel *ansLed;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout1;
    QLabel *launcherLedLabel;
    QLabel *launcherLed;
    QSpacerItem *spacerItem1;
    QGroupBox *positionGroup;
    QHBoxLayout *positionLayout;
    QVBoxLayout *vboxLayout;
    QLabel *label;
    QLineEdit *latitudeDisplay;
    QVBoxLayout *vboxLayout1;
    QLabel *label1;
    QLineEdit *longitudeDisplay;
    QVBoxLayout *vboxLayout2;
    QLabel *label2;
    QLineEdit *altitudeDisplay;
    QGroupBox *targetGroup;
    QVBoxLayout *vboxLayout3;
    QHBoxLayout *hboxLayout2;
    QVBoxLayout *vboxLayout4;
    QLabel *label3;
    QLineEdit *targetLatInput;
    QVBoxLayout *vboxLayout5;
    QLabel *label4;
    QLineEdit *targetLonInput;
    QVBoxLayout *vboxLayout6;
    QLabel *label5;
    QLineEdit *targetAltInput;
    QVBoxLayout *vboxLayout7;
    QLabel *label6;
    QLineEdit *targetSpeedInput;
    QVBoxLayout *vboxLayout8;
    QLabel *label7;
    QLineEdit *targetDistanceInput;
    QPushButton *setTargetButton;
    QGroupBox *launcherGroup;
    QVBoxLayout *launcherLayout;
    QPushButton *fireButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 700);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow { background-color: #1e1e2e; }\n"
"QLabel { color: #cdd6f4; }\n"
"QGroupBox { color: #cdd6f4; border: 1px solid #45475a; border-radius: 8px; margin-top: 10px; padding-top: 10px; }\n"
"QGroupBox::title { subcontrol-origin: margin; left: 10px; padding: 0 5px; }\n"
"QLineEdit { background-color: #313244; color: #cdd6f4; border: 1px solid #45475a; border-radius: 4px; padding: 5px; }\n"
"QPushButton { background-color: #89b4fa; color: #1e1e2e; border: none; border-radius: 6px; padding: 8px 16px; font-weight: bold; }\n"
"QPushButton:hover { background-color: #b4befe; }\n"
"QPushButton:disabled { background-color: #45475a; color: #6c7086; }\n"
"QPushButton#fireButton { background-color: #f38ba8; }\n"
"QPushButton#fireButton:hover { background-color: #eba0ac; }\n"
"QPushButton#fireButton:disabled { background-color: #45475a; }"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(15);
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        verticalLayout->setObjectName("verticalLayout");
        connectionGroup = new QGroupBox(centralwidget);
        connectionGroup->setObjectName("connectionGroup");
        connectionLayout = new QHBoxLayout(connectionGroup);
        connectionLayout->setObjectName("connectionLayout");
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName("hboxLayout");
        ansLedLabel = new QLabel(connectionGroup);
        ansLedLabel->setObjectName("ansLedLabel");
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        ansLedLabel->setFont(font);

        hboxLayout->addWidget(ansLedLabel);

        ansLed = new QLabel(connectionGroup);
        ansLed->setObjectName("ansLed");
        ansLed->setMinimumSize(QSize(24, 24));
        ansLed->setMaximumSize(QSize(24, 24));

        hboxLayout->addWidget(ansLed);


        connectionLayout->addLayout(hboxLayout);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        connectionLayout->addItem(spacerItem);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName("hboxLayout1");
        launcherLedLabel = new QLabel(connectionGroup);
        launcherLedLabel->setObjectName("launcherLedLabel");
        launcherLedLabel->setFont(font);

        hboxLayout1->addWidget(launcherLedLabel);

        launcherLed = new QLabel(connectionGroup);
        launcherLed->setObjectName("launcherLed");
        launcherLed->setMinimumSize(QSize(24, 24));
        launcherLed->setMaximumSize(QSize(24, 24));

        hboxLayout1->addWidget(launcherLed);


        connectionLayout->addLayout(hboxLayout1);

        spacerItem1 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        connectionLayout->addItem(spacerItem1);


        verticalLayout->addWidget(connectionGroup);

        positionGroup = new QGroupBox(centralwidget);
        positionGroup->setObjectName("positionGroup");
        positionLayout = new QHBoxLayout(positionGroup);
        positionLayout->setObjectName("positionLayout");
        vboxLayout = new QVBoxLayout();
        vboxLayout->setObjectName("vboxLayout");
        label = new QLabel(positionGroup);
        label->setObjectName("label");

        vboxLayout->addWidget(label);

        latitudeDisplay = new QLineEdit(positionGroup);
        latitudeDisplay->setObjectName("latitudeDisplay");
        latitudeDisplay->setReadOnly(true);

        vboxLayout->addWidget(latitudeDisplay);


        positionLayout->addLayout(vboxLayout);

        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setObjectName("vboxLayout1");
        label1 = new QLabel(positionGroup);
        label1->setObjectName("label1");

        vboxLayout1->addWidget(label1);

        longitudeDisplay = new QLineEdit(positionGroup);
        longitudeDisplay->setObjectName("longitudeDisplay");
        longitudeDisplay->setReadOnly(true);

        vboxLayout1->addWidget(longitudeDisplay);


        positionLayout->addLayout(vboxLayout1);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setObjectName("vboxLayout2");
        label2 = new QLabel(positionGroup);
        label2->setObjectName("label2");

        vboxLayout2->addWidget(label2);

        altitudeDisplay = new QLineEdit(positionGroup);
        altitudeDisplay->setObjectName("altitudeDisplay");
        altitudeDisplay->setReadOnly(true);

        vboxLayout2->addWidget(altitudeDisplay);


        positionLayout->addLayout(vboxLayout2);


        verticalLayout->addWidget(positionGroup);

        targetGroup = new QGroupBox(centralwidget);
        targetGroup->setObjectName("targetGroup");
        vboxLayout3 = new QVBoxLayout(targetGroup);
        vboxLayout3->setObjectName("vboxLayout3");
        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName("hboxLayout2");
        vboxLayout4 = new QVBoxLayout();
        vboxLayout4->setObjectName("vboxLayout4");
        label3 = new QLabel(targetGroup);
        label3->setObjectName("label3");

        vboxLayout4->addWidget(label3);

        targetLatInput = new QLineEdit(targetGroup);
        targetLatInput->setObjectName("targetLatInput");

        vboxLayout4->addWidget(targetLatInput);


        hboxLayout2->addLayout(vboxLayout4);

        vboxLayout5 = new QVBoxLayout();
        vboxLayout5->setObjectName("vboxLayout5");
        label4 = new QLabel(targetGroup);
        label4->setObjectName("label4");

        vboxLayout5->addWidget(label4);

        targetLonInput = new QLineEdit(targetGroup);
        targetLonInput->setObjectName("targetLonInput");

        vboxLayout5->addWidget(targetLonInput);


        hboxLayout2->addLayout(vboxLayout5);

        vboxLayout6 = new QVBoxLayout();
        vboxLayout6->setObjectName("vboxLayout6");
        label5 = new QLabel(targetGroup);
        label5->setObjectName("label5");

        vboxLayout6->addWidget(label5);

        targetAltInput = new QLineEdit(targetGroup);
        targetAltInput->setObjectName("targetAltInput");

        vboxLayout6->addWidget(targetAltInput);


        hboxLayout2->addLayout(vboxLayout6);

        vboxLayout7 = new QVBoxLayout();
        vboxLayout7->setObjectName("vboxLayout7");
        label6 = new QLabel(targetGroup);
        label6->setObjectName("label6");

        vboxLayout7->addWidget(label6);

        targetSpeedInput = new QLineEdit(targetGroup);
        targetSpeedInput->setObjectName("targetSpeedInput");

        vboxLayout7->addWidget(targetSpeedInput);


        hboxLayout2->addLayout(vboxLayout7);

        vboxLayout8 = new QVBoxLayout();
        vboxLayout8->setObjectName("vboxLayout8");
        label7 = new QLabel(targetGroup);
        label7->setObjectName("label7");

        vboxLayout8->addWidget(label7);

        targetDistanceInput = new QLineEdit(targetGroup);
        targetDistanceInput->setObjectName("targetDistanceInput");

        vboxLayout8->addWidget(targetDistanceInput);


        hboxLayout2->addLayout(vboxLayout8);


        vboxLayout3->addLayout(hboxLayout2);

        setTargetButton = new QPushButton(targetGroup);
        setTargetButton->setObjectName("setTargetButton");

        vboxLayout3->addWidget(setTargetButton);


        verticalLayout->addWidget(targetGroup);

        launcherGroup = new QGroupBox(centralwidget);
        launcherGroup->setObjectName("launcherGroup");
        launcherLayout = new QVBoxLayout(launcherGroup);
        launcherLayout->setObjectName("launcherLayout");

        verticalLayout->addWidget(launcherGroup);

        fireButton = new QPushButton(centralwidget);
        fireButton->setObjectName("fireButton");
        fireButton->setEnabled(false);
        fireButton->setMinimumHeight(50);
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        fireButton->setFont(font1);

        verticalLayout->addWidget(fireButton);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "AKS - At\304\261\305\237 Kontrol Sistemi", nullptr));
        connectionGroup->setTitle(QCoreApplication::translate("MainWindow", "Haberle\305\237me Durumu", nullptr));
        ansLedLabel->setText(QCoreApplication::translate("MainWindow", "ANS:", nullptr));
        ansLed->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #f38ba8; border-radius: 12px;", nullptr));
        launcherLedLabel->setText(QCoreApplication::translate("MainWindow", "Lan\303\247er:", nullptr));
        launcherLed->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #f38ba8; border-radius: 12px;", nullptr));
        positionGroup->setTitle(QCoreApplication::translate("MainWindow", "Platform Konum Bilgisi (ANS)", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Enlem (\302\260)", nullptr));
        latitudeDisplay->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        label1->setText(QCoreApplication::translate("MainWindow", "Boylam (\302\260)", nullptr));
        longitudeDisplay->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        label2->setText(QCoreApplication::translate("MainWindow", "\304\260rtifa (m)", nullptr));
        altitudeDisplay->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        targetGroup->setTitle(QCoreApplication::translate("MainWindow", "Hedef Bilgileri", nullptr));
        label3->setText(QCoreApplication::translate("MainWindow", "Enlem (\302\260)", nullptr));
        targetLatInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "39.925", nullptr));
        label4->setText(QCoreApplication::translate("MainWindow", "Boylam (\302\260)", nullptr));
        targetLonInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "32.836", nullptr));
        label5->setText(QCoreApplication::translate("MainWindow", "\304\260rtifa (m)", nullptr));
        targetAltInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "850", nullptr));
        label6->setText(QCoreApplication::translate("MainWindow", "H\304\261z (m/s)", nullptr));
        targetSpeedInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "250", nullptr));
        label7->setText(QCoreApplication::translate("MainWindow", "Mesafe (m)", nullptr));
        targetDistanceInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "15000", nullptr));
        setTargetButton->setText(QCoreApplication::translate("MainWindow", "Hedef Bilgilerini Ayarla", nullptr));
        launcherGroup->setTitle(QCoreApplication::translate("MainWindow", "Lan\303\247er ve F\303\274zeler", nullptr));
        fireButton->setText(QCoreApplication::translate("MainWindow", "ATE\305\236LE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
