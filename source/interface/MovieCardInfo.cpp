//
// Created by vova3 on 24.11.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MovieCardInfo.h" resolved

#include "../../headers/interface/MovieCardInfo.h"
#include "ui_MovieCardInfo.h"


MovieCardInfo::MovieCardInfo(QWidget *parent) : QWidget(parent), ui(new Ui::MovieCardInfo) {
    ui->setupUi(this);

    ui->LikeButton->setIcon(QIcon("D:/Labs-2-cours/Labs-2-cours/images/InActiveLike.png"));
}

MovieCardInfo::~MovieCardInfo() {
    delete ui;
}

void MovieCardInfo::set_information(QString title, QString genre, QString release_year,
                               QString runtime, QString age_limit, QString description) {
    ui->TitleMovie->setText(title);
    ui->Genre->setText(genre);
    ui->Year->setText(release_year);
    ui->Runtime->setText(runtime);
    ui->AgeLimit->setText(age_limit);
    ui->Description->setText(description);
}
