//
// Created by vova3 on 28.11.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_FiltersWindow.h" resolved

#include "../../headers/interface/FiltersWindow.h"
#include "ui_FiltersWindow.h"


FiltersWindow::FiltersWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::FiltersWindow) {
    ui->setupUi(this);
}

FiltersWindow::~FiltersWindow() {
    delete ui;
}
