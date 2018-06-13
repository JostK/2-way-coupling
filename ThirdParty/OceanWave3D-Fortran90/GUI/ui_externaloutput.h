/********************************************************************************
** Form generated from reading UI file 'externaloutput.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTERNALOUTPUT_H
#define UI_EXTERNALOUTPUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_externalOutput
{
public:

    void setupUi(QWidget *externalOutput)
    {
        if (externalOutput->objectName().isEmpty())
            externalOutput->setObjectName(QString::fromUtf8("externalOutput"));
        externalOutput->resize(1028, 318);

        retranslateUi(externalOutput);

        QMetaObject::connectSlotsByName(externalOutput);
    } // setupUi

    void retranslateUi(QWidget *externalOutput)
    {
        externalOutput->setWindowTitle(QApplication::translate("externalOutput", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class externalOutput: public Ui_externalOutput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTERNALOUTPUT_H
