#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    stateOfGame(new QStateMachine),
    start(new QState),
    game(new QState),
    setting(new QState),
    youAreWinner(new QState)
{
    ui->setupUi(this);

    initAllStateAndStartMachine();
    connect(ui->saveSettingBtn, SIGNAL(clicked()), this, SLOT(saveSettings));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initAllStateAndStartMachine(){

    setting->assignProperty(ui->stackedWidget, "currentIndex", SETTING_SCREEN_INDEX);
    setting->addTransition(ui->goStartScreenBtn, SIGNAL(clicked()), start);

    start->assignProperty(ui->stackedWidget, "currentIndex", START_SCREEN_INDEX);
    start->addTransition(ui->newGameBtn, SIGNAL(clicked()), game);
    start->addTransition(ui->settingBtn, SIGNAL(clicked()), setting);


    game->assignProperty(ui->stackedWidget, "currentIndex", GAME_SCREEN_INDEX);
    game->addTransition(ui->exitGameBtn, SIGNAL(clicked()), start);


    stateOfGame->addState(start);
    stateOfGame->addState(game);
    stateOfGame->addState(setting);

    stateOfGame->setInitialState(start);
    stateOfGame->start();
}

void MainWindow::saveSettings(){
    // TODO
    // develop class which keep settings
    // rewrite serting
    qDebug() << "save Settings";
}
