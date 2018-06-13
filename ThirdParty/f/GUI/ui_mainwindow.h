/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionRun_F5;
    QAction *actionClear_case_F6;
    QAction *actionWrite_input_file_F4;
    QAction *actionChange_directory;
    QAction *actionCheck;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *run;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QTabWidget *output;
    QWidget *tab_11;
    QLabel *label_79;
    QFrame *line_35;
    QFrame *line_36;
    QFrame *line_41;
    QLabel *label_92;
    QFrame *line_66;
    QLabel *label_165;
    QPushButton *OpenDirBrowser;
    QLineEdit *workingDir;
    QLineEdit *header_input;
    QComboBox *nonlin_onOff;
    QFrame *line_6;
    QFrame *line_67;
    QWidget *constantWidget;
    QDoubleSpinBox *Density;
    QDoubleSpinBox *gravity_input;
    QLabel *label_160;
    QLabel *label_158;
    QLabel *label_159;
    QLabel *label_90;
    QWidget *widget_2;
    QLabel *label_91;
    QWidget *breakingWidget;
    QLabel *label_87;
    QLabel *label_89;
    QDoubleSpinBox *breaking_beta0;
    QCheckBox *checkBox_breakingWidget;
    QWidget *FDwidget;
    QLabel *gamma_label;
    QLabel *alpha_label;
    QSpinBox *alpha;
    QLabel *beta_label;
    QSpinBox *gamma;
    QLabel *label_13;
    QSpinBox *beta;
    QCheckBox *checkBox_FD;
    QWidget *PreconWidget;
    QLabel *label_30;
    QSpinBox *a;
    QSpinBox *c;
    QLabel *label_12;
    QLabel *label_31;
    QSpinBox *b;
    QLabel *label_27;
    QCheckBox *checkBox_precon;
    QWidget *widget;
    QDoubleSpinBox *dt;
    QLabel *label_138;
    QLabel *label_157;
    QLabel *label_161;
    QDoubleSpinBox *timeDuration;
    QCheckBox *checkBox_constantWidget;
    QWidget *tab;
    QLabel *label_88;
    QComboBox *geometryType;
    QWidget *simpleDomainWidget;
    QSpinBox *ny;
    QLabel *label_4;
    QLabel *label_10;
    QSpinBox *nz;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label_3;
    QDoubleSpinBox *length;
    QFrame *line_4;
    QCheckBox *sz;
    QDoubleSpinBox *depth;
    QLabel *label_5;
    QDoubleSpinBox *width;
    QSpinBox *nx;
    QLabel *label_9;
    QLabel *label_2;
    QFrame *line_3;
    QLabel *label_7;
    QFrame *line_2;
    QFrame *line;
    QWidget *customGridWidget;
    QPushButton *smooth;
    QTableWidget *geometry_table;
    QPushButton *generateGrid;
    QPushButton *showGrid;
    QPushButton *selectGridFile;
    QSpinBox *nGridPoints;
    QLineEdit *selectedGridFile;
    QLabel *label_21;
    QWidget *tab_5;
    QFrame *line_25;
    QLabel *label_52;
    QFrame *line_27;
    QDoubleSpinBox *yAbsorbStart;
    QLabel *label_132;
    QDoubleSpinBox *xAbsorbStart;
    QLabel *label_133;
    QLabel *label_134;
    QDoubleSpinBox *xAbsorbEnd;
    QDoubleSpinBox *yAbsorbEnd;
    QLabel *label_135;
    QLabel *label_136;
    QFrame *line_26;
    QComboBox *waveType;
    QWidget *widget_SF;
    QLabel *SF_TLabel;
    QDoubleSpinBox *SF_H;
    QLabel *label_142;
    QDoubleSpinBox *SF_h;
    QDoubleSpinBox *SF_T;
    QLabel *label_140;
    QDoubleSpinBox *SF_U;
    QLabel *label_143;
    QLabel *label_144;
    QLabel *SF_TL_unit;
    QLabel *label_146;
    QLabel *label_147;
    QLabel *label_148;
    QComboBox *stokesOrEuler;
    QLabel *label_149;
    QSpinBox *SF_n;
    QComboBox *LorP_ComboBox;
    QComboBox *pressureDampingOrRelax;
    QLabel *label_164;
    QWidget *waveGeneration_widget;
    QLabel *label_126;
    QDoubleSpinBox *yGenStart;
    QLabel *label_130;
    QDoubleSpinBox *xGenEnd;
    QDoubleSpinBox *rampTime;
    QLabel *label_55;
    QLabel *label_127;
    QLabel *label_163;
    QLabel *label_129;
    QDoubleSpinBox *yGenEnd;
    QDoubleSpinBox *xGenStart;
    QWidget *widget_customSpectrum;
    QLabel *label_170;
    QLineEdit *selectedWaveFile_eta;
    QPushButton *selectWaveFile_eta;
    QDoubleSpinBox *irr_y0;
    QLabel *label_171;
    QDoubleSpinBox *irr_x0;
    QLabel *label_172;
    QWidget *widget_waveFile;
    QLabel *label_169;
    QLineEdit *selectedWaveFile;
    QPushButton *selectWaveFile;
    QDoubleSpinBox *rampTime_waveFile;
    QLabel *label_168;
    QWidget *widget_JONSWAP;
    QLabel *label_150;
    QDoubleSpinBox *Hs;
    QLabel *label_151;
    QDoubleSpinBox *h;
    QDoubleSpinBox *Tp;
    QLabel *label_152;
    QLabel *label_154;
    QLabel *label_155;
    QLabel *label_156;
    QDoubleSpinBox *maxkh;
    QLabel *label_166;
    QLabel *label_167;
    QSpinBox *seed;
    QDoubleSpinBox *gamma_jonswap;
    QLabel *gamma_jonswap_label;
    QWidget *tab_9;
    QFrame *line_28;
    QCheckBox *storeAscii_onOff;
    QSpinBox *nASCII;
    QLabel *ACCII_label;
    QLabel *ASCII_label2;
    QComboBox *DropDownListOutputType;
    QLabel *ACCII_label_2;
    QWidget *outputTable;
    QSpinBox *nOutFiles;
    QLabel *label;
    QTableWidget *tableWidget;
    QWidget *tab_3;
    QPushButton *selectPPfile;
    QLineEdit *selectedPPfiles;
    QFrame *line_9;
    QPushButton *convert;
    QPushButton *selectGnuplotFile;
    QLineEdit *gnuplotFile;
    QLabel *label_14;
    QLabel *label_15;
    QPushButton *plot;
    QPushButton *read_bottom;
    QProgressBar *readProgressBar;
    QComboBox *SelectOutput;
    QWidget *morison_widget;
    QLabel *label_16;
    QLabel *label_17;
    QDoubleSpinBox *morison_D;
    QLabel *label_18;
    QDoubleSpinBox *morison_cd;
    QLabel *label_19;
    QDoubleSpinBox *morison_cm;
    QComboBox *morisonX0;
    QPushButton *pushButton_advancedMorison;
    QLabel *convertStatus;
    QWidget *eta_widget;
    QLabel *label_20;
    QComboBox *etaX0;
    QWidget *tab_4;
    QTextBrowser *aboutText_OCW3D_publications_2;
    QWidget *About;
    QComboBox *about_combobox;
    QTextBrowser *aboutText_OCW3D;
    QTextBrowser *aboutText_OCW3dGUI;
    QTextBrowser *aboutText_OCW3D_publications;
    QLabel *deltaresLogo;
    QLabel *dtuLogo;
    QTextBrowser *aboutText_OCW3DVersion;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuRun;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(783, 509);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(234, 234, 234, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(244, 244, 244, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(117, 117, 117, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(156, 156, 156, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush3);
        QBrush brush6(QColor(255, 255, 220, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        MainWindow->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../pictures/DELTARES.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionRun_F5 = new QAction(MainWindow);
        actionRun_F5->setObjectName(QString::fromUtf8("actionRun_F5"));
        actionClear_case_F6 = new QAction(MainWindow);
        actionClear_case_F6->setObjectName(QString::fromUtf8("actionClear_case_F6"));
        actionWrite_input_file_F4 = new QAction(MainWindow);
        actionWrite_input_file_F4->setObjectName(QString::fromUtf8("actionWrite_input_file_F4"));
        actionChange_directory = new QAction(MainWindow);
        actionChange_directory->setObjectName(QString::fromUtf8("actionChange_directory"));
        actionCheck = new QAction(MainWindow);
        actionCheck->setObjectName(QString::fromUtf8("actionCheck"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        run = new QPushButton(centralWidget);
        run->setObjectName(QString::fromUtf8("run"));
        run->setEnabled(true);

        gridLayout->addWidget(run, 4, 0, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 4, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(500, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 1, 1, 1);

        output = new QTabWidget(centralWidget);
        output->setObjectName(QString::fromUtf8("output"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(output->sizePolicy().hasHeightForWidth());
        output->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(10);
        output->setFont(font);
        output->setLayoutDirection(Qt::LeftToRight);
        output->setTabPosition(QTabWidget::North);
        output->setTabShape(QTabWidget::Rounded);
        tab_11 = new QWidget();
        tab_11->setObjectName(QString::fromUtf8("tab_11"));
        label_79 = new QLabel(tab_11);
        label_79->setObjectName(QString::fromUtf8("label_79"));
        label_79->setGeometry(QRect(10, 10, 201, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Vemana2000"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setWeight(75);
        label_79->setFont(font1);
        line_35 = new QFrame(tab_11);
        line_35->setObjectName(QString::fromUtf8("line_35"));
        line_35->setGeometry(QRect(430, 250, 20, 151));
        QFont font2;
        font2.setPointSize(12);
        line_35->setFont(font2);
        line_35->setFrameShape(QFrame::VLine);
        line_35->setFrameShadow(QFrame::Sunken);
        line_36 = new QFrame(tab_11);
        line_36->setObjectName(QString::fromUtf8("line_36"));
        line_36->setGeometry(QRect(430, 140, 20, 101));
        line_36->setFont(font2);
        line_36->setFrameShape(QFrame::VLine);
        line_36->setFrameShadow(QFrame::Sunken);
        line_41 = new QFrame(tab_11);
        line_41->setObjectName(QString::fromUtf8("line_41"));
        line_41->setGeometry(QRect(160, 140, 20, 101));
        line_41->setFont(font2);
        line_41->setFrameShape(QFrame::VLine);
        line_41->setFrameShadow(QFrame::Sunken);
        label_92 = new QLabel(tab_11);
        label_92->setObjectName(QString::fromUtf8("label_92"));
        label_92->setGeometry(QRect(10, 150, 151, 31));
        label_92->setFont(font1);
        line_66 = new QFrame(tab_11);
        line_66->setObjectName(QString::fromUtf8("line_66"));
        line_66->setGeometry(QRect(0, 240, 781, 16));
        line_66->setFont(font2);
        line_66->setFrameShape(QFrame::HLine);
        line_66->setFrameShadow(QFrame::Sunken);
        label_165 = new QLabel(tab_11);
        label_165->setObjectName(QString::fromUtf8("label_165"));
        label_165->setGeometry(QRect(10, 70, 171, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Vemana2000"));
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setUnderline(false);
        font3.setWeight(75);
        font3.setKerning(false);
        label_165->setFont(font3);
        OpenDirBrowser = new QPushButton(tab_11);
        OpenDirBrowser->setObjectName(QString::fromUtf8("OpenDirBrowser"));
        OpenDirBrowser->setGeometry(QRect(610, 100, 91, 24));
        workingDir = new QLineEdit(tab_11);
        workingDir->setObjectName(QString::fromUtf8("workingDir"));
        workingDir->setEnabled(false);
        workingDir->setGeometry(QRect(10, 100, 581, 23));
        header_input = new QLineEdit(tab_11);
        header_input->setObjectName(QString::fromUtf8("header_input"));
        header_input->setEnabled(true);
        header_input->setGeometry(QRect(10, 40, 691, 23));
        nonlin_onOff = new QComboBox(tab_11);
        nonlin_onOff->setObjectName(QString::fromUtf8("nonlin_onOff"));
        nonlin_onOff->setGeometry(QRect(10, 190, 121, 23));
        line_6 = new QFrame(tab_11);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(160, 250, 20, 151));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_67 = new QFrame(tab_11);
        line_67->setObjectName(QString::fromUtf8("line_67"));
        line_67->setGeometry(QRect(10, 130, 781, 16));
        line_67->setFont(font2);
        line_67->setFrameShape(QFrame::HLine);
        line_67->setFrameShadow(QFrame::Sunken);
        constantWidget = new QWidget(tab_11);
        constantWidget->setObjectName(QString::fromUtf8("constantWidget"));
        constantWidget->setEnabled(false);
        constantWidget->setGeometry(QRect(460, 150, 281, 101));
        Density = new QDoubleSpinBox(constantWidget);
        Density->setObjectName(QString::fromUtf8("Density"));
        Density->setGeometry(QRect(120, 50, 81, 24));
        Density->setMaximum(5000);
        Density->setSingleStep(0.1);
        Density->setValue(1025);
        gravity_input = new QDoubleSpinBox(constantWidget);
        gravity_input->setObjectName(QString::fromUtf8("gravity_input"));
        gravity_input->setGeometry(QRect(0, 50, 66, 24));
        gravity_input->setSingleStep(0.1);
        gravity_input->setValue(9.81);
        label_160 = new QLabel(constantWidget);
        label_160->setObjectName(QString::fromUtf8("label_160"));
        label_160->setGeometry(QRect(210, 50, 51, 16));
        label_158 = new QLabel(constantWidget);
        label_158->setObjectName(QString::fromUtf8("label_158"));
        label_158->setGeometry(QRect(120, 30, 51, 16));
        label_159 = new QLabel(constantWidget);
        label_159->setObjectName(QString::fromUtf8("label_159"));
        label_159->setGeometry(QRect(70, 50, 51, 16));
        label_90 = new QLabel(constantWidget);
        label_90->setObjectName(QString::fromUtf8("label_90"));
        label_90->setGeometry(QRect(0, 0, 151, 31));
        label_90->setFont(font1);
        widget_2 = new QWidget(constantWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(410, 50, 120, 80));
        label_91 = new QLabel(constantWidget);
        label_91->setObjectName(QString::fromUtf8("label_91"));
        label_91->setGeometry(QRect(0, 30, 51, 16));
        breakingWidget = new QWidget(tab_11);
        breakingWidget->setObjectName(QString::fromUtf8("breakingWidget"));
        breakingWidget->setEnabled(false);
        breakingWidget->setGeometry(QRect(10, 270, 141, 81));
        label_87 = new QLabel(breakingWidget);
        label_87->setObjectName(QString::fromUtf8("label_87"));
        label_87->setGeometry(QRect(0, 0, 151, 31));
        label_87->setFont(font1);
        label_89 = new QLabel(breakingWidget);
        label_89->setObjectName(QString::fromUtf8("label_89"));
        label_89->setGeometry(QRect(0, 30, 151, 16));
        breaking_beta0 = new QDoubleSpinBox(breakingWidget);
        breaking_beta0->setObjectName(QString::fromUtf8("breaking_beta0"));
        breaking_beta0->setGeometry(QRect(0, 50, 66, 24));
        breaking_beta0->setSingleStep(0.1);
        breaking_beta0->setValue(0);
        checkBox_breakingWidget = new QCheckBox(tab_11);
        checkBox_breakingWidget->setObjectName(QString::fromUtf8("checkBox_breakingWidget"));
        checkBox_breakingWidget->setEnabled(true);
        checkBox_breakingWidget->setGeometry(QRect(80, 250, 111, 21));
        checkBox_breakingWidget->setChecked(true);
        FDwidget = new QWidget(tab_11);
        FDwidget->setObjectName(QString::fromUtf8("FDwidget"));
        FDwidget->setEnabled(false);
        FDwidget->setGeometry(QRect(460, 270, 201, 91));
        gamma_label = new QLabel(FDwidget);
        gamma_label->setObjectName(QString::fromUtf8("gamma_label"));
        gamma_label->setGeometry(QRect(140, 30, 75, 16));
        gamma_label->setMinimumSize(QSize(75, 0));
        alpha_label = new QLabel(FDwidget);
        alpha_label->setObjectName(QString::fromUtf8("alpha_label"));
        alpha_label->setGeometry(QRect(0, 30, 75, 16));
        alpha_label->setMinimumSize(QSize(75, 0));
        alpha = new QSpinBox(FDwidget);
        alpha->setObjectName(QString::fromUtf8("alpha"));
        alpha->setGeometry(QRect(-1, 50, 51, 24));
        alpha->setMinimumSize(QSize(50, 0));
        alpha->setMaximum(10);
        alpha->setValue(3);
        beta_label = new QLabel(FDwidget);
        beta_label->setObjectName(QString::fromUtf8("beta_label"));
        beta_label->setGeometry(QRect(70, 30, 75, 16));
        beta_label->setMinimumSize(QSize(75, 0));
        gamma = new QSpinBox(FDwidget);
        gamma->setObjectName(QString::fromUtf8("gamma"));
        gamma->setGeometry(QRect(139, 50, 50, 24));
        gamma->setMinimumSize(QSize(50, 0));
        gamma->setMaximum(10);
        gamma->setValue(3);
        label_13 = new QLabel(FDwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(0, 0, 151, 31));
        label_13->setFont(font1);
        beta = new QSpinBox(FDwidget);
        beta->setObjectName(QString::fromUtf8("beta"));
        beta->setGeometry(QRect(70, 50, 51, 24));
        beta->setMaximum(10);
        beta->setValue(3);
        checkBox_FD = new QCheckBox(tab_11);
        checkBox_FD->setObjectName(QString::fromUtf8("checkBox_FD"));
        checkBox_FD->setEnabled(true);
        checkBox_FD->setGeometry(QRect(620, 250, 81, 21));
        checkBox_FD->setChecked(true);
        PreconWidget = new QWidget(tab_11);
        PreconWidget->setObjectName(QString::fromUtf8("PreconWidget"));
        PreconWidget->setEnabled(false);
        PreconWidget->setGeometry(QRect(200, 270, 221, 101));
        label_30 = new QLabel(PreconWidget);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(10, 30, 57, 15));
        a = new QSpinBox(PreconWidget);
        a->setObjectName(QString::fromUtf8("a"));
        a->setGeometry(QRect(10, 50, 51, 24));
        a->setMaximum(10);
        a->setValue(1);
        c = new QSpinBox(PreconWidget);
        c->setObjectName(QString::fromUtf8("c"));
        c->setGeometry(QRect(150, 50, 51, 24));
        c->setMaximum(10);
        c->setValue(1);
        label_12 = new QLabel(PreconWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 5, 151, 21));
        label_12->setFont(font1);
        label_31 = new QLabel(PreconWidget);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(150, 30, 57, 15));
        b = new QSpinBox(PreconWidget);
        b->setObjectName(QString::fromUtf8("b"));
        b->setGeometry(QRect(80, 50, 51, 24));
        b->setMaximum(10);
        b->setValue(1);
        label_27 = new QLabel(PreconWidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(80, 30, 57, 15));
        checkBox_precon = new QCheckBox(tab_11);
        checkBox_precon->setObjectName(QString::fromUtf8("checkBox_precon"));
        checkBox_precon->setEnabled(true);
        checkBox_precon->setGeometry(QRect(340, 250, 81, 21));
        checkBox_precon->setChecked(true);
        widget = new QWidget(tab_11);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(190, 150, 231, 80));
        dt = new QDoubleSpinBox(widget);
        dt->setObjectName(QString::fromUtf8("dt"));
        dt->setGeometry(QRect(113, 50, 66, 24));
        dt->setDecimals(3);
        dt->setValue(0.2);
        label_138 = new QLabel(widget);
        label_138->setObjectName(QString::fromUtf8("label_138"));
        label_138->setGeometry(QRect(115, 30, 101, 16));
        label_157 = new QLabel(widget);
        label_157->setObjectName(QString::fromUtf8("label_157"));
        label_157->setGeometry(QRect(10, 30, 71, 16));
        label_161 = new QLabel(widget);
        label_161->setObjectName(QString::fromUtf8("label_161"));
        label_161->setGeometry(QRect(10, 0, 201, 31));
        label_161->setFont(font1);
        timeDuration = new QDoubleSpinBox(widget);
        timeDuration->setObjectName(QString::fromUtf8("timeDuration"));
        timeDuration->setGeometry(QRect(10, 50, 81, 24));
        timeDuration->setDecimals(1);
        timeDuration->setMaximum(100000);
        timeDuration->setSingleStep(0.1);
        timeDuration->setValue(10800);
        checkBox_constantWidget = new QCheckBox(tab_11);
        checkBox_constantWidget->setObjectName(QString::fromUtf8("checkBox_constantWidget"));
        checkBox_constantWidget->setEnabled(true);
        checkBox_constantWidget->setGeometry(QRect(620, 140, 111, 21));
        checkBox_constantWidget->setChecked(true);
        output->addTab(tab_11, QString());
        line_35->raise();
        line_36->raise();
        line_41->raise();
        line_66->raise();
        OpenDirBrowser->raise();
        workingDir->raise();
        header_input->raise();
        nonlin_onOff->raise();
        label_79->raise();
        label_92->raise();
        label_165->raise();
        line_6->raise();
        line_67->raise();
        constantWidget->raise();
        breakingWidget->raise();
        checkBox_breakingWidget->raise();
        FDwidget->raise();
        checkBox_FD->raise();
        PreconWidget->raise();
        checkBox_precon->raise();
        widget->raise();
        checkBox_constantWidget->raise();
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_88 = new QLabel(tab);
        label_88->setObjectName(QString::fromUtf8("label_88"));
        label_88->setGeometry(QRect(10, 10, 201, 31));
        label_88->setFont(font1);
        geometryType = new QComboBox(tab);
        geometryType->setObjectName(QString::fromUtf8("geometryType"));
        geometryType->setGeometry(QRect(100, 10, 121, 24));
        simpleDomainWidget = new QWidget(tab);
        simpleDomainWidget->setObjectName(QString::fromUtf8("simpleDomainWidget"));
        simpleDomainWidget->setGeometry(QRect(10, 40, 791, 131));
        ny = new QSpinBox(simpleDomainWidget);
        ny->setObjectName(QString::fromUtf8("ny"));
        ny->setGeometry(QRect(390, 70, 60, 24));
        ny->setMaximum(10000);
        ny->setValue(1);
        label_4 = new QLabel(simpleDomainWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 10, 81, 31));
        label_4->setFont(font1);
        label_10 = new QLabel(simpleDomainWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(310, 10, 111, 31));
        label_10->setFont(font1);
        nz = new QSpinBox(simpleDomainWidget);
        nz->setObjectName(QString::fromUtf8("nz"));
        nz->setGeometry(QRect(470, 70, 60, 24));
        nz->setMaximum(10000);
        nz->setValue(9);
        label_8 = new QLabel(simpleDomainWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(470, 40, 57, 15));
        label_6 = new QLabel(simpleDomainWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(310, 40, 57, 15));
        label_3 = new QLabel(simpleDomainWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 40, 75, 16));
        label_3->setMinimumSize(QSize(75, 0));
        length = new QDoubleSpinBox(simpleDomainWidget);
        length->setObjectName(QString::fromUtf8("length"));
        length->setGeometry(QRect(0, 70, 80, 24));
        length->setMaximum(10000);
        length->setSingleStep(0.1);
        length->setValue(1000);
        line_4 = new QFrame(simpleDomainWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(560, 10, 20, 91));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        sz = new QCheckBox(simpleDomainWidget);
        sz->setObjectName(QString::fromUtf8("sz"));
        sz->setGeometry(QRect(590, 50, 91, 21));
        sz->setChecked(true);
        depth = new QDoubleSpinBox(simpleDomainWidget);
        depth->setObjectName(QString::fromUtf8("depth"));
        depth->setGeometry(QRect(200, 70, 80, 24));
        depth->setDecimals(3);
        depth->setMaximum(10000);
        depth->setSingleStep(0.1);
        depth->setValue(30);
        label_5 = new QLabel(simpleDomainWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(200, 40, 75, 16));
        label_5->setMinimumSize(QSize(75, 0));
        width = new QDoubleSpinBox(simpleDomainWidget);
        width->setObjectName(QString::fromUtf8("width"));
        width->setGeometry(QRect(100, 70, 80, 24));
        width->setMaximum(10000);
        width->setSingleStep(0.1);
        width->setValue(1);
        nx = new QSpinBox(simpleDomainWidget);
        nx->setObjectName(QString::fromUtf8("nx"));
        nx->setGeometry(QRect(310, 70, 60, 24));
        nx->setMaximum(10000);
        nx->setValue(500);
        label_9 = new QLabel(simpleDomainWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(590, 10, 111, 31));
        label_9->setFont(font1);
        label_2 = new QLabel(simpleDomainWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 40, 81, 16));
        label_2->setMinimumSize(QSize(75, 0));
        line_3 = new QFrame(simpleDomainWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(-20, 100, 781, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_7 = new QLabel(simpleDomainWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(390, 40, 57, 15));
        line_2 = new QFrame(simpleDomainWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(290, 10, 20, 91));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line = new QFrame(simpleDomainWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(-10, 0, 781, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2->raise();
        ny->raise();
        label_10->raise();
        nz->raise();
        label_8->raise();
        label_6->raise();
        label_3->raise();
        length->raise();
        line_4->raise();
        sz->raise();
        depth->raise();
        label_5->raise();
        width->raise();
        nx->raise();
        label_9->raise();
        label_2->raise();
        label_7->raise();
        line->raise();
        line_3->raise();
        label_4->raise();
        customGridWidget = new QWidget(tab);
        customGridWidget->setObjectName(QString::fromUtf8("customGridWidget"));
        customGridWidget->setGeometry(QRect(10, 140, 751, 221));
        smooth = new QPushButton(customGridWidget);
        smooth->setObjectName(QString::fromUtf8("smooth"));
        smooth->setEnabled(false);
        smooth->setGeometry(QRect(530, 190, 91, 24));
        geometry_table = new QTableWidget(customGridWidget);
        geometry_table->setObjectName(QString::fromUtf8("geometry_table"));
        geometry_table->setGeometry(QRect(0, 90, 731, 91));
        generateGrid = new QPushButton(customGridWidget);
        generateGrid->setObjectName(QString::fromUtf8("generateGrid"));
        generateGrid->setGeometry(QRect(420, 190, 91, 24));
        showGrid = new QPushButton(customGridWidget);
        showGrid->setObjectName(QString::fromUtf8("showGrid"));
        showGrid->setEnabled(false);
        showGrid->setGeometry(QRect(640, 190, 91, 24));
        selectGridFile = new QPushButton(customGridWidget);
        selectGridFile->setObjectName(QString::fromUtf8("selectGridFile"));
        selectGridFile->setEnabled(true);
        selectGridFile->setGeometry(QRect(380, 30, 121, 24));
        nGridPoints = new QSpinBox(customGridWidget);
        nGridPoints->setObjectName(QString::fromUtf8("nGridPoints"));
        nGridPoints->setGeometry(QRect(0, 70, 81, 23));
        nGridPoints->setMinimum(1);
        nGridPoints->setMaximum(50);
        nGridPoints->setValue(1);
        selectedGridFile = new QLineEdit(customGridWidget);
        selectedGridFile->setObjectName(QString::fromUtf8("selectedGridFile"));
        selectedGridFile->setEnabled(true);
        selectedGridFile->setGeometry(QRect(70, 30, 291, 23));
        label_21 = new QLabel(customGridWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(0, 30, 71, 16));
        QFont font4;
        font4.setUnderline(true);
        label_21->setFont(font4);
        output->addTab(tab, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        line_25 = new QFrame(tab_5);
        line_25->setObjectName(QString::fromUtf8("line_25"));
        line_25->setGeometry(QRect(0, 270, 781, 16));
        line_25->setFrameShape(QFrame::HLine);
        line_25->setFrameShadow(QFrame::Sunken);
        label_52 = new QLabel(tab_5);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(10, 20, 131, 31));
        label_52->setFont(font1);
        line_27 = new QFrame(tab_5);
        line_27->setObjectName(QString::fromUtf8("line_27"));
        line_27->setGeometry(QRect(10, 130, 781, 16));
        line_27->setFrameShape(QFrame::HLine);
        line_27->setFrameShadow(QFrame::Sunken);
        yAbsorbStart = new QDoubleSpinBox(tab_5);
        yAbsorbStart->setObjectName(QString::fromUtf8("yAbsorbStart"));
        yAbsorbStart->setGeometry(QRect(530, 190, 66, 24));
        yAbsorbStart->setMaximum(100000);
        label_132 = new QLabel(tab_5);
        label_132->setObjectName(QString::fromUtf8("label_132"));
        label_132->setGeometry(QRect(440, 170, 41, 16));
        xAbsorbStart = new QDoubleSpinBox(tab_5);
        xAbsorbStart->setObjectName(QString::fromUtf8("xAbsorbStart"));
        xAbsorbStart->setGeometry(QRect(425, 190, 81, 24));
        xAbsorbStart->setMaximum(100000);
        label_133 = new QLabel(tab_5);
        label_133->setObjectName(QString::fromUtf8("label_133"));
        label_133->setGeometry(QRect(380, 220, 31, 16));
        label_134 = new QLabel(tab_5);
        label_134->setObjectName(QString::fromUtf8("label_134"));
        label_134->setGeometry(QRect(380, 140, 181, 31));
        label_134->setFont(font1);
        xAbsorbEnd = new QDoubleSpinBox(tab_5);
        xAbsorbEnd->setObjectName(QString::fromUtf8("xAbsorbEnd"));
        xAbsorbEnd->setGeometry(QRect(425, 220, 81, 24));
        xAbsorbEnd->setMaximum(100000);
        yAbsorbEnd = new QDoubleSpinBox(tab_5);
        yAbsorbEnd->setObjectName(QString::fromUtf8("yAbsorbEnd"));
        yAbsorbEnd->setGeometry(QRect(530, 220, 66, 24));
        yAbsorbEnd->setMaximum(100000);
        label_135 = new QLabel(tab_5);
        label_135->setObjectName(QString::fromUtf8("label_135"));
        label_135->setGeometry(QRect(530, 170, 41, 16));
        label_136 = new QLabel(tab_5);
        label_136->setObjectName(QString::fromUtf8("label_136"));
        label_136->setGeometry(QRect(380, 190, 41, 16));
        line_26 = new QFrame(tab_5);
        line_26->setObjectName(QString::fromUtf8("line_26"));
        line_26->setGeometry(QRect(340, 150, 20, 121));
        line_26->setFrameShape(QFrame::VLine);
        line_26->setFrameShadow(QFrame::Sunken);
        waveType = new QComboBox(tab_5);
        waveType->setObjectName(QString::fromUtf8("waveType"));
        waveType->setGeometry(QRect(90, 20, 141, 23));
        widget_SF = new QWidget(tab_5);
        widget_SF->setObjectName(QString::fromUtf8("widget_SF"));
        widget_SF->setEnabled(true);
        widget_SF->setGeometry(QRect(0, 60, 771, 80));
        SF_TLabel = new QLabel(widget_SF);
        SF_TLabel->setObjectName(QString::fromUtf8("SF_TLabel"));
        SF_TLabel->setGeometry(QRect(120, 10, 81, 16));
        SF_H = new QDoubleSpinBox(widget_SF);
        SF_H->setObjectName(QString::fromUtf8("SF_H"));
        SF_H->setGeometry(QRect(20, 30, 66, 24));
        SF_H->setDecimals(3);
        label_142 = new QLabel(widget_SF);
        label_142->setObjectName(QString::fromUtf8("label_142"));
        label_142->setGeometry(QRect(220, 10, 81, 16));
        SF_h = new QDoubleSpinBox(widget_SF);
        SF_h->setObjectName(QString::fromUtf8("SF_h"));
        SF_h->setGeometry(QRect(220, 30, 66, 24));
        SF_h->setDecimals(3);
        SF_h->setMaximum(9999);
        SF_T = new QDoubleSpinBox(widget_SF);
        SF_T->setObjectName(QString::fromUtf8("SF_T"));
        SF_T->setGeometry(QRect(120, 30, 66, 24));
        SF_T->setDecimals(3);
        SF_T->setMaximum(1000);
        SF_T->setSingleStep(0.1);
        label_140 = new QLabel(widget_SF);
        label_140->setObjectName(QString::fromUtf8("label_140"));
        label_140->setGeometry(QRect(20, 6, 91, 20));
        SF_U = new QDoubleSpinBox(widget_SF);
        SF_U->setObjectName(QString::fromUtf8("SF_U"));
        SF_U->setGeometry(QRect(320, 30, 66, 24));
        label_143 = new QLabel(widget_SF);
        label_143->setObjectName(QString::fromUtf8("label_143"));
        label_143->setGeometry(QRect(320, 10, 101, 16));
        label_144 = new QLabel(widget_SF);
        label_144->setObjectName(QString::fromUtf8("label_144"));
        label_144->setGeometry(QRect(90, 30, 21, 16));
        SF_TL_unit = new QLabel(widget_SF);
        SF_TL_unit->setObjectName(QString::fromUtf8("SF_TL_unit"));
        SF_TL_unit->setGeometry(QRect(190, 30, 21, 16));
        label_146 = new QLabel(widget_SF);
        label_146->setObjectName(QString::fromUtf8("label_146"));
        label_146->setGeometry(QRect(290, 30, 21, 16));
        label_147 = new QLabel(widget_SF);
        label_147->setObjectName(QString::fromUtf8("label_147"));
        label_147->setGeometry(QRect(390, 30, 21, 16));
        label_148 = new QLabel(widget_SF);
        label_148->setObjectName(QString::fromUtf8("label_148"));
        label_148->setGeometry(QRect(430, 10, 81, 16));
        stokesOrEuler = new QComboBox(widget_SF);
        stokesOrEuler->setObjectName(QString::fromUtf8("stokesOrEuler"));
        stokesOrEuler->setGeometry(QRect(430, 30, 91, 23));
        label_149 = new QLabel(widget_SF);
        label_149->setObjectName(QString::fromUtf8("label_149"));
        label_149->setGeometry(QRect(540, 10, 81, 16));
        SF_n = new QSpinBox(widget_SF);
        SF_n->setObjectName(QString::fromUtf8("SF_n"));
        SF_n->setGeometry(QRect(540, 30, 47, 24));
        SF_n->setMinimum(1);
        SF_n->setMaximum(40);
        SF_n->setValue(32);
        SF_TLabel->raise();
        SF_T->raise();
        SF_h->raise();
        label_140->raise();
        SF_H->raise();
        label_142->raise();
        SF_U->raise();
        label_143->raise();
        label_144->raise();
        SF_TL_unit->raise();
        label_146->raise();
        label_147->raise();
        label_148->raise();
        stokesOrEuler->raise();
        label_149->raise();
        SF_n->raise();
        LorP_ComboBox = new QComboBox(tab_5);
        LorP_ComboBox->setObjectName(QString::fromUtf8("LorP_ComboBox"));
        LorP_ComboBox->setGeometry(QRect(290, 20, 111, 23));
        pressureDampingOrRelax = new QComboBox(tab_5);
        pressureDampingOrRelax->setObjectName(QString::fromUtf8("pressureDampingOrRelax"));
        pressureDampingOrRelax->setGeometry(QRect(610, 190, 141, 23));
        label_164 = new QLabel(tab_5);
        label_164->setObjectName(QString::fromUtf8("label_164"));
        label_164->setGeometry(QRect(620, 170, 41, 16));
        waveGeneration_widget = new QWidget(tab_5);
        waveGeneration_widget->setObjectName(QString::fromUtf8("waveGeneration_widget"));
        waveGeneration_widget->setGeometry(QRect(0, 140, 371, 111));
        label_126 = new QLabel(waveGeneration_widget);
        label_126->setObjectName(QString::fromUtf8("label_126"));
        label_126->setGeometry(QRect(50, 30, 41, 16));
        yGenStart = new QDoubleSpinBox(waveGeneration_widget);
        yGenStart->setObjectName(QString::fromUtf8("yGenStart"));
        yGenStart->setGeometry(QRect(140, 50, 66, 24));
        yGenStart->setMaximum(100000);
        label_130 = new QLabel(waveGeneration_widget);
        label_130->setObjectName(QString::fromUtf8("label_130"));
        label_130->setGeometry(QRect(10, 80, 31, 16));
        xGenEnd = new QDoubleSpinBox(waveGeneration_widget);
        xGenEnd->setObjectName(QString::fromUtf8("xGenEnd"));
        xGenEnd->setGeometry(QRect(50, 80, 66, 24));
        xGenEnd->setMaximum(100000);
        rampTime = new QDoubleSpinBox(waveGeneration_widget);
        rampTime->setObjectName(QString::fromUtf8("rampTime"));
        rampTime->setGeometry(QRect(230, 50, 66, 24));
        rampTime->setValue(5);
        label_55 = new QLabel(waveGeneration_widget);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setGeometry(QRect(10, 0, 191, 31));
        label_55->setFont(font1);
        label_127 = new QLabel(waveGeneration_widget);
        label_127->setObjectName(QString::fromUtf8("label_127"));
        label_127->setGeometry(QRect(140, 30, 41, 16));
        label_163 = new QLabel(waveGeneration_widget);
        label_163->setObjectName(QString::fromUtf8("label_163"));
        label_163->setGeometry(QRect(230, 30, 91, 16));
        label_129 = new QLabel(waveGeneration_widget);
        label_129->setObjectName(QString::fromUtf8("label_129"));
        label_129->setGeometry(QRect(10, 50, 41, 16));
        yGenEnd = new QDoubleSpinBox(waveGeneration_widget);
        yGenEnd->setObjectName(QString::fromUtf8("yGenEnd"));
        yGenEnd->setGeometry(QRect(140, 80, 66, 24));
        yGenEnd->setMaximum(100000);
        xGenStart = new QDoubleSpinBox(waveGeneration_widget);
        xGenStart->setObjectName(QString::fromUtf8("xGenStart"));
        xGenStart->setGeometry(QRect(50, 50, 66, 24));
        xGenStart->setMaximum(100000);
        label_126->raise();
        yGenStart->raise();
        label_130->raise();
        xGenEnd->raise();
        rampTime->raise();
        label_127->raise();
        label_163->raise();
        label_129->raise();
        yGenEnd->raise();
        label_55->raise();
        xGenStart->raise();
        widget_customSpectrum = new QWidget(tab_5);
        widget_customSpectrum->setObjectName(QString::fromUtf8("widget_customSpectrum"));
        widget_customSpectrum->setEnabled(true);
        widget_customSpectrum->setGeometry(QRect(20, 250, 681, 80));
        label_170 = new QLabel(widget_customSpectrum);
        label_170->setObjectName(QString::fromUtf8("label_170"));
        label_170->setGeometry(QRect(20, 20, 121, 20));
        selectedWaveFile_eta = new QLineEdit(widget_customSpectrum);
        selectedWaveFile_eta->setObjectName(QString::fromUtf8("selectedWaveFile_eta"));
        selectedWaveFile_eta->setGeometry(QRect(100, 20, 261, 23));
        selectWaveFile_eta = new QPushButton(widget_customSpectrum);
        selectWaveFile_eta->setObjectName(QString::fromUtf8("selectWaveFile_eta"));
        selectWaveFile_eta->setGeometry(QRect(370, 20, 121, 24));
        irr_y0 = new QDoubleSpinBox(widget_customSpectrum);
        irr_y0->setObjectName(QString::fromUtf8("irr_y0"));
        irr_y0->setGeometry(QRect(610, 20, 66, 24));
        irr_y0->setMaximum(10000);
        irr_y0->setValue(0);
        label_171 = new QLabel(widget_customSpectrum);
        label_171->setObjectName(QString::fromUtf8("label_171"));
        label_171->setGeometry(QRect(630, 0, 31, 16));
        irr_x0 = new QDoubleSpinBox(widget_customSpectrum);
        irr_x0->setObjectName(QString::fromUtf8("irr_x0"));
        irr_x0->setGeometry(QRect(520, 20, 66, 24));
        irr_x0->setMaximum(10000);
        irr_x0->setValue(0);
        label_172 = new QLabel(widget_customSpectrum);
        label_172->setObjectName(QString::fromUtf8("label_172"));
        label_172->setGeometry(QRect(540, 0, 31, 16));
        widget_waveFile = new QWidget(tab_5);
        widget_waveFile->setObjectName(QString::fromUtf8("widget_waveFile"));
        widget_waveFile->setEnabled(true);
        widget_waveFile->setGeometry(QRect(30, 110, 711, 80));
        label_169 = new QLabel(widget_waveFile);
        label_169->setObjectName(QString::fromUtf8("label_169"));
        label_169->setGeometry(QRect(20, 20, 121, 20));
        selectedWaveFile = new QLineEdit(widget_waveFile);
        selectedWaveFile->setObjectName(QString::fromUtf8("selectedWaveFile"));
        selectedWaveFile->setGeometry(QRect(150, 20, 261, 23));
        selectWaveFile = new QPushButton(widget_waveFile);
        selectWaveFile->setObjectName(QString::fromUtf8("selectWaveFile"));
        selectWaveFile->setGeometry(QRect(420, 20, 121, 24));
        rampTime_waveFile = new QDoubleSpinBox(widget_waveFile);
        rampTime_waveFile->setObjectName(QString::fromUtf8("rampTime_waveFile"));
        rampTime_waveFile->setGeometry(QRect(610, 20, 66, 24));
        rampTime_waveFile->setValue(5);
        label_168 = new QLabel(widget_waveFile);
        label_168->setObjectName(QString::fromUtf8("label_168"));
        label_168->setGeometry(QRect(610, 0, 91, 16));
        widget_JONSWAP = new QWidget(tab_5);
        widget_JONSWAP->setObjectName(QString::fromUtf8("widget_JONSWAP"));
        widget_JONSWAP->setEnabled(true);
        widget_JONSWAP->setGeometry(QRect(0, 320, 681, 80));
        label_150 = new QLabel(widget_JONSWAP);
        label_150->setObjectName(QString::fromUtf8("label_150"));
        label_150->setGeometry(QRect(120, 10, 81, 16));
        Hs = new QDoubleSpinBox(widget_JONSWAP);
        Hs->setObjectName(QString::fromUtf8("Hs"));
        Hs->setGeometry(QRect(20, 30, 66, 24));
        Hs->setDecimals(3);
        label_151 = new QLabel(widget_JONSWAP);
        label_151->setObjectName(QString::fromUtf8("label_151"));
        label_151->setGeometry(QRect(220, 10, 81, 16));
        h = new QDoubleSpinBox(widget_JONSWAP);
        h->setObjectName(QString::fromUtf8("h"));
        h->setGeometry(QRect(220, 30, 66, 24));
        h->setDecimals(3);
        Tp = new QDoubleSpinBox(widget_JONSWAP);
        Tp->setObjectName(QString::fromUtf8("Tp"));
        Tp->setGeometry(QRect(120, 30, 66, 24));
        Tp->setDecimals(3);
        label_152 = new QLabel(widget_JONSWAP);
        label_152->setObjectName(QString::fromUtf8("label_152"));
        label_152->setGeometry(QRect(20, 10, 81, 16));
        label_154 = new QLabel(widget_JONSWAP);
        label_154->setObjectName(QString::fromUtf8("label_154"));
        label_154->setGeometry(QRect(90, 30, 21, 16));
        label_155 = new QLabel(widget_JONSWAP);
        label_155->setObjectName(QString::fromUtf8("label_155"));
        label_155->setGeometry(QRect(190, 30, 21, 16));
        label_156 = new QLabel(widget_JONSWAP);
        label_156->setObjectName(QString::fromUtf8("label_156"));
        label_156->setGeometry(QRect(290, 30, 21, 16));
        maxkh = new QDoubleSpinBox(widget_JONSWAP);
        maxkh->setObjectName(QString::fromUtf8("maxkh"));
        maxkh->setGeometry(QRect(320, 30, 66, 24));
        maxkh->setValue(5);
        label_166 = new QLabel(widget_JONSWAP);
        label_166->setObjectName(QString::fromUtf8("label_166"));
        label_166->setGeometry(QRect(320, 10, 81, 16));
        label_167 = new QLabel(widget_JONSWAP);
        label_167->setObjectName(QString::fromUtf8("label_167"));
        label_167->setGeometry(QRect(410, 10, 81, 16));
        seed = new QSpinBox(widget_JONSWAP);
        seed->setObjectName(QString::fromUtf8("seed"));
        seed->setGeometry(QRect(410, 30, 47, 24));
        seed->setMinimum(1);
        seed->setMaximum(5);
        gamma_jonswap = new QDoubleSpinBox(widget_JONSWAP);
        gamma_jonswap->setObjectName(QString::fromUtf8("gamma_jonswap"));
        gamma_jonswap->setGeometry(QRect(480, 30, 62, 23));
        gamma_jonswap->setMaximum(10);
        gamma_jonswap->setSingleStep(0.1);
        gamma_jonswap->setValue(3.3);
        gamma_jonswap_label = new QLabel(widget_JONSWAP);
        gamma_jonswap_label->setObjectName(QString::fromUtf8("gamma_jonswap_label"));
        gamma_jonswap_label->setGeometry(QRect(480, 10, 54, 15));
        output->addTab(tab_5, QString());
        label_52->raise();
        widget_SF->raise();
        line_25->raise();
        line_27->raise();
        yAbsorbStart->raise();
        label_132->raise();
        xAbsorbStart->raise();
        label_133->raise();
        xAbsorbEnd->raise();
        yAbsorbEnd->raise();
        label_135->raise();
        label_136->raise();
        line_26->raise();
        waveType->raise();
        LorP_ComboBox->raise();
        pressureDampingOrRelax->raise();
        label_164->raise();
        waveGeneration_widget->raise();
        label_134->raise();
        widget_customSpectrum->raise();
        widget_waveFile->raise();
        widget_JONSWAP->raise();
        tab_9 = new QWidget();
        tab_9->setObjectName(QString::fromUtf8("tab_9"));
        line_28 = new QFrame(tab_9);
        line_28->setObjectName(QString::fromUtf8("line_28"));
        line_28->setGeometry(QRect(7, 50, 761, 20));
        line_28->setFrameShape(QFrame::HLine);
        line_28->setFrameShadow(QFrame::Sunken);
        storeAscii_onOff = new QCheckBox(tab_9);
        storeAscii_onOff->setObjectName(QString::fromUtf8("storeAscii_onOff"));
        storeAscii_onOff->setGeometry(QRect(290, 20, 121, 21));
        storeAscii_onOff->setChecked(true);
        nASCII = new QSpinBox(tab_9);
        nASCII->setObjectName(QString::fromUtf8("nASCII"));
        nASCII->setGeometry(QRect(620, 20, 61, 24));
        nASCII->setMaximum(1000);
        nASCII->setValue(20);
        ACCII_label = new QLabel(tab_9);
        ACCII_label->setObjectName(QString::fromUtf8("ACCII_label"));
        ACCII_label->setGeometry(QRect(430, 20, 211, 21));
        ASCII_label2 = new QLabel(tab_9);
        ASCII_label2->setObjectName(QString::fromUtf8("ASCII_label2"));
        ASCII_label2->setGeometry(QRect(690, 20, 211, 21));
        DropDownListOutputType = new QComboBox(tab_9);
        DropDownListOutputType->setObjectName(QString::fromUtf8("DropDownListOutputType"));
        DropDownListOutputType->setGeometry(QRect(50, 20, 201, 24));
        ACCII_label_2 = new QLabel(tab_9);
        ACCII_label_2->setObjectName(QString::fromUtf8("ACCII_label_2"));
        ACCII_label_2->setGeometry(QRect(10, 20, 41, 21));
        outputTable = new QWidget(tab_9);
        outputTable->setObjectName(QString::fromUtf8("outputTable"));
        outputTable->setEnabled(false);
        outputTable->setGeometry(QRect(10, 70, 781, 301));
        nOutFiles = new QSpinBox(outputTable);
        nOutFiles->setObjectName(QString::fromUtf8("nOutFiles"));
        nOutFiles->setGeometry(QRect(150, 10, 47, 24));
        nOutFiles->setMinimum(1);
        nOutFiles->setMaximum(10);
        label = new QLabel(outputTable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 10, 151, 16));
        tableWidget = new QTableWidget(outputTable);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(35, 40, 681, 241));
        output->addTab(tab_9, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        selectPPfile = new QPushButton(tab_3);
        selectPPfile->setObjectName(QString::fromUtf8("selectPPfile"));
        selectPPfile->setGeometry(QRect(10, 140, 91, 24));
        selectedPPfiles = new QLineEdit(tab_3);
        selectedPPfiles->setObjectName(QString::fromUtf8("selectedPPfiles"));
        selectedPPfiles->setGeometry(QRect(110, 140, 251, 23));
        line_9 = new QFrame(tab_3);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(0, 80, 741, 16));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        convert = new QPushButton(tab_3);
        convert->setObjectName(QString::fromUtf8("convert"));
        convert->setEnabled(true);
        convert->setGeometry(QRect(140, 190, 91, 24));
        selectGnuplotFile = new QPushButton(tab_3);
        selectGnuplotFile->setObjectName(QString::fromUtf8("selectGnuplotFile"));
        selectGnuplotFile->setGeometry(QRect(10, 40, 91, 24));
        gnuplotFile = new QLineEdit(tab_3);
        gnuplotFile->setObjectName(QString::fromUtf8("gnuplotFile"));
        gnuplotFile->setGeometry(QRect(110, 40, 251, 23));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(13, 10, 81, 31));
        label_14->setFont(font1);
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 100, 81, 31));
        label_15->setFont(font1);
        plot = new QPushButton(tab_3);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setGeometry(QRect(380, 40, 91, 24));
        read_bottom = new QPushButton(tab_3);
        read_bottom->setObjectName(QString::fromUtf8("read_bottom"));
        read_bottom->setGeometry(QRect(380, 140, 91, 24));
        readProgressBar = new QProgressBar(tab_3);
        readProgressBar->setObjectName(QString::fromUtf8("readProgressBar"));
        readProgressBar->setGeometry(QRect(490, 140, 141, 23));
        readProgressBar->setValue(24);
        readProgressBar->setTextVisible(true);
        SelectOutput = new QComboBox(tab_3);
        SelectOutput->setObjectName(QString::fromUtf8("SelectOutput"));
        SelectOutput->setGeometry(QRect(10, 190, 111, 24));
        morison_widget = new QWidget(tab_3);
        morison_widget->setObjectName(QString::fromUtf8("morison_widget"));
        morison_widget->setEnabled(true);
        morison_widget->setGeometry(QRect(20, 220, 571, 81));
        label_16 = new QLabel(morison_widget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 10, 41, 21));
        label_17 = new QLabel(morison_widget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(100, 10, 41, 21));
        morison_D = new QDoubleSpinBox(morison_widget);
        morison_D->setObjectName(QString::fromUtf8("morison_D"));
        morison_D->setGeometry(QRect(90, 40, 62, 23));
        morison_D->setSingleStep(0.1);
        morison_D->setValue(5);
        label_18 = new QLabel(morison_widget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(190, 10, 41, 21));
        morison_cd = new QDoubleSpinBox(morison_widget);
        morison_cd->setObjectName(QString::fromUtf8("morison_cd"));
        morison_cd->setGeometry(QRect(180, 40, 62, 23));
        morison_cd->setSingleStep(0.1);
        morison_cd->setValue(0.95);
        label_19 = new QLabel(morison_widget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(280, 10, 41, 21));
        morison_cm = new QDoubleSpinBox(morison_widget);
        morison_cm->setObjectName(QString::fromUtf8("morison_cm"));
        morison_cm->setGeometry(QRect(270, 40, 62, 23));
        morison_cm->setValue(2);
        morisonX0 = new QComboBox(morison_widget);
        morisonX0->setObjectName(QString::fromUtf8("morisonX0"));
        morisonX0->setGeometry(QRect(0, 40, 78, 24));
        morisonX0->setMaxVisibleItems(10000);
        morisonX0->setFrame(true);
        pushButton_advancedMorison = new QPushButton(morison_widget);
        pushButton_advancedMorison->setObjectName(QString::fromUtf8("pushButton_advancedMorison"));
        pushButton_advancedMorison->setGeometry(QRect(470, 40, 91, 24));
        convertStatus = new QLabel(tab_3);
        convertStatus->setObjectName(QString::fromUtf8("convertStatus"));
        convertStatus->setGeometry(QRect(260, 190, 161, 21));
        convertStatus->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        eta_widget = new QWidget(tab_3);
        eta_widget->setObjectName(QString::fromUtf8("eta_widget"));
        eta_widget->setEnabled(true);
        eta_widget->setGeometry(QRect(400, 320, 351, 81));
        label_20 = new QLabel(eta_widget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(10, 10, 41, 21));
        etaX0 = new QComboBox(eta_widget);
        etaX0->setObjectName(QString::fromUtf8("etaX0"));
        etaX0->setGeometry(QRect(0, 40, 121, 24));
        etaX0->setMaxVisibleItems(10000);
        etaX0->setFrame(true);
        output->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        aboutText_OCW3D_publications_2 = new QTextBrowser(tab_4);
        aboutText_OCW3D_publications_2->setObjectName(QString::fromUtf8("aboutText_OCW3D_publications_2"));
        aboutText_OCW3D_publications_2->setGeometry(QRect(20, 10, 731, 351));
        aboutText_OCW3D_publications_2->setLayoutDirection(Qt::LeftToRight);
        aboutText_OCW3D_publications_2->setOpenExternalLinks(true);
        output->addTab(tab_4, QString());
        About = new QWidget();
        About->setObjectName(QString::fromUtf8("About"));
        About->setLayoutDirection(Qt::RightToLeft);
        about_combobox = new QComboBox(About);
        about_combobox->setObjectName(QString::fromUtf8("about_combobox"));
        about_combobox->setGeometry(QRect(580, 20, 151, 24));
        about_combobox->setLayoutDirection(Qt::LeftToRight);
        aboutText_OCW3D = new QTextBrowser(About);
        aboutText_OCW3D->setObjectName(QString::fromUtf8("aboutText_OCW3D"));
        aboutText_OCW3D->setGeometry(QRect(10, 10, 531, 361));
        aboutText_OCW3D->setLayoutDirection(Qt::LeftToRight);
        aboutText_OCW3dGUI = new QTextBrowser(About);
        aboutText_OCW3dGUI->setObjectName(QString::fromUtf8("aboutText_OCW3dGUI"));
        aboutText_OCW3dGUI->setGeometry(QRect(80, 20, 411, 111));
        aboutText_OCW3dGUI->setLayoutDirection(Qt::LeftToRight);
        aboutText_OCW3D_publications = new QTextBrowser(About);
        aboutText_OCW3D_publications->setObjectName(QString::fromUtf8("aboutText_OCW3D_publications"));
        aboutText_OCW3D_publications->setGeometry(QRect(30, 100, 441, 461));
        aboutText_OCW3D_publications->setLayoutDirection(Qt::LeftToRight);
        deltaresLogo = new QLabel(About);
        deltaresLogo->setObjectName(QString::fromUtf8("deltaresLogo"));
        deltaresLogo->setGeometry(QRect(550, 230, 191, 111));
        deltaresLogo->setPixmap(QPixmap(QString::fromUtf8(":/pictures/deltares.png")));
        deltaresLogo->setScaledContents(true);
        dtuLogo = new QLabel(About);
        dtuLogo->setObjectName(QString::fromUtf8("dtuLogo"));
        dtuLogo->setGeometry(QRect(570, 90, 161, 101));
        dtuLogo->setPixmap(QPixmap(QString::fromUtf8(":/pictures/dtu.png")));
        dtuLogo->setScaledContents(true);
        aboutText_OCW3DVersion = new QTextBrowser(About);
        aboutText_OCW3DVersion->setObjectName(QString::fromUtf8("aboutText_OCW3DVersion"));
        aboutText_OCW3DVersion->setEnabled(true);
        aboutText_OCW3DVersion->setGeometry(QRect(0, 220, 521, 151));
        aboutText_OCW3DVersion->setLayoutDirection(Qt::LeftToRight);
        output->addTab(About, QString());

        gridLayout->addWidget(output, 0, 0, 1, 3);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 783, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuRun = new QMenu(menuBar);
        menuRun->setObjectName(QString::fromUtf8("menuRun"));
        MainWindow->setMenuBar(menuBar);
        QWidget::setTabOrder(header_input, OpenDirBrowser);
        QWidget::setTabOrder(OpenDirBrowser, nonlin_onOff);
        QWidget::setTabOrder(nonlin_onOff, geometryType);
        QWidget::setTabOrder(geometryType, length);
        QWidget::setTabOrder(length, width);
        QWidget::setTabOrder(width, depth);
        QWidget::setTabOrder(depth, nx);
        QWidget::setTabOrder(nx, ny);
        QWidget::setTabOrder(ny, nz);
        QWidget::setTabOrder(nz, sz);
        QWidget::setTabOrder(sz, selectGridFile);
        QWidget::setTabOrder(selectGridFile, nGridPoints);
        QWidget::setTabOrder(nGridPoints, generateGrid);
        QWidget::setTabOrder(generateGrid, smooth);
        QWidget::setTabOrder(smooth, showGrid);
        QWidget::setTabOrder(showGrid, waveType);
        QWidget::setTabOrder(waveType, LorP_ComboBox);
        QWidget::setTabOrder(LorP_ComboBox, SF_H);
        QWidget::setTabOrder(SF_H, SF_T);
        QWidget::setTabOrder(SF_T, SF_h);
        QWidget::setTabOrder(SF_h, SF_U);
        QWidget::setTabOrder(SF_U, stokesOrEuler);
        QWidget::setTabOrder(stokesOrEuler, SF_n);
        QWidget::setTabOrder(SF_n, xGenStart);
        QWidget::setTabOrder(xGenStart, xGenEnd);
        QWidget::setTabOrder(xGenEnd, yGenStart);
        QWidget::setTabOrder(yGenStart, yGenEnd);
        QWidget::setTabOrder(yGenEnd, rampTime);
        QWidget::setTabOrder(rampTime, xAbsorbStart);
        QWidget::setTabOrder(xAbsorbStart, xAbsorbEnd);
        QWidget::setTabOrder(xAbsorbEnd, yAbsorbStart);
        QWidget::setTabOrder(yAbsorbStart, yAbsorbEnd);
        QWidget::setTabOrder(yAbsorbEnd, pressureDampingOrRelax);
        QWidget::setTabOrder(pressureDampingOrRelax, Hs);
        QWidget::setTabOrder(Hs, Tp);
        QWidget::setTabOrder(Tp, h);
        QWidget::setTabOrder(h, maxkh);
        QWidget::setTabOrder(maxkh, seed);
        QWidget::setTabOrder(seed, selectedWaveFile);
        QWidget::setTabOrder(selectedWaveFile, selectWaveFile);
        QWidget::setTabOrder(selectWaveFile, rampTime_waveFile);
        QWidget::setTabOrder(rampTime_waveFile, nOutFiles);
        QWidget::setTabOrder(nOutFiles, storeAscii_onOff);
        QWidget::setTabOrder(storeAscii_onOff, nASCII);
        QWidget::setTabOrder(nASCII, run);
        QWidget::setTabOrder(run, pushButton);
        QWidget::setTabOrder(pushButton, selectGnuplotFile);
        QWidget::setTabOrder(selectGnuplotFile, plot);
        QWidget::setTabOrder(plot, selectPPfile);
        QWidget::setTabOrder(selectPPfile, read_bottom);
        QWidget::setTabOrder(read_bottom, SelectOutput);
        QWidget::setTabOrder(SelectOutput, convert);
        QWidget::setTabOrder(convert, morisonX0);
        QWidget::setTabOrder(morisonX0, morison_D);
        QWidget::setTabOrder(morison_D, morison_cd);
        QWidget::setTabOrder(morison_cd, morison_cm);
        QWidget::setTabOrder(morison_cm, about_combobox);
        QWidget::setTabOrder(about_combobox, workingDir);
        QWidget::setTabOrder(workingDir, geometry_table);
        QWidget::setTabOrder(geometry_table, tableWidget);
        QWidget::setTabOrder(tableWidget, selectedGridFile);
        QWidget::setTabOrder(selectedGridFile, gnuplotFile);
        QWidget::setTabOrder(gnuplotFile, selectedPPfiles);
        QWidget::setTabOrder(selectedPPfiles, etaX0);
        QWidget::setTabOrder(etaX0, output);
        QWidget::setTabOrder(output, aboutText_OCW3D);
        QWidget::setTabOrder(aboutText_OCW3D, aboutText_OCW3dGUI);
        QWidget::setTabOrder(aboutText_OCW3dGUI, aboutText_OCW3D_publications);
        QWidget::setTabOrder(aboutText_OCW3D_publications, aboutText_OCW3DVersion);
        QWidget::setTabOrder(aboutText_OCW3DVersion, aboutText_OCW3D_publications_2);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuRun->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionChange_directory);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuRun->addAction(actionWrite_input_file_F4);
        menuRun->addAction(actionRun_F5);
        menuRun->addAction(actionClear_case_F6);
        menuRun->addAction(actionCheck);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        output->setCurrentIndex(0);
        nonlin_onOff->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OCW3D - A GUI for OceanWave3D", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionRun_F5->setText(QApplication::translate("MainWindow", "Run", 0, QApplication::UnicodeUTF8));
        actionClear_case_F6->setText(QApplication::translate("MainWindow", "Clear case", 0, QApplication::UnicodeUTF8));
        actionWrite_input_file_F4->setText(QApplication::translate("MainWindow", "Write input file", 0, QApplication::UnicodeUTF8));
        actionChange_directory->setText(QApplication::translate("MainWindow", "Change directory", 0, QApplication::UnicodeUTF8));
        actionCheck->setText(QApplication::translate("MainWindow", "Check", 0, QApplication::UnicodeUTF8));
        run->setText(QApplication::translate("MainWindow", "Run", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        output->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_79->setText(QApplication::translate("MainWindow", "Header", 0, QApplication::UnicodeUTF8));
        label_92->setText(QApplication::translate("MainWindow", "Mode", 0, QApplication::UnicodeUTF8));
        label_165->setText(QApplication::translate("MainWindow", "Working directory ", 0, QApplication::UnicodeUTF8));
        OpenDirBrowser->setText(QApplication::translate("MainWindow", "Change", 0, QApplication::UnicodeUTF8));
        workingDir->setText(QString());
#ifndef QT_NO_WHATSTHIS
        header_input->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        header_input->setText(QApplication::translate("MainWindow", "Header", 0, QApplication::UnicodeUTF8));
        header_input->setPlaceholderText(QString());
        nonlin_onOff->clear();
        nonlin_onOff->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Non-linear", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Linear", 0, QApplication::UnicodeUTF8)
        );
        label_160->setText(QApplication::translate("MainWindow", "[kg/m^3]", 0, QApplication::UnicodeUTF8));
        label_158->setText(QApplication::translate("MainWindow", "Density", 0, QApplication::UnicodeUTF8));
        label_159->setText(QApplication::translate("MainWindow", "[m/s^2]", 0, QApplication::UnicodeUTF8));
        label_90->setText(QApplication::translate("MainWindow", "Constants", 0, QApplication::UnicodeUTF8));
        label_91->setText(QApplication::translate("MainWindow", "Gravity", 0, QApplication::UnicodeUTF8));
        label_87->setText(QApplication::translate("MainWindow", "Breaking filter", 0, QApplication::UnicodeUTF8));
        label_89->setText(QApplication::translate("MainWindow", "Fraction of gravity", 0, QApplication::UnicodeUTF8));
        checkBox_breakingWidget->setText(QApplication::translate("MainWindow", "default", 0, QApplication::UnicodeUTF8));
        gamma_label->setText(QApplication::translate("MainWindow", "gamma", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        alpha_label->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        alpha_label->setText(QApplication::translate("MainWindow", "alpha", 0, QApplication::UnicodeUTF8));
        beta_label->setText(QApplication::translate("MainWindow", "beta", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Finite difference", 0, QApplication::UnicodeUTF8));
        checkBox_FD->setText(QApplication::translate("MainWindow", "default", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MainWindow", "a", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Preconditioner", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("MainWindow", "c", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "b", 0, QApplication::UnicodeUTF8));
        checkBox_precon->setText(QApplication::translate("MainWindow", "default", 0, QApplication::UnicodeUTF8));
        label_138->setText(QApplication::translate("MainWindow", "Time step [s]", 0, QApplication::UnicodeUTF8));
        label_157->setText(QApplication::translate("MainWindow", "Duration [s]", 0, QApplication::UnicodeUTF8));
        label_161->setText(QApplication::translate("MainWindow", "Time", 0, QApplication::UnicodeUTF8));
        checkBox_constantWidget->setText(QApplication::translate("MainWindow", "default", 0, QApplication::UnicodeUTF8));
        output->setTabText(output->indexOf(tab_11), QApplication::translate("MainWindow", "General", 0, QApplication::UnicodeUTF8));
        label_88->setText(QApplication::translate("MainWindow", "Geometry", 0, QApplication::UnicodeUTF8));
        geometryType->clear();
        geometryType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Standard", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Custom (2D)", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("MainWindow", "Domain", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Resolution", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "nz", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "nx", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Width [m]", 0, QApplication::UnicodeUTF8));
        sz->setText(QApplication::translate("MainWindow", "vertical", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Depth [m]", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Stretching", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        label_2->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_2->setText(QApplication::translate("MainWindow", "Length [m]", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "ny", 0, QApplication::UnicodeUTF8));
        smooth->setText(QApplication::translate("MainWindow", "Smooth", 0, QApplication::UnicodeUTF8));
        generateGrid->setText(QApplication::translate("MainWindow", "Generate grid", 0, QApplication::UnicodeUTF8));
        showGrid->setText(QApplication::translate("MainWindow", "Show grid", 0, QApplication::UnicodeUTF8));
        selectGridFile->setText(QApplication::translate("MainWindow", "Select grid file", 0, QApplication::UnicodeUTF8));
        selectedGridFile->setText(QApplication::translate("MainWindow", "customGrid.bot", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "File Name:", 0, QApplication::UnicodeUTF8));
        output->setTabText(output->indexOf(tab), QApplication::translate("MainWindow", "Geometry", 0, QApplication::UnicodeUTF8));
        label_52->setText(QApplication::translate("MainWindow", "Wave type", 0, QApplication::UnicodeUTF8));
        label_132->setText(QApplication::translate("MainWindow", "x [m]", 0, QApplication::UnicodeUTF8));
        label_133->setText(QApplication::translate("MainWindow", "End", 0, QApplication::UnicodeUTF8));
        label_134->setText(QApplication::translate("MainWindow", "Wave absorption zone", 0, QApplication::UnicodeUTF8));
        label_135->setText(QApplication::translate("MainWindow", "y[m]", 0, QApplication::UnicodeUTF8));
        label_136->setText(QApplication::translate("MainWindow", "Begin", 0, QApplication::UnicodeUTF8));
        waveType->clear();
        waveType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Wave theory", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Stream function", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "JONSWAP", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "PM", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Wave file", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Wave maker", 0, QApplication::UnicodeUTF8)
        );
        SF_TLabel->setText(QApplication::translate("MainWindow", "Wave period:", 0, QApplication::UnicodeUTF8));
        label_142->setText(QApplication::translate("MainWindow", "Water depth", 0, QApplication::UnicodeUTF8));
        label_140->setText(QApplication::translate("MainWindow", "Wave height", 0, QApplication::UnicodeUTF8));
        label_143->setText(QApplication::translate("MainWindow", "Current velocity", 0, QApplication::UnicodeUTF8));
        label_144->setText(QApplication::translate("MainWindow", "m", 0, QApplication::UnicodeUTF8));
        SF_TL_unit->setText(QApplication::translate("MainWindow", "s", 0, QApplication::UnicodeUTF8));
        label_146->setText(QApplication::translate("MainWindow", "m", 0, QApplication::UnicodeUTF8));
        label_147->setText(QApplication::translate("MainWindow", "m/s", 0, QApplication::UnicodeUTF8));
        label_148->setText(QApplication::translate("MainWindow", "Current type", 0, QApplication::UnicodeUTF8));
        stokesOrEuler->clear();
        stokesOrEuler->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Euler", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Stokes", 0, QApplication::UnicodeUTF8)
        );
        label_149->setText(QApplication::translate("MainWindow", "Order", 0, QApplication::UnicodeUTF8));
        LorP_ComboBox->clear();
        LorP_ComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Wave length", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "wave period", 0, QApplication::UnicodeUTF8)
        );
        pressureDampingOrRelax->clear();
        pressureDampingOrRelax->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Pressure damping", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Relaxation zone", 0, QApplication::UnicodeUTF8)
        );
        label_164->setText(QApplication::translate("MainWindow", "Type", 0, QApplication::UnicodeUTF8));
        label_126->setText(QApplication::translate("MainWindow", "x [m]", 0, QApplication::UnicodeUTF8));
        label_130->setText(QApplication::translate("MainWindow", "End", 0, QApplication::UnicodeUTF8));
        label_55->setText(QApplication::translate("MainWindow", "Wave generation zone", 0, QApplication::UnicodeUTF8));
        label_127->setText(QApplication::translate("MainWindow", "y [m]", 0, QApplication::UnicodeUTF8));
        label_163->setText(QApplication::translate("MainWindow", "Ramp time [s]", 0, QApplication::UnicodeUTF8));
        label_129->setText(QApplication::translate("MainWindow", "Begin", 0, QApplication::UnicodeUTF8));
        label_170->setText(QApplication::translate("MainWindow", "Wave signal", 0, QApplication::UnicodeUTF8));
        selectWaveFile_eta->setText(QApplication::translate("MainWindow", "Select wave file", 0, QApplication::UnicodeUTF8));
        label_171->setText(QApplication::translate("MainWindow", "y0", 0, QApplication::UnicodeUTF8));
        label_172->setText(QApplication::translate("MainWindow", "x0", 0, QApplication::UnicodeUTF8));
        label_169->setText(QApplication::translate("MainWindow", "Wave paddle signal", 0, QApplication::UnicodeUTF8));
        selectWaveFile->setText(QApplication::translate("MainWindow", "Select wave file", 0, QApplication::UnicodeUTF8));
        label_168->setText(QApplication::translate("MainWindow", "Ramp time [s]", 0, QApplication::UnicodeUTF8));
        label_150->setText(QApplication::translate("MainWindow", "Tp", 0, QApplication::UnicodeUTF8));
        label_151->setText(QApplication::translate("MainWindow", "Water depth", 0, QApplication::UnicodeUTF8));
        label_152->setText(QApplication::translate("MainWindow", "Hs", 0, QApplication::UnicodeUTF8));
        label_154->setText(QApplication::translate("MainWindow", "m", 0, QApplication::UnicodeUTF8));
        label_155->setText(QApplication::translate("MainWindow", "s", 0, QApplication::UnicodeUTF8));
        label_156->setText(QApplication::translate("MainWindow", "m", 0, QApplication::UnicodeUTF8));
        label_166->setText(QApplication::translate("MainWindow", "max(kh)", 0, QApplication::UnicodeUTF8));
        label_167->setText(QApplication::translate("MainWindow", "Seed", 0, QApplication::UnicodeUTF8));
        gamma_jonswap_label->setText(QApplication::translate("MainWindow", "gamma", 0, QApplication::UnicodeUTF8));
        output->setTabText(output->indexOf(tab_5), QApplication::translate("MainWindow", "Wave Generation", 0, QApplication::UnicodeUTF8));
        storeAscii_onOff->setText(QApplication::translate("MainWindow", "Store ASCII files", 0, QApplication::UnicodeUTF8));
        ACCII_label->setText(QApplication::translate("MainWindow", "ASCII files are stored for every:", 0, QApplication::UnicodeUTF8));
        ASCII_label2->setText(QApplication::translate("MainWindow", "time steps.", 0, QApplication::UnicodeUTF8));
        DropDownListOutputType->clear();
        DropDownListOutputType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "No outputs", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Kinematics (all information)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Wave gagues ", 0, QApplication::UnicodeUTF8)
        );
        ACCII_label_2->setText(QApplication::translate("MainWindow", "Type:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Number of output files", 0, QApplication::UnicodeUTF8));
        output->setTabText(output->indexOf(tab_9), QApplication::translate("MainWindow", "Output", 0, QApplication::UnicodeUTF8));
        selectPPfile->setText(QApplication::translate("MainWindow", "Select File", 0, QApplication::UnicodeUTF8));
        convert->setText(QApplication::translate("MainWindow", "Convert", 0, QApplication::UnicodeUTF8));
        selectGnuplotFile->setText(QApplication::translate("MainWindow", "Select File", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "GNUPLOT", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "Convert", 0, QApplication::UnicodeUTF8));
        plot->setText(QApplication::translate("MainWindow", "Plot", 0, QApplication::UnicodeUTF8));
        read_bottom->setText(QApplication::translate("MainWindow", "Read", 0, QApplication::UnicodeUTF8));
        SelectOutput->clear();
        SelectOutput->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Select output", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Force", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "matlab", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "eta", 0, QApplication::UnicodeUTF8)
        );
        label_16->setText(QApplication::translate("MainWindow", "x0 [m]", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "D [m]", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "Cd", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "Cm", 0, QApplication::UnicodeUTF8));
        pushButton_advancedMorison->setText(QApplication::translate("MainWindow", "Advanced", 0, QApplication::UnicodeUTF8));
        convertStatus->setText(QApplication::translate("MainWindow", "Converting...", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "x0 [m]", 0, QApplication::UnicodeUTF8));
        output->setTabText(output->indexOf(tab_3), QApplication::translate("MainWindow", "Post-processing", 0, QApplication::UnicodeUTF8));
        aboutText_OCW3D_publications_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:600;\">Governing equations / theory:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:9pt;\">The theory behind and the performance of OceanWave3D is documented in numerous journal articles, see the &quot;About&quot; section.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:"
                        "0; text-indent:0px; font-family:'Sans Serif'; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:600;\">Input files:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:9pt;\">Input files showing all functionalities of the code are distributed with the source code of OceanWave3D; the relative path is: ./trunk/examples/inputfiles/</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Sans Serif'; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size"
                        ":9pt; font-weight:600;\">Post-processing:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:9pt;\">Matlab/octave post-processing scripts are delivered with the source code; the relative path is: ./trunk/utils/matlab/ </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Sans Serif'; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:600;\">Other questions:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:9pt;\">For questions related to academic use of Ocean"
                        "Wave3D contact Allan Peter Engsig-Karup (</span><a href=\"mailto:apek@dtu.dk\"><span style=\" font-family:'Sans Serif'; font-size:9pt; text-decoration: underline; color:#0000ff;\">apek@dtu.dk</span></a><span style=\" font-family:'Sans Serif'; font-size:9pt;\">). For all other questions please contact Bo Terp Paulsen, (</span><a href=\"mailto:bo.paulsen@deltares.nl\"><span style=\" font-family:'Sans Serif'; font-size:9pt; text-decoration: underline; color:#0000ff;\">bo.paulsen@deltares.nl</span></a><span style=\" font-family:'Sans Serif'; font-size:9pt;\">)</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Sans Serif'; font-size:9pt;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        output->setTabText(output->indexOf(tab_4), QApplication::translate("MainWindow", "Help / support", 0, QApplication::UnicodeUTF8));
        about_combobox->clear();
        about_combobox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "OceanWave3D", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "GUI", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Publications", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Versions", 0, QApplication::UnicodeUTF8)
        );
        aboutText_OCW3D->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">OceanWave3D - a costal engineering tool for simulation of nonlinear free</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">surface waves. </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">Copyright (C) 2009 Allan P. Engsig-Karup, DTU Compute, </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:"
                        "0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">Technical University of Denmark</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">This OceanWave3D program comes with ABSOLUTELY NO WARRANTY. This is free</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">software and you are welcome to redistribute it under the conditions</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">of the GNU General Public License version 3.</span></p>\n"
