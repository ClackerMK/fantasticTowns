#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

#include "../StateManager.h"
#include "../GenerateHeightMapState.h"

#include "../HeightMapModificationProcess.h"
#include "../HMMP_Erosion.h"
#include "../HMMP_LibNoise.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startButton_released();

    void on_addHMP_pressed();

    void on_deleteHMMP_pressed();

private:
    Ui::MainWindow *ui;

    CStateManager manager;
    CGenerateHeightMapState HM_State;

    std::vector<CHeightmapModificationProcess*> m_processes;
};

#endif // MAINWINDOW_H
