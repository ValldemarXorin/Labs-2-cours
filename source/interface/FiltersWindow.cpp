//
// Created by vova3 on 28.11.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_FiltersWindow.h" resolved

#include "../../headers/interface/FiltersWindow.h"
#include "ui_FiltersWindow.h"


FiltersWindow::FiltersWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::FiltersWindow) {
    ui->setupUi(this);

    connect(ui->ApplyButton, &QPushButton::clicked,
            this, &FiltersWindow::onApplyButtonClicked);
}

FiltersWindow::~FiltersWindow() {
    delete ui;
}

void FiltersWindow::onApplyButtonClicked() {
    QString genre = ui->GenreFilter->currentText();
    QString age_limit = ui->AgeLimitFilter->currentText();
    QString rating = ui->RatingFilter->currentText();
    QString year = ui->YearFilter->currentText();
    QString runtime = ui->RuntimeYear->currentText();
    this->close();
    emit FiltersWindow::filters_applied(genre, age_limit, rating, year, runtime);
}

