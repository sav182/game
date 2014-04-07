#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define GAME_SCREEN_INDEX 1
#define START_SCREEN_INDEX 0
#define SETTING_SCREEN_INDEX 2

#include <QMainWindow>
#include <QStateMachine>
#include <QState>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void makeTransition();


signals:
    void openWindow(QString key);

private:
    Ui::MainWindow *ui;
    QStateMachine *stateOfGame;
    QState *start;
    QState *game;
    QState *setting;
    QState *youAreWinner;
    void initAllStateAndStartMachine();
};

#endif // MAINWINDOW_H
