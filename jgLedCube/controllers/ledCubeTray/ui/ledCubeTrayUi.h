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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ledCubeTrayUi
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lblImage;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QLabel *lblCubeName;
    QLabel *lblCubePort;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lblCubeDescription;
    QLabel *lblCubeVersion;
    QLabel *label_2;
    QFrame *line_2;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnPreviousScreen;
    QLabel *lblScreenName;
    QPushButton *btnNextScreen;
    QFrame *line;
    QFrame *frmContent;

    void setupUi(QWidget *ledCubeTrayUi)
    {
        if (ledCubeTrayUi->objectName().isEmpty())
            ledCubeTrayUi->setObjectName(QStringLiteral("ledCubeTrayUi"));
        ledCubeTrayUi->resize(303, 300);
        verticalLayout = new QVBoxLayout(ledCubeTrayUi);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        frame_5 = new QFrame(ledCubeTrayUi);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy);
        frame_5->setMinimumSize(QSize(0, 0));
        horizontalLayout_4 = new QHBoxLayout(frame_5);
        horizontalLayout_4->setSpacing(4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(4, 4, 4, 0);
        lblImage = new QLabel(frame_5);
        lblImage->setObjectName(QStringLiteral("lblImage"));
        lblImage->setMinimumSize(QSize(48, 48));
        lblImage->setMaximumSize(QSize(48, 48));
        lblImage->setFrameShape(QFrame::StyledPanel);
        lblImage->setFrameShadow(QFrame::Plain);
        lblImage->setLineWidth(1);
        lblImage->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(lblImage);

        frame = new QFrame(frame_5);
        frame->setObjectName(QStringLiteral("frame"));
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        lblCubeName = new QLabel(frame_2);
        lblCubeName->setObjectName(QStringLiteral("lblCubeName"));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        lblCubeName->setFont(font);
        lblCubeName->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout->addWidget(lblCubeName);

        lblCubePort = new QLabel(frame_2);
        lblCubePort->setObjectName(QStringLiteral("lblCubePort"));
        QFont font1;
        font1.setPointSize(8);
        font1.setItalic(true);
        lblCubePort->setFont(font1);
        lblCubePort->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        horizontalLayout->addWidget(lblCubePort);


        verticalLayout_3->addWidget(frame_2);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        horizontalLayout_3 = new QHBoxLayout(frame_4);
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lblCubeDescription = new QLabel(frame_4);
        lblCubeDescription->setObjectName(QStringLiteral("lblCubeDescription"));
        QFont font2;
        font2.setPointSize(9);
        lblCubeDescription->setFont(font2);
        lblCubeDescription->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_3->addWidget(lblCubeDescription);

        lblCubeVersion = new QLabel(frame_4);
        lblCubeVersion->setObjectName(QStringLiteral("lblCubeVersion"));
        lblCubeVersion->setFont(font1);
        lblCubeVersion->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        horizontalLayout_3->addWidget(lblCubeVersion);


        verticalLayout_3->addWidget(frame_4);


        horizontalLayout_4->addWidget(frame);

        label_2 = new QLabel(frame_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_2);


        verticalLayout->addWidget(frame_5);

        line_2 = new QFrame(ledCubeTrayUi);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        frame_6 = new QFrame(ledCubeTrayUi);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setMinimumSize(QSize(0, 25));
        frame_6->setMaximumSize(QSize(16777215, 25));
        horizontalLayout_5 = new QHBoxLayout(frame_6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        btnPreviousScreen = new QPushButton(frame_6);
        btnPreviousScreen->setObjectName(QStringLiteral("btnPreviousScreen"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnPreviousScreen->sizePolicy().hasHeightForWidth());
        btnPreviousScreen->setSizePolicy(sizePolicy2);
        btnPreviousScreen->setMinimumSize(QSize(20, 0));
        btnPreviousScreen->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_5->addWidget(btnPreviousScreen);

        lblScreenName = new QLabel(frame_6);
        lblScreenName->setObjectName(QStringLiteral("lblScreenName"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lblScreenName->sizePolicy().hasHeightForWidth());
        lblScreenName->setSizePolicy(sizePolicy3);
        QFont font4;
        font4.setPointSize(10);
        lblScreenName->setFont(font4);
        lblScreenName->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(lblScreenName);

        btnNextScreen = new QPushButton(frame_6);
        btnNextScreen->setObjectName(QStringLiteral("btnNextScreen"));
        btnNextScreen->setMinimumSize(QSize(20, 0));
        btnNextScreen->setMaximumSize(QSize(20, 16777215));

        horizontalLayout_5->addWidget(btnNextScreen);


        verticalLayout->addWidget(frame_6);

        line = new QFrame(ledCubeTrayUi);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        frmContent = new QFrame(ledCubeTrayUi);
        frmContent->setObjectName(QStringLiteral("frmContent"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frmContent->sizePolicy().hasHeightForWidth());
        frmContent->setSizePolicy(sizePolicy4);

        verticalLayout->addWidget(frmContent);


        retranslateUi(ledCubeTrayUi);

        QMetaObject::connectSlotsByName(ledCubeTrayUi);
    } // setupUi

    void retranslateUi(QWidget *ledCubeTrayUi)
    {
        ledCubeTrayUi->setWindowTitle(QApplication::translate("ledCubeTrayUi", "Form", Q_NULLPTR));
        lblImage->setText(QString());
        lblCubeName->setText(QApplication::translate("ledCubeTrayUi", "CubeName", Q_NULLPTR));
        lblCubePort->setText(QApplication::translate("ledCubeTrayUi", "/dev/ttyUSB0", Q_NULLPTR));
        lblCubeDescription->setText(QApplication::translate("ledCubeTrayUi", "4x4x4 RGB", Q_NULLPTR));
        lblCubeVersion->setText(QApplication::translate("ledCubeTrayUi", "v0.1.15", Q_NULLPTR));
        label_2->setText(QApplication::translate("ledCubeTrayUi", "^", Q_NULLPTR));
        btnPreviousScreen->setText(QApplication::translate("ledCubeTrayUi", "<", Q_NULLPTR));
        lblScreenName->setText(QApplication::translate("ledCubeTrayUi", "System Monitor", Q_NULLPTR));
        btnNextScreen->setText(QApplication::translate("ledCubeTrayUi", ">", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ledCubeTrayUi: public Ui_ledCubeTrayUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LEDCUBETRAYUI_H
