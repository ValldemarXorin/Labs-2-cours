//
// Created by vova3 on 22.12.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_FiltersWindowSearch.h" resolved

#include "../../headers/interface/FiltersWindowSearch.h"
#include "ui_FiltersWindowSearch.h"


FiltersWindowSearch::FiltersWindowSearch(QWidget *parent) :
        QWidget(parent), ui(new Ui::FiltersWindowSearch) {
    ui->setupUi(this);

    connect(ui->ApplyButton, &QPushButton::clicked,
            this, &FiltersWindowSearch::onApplyButtonClicked);
}

FiltersWindowSearch::~FiltersWindowSearch() {
    delete ui;
}

void FiltersWindowSearch::onApplyButtonClicked() {
    QString genre = ui->GenreFilter->currentText();
    QString age_limit = ui->AgeLimitFilter->currentText();
    QString rating = ui->RatingFilter->currentText();
    QString year = ui->YearFilter->currentText();
    QString runtime = ui->RuntimeYear->currentText();
    this->close();
    emit FiltersWindowSearch::filters_applied(genre, age_limit, rating, year, runtime);
}

void FiltersWindowSearch::closeEvent(QCloseEvent *event) {
    emit filters_window_close();
}
