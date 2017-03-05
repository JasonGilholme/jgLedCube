/********************************************************************************
** Form generated from reading UI file 'systemMonitorUi.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SYSTEMMONITORUI_H
#define SYSTEMMONITORUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_systemMonitorUi
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QRadioButton *optCpuMode;
    QRadioButton *optNetworkMode;
    QRadioButton *optUsbMode;
    QRadioButton *optAudioMode;
    QComboBox *comboBox_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *systemMonitorUi)
    {
        if (systemMonitorUi->objectName().isEmpty())
            systemMonitorUi->setObjectName(QStringLiteral("systemMonitorUi"));
        systemMonitorUi->resize(285, 176);
        verticalLayout = new QVBoxLayout(systemMonitorUi);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(systemMonitorUi);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(29, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(29, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(frame);

        frame_2 = new QFrame(systemMonitorUi);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(4);
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(10, 0, 10, 0);
        comboBox = new QComboBox(frame_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 1, 1, 1, 1);

        optCpuMode = new QRadioButton(frame_2);
        optCpuMode->setObjectName(QStringLiteral("optCpuMode"));

        gridLayout->addWidget(optCpuMode, 0, 0, 1, 1);

        optNetworkMode = new QRadioButton(frame_2);
        optNetworkMode->setObjectName(QStringLiteral("optNetworkMode"));

        gridLayout->addWidget(optNetworkMode, 1, 0, 1, 1);

        optUsbMode = new QRadioButton(frame_2);
        optUsbMode->setObjectName(QStringLiteral("optUsbMode"));

        gridLayout->addWidget(optUsbMode, 2, 0, 1, 1);

        optAudioMode = new QRadioButton(frame_2);
        optAudioMode->setObjectName(QStringLiteral("optAudioMode"));

        gridLayout->addWidget(optAudioMode, 3, 0, 1, 1);

        comboBox_2 = new QComboBox(frame_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);


        verticalLayout->addWidget(frame_2);


        retranslateUi(systemMonitorUi);

        QMetaObject::connectSlotsByName(systemMonitorUi);
    } // setupUi

    void retranslateUi(QWidget *systemMonitorUi)
    {
        systemMonitorUi->setWindowTitle(QApplication::translate("systemMonitorUi", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("systemMonitorUi", "System Monitor mode visualises various aspects of your computer on the LED Cube.", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("systemMonitorUi", "eth0", Q_NULLPTR)
         << QApplication::translate("systemMonitorUi", "eth1", Q_NULLPTR)
         << QApplication::translate("systemMonitorUi", "wlan0", Q_NULLPTR)
        );
        optCpuMode->setText(QApplication::translate("systemMonitorUi", "CPU Usage && Temp", Q_NULLPTR));
        optNetworkMode->setText(QApplication::translate("systemMonitorUi", "Wifi / Network Traffic", Q_NULLPTR));
        optUsbMode->setText(QApplication::translate("systemMonitorUi", "Usb Traffic", Q_NULLPTR));
        optAudioMode->setText(QApplication::translate("systemMonitorUi", "Audio Output", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("systemMonitorUi", "ttyUSB0", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class systemMonitorUi: public Ui_systemMonitorUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SYSTEMMONITORUI_H
