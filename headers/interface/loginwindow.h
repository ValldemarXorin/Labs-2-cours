//
// Created by vova3 on 27.10.2024.
//

#ifndef LABS_2_COURS_LOGINWINDOW_H
#define LABS_2_COURS_LOGINWINDOW_H

#include "MainWindow.h"
#include "../repositories/IUsersRepository.h"
#include "../repositories/IMoviesRepository.h"
#include "../TopParser.h"
#include <QWidget>
#include <QLineEdit>
#include <QToolButton>
#include <QIcon>
#include <QLabel>
#include <QString>
#include <QCryptographicHash>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QWidget {
Q_OBJECT

public:
    explicit LoginWindow( IMoviesRepository* movies_repository,
                          IUserRepository* users, LikedRepository* liked_movies, QWidget *parent = nullptr);

    ~LoginWindow() override;

private slots:
    void on_SingIn_clicked();

    void on_SingUp_clicked();

    void on_CheckPassword_pressed();

    void on_CheckPassword_released();

private:
    Ui::LoginWindow *ui;
    MainWindow *mainWindow;
    IUserRepository *users;
    IMoviesRepository *movies_repository;
    LikedRepository* liked_movies;
    TopParser* parser;
};


#endif //LABS_2_COURS_LOGINWINDOW_H
