//
// Created by vova3 on 20.10.2024.
//

#ifndef LABS_2_COURS_MAINWINDOW_H
#define LABS_2_COURS_MAINWINDOW_H

#include "../repositories/IUsersRepository.h"
#include "../repositories/IMoviesRepository.h"
#include <QMainWindow>
#include <QListView>
#include <QStandardItemModel>
#include <QPropertyAnimation>
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(IMoviesRepository* movies, IUserRepository* users,
                        QWidget *parent = nullptr);

    ~MainWindow() override;

private slots:
    void on_MenuButtonAutoselectionMoviePage_clicked();

    void on_MenuListAutoselectionMoviePage_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    IUserRepository* users;
    IMoviesRepository* movies;
    enum {AUTOSELECTION_MOVIE_PAGE_INDEX, SEARCH_PAGE_INDEX,
            LIKED_PAGE_INDEX};
};


#endif //LABS_2_COURS_MAINWINDOW_H
