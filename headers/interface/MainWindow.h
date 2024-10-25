//
// Created by vova3 on 20.10.2024.
//

#ifndef LABS_2_COURS_MAINWINDOW_H
#define LABS_2_COURS_MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};


#endif //LABS_2_COURS_MAINWINDOW_H
