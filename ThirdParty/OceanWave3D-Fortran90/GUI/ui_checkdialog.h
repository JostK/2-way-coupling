/********************************************************************************
** Form generated from reading UI file 'checkdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKDIALOG_H
#define UI_CHECKDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QToolBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_checkDialog
{
public:
    QVBoxLayout *verticalLayout;
    QToolBox *checkwidget;
    QWidget *page;
    QFrame *frame;
    QLabel *label;
    QLabel *spatialRes_label;
    QFrame *line;
    QLabel *spatialRes_image;
    QLabel *explanation_spatial;
    QFrame *frame_2;
    QLabel *label_4;
    QLabel *temporalRes_label;
    QFrame *line_2;
    QLabel *temporalRes_image;
    QLabel *explanation_temporal;
    QFrame *frame_3;
    QLabel *label_7;
    QLabel *genZone_start_label;
    QFrame *line_3;
    QLabel *genZone_image;
    QLabel *genZone_end_label;
    QLabel *genZone_length_label;
    QLabel *explanation_genZone;
    QFrame *frame_4;
    QLabel *label_12;
    QLabel *endZone_start_label;
    QFrame *line_4;
    QLabel *endZone_image;
    QLabel *endZone_end_label;
    QLabel *endZone_length_label;
    QLabel *explanation_endZone;
    QFrame *frame_5;
    QLabel *label_13;
    QLabel *depth_geo;
    QFrame *line_5;
    QLabel *depth_image;
    QLabel *depth_waveTheory;
    QLabel *explanation_endZone_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *checkDialog)
    {
        if (checkDialog->objectName().isEmpty())
            checkDialog->setObjectName(QString::fromUtf8("checkDialog"));
        checkDialog->resize(759, 603);
        verticalLayout = new QVBoxLayout(checkDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkwidget = new QToolBox(checkDialog);
        checkwidget->setObjectName(QString::fromUtf8("checkwidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("Vemana2000"));
        font.setBold(true);
        font.setWeight(75);
        checkwidget->setFont(font);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 741, 521));
        frame = new QFrame(page);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 741, 101));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 5, 151, 31));
        spatialRes_label = new QLabel(frame);
        spatialRes_label->setObjectName(QString::fromUtf8("spatialRes_label"));
        spatialRes_label->setGeometry(QRect(10, 50, 301, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        spatialRes_label->setFont(font1);
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 20, 711, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        spatialRes_image = new QLabel(frame);
        spatialRes_image->setObjectName(QString::fromUtf8("spatialRes_image"));
        spatialRes_image->setGeometry(QRect(630, 40, 51, 51));
        spatialRes_image->setPixmap(QPixmap(QString::fromUtf8(":/pictures/warning.png")));
        explanation_spatial = new QLabel(frame);
        explanation_spatial->setObjectName(QString::fromUtf8("explanation_spatial"));
        explanation_spatial->setGeometry(QRect(300, 40, 261, 41));
        frame_2 = new QFrame(page);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 100, 741, 101));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 5, 151, 31));
        temporalRes_label = new QLabel(frame_2);
        temporalRes_label->setObjectName(QString::fromUtf8("temporalRes_label"));
        temporalRes_label->setGeometry(QRect(10, 50, 271, 21));
        temporalRes_label->setFont(font1);
        line_2 = new QFrame(frame_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 20, 711, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        temporalRes_image = new QLabel(frame_2);
        temporalRes_image->setObjectName(QString::fromUtf8("temporalRes_image"));
        temporalRes_image->setGeometry(QRect(630, 40, 51, 51));
        explanation_temporal = new QLabel(frame_2);
        explanation_temporal->setObjectName(QString::fromUtf8("explanation_temporal"));
        explanation_temporal->setGeometry(QRect(300, 50, 261, 41));
        frame_3 = new QFrame(page);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(0, 200, 741, 101));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 5, 151, 31));
        genZone_start_label = new QLabel(frame_3);
        genZone_start_label->setObjectName(QString::fromUtf8("genZone_start_label"));
        genZone_start_label->setGeometry(QRect(10, 30, 241, 21));
        genZone_start_label->setFont(font1);
        line_3 = new QFrame(frame_3);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 20, 711, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        genZone_image = new QLabel(frame_3);
        genZone_image->setObjectName(QString::fromUtf8("genZone_image"));
        genZone_image->setGeometry(QRect(630, 40, 51, 51));
        genZone_end_label = new QLabel(frame_3);
        genZone_end_label->setObjectName(QString::fromUtf8("genZone_end_label"));
        genZone_end_label->setGeometry(QRect(10, 50, 241, 21));
        genZone_end_label->setFont(font1);
        genZone_length_label = new QLabel(frame_3);
        genZone_length_label->setObjectName(QString::fromUtf8("genZone_length_label"));
        genZone_length_label->setGeometry(QRect(10, 70, 241, 21));
        genZone_length_label->setFont(font1);
        explanation_genZone = new QLabel(frame_3);
        explanation_genZone->setObjectName(QString::fromUtf8("explanation_genZone"));
        explanation_genZone->setGeometry(QRect(300, 30, 261, 61));
        frame_4 = new QFrame(page);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(0, 300, 741, 101));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_12 = new QLabel(frame_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 5, 151, 31));
        endZone_start_label = new QLabel(frame_4);
        endZone_start_label->setObjectName(QString::fromUtf8("endZone_start_label"));
        endZone_start_label->setGeometry(QRect(10, 30, 141, 21));
        endZone_start_label->setFont(font1);
        line_4 = new QFrame(frame_4);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(10, 20, 711, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        endZone_image = new QLabel(frame_4);
        endZone_image->setObjectName(QString::fromUtf8("endZone_image"));
        endZone_image->setGeometry(QRect(630, 40, 51, 51));
        endZone_end_label = new QLabel(frame_4);
        endZone_end_label->setObjectName(QString::fromUtf8("endZone_end_label"));
        endZone_end_label->setGeometry(QRect(10, 50, 141, 21));
        endZone_end_label->setFont(font1);
        endZone_length_label = new QLabel(frame_4);
        endZone_length_label->setObjectName(QString::fromUtf8("endZone_length_label"));
        endZone_length_label->setGeometry(QRect(10, 70, 201, 21));
        endZone_length_label->setFont(font1);
        explanation_endZone = new QLabel(frame_4);
        explanation_endZone->setObjectName(QString::fromUtf8("explanation_endZone"));
        explanation_endZone->setGeometry(QRect(300, 30, 261, 61));
        frame_5 = new QFrame(page);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(0, 400, 741, 101));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        label_13 = new QLabel(frame_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 5, 151, 31));
        depth_geo = new QLabel(frame_5);
        depth_geo->setObjectName(QString::fromUtf8("depth_geo"));
        depth_geo->setGeometry(QRect(10, 40, 181, 21));
        depth_geo->setFont(font1);
        line_5 = new QFrame(frame_5);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(10, 20, 711, 16));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        depth_image = new QLabel(frame_5);
        depth_image->setObjectName(QString::fromUtf8("depth_image"));
        depth_image->setGeometry(QRect(630, 40, 51, 51));
        depth_waveTheory = new QLabel(frame_5);
        depth_waveTheory->setObjectName(QString::fromUtf8("depth_waveTheory"));
        depth_waveTheory->setGeometry(QRect(10, 60, 211, 21));
        depth_waveTheory->setFont(font1);
        explanation_endZone_2 = new QLabel(frame_5);
        explanation_endZone_2->setObjectName(QString::fromUtf8("explanation_endZone_2"));
        explanation_endZone_2->setGeometry(QRect(300, 30, 261, 61));
        checkwidget->addItem(page, QString::fromUtf8("Summary"));

        verticalLayout->addWidget(checkwidget);

        buttonBox = new QDialogButtonBox(checkDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel);
        buttonBox->setCenterButtons(false);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(checkDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), checkDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), checkDialog, SLOT(reject()));

        checkwidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(checkDialog);
    } // setupUi

    void retranslateUi(QDialog *checkDialog)
    {
        checkDialog->setWindowTitle(QApplication::translate("checkDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("checkDialog", "Spatial resolution", 0, QApplication::UnicodeUTF8));
        spatialRes_label->setText(QApplication::translate("checkDialog", "Points per wave length:", 0, QApplication::UnicodeUTF8));
        spatialRes_image->setText(QString());
        explanation_spatial->setText(QString());
        label_4->setText(QApplication::translate("checkDialog", "Temporal resolution", 0, QApplication::UnicodeUTF8));
        temporalRes_label->setText(QApplication::translate("checkDialog", "Time steps per wave perid:", 0, QApplication::UnicodeUTF8));
        temporalRes_image->setText(QApplication::translate("checkDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        explanation_temporal->setText(QString());
        label_7->setText(QApplication::translate("checkDialog", "Generation zone", 0, QApplication::UnicodeUTF8));
        genZone_start_label->setText(QApplication::translate("checkDialog", "Start:", 0, QApplication::UnicodeUTF8));
        genZone_image->setText(QApplication::translate("checkDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        genZone_end_label->setText(QApplication::translate("checkDialog", "End:", 0, QApplication::UnicodeUTF8));
        genZone_length_label->setText(QApplication::translate("checkDialog", "Length:", 0, QApplication::UnicodeUTF8));
        explanation_genZone->setText(QString());
        label_12->setText(QApplication::translate("checkDialog", "Relaxation zone", 0, QApplication::UnicodeUTF8));
        endZone_start_label->setText(QApplication::translate("checkDialog", "Start:", 0, QApplication::UnicodeUTF8));
        endZone_image->setText(QApplication::translate("checkDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        endZone_end_label->setText(QApplication::translate("checkDialog", "End:", 0, QApplication::UnicodeUTF8));
        endZone_length_label->setText(QApplication::translate("checkDialog", "Length:", 0, QApplication::UnicodeUTF8));
        explanation_endZone->setText(QString());
        label_13->setText(QApplication::translate("checkDialog", "Depth", 0, QApplication::UnicodeUTF8));
        depth_geo->setText(QApplication::translate("checkDialog", "Geometry:", 0, QApplication::UnicodeUTF8));
        depth_image->setText(QApplication::translate("checkDialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        depth_waveTheory->setText(QApplication::translate("checkDialog", "Wave theory:", 0, QApplication::UnicodeUTF8));
        explanation_endZone_2->setText(QString());
        checkwidget->setItemText(checkwidget->indexOf(page), QApplication::translate("checkDialog", "Summary", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class checkDialog: public Ui_checkDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKDIALOG_H
