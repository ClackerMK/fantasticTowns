/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *addHMP;
    QPushButton *deleteHMMP;
    QListWidget *listHMMP;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *size_x;
    QLabel *label_2;
    QSpinBox *size_y;
    QToolBox *ModProcessBox;
    QWidget *PN_Page;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *stepsLabel;
    QLineEdit *PN_steps;
    QLabel *amplitudeLabel;
    QLineEdit *PN_amplitude;
    QLabel *lacunarityLabel;
    QLineEdit *PN_lacunarity;
    QLabel *qualityLabel;
    QComboBox *PN_quality;
    QLabel *persistenceLabel;
    QLineEdit *PN_persistence;
    QLabel *octaveCountLabel;
    QLineEdit *PN_octaveCount;
    QWidget *Erosion_Page;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_5;
    QLineEdit *Erosion_Solubility;
    QLabel *label_3;
    QLineEdit *Erosion_Iterations;
    QLabel *Evaporation_Erosion;
    QLineEdit *Erosion_Evaporation;
    QLineEdit *Erosion_Capacity;
    QLabel *Evaporation_Capacity;
    QLabel *label_4;
    QLineEdit *Erosion_RainAmount;
    QWidget *page;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *stonesLabel;
    QLineEdit *Volcanic_Stones;
    QLabel *stoneSizeMinLabel;
    QLineEdit *Volcanic_stoneSizeMin;
    QLabel *stoneSizeMaxLabel;
    QLineEdit *Volcanic_stoneSizeMax;
    QLabel *stabilityLabel;
    QSpinBox *Volcanic_stability;
    QWidget *page_2;
    QWidget *formLayoutWidget_4;
    QFormLayout *formLayout_4;
    QLabel *radiusLabel;
    QLineEdit *Stretch_Factor;
    QGroupBox *groupBox_2;
    QLineEdit *seedEdit;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *startButton;
    QTextBrowser *textBrowser;
    QProgressBar *progressBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(682, 597);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 531, 581));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayoutWidget = new QWidget(tab);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(320, 10, 51, 82));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        addHMP = new QPushButton(verticalLayoutWidget);
        addHMP->setObjectName(QStringLiteral("addHMP"));
        addHMP->setMinimumSize(QSize(40, 40));

        verticalLayout->addWidget(addHMP);

        deleteHMMP = new QPushButton(verticalLayoutWidget);
        deleteHMMP->setObjectName(QStringLiteral("deleteHMMP"));
        deleteHMMP->setEnabled(false);
        deleteHMMP->setMinimumSize(QSize(40, 40));

        verticalLayout->addWidget(deleteHMMP);

        listHMMP = new QListWidget(tab);
        listHMMP->setObjectName(QStringLiteral("listHMMP"));
        listHMMP->setGeometry(QRect(10, 10, 301, 411));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 430, 221, 61));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 20, 221, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(10, 0));
        label->setMaximumSize(QSize(10, 16777215));

        horizontalLayout->addWidget(label);

        size_x = new QSpinBox(horizontalLayoutWidget);
        size_x->setObjectName(QStringLiteral("size_x"));
        size_x->setMaximumSize(QSize(1666666, 16777215));
        size_x->setMinimum(1);
        size_x->setMaximum(9999999);
        size_x->setSingleStep(10);
        size_x->setValue(800);

        horizontalLayout->addWidget(size_x);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(10, 16777215));

        horizontalLayout->addWidget(label_2);

        size_y = new QSpinBox(horizontalLayoutWidget);
        size_y->setObjectName(QStringLiteral("size_y"));
        size_y->setMinimum(1);
        size_y->setMaximum(999999);
        size_y->setSingleStep(10);
        size_y->setValue(800);

        horizontalLayout->addWidget(size_y);

        ModProcessBox = new QToolBox(tab);
        ModProcessBox->setObjectName(QStringLiteral("ModProcessBox"));
        ModProcessBox->setGeometry(QRect(310, 100, 221, 381));
        PN_Page = new QWidget();
        PN_Page->setObjectName(QStringLiteral("PN_Page"));
        PN_Page->setGeometry(QRect(0, 0, 221, 269));
        formLayoutWidget_2 = new QWidget(PN_Page);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(0, 0, 211, 171));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        stepsLabel = new QLabel(formLayoutWidget_2);
        stepsLabel->setObjectName(QStringLiteral("stepsLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, stepsLabel);

        PN_steps = new QLineEdit(formLayoutWidget_2);
        PN_steps->setObjectName(QStringLiteral("PN_steps"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, PN_steps);

        amplitudeLabel = new QLabel(formLayoutWidget_2);
        amplitudeLabel->setObjectName(QStringLiteral("amplitudeLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, amplitudeLabel);

        PN_amplitude = new QLineEdit(formLayoutWidget_2);
        PN_amplitude->setObjectName(QStringLiteral("PN_amplitude"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, PN_amplitude);

        lacunarityLabel = new QLabel(formLayoutWidget_2);
        lacunarityLabel->setObjectName(QStringLiteral("lacunarityLabel"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, lacunarityLabel);

        PN_lacunarity = new QLineEdit(formLayoutWidget_2);
        PN_lacunarity->setObjectName(QStringLiteral("PN_lacunarity"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, PN_lacunarity);

        qualityLabel = new QLabel(formLayoutWidget_2);
        qualityLabel->setObjectName(QStringLiteral("qualityLabel"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, qualityLabel);

        PN_quality = new QComboBox(formLayoutWidget_2);
        PN_quality->setObjectName(QStringLiteral("PN_quality"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, PN_quality);

        persistenceLabel = new QLabel(formLayoutWidget_2);
        persistenceLabel->setObjectName(QStringLiteral("persistenceLabel"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, persistenceLabel);

        PN_persistence = new QLineEdit(formLayoutWidget_2);
        PN_persistence->setObjectName(QStringLiteral("PN_persistence"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, PN_persistence);

        octaveCountLabel = new QLabel(formLayoutWidget_2);
        octaveCountLabel->setObjectName(QStringLiteral("octaveCountLabel"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, octaveCountLabel);

        PN_octaveCount = new QLineEdit(formLayoutWidget_2);
        PN_octaveCount->setObjectName(QStringLiteral("PN_octaveCount"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, PN_octaveCount);

        ModProcessBox->addItem(PN_Page, QStringLiteral("PerlinNoise"));
        Erosion_Page = new QWidget();
        Erosion_Page->setObjectName(QStringLiteral("Erosion_Page"));
        Erosion_Page->setGeometry(QRect(0, 0, 221, 269));
        formLayoutWidget = new QWidget(Erosion_Page);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 0, 211, 161));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        Erosion_Solubility = new QLineEdit(formLayoutWidget);
        Erosion_Solubility->setObjectName(QStringLiteral("Erosion_Solubility"));

        formLayout->setWidget(0, QFormLayout::FieldRole, Erosion_Solubility);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        Erosion_Iterations = new QLineEdit(formLayoutWidget);
        Erosion_Iterations->setObjectName(QStringLiteral("Erosion_Iterations"));

        formLayout->setWidget(1, QFormLayout::FieldRole, Erosion_Iterations);

        Evaporation_Erosion = new QLabel(formLayoutWidget);
        Evaporation_Erosion->setObjectName(QStringLiteral("Evaporation_Erosion"));
        sizePolicy.setHeightForWidth(Evaporation_Erosion->sizePolicy().hasHeightForWidth());
        Evaporation_Erosion->setSizePolicy(sizePolicy);
        Evaporation_Erosion->setWordWrap(true);

        formLayout->setWidget(2, QFormLayout::LabelRole, Evaporation_Erosion);

        Erosion_Evaporation = new QLineEdit(formLayoutWidget);
        Erosion_Evaporation->setObjectName(QStringLiteral("Erosion_Evaporation"));

        formLayout->setWidget(2, QFormLayout::FieldRole, Erosion_Evaporation);

        Erosion_Capacity = new QLineEdit(formLayoutWidget);
        Erosion_Capacity->setObjectName(QStringLiteral("Erosion_Capacity"));

        formLayout->setWidget(3, QFormLayout::FieldRole, Erosion_Capacity);

        Evaporation_Capacity = new QLabel(formLayoutWidget);
        Evaporation_Capacity->setObjectName(QStringLiteral("Evaporation_Capacity"));
        sizePolicy.setHeightForWidth(Evaporation_Capacity->sizePolicy().hasHeightForWidth());
        Evaporation_Capacity->setSizePolicy(sizePolicy);
        Evaporation_Capacity->setWordWrap(true);

        formLayout->setWidget(3, QFormLayout::LabelRole, Evaporation_Capacity);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(100, 10000));
        label_4->setWordWrap(true);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        Erosion_RainAmount = new QLineEdit(formLayoutWidget);
        Erosion_RainAmount->setObjectName(QStringLiteral("Erosion_RainAmount"));

        formLayout->setWidget(4, QFormLayout::FieldRole, Erosion_RainAmount);

        ModProcessBox->addItem(Erosion_Page, QStringLiteral("Erosion"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 221, 269));
        formLayoutWidget_3 = new QWidget(page);
        formLayoutWidget_3->setObjectName(QStringLiteral("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(0, 0, 211, 111));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        stonesLabel = new QLabel(formLayoutWidget_3);
        stonesLabel->setObjectName(QStringLiteral("stonesLabel"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, stonesLabel);

        Volcanic_Stones = new QLineEdit(formLayoutWidget_3);
        Volcanic_Stones->setObjectName(QStringLiteral("Volcanic_Stones"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, Volcanic_Stones);

        stoneSizeMinLabel = new QLabel(formLayoutWidget_3);
        stoneSizeMinLabel->setObjectName(QStringLiteral("stoneSizeMinLabel"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, stoneSizeMinLabel);

        Volcanic_stoneSizeMin = new QLineEdit(formLayoutWidget_3);
        Volcanic_stoneSizeMin->setObjectName(QStringLiteral("Volcanic_stoneSizeMin"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, Volcanic_stoneSizeMin);

        stoneSizeMaxLabel = new QLabel(formLayoutWidget_3);
        stoneSizeMaxLabel->setObjectName(QStringLiteral("stoneSizeMaxLabel"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, stoneSizeMaxLabel);

        Volcanic_stoneSizeMax = new QLineEdit(formLayoutWidget_3);
        Volcanic_stoneSizeMax->setObjectName(QStringLiteral("Volcanic_stoneSizeMax"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, Volcanic_stoneSizeMax);

        stabilityLabel = new QLabel(formLayoutWidget_3);
        stabilityLabel->setObjectName(QStringLiteral("stabilityLabel"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, stabilityLabel);

        Volcanic_stability = new QSpinBox(formLayoutWidget_3);
        Volcanic_stability->setObjectName(QStringLiteral("Volcanic_stability"));
        Volcanic_stability->setMinimum(1);
        Volcanic_stability->setMaximum(4);
        Volcanic_stability->setValue(2);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, Volcanic_stability);

        ModProcessBox->addItem(page, QStringLiteral("Volcanic"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 221, 269));
        formLayoutWidget_4 = new QWidget(page_2);
        formLayoutWidget_4->setObjectName(QStringLiteral("formLayoutWidget_4"));
        formLayoutWidget_4->setGeometry(QRect(0, 0, 211, 31));
        formLayout_4 = new QFormLayout(formLayoutWidget_4);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        radiusLabel = new QLabel(formLayoutWidget_4);
        radiusLabel->setObjectName(QStringLiteral("radiusLabel"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, radiusLabel);

        Stretch_Factor = new QLineEdit(formLayoutWidget_4);
        Stretch_Factor->setObjectName(QStringLiteral("Stretch_Factor"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, Stretch_Factor);

        ModProcessBox->addItem(page_2, QStringLiteral("Stretch"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 500, 511, 41));
        seedEdit = new QLineEdit(groupBox_2);
        seedEdit->setObjectName(QStringLiteral("seedEdit"));
        seedEdit->setGeometry(QRect(0, 20, 511, 21));
        tabWidget->addTab(tab, QString());
        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(540, 20, 131, 551));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        startButton = new QPushButton(verticalLayoutWidget_2);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setEnabled(true);
        startButton->setMinimumSize(QSize(0, 40));
        startButton->setFlat(false);

        verticalLayout_2->addWidget(startButton);

        textBrowser = new QTextBrowser(verticalLayoutWidget_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout_2->addWidget(textBrowser);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(0, 580, 681, 20));
        progressBar->setValue(0);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        ModProcessBox->setCurrentIndex(0);
        startButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        addHMP->setText(QApplication::translate("MainWindow", "+", 0));
        deleteHMMP->setText(QApplication::translate("MainWindow", "-", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Start Size", 0));
        label->setText(QApplication::translate("MainWindow", "X", 0));
        label_2->setText(QApplication::translate("MainWindow", "Y", 0));
        stepsLabel->setText(QApplication::translate("MainWindow", "Step", 0));
        PN_steps->setText(QApplication::translate("MainWindow", "0.05", 0));
        amplitudeLabel->setText(QApplication::translate("MainWindow", "Amplitude", 0));
        PN_amplitude->setText(QApplication::translate("MainWindow", "30.0", 0));
        lacunarityLabel->setText(QApplication::translate("MainWindow", "Lacunarity", 0));
        PN_lacunarity->setText(QApplication::translate("MainWindow", "2.0", 0));
        qualityLabel->setText(QApplication::translate("MainWindow", "Quality", 0));
        PN_quality->clear();
        PN_quality->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Standard", 0)
         << QApplication::translate("MainWindow", "Fast", 0)
         << QApplication::translate("MainWindow", "Best", 0)
        );
        persistenceLabel->setText(QApplication::translate("MainWindow", "Persistence", 0));
        PN_persistence->setText(QApplication::translate("MainWindow", "0.5", 0));
        octaveCountLabel->setText(QApplication::translate("MainWindow", "Octave Count", 0));
        PN_octaveCount->setText(QApplication::translate("MainWindow", "6", 0));
        ModProcessBox->setItemText(ModProcessBox->indexOf(PN_Page), QApplication::translate("MainWindow", "PerlinNoise", 0));
        label_5->setText(QApplication::translate("MainWindow", "Solubility ", 0));
        Erosion_Solubility->setText(QApplication::translate("MainWindow", "5", 0));
        label_3->setText(QApplication::translate("MainWindow", "Iterations", 0));
        Erosion_Iterations->setText(QApplication::translate("MainWindow", "50", 0));
        Evaporation_Erosion->setText(QApplication::translate("MainWindow", "Evaporation (in Percent)", 0));
        Erosion_Evaporation->setText(QApplication::translate("MainWindow", "40", 0));
        Erosion_Capacity->setText(QApplication::translate("MainWindow", "5", 0));
        Evaporation_Capacity->setText(QApplication::translate("MainWindow", "Capacity (of Rain)", 0));
        label_4->setText(QApplication::translate("MainWindow", "Rain Amount (per Iteration)", 0));
        Erosion_RainAmount->setText(QApplication::translate("MainWindow", "10", 0));
        ModProcessBox->setItemText(ModProcessBox->indexOf(Erosion_Page), QApplication::translate("MainWindow", "Erosion", 0));
        stonesLabel->setText(QApplication::translate("MainWindow", "Stones", 0));
        Volcanic_Stones->setText(QApplication::translate("MainWindow", "1000", 0));
        stoneSizeMinLabel->setText(QApplication::translate("MainWindow", "Stone Size Min", 0));
        Volcanic_stoneSizeMin->setText(QApplication::translate("MainWindow", "1", 0));
        stoneSizeMaxLabel->setText(QApplication::translate("MainWindow", "Stone Size Max", 0));
        Volcanic_stoneSizeMax->setText(QApplication::translate("MainWindow", "10", 0));
        stabilityLabel->setText(QApplication::translate("MainWindow", "Stability", 0));
        ModProcessBox->setItemText(ModProcessBox->indexOf(page), QApplication::translate("MainWindow", "Volcanic", 0));
        radiusLabel->setText(QApplication::translate("MainWindow", "Factor", 0));
        Stretch_Factor->setText(QApplication::translate("MainWindow", "2", 0));
        ModProcessBox->setItemText(ModProcessBox->indexOf(page_2), QApplication::translate("MainWindow", "Stretch", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Seed (keep empty for random seed)", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Heightmap", 0));
        startButton->setText(QApplication::translate("MainWindow", "Start", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
