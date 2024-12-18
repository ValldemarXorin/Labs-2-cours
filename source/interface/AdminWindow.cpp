//
// Created by vova3 on 18.12.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AdminWindow.h" resolved

#include "../../headers/interface/AdminWindow.h"
#include "ui_AdminWindow.h"


AdminWindow::AdminWindow(IMoviesRepository& movies_repository, QWidget *parent) : movies_repository(movies_repository),
        QWidget(parent), ui(new Ui::AdminWindow) {
    ui->setupUi(this);

    ui->ErrorAgeLimitAddPage->setVisible(false);
    ui->ErrorDescriptionAddPage->setVisible(false);
    ui->ErrorGenreAddPage->setVisible(false);
    ui->ErrorPosterAddPage->setVisible(false);
    ui->ErrorRatingAddPage->setVisible(false);
    ui->ErrorRuntimeAddPage->setVisible(false);
    ui->ErrorTitleAddPage->setVisible(false);
    ui->ErrorTrailerAddPage->setVisible(false);
    ui->ErrorYearAddPage->setVisible(false);
}

AdminWindow::~AdminWindow() {
    delete ui;
}

void AdminWindow::on_AddMoviePageAddPage_clicked() {
    {
        bool is_continue = true;

        if (ui->titleAddPage->text().isEmpty()) {
            ui->ErrorTitleAddPage->setVisible(true);
            is_continue = false;
        }
        if (ui->descriptionAddPage->text().isEmpty()) {
            ui->ErrorDescriptionAddPage->setVisible(true);
            is_continue = false;
        }
        if (!movies_repository.validate_year(std::stoi(ui->yearAddPage->text().toStdString()))) {
            ui->ErrorYearAddPage->setVisible(true);
            is_continue = false;
        }
        if (!movies_repository.validate_rating(ui->ratingAddPage->text().toStdString())) {
            ui->ErrorRatingAddPage->setVisible(true);
            is_continue = false;
        }
        if (!movies_repository.validate_genre(ui->genreAddPage->text().toStdString())) {
            ui->ErrorGenreAddPage->setVisible(true);
            is_continue = false;
        }
        if (!movies_repository.validate_runtime(ui->runtimeAddPage->text().toStdString())) {
            ui->ErrorRuntimeAddPage->setVisible(true);
            is_continue = false;
        }
        if (!movies_repository.validate_age_limit(ui->ageLimitAddPAge->text().toStdString())) {
            ui->ErrorAgeLimitAddPage->setVisible(true);
            is_continue = false;
        }
        if (!movies_repository.validate_trailer(ui->trailerAddPage->text().toStdString())) {
            ui->ErrorTrailerAddPage->setVisible(true);
            is_continue = false;
        }
        if (!movies_repository.validate_poster(ui->posterAddPage->text().toStdString())) {
            ui->ErrorPosterAddPage->setVisible(true);
            is_continue = false;
        }

        if (is_continue) {


        }

    }
}