""
                        "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">Permission is hereby granted, free of charge, to any person obtaining a copy</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">of this software and associated documentation files (the &quot;Software&quot;), to deal</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">in the Software without restriction, including without limitation the rights</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; t"
                        "ext-indent:0px;\"><span style=\" font-size:9pt;\">to use, copy, modify, merge, publish, distribute, sublicense, and/or sell</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">copies of the Software, and to permit persons to whom the Software is</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">furnished to do so, subject to the following conditions:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">The above copyright notice and this permission notice shall be included in</span></p>\n"
"<p s"
                        "tyle=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">all copies or substantial portions of the Software.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">THE SOFTWARE IS PROVIDED &quot;AS IS&quot;, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" fon"
                        "t-size:9pt;\">FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">THE SOFTWARE.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        aboutText_OCW3dGUI->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">The Graphical User Interface (GUI) for OceanWave3D (C) is developed and maintained by Bo Terp Paulsen, </span><a href=\"mailto: bo.paulsen@deltares.nl\"><span style=\" text-decoration: underline; color:#0057ae;\">bo.paulsen@deltares.nl</span></a><span style=\" font-size:9pt;\">. The software has inherited the GNU General Public Licence version 3 of OceanWave3D, and is hence free to use and redistribute. </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-bloc"
                        "k-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">THE SOFTWARE IS PROVIDED &quot;AS IS&quot;, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        aboutText_OCW3D_publications->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">Please acknowledge this software referred to as &quot;OceanWave3D&quot; in your work and any of the publications below by using the following references:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">  @ARTICLE{EngsigKarupEtAl08,</span></p>"
                        "\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">  AUTHOR    = &quot;Engsig-Karup, A.P. and Bingham, H.B. and Lindberg, O.&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">  TITLE     = &quot;An efficient flexible-order model for {3D} nonlinear water waves&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">  YEAR      = &quot;2009&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">  JOURNAL   = &quot;Journal of Computational Physics&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -"
                        "qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">  VOLUME    = &quot;228&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">  PAGES     = &quot;2100-2118&quot;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">  }</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">and this chapter with general details on the properties of the model and its parallel implementation (note that this Fortran version is not yet parallel)</span></p>\n"
