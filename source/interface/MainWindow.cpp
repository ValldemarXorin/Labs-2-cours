//
// Created by vova3 on 20.10.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainwindow.h" resolved

#include "../../headers/interface/MainWindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(IMoviesRepository* movies, IUserRepository* users,
                       QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow), movies(movies), users(users) {
    ui->setupUi(this);

    ui->PageSwitcher->setCurrentIndex(AUTOSELECTION_MOVIE_PAGE_INDEX);
    ui->MenuListAutoselectionMoviePage->setFixedWidth(0);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_MenuButtonAutoselectionMoviePage_clicked() {
    if (ui->MenuListAutoselectionMoviePage->maximumWidth() == 0) {
        ui->MenuListAutoselectionMoviePage->setFixedWidth(118);
    }
    else
        ui->MenuListAutoselectionMoviePage->setFixedWidth(0);
    ui->MenuButtonAutoselectionMoviePage->setVisible(false);
}

void MainWindow::on_MenuListAutoselectionMoviePage_itemClicked(QListWidgetItem *item) {
    if (item->text() == "Back") {
        ui->MenuListAutoselectionMoviePage->setFixedWidth(0);
        ui->MenuButtonAutoselectionMoviePage->setVisible(true);
        return;
    }

    if (item->text() == "Search") {
        ui->PageSwitcher->setCurrentIndex(SEARCH_PAGE_INDEX);
        ui->MenuButtonSearchPage->setVisible(false);
        ui->MenuButtonSearchPage->setVisible(true);
        return;
    }
}