/********************************************************************************
** Form generated from reading UI file 'ledCubeTrayUi.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LEDCUBETRAYUI_H
#define LEDCUBETRAYUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QPushButton *btnClose;
    QFrame *line;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QComboBox *cmbDevice;
    QLabel *label_2;
    QFrame *line_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *optAnimation;
    QRadioButton *optSystemMonitor;
    QRadioButton *optInteractive;
    QFrame *frame_3;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(315, 303);
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        frame_5 = new QFrame(Form);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(frame_5);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(frame_5);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        btnClose = new QPushButton(frame_5);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setMinimumSize(QSize(25, 25));
        btnClose->setMaximumSize(QSize(25, 25));

        horizontalLayout_3->addWidget(btnClose);


        verticalLayout->addWidget(frame_5);

        line = new QFrame(Form);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(0, 0));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        cmbDevice = new QComboBox(groupBox);
        cmbDevice->setObjectName(QStringLiteral("cmbDevice"));

        verticalLayout_2->addWidget(cmbDevice);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);


        verticalLayout->addWidget(groupBox);

        line_2 = new QFrame(Form);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        groupBox_2 = new QGroupBox(Form);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(2, 2, 2, 2);
        optAnimation = new QRadioButton(groupBox_2);
        optAnimation->setObjectName(QStringLiteral("optAnimation"));

        horizontalLayout_2->addWidget(optAnimation);

        optSystemMonitor = new QRadioButton(groupBox_2);
        optSystemMonitor->setObjectName(QStringLiteral("optSystemMonitor"));

        horizontalLayout_2->addWidget(optSystemMonitor);

        optInteractive = new QRadioButton(groupBox_2);
        optInteractive->setObjectName(QStringLiteral("optInteractive"));

        horizontalLayout_2->addWidget(optInteractive);


        verticalLayout->addWidget(groupBox_2);

        frame_3 = new QFrame(Form);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(frame_3);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        label_6->setText(QApplication::translate("Form", "Led Cube Controller", Q_NULLPTR));
        btnClose->setText(QApplication::translate("Form", "X", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Form", "Device", Q_NULLPTR));
        cmbDevice->clear();
        cmbDevice->insertItems(0, QStringList()
         << QApplication::translate("Form", "CubeName on /dev/ttyUSB0", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("Form", "4x4x4 RGB  v0.1.15 ", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Form", "Mode", Q_NULLPTR));
        optAnimation->setText(QApplication::translate("Form", "Animation", Q_NULLPTR));
        optSystemMonitor->setText(QApplication::translate("Form", "System Monitor", Q_NULLPTR));
        optInteractive->setText(QApplication::translate("Form", "Interactive", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LEDCUBETRAYUI_H
