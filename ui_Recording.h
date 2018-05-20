/********************************************************************************
** Form generated from reading UI file 'Recording.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDING_H
#define UI_RECORDING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Recording
{
public:
    QPushButton *btnLeftChannel;
    QPushButton *btnRightChannel;
    QPushButton *btnSingleChannel;
    QPushButton *btnStop;

    void setupUi(QDialog *Recording)
    {
        if (Recording->objectName().isEmpty())
            Recording->setObjectName(QStringLiteral("Recording"));
        Recording->resize(400, 300);
        btnLeftChannel = new QPushButton(Recording);
        btnLeftChannel->setObjectName(QStringLiteral("btnLeftChannel"));
        btnLeftChannel->setGeometry(QRect(70, 90, 75, 23));
        btnRightChannel = new QPushButton(Recording);
        btnRightChannel->setObjectName(QStringLiteral("btnRightChannel"));
        btnRightChannel->setGeometry(QRect(200, 90, 75, 23));
        btnSingleChannel = new QPushButton(Recording);
        btnSingleChannel->setObjectName(QStringLiteral("btnSingleChannel"));
        btnSingleChannel->setGeometry(QRect(70, 170, 75, 23));
        btnStop = new QPushButton(Recording);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        btnStop->setGeometry(QRect(200, 170, 75, 23));

        retranslateUi(Recording);

        QMetaObject::connectSlotsByName(Recording);
    } // setupUi

    void retranslateUi(QDialog *Recording)
    {
        Recording->setWindowTitle(QApplication::translate("Recording", "Dialog", 0));
        btnLeftChannel->setText(QApplication::translate("Recording", "\345\267\246\345\243\260\351\201\223", 0));
        btnRightChannel->setText(QApplication::translate("Recording", "\345\217\263\345\243\260\351\201\223", 0));
        btnSingleChannel->setText(QApplication::translate("Recording", "\345\215\225\345\243\260\351\201\223", 0));
        btnStop->setText(QApplication::translate("Recording", "\345\201\234\346\255\242", 0));
    } // retranslateUi

};

namespace Ui {
    class Recording: public Ui_Recording {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDING_H
