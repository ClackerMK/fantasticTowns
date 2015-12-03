#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <SFML/Graphics.hpp>
#include <map>

#include "../StateManager.h"
#include "../GenerateHeightMapState.h"
#include "../HeightMapModificationProcess.h"

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
    void on_pushButton_released();

    void on_pushButton_2_released();

    void on_startButton_released();

    void on_listWidget_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

    CStateManager manager;
    CGenerateHeightMapState HM_State;

    std::map<int, std::pair<HMMP_ID, CHeightmapModificationProcess*>> m_processes;
};

#endif // MAINWINDOW_H
