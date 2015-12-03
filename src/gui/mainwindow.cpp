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
    switch (ui->ModProcessBox->currentIndex()){
    case 0:{
        HMMP_Erosion* erosion = new HMMP_Erosion();
        erosion->setCapacity(ui->Erosion_Capacity->text().toInt());
        erosion->setEvaporation(static_cast<double>(ui->Erosion_Evaporation->text().toInt()) / 100.0);
        erosion->setIterations(ui->Erosion_Iterations->text().toInt());
        erosion->setRainAmount(ui->Erosion_RainAmount->text().toInt());
        erosion->setSolubility(ui->Erosion_Solubility->text().toInt());

        ui->listHMMP->addItem("Erosion");
        m_processes.push_back(erosion);
        break;
    }
     case 1:{
        HMMP_LibNoise* perlin = new HMMP_LibNoise();
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
        m_processes.push_back(perlin);

        break;
    }
    }
}

void MainWindow::on_deleteHMMP_pressed()
{

}
