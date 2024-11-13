//
// Created by vova3 on 27.10.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_LoginWindow.h" resolved

#include <QToolTip>
#include "../../headers/interface/loginwindow.h"
#include "ui_LoginWindow.h"
#include <QDebug>
#include "../../headers/auth_models/User.h"


LoginWindow::LoginWindow(IMoviesRepository* movies,
                         IUserRepository* users, QWidget *parent) :
        QWidget(parent), ui(new Ui::LoginWindow), movies(movies), users(users) {

    ui->setupUi(this);

    ui->password->setEchoMode(QLineEdit::Password);

    ui->support->installEventFilter(this);

    ui->CheckPassword->setIcon(QIcon("D:/Labs-2-cours/Labs-2-cours/images/eye.png"));

    mainWindow = new MainWindow(movies, users);
}

LoginWindow::~LoginWindow() {
    delete ui;
}

void LoginWindow::on_SingIn_clicked() {
    QString email = ui->email->text();
    QString password = ui->password->text();

    if (!users->email_is_valid(email.toStdString()) ||
        !users->password_is_vaild(password.toStdString())) {
        ui->ErrorMessage->setText("Error: check email and password.");
        return;
    }
    password = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
    if (!users->user_exist(email.toStdString(), password.toStdString(), "user")) {
        ui->ErrorMessage->setText("Error: This user does not exist.");
        return;
    }
    mainWindow->show();
    this->close();
}

void LoginWindow::on_SingUp_clicked() {

    QString email = ui->email->text();
    QString password = ui->password->text();

    if (!users->email_is_valid(email.toStdString()) ||
        !users->password_is_vaild(password.toStdString())) {
        ui->ErrorMessage->setText("Error: check email and password.");
        return;
    }

    if(users->email_exist(email.toStdString())) {
        ui->ErrorMessage->setText("Error: This user already exist.");
        return;
    }

    password = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
    users->add_user(email.toStdString(), password.toStdString(), "user");
    mainWindow->show();
    this->close();
}

void LoginWindow::on_CheckPassword_pressed() {
    ui->password->setEchoMode(QLineEdit::Normal);
}

void LoginWindow::on_CheckPassword_released() {
    ui->password->setEchoMode(QLineEdit::Password);
}