"<p style=\"-qt-paragraph-type:empty"
                        "; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">  @inbook{EngsigKarupEtAl2013,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">  title     = &quot;Fast hydrodynamics on heterogenous many-core hardware&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">  publisher = &quot;Taylor &amp; Francis&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">  author    = &quot;Engsig-Karup, {Allan Peter} and Glimberg, {Stef"
                        "an Lemvig} and Nielsen, {Allan S.} and Ole Lindberg&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">  note      = &quot;2013; 11&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">  year      = &quot;2013&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">  editor    = &quot;Rapha\\'el Couturier&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">  isbn      = &quot;978-1-4665-7162-4&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;"
                        "\"><span style=\" font-size:9pt;\">  pages     = &quot;251--294&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">  booktitle = &quot;Designing Scientific Applications on GPUs&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">  }</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">OceanWave3D is distributed under the GNU General Public License (See file LICENSE) and a base code was developed at DTU Mechanics 2006-2008 by Allan P. Engsig-Karup and entirely rewritten at DTU Inform"
                        "atics 2008-2011 (current version) by Allan P. Engsig-Karup with contributions as mentioned below section 4 of this file.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">A GPU-accelerated massively parallel version of OceanWave3D that can execute on heterogenous archictures using the CUDA programming model has been developed in collaboration between Morten Gorm Madsen (first proof-of-concept version), Stefan Lemvig Glimberg (advanced version within GPULAB library) and Allan P. Engsig-Karup. In this version of the code the multigrid preconditioned defect correction method (PDC) appeared for the first time and it accessbile in this fortran version of the code as well. This work can be cited by the following reference</span"
                        "></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   @ARTICLE{EngsigKarupEtAl2011,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   AUTHOR = &quot;Engsig-Karup, A. P. and Madsen, M. G. and Glimberg, S. L.&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   TITLE = &quot;A massively parallel {GPU}-accelerated model for analysis of fully nonlinear free surface waves&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:"
                        "0; text-indent:0px;\"><span style=\" font-size:9pt;\">   JOURNAL = &quot;International Journal of Numerical Methods in Fluids&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   YEAR = &quot;2011&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   DOI = &quot;10.1002/fld.2675&quot;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   }</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span"
                        " style=\" font-size:9pt;\">The properties of the PDC method is analyzed in great detail in</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   @ARTICLE{EngsigKarupEtAl2013,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   AUTHOR = &quot;Engsig-Karup, A.P.&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   TITLE = &quot;Analysis of Efficient Preconditioned Defect Correction Methods for Nonlinear Water Waves&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; ma"
                        "rgin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   JOURNAL = &quot;International Journal of Numerical Methods in Fluids&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   YEAR = &quot;2013&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   }</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">The splitting technique that can be used for efficient wave-structure interactions are described here</span></p>\n"
"<p style=\"-"
                        "qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   @article{DucrozetEtAl2013,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   title     = &quot;A non-linear wave decomposition model for efficient wave\342\200\232\303\204\303\254structure interaction. Part A: Formulation, validations and analysis&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   publisher = &quot;Academic Press&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; t"
                        "ext-indent:0px;\"><span style=\" font-size:9pt;\">   author    = &quot;Guillaume Ducrozet and Engsig-Karup, {Allan Peter} and Bingham, {Harry B.} and Pierre Ferrant&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   year      = &quot;2014&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   volume    = &quot;257&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   pages     = &quot;863--883&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   journal   = &quot;Journal of Computational Physics&quot;,</span></p>\n"
"<p "
                        "style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   issn      = &quot;0021-9991&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   }</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">A comparison between OceanWave3D and HOS is described here</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin"
                        "-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   @article{DucrozetEtAl2012,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   title     = &quot;A comparative study of two fast nonlinear free-surface water wave models&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   publisher = &quot;John/Wiley &amp; Sons Ltd.&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   author    = &quot;Guillaume Ducrozet and Bingham, {Harry B.} and Engsig-Karup, {Allan Peter} and Felicien Bonnefoy and Pierre Ferrant&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-i"
                        "ndent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   year      = &quot;2012&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   volume    = &quot;69&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   pages     = &quot;1818--1834&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   journal   = &quot;International Journal for Numerical Methods in Fluids&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   issn      = &quot;0271-2091&quot;,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-l"
                        "eft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">   }</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:9pt;\"><br /></p></body></html>", 0, QApplication::UnicodeUTF8));
        deltaresLogo->setText(QString());
        dtuLogo->setText(QString());
        aboutText_OCW3DVersion->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif';\">This is version v1.0.0 of OCW3D - a GUI for OceanWave3D.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Sans Serif';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif';\">This version has been tested with r.123 of OceanWave3D (branch botp).</span></p>\n"
"<p style=\"-qt-para"
                        "graph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Sans Serif';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif';\">/Bo Terp Paulsen</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Sans Serif';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif';\">:wq</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        output->setTabText(output->indexOf(About), QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuRun->setTitle(QApplication::translate("MainWindow", "Run", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
