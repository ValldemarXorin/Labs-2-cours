//
// Created by vova3 on 18.12.2024.
//

#ifndef LABS_2_COURS_ADMINWINDOW_H
#define LABS_2_COURS_ADMINWINDOW_H

#include <QWidget>
#include "../repositories/IMoviesRepository.h"
#include "functional"


QT_BEGIN_NAMESPACE
namespace Ui { class AdminWindow; }
QT_END_NAMESPACE

class AdminWindow : public QWidget {
Q_OBJECT

public:
    explicit AdminWindow(IMoviesRepository *movies_repository, QWidget *parent = nullptr);

    ~AdminWindow() override;

    void on_addMoviePageAddPage_clicked();

private:
    Ui::AdminWindow *ui;
    IMoviesRepository* movies_repository;
};


#endif //LABS_2_COURS_ADMINWINDOW_H
