#include "mainwindow.h"
#include "build-fantasticTowns-Desktop-Debug/ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->seedEdit->setValidator( new QIntValidator(0, INT32_MAX, this) );

    ui->Erosion_Evaporation->setValidator(new QIntValidator(0, 100, this));
    ui->Erosion_Iterations->setValidator(new QIntValidator(0, INT32_MAX, this));
    ui->Erosion_RainAmount->setValidator(new QIntValidator(0, INT32_MAX, this));
    ui->Erosion_Solubility->setValidator(new QIntValidator(0, INT32_MAX, this));
    ui->Erosion_Capacity->setValidator(new QIntValidator(0, INT32_MAX, this));

    ui->PN_amplitude->setValidator(new QDoubleValidator(1.0, 1000.0, 4, this));
    ui->PN_octaveCount->setValidator(new QIntValidator(1, 30, this));
    ui->PN_steps->setValidator(new QDoubleValidator(0.005, 0.2,4, this));
    ui->PN_lacunarity->setValidator(new QDoubleValidator(1.0, 4.0,4, this));
    ui->PN_persistence->setValidator(new QDoubleValidator(0.01, 1.0,4, this));

    ui->Volcanic_Stones->setValidator(new QIntValidator(0, INT32_MAX, this));
    ui->Volcanic_stoneSizeMax->setValidator(new QIntValidator(0, INT32_MAX, this));
    ui->Volcanic_stoneSizeMin->setValidator(new QIntValidator(0, INT32_MAX, this));

    ui->Stretch_Factor->setValidator(new QIntValidator(0, INT32_MAX, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_released()
{
    sf::RenderWindow* wndw = new sf::RenderWindow(sf::VideoMode(800,800,32), "Main SFML Window");


    // Register Manager
    HM_State.setManager(&manager);
    HM_State.setRenderWindow(wndw);

    // Add Modification Processes
    for (auto p : m_processes)
    {
        HM_State.getMapGenerator()->pushProcess(p);
    }

    if (ui->seedEdit->text() != "")
        HM_State.setSeed(ui->seedEdit->text().toInt());
    else
        HM_State.setSeed(std::random_device()());

    HM_State.setSize(ui->size_x->text().toInt(), ui->size_y->text().toInt());

    // Push State
    manager.pushState(&HM_State);

    manager.run();

    delete wndw;
}


void MainWindow::on_addHMP_pressed()
{

    CHeightmapModificationProcess* hmmp;

    switch (ui->ModProcessBox->currentIndex()){
         case 0:{
            hmmp = new HMMP_LibNoise();
            HMMP_LibNoise* perlin = dynamic_cast<HMMP_LibNoise*>(hmmp);

            perlin->setAmplitude(ui->PN_amplitude->text().toDouble());
            perlin->setLacunarity(ui->PN_lacunarity->text().toDouble());
            switch (ui->PN_quality->currentIndex()) {
            case 0:{
                perlin->setNoiseQuality(noise::QUALITY_STD);
                break;
            }
            case 1:
            {
                perlin->setNoiseQuality(noise::QUALITY_FAST);
                break;
            }
            case 2:
            {
                perlin->setNoiseQuality(noise::QUALITY_BEST);
                break;
            }
            }
            perlin->setOctaveCount(ui->PN_octaveCount->text().toInt());
            perlin->setPersistence(ui->PN_persistence->text().toDouble());
            perlin->setStep(ui->PN_steps->text().toDouble());

            ui->listHMMP->addItem("Perlin Noise");

            break;
        }
        case 1:{
            hmmp = new HMMP_Erosion();
            HMMP_Erosion* erosion = dynamic_cast<HMMP_Erosion*>(hmmp);

            erosion->setCapacity(ui->Erosion_Capacity->text().toInt());
            erosion->setEvaporation(static_cast<double>(ui->Erosion_Evaporation->text().toInt()) / 100.0);
            erosion->setIterations(ui->Erosion_Iterations->text().toInt());
            erosion->setRainAmount(ui->Erosion_RainAmount->text().toInt());
            erosion->setSolubility(ui->Erosion_Solubility->text().toInt());

            ui->listHMMP->addItem("Erosion");

            break;
        }
        case 2:
        {
            hmmp = new HMMP_Volcanic();
            HMMP_Volcanic* volc = dynamic_cast<HMMP_Volcanic*>(hmmp);

            volc->setStones(ui->Volcanic_Stones->text().toInt());
            volc->setMinStoneSize(ui->Volcanic_stoneSizeMin->text().toInt());
            volc->setMaxStoneSize(ui->Volcanic_stoneSizeMax->text().toInt());
            volc->setStability(ui->Volcanic_stability->value());

            ui->listHMMP->addItem("Volcanic");

            break;
        }
        case 3:
        {
            hmmp = new HMMP_SmoothStretch();
            HMMP_SmoothStretch* stretch = dynamic_cast<HMMP_SmoothStretch*>(hmmp);

            stretch->setFactor(ui->Stretch_Factor->text().toInt());

            ui->listHMMP->addItem("Stretch");

            break;
        }
    }



    m_processes.push_back(hmmp);
}

void MainWindow::on_deleteHMMP_pressed()
{

}
