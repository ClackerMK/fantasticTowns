#include "mainwindow.h"
#include "build-fantasticTowns-Desktop-Debug/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->seedEdit->setValidator( new QIntValidator(0, INT32_MAX, this) );
    ui->Erosion_Evaporation->setValidator(new QIntValidator(0, 10, this));
    ui->Erosion_Iterations->setValidator(new QIntValidator(0, INT32_MAX, this));
    ui->Erosion_RainAmount->setValidator(new QIntValidator(0, INT32_MAX, this));
    ui->Erosion_Solubility->setValidator(new QIntValidator(0, INT32_MAX, this));
    ui->Erosion_Capacity->setValidator(new QIntValidator(0, INT32_MAX, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_released()
{

}

void MainWindow::on_pushButton_2_released()
{

}

void MainWindow::on_listWidget_activated(QModelIndex const& index)
{

}

void MainWindow::on_startButton_released()
{
    sf::RenderWindow* wndw = new sf::RenderWindow(sf::VideoMode(800,800,32), "Main SFML Window");


    // Register Manager
    HM_State.setManager(&manager);
    HM_State.setRenderWindow(wndw);

    // Push State
    manager.pushState(&HM_State);

    manager.run();

    delete wndw;
}

