//
// Created by vova3 on 27.10.2024.
//

#include "../../headers/interface/loginwindow.h"
#include "ui_LoginWindow.h"

LoginWindow::LoginWindow(IMoviesRepository* movies,
                         IUserRepository* users, LikedRepository* liked_movies, QWidget *parent) :
        QWidget(parent), ui(new Ui::LoginWindow), movies_repository(movies), users(users),
        liked_movies(liked_movies) {

    ui->setupUi(this);

    ui->password->setEchoMode(QLineEdit::Password);
    ui->PasswordAdministrator->setEchoMode(QLineEdit::Password);

    ui->support->installEventFilter(this);

    ui->CheckPassword->setIcon(QIcon("D:/Labs-2-cours/Labs-2-cours/images/eye.png"));
    ui->CheckPasswordAdministrator->setIcon(QIcon("D:/Labs-2-cours/Labs-2-cours/images/eye.png"));
}

LoginWindow::~LoginWindow() {
    delete ui;
}

void LoginWindow::on_SingIn_clicked() {

    QString email = ui->email->text();
    QString password = ui->password->text();
    QString password_administrator = ui->PasswordAdministrator->text();

    bool is_administrator;

    try {
        users->email_is_valid(email.toStdString());
        users->password_is_vaild(password.toStdString());
        is_administrator = users->password_administrator_is_valid(password_administrator.toStdString());
    }
    catch (const std::invalid_argument &e) {
        ui->ErrorMessage->setText("Ошибка. Проверьте email и пароли.");
        std::cerr << "Error: " << e.what() << std::endl;
        return;
    }


    password = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());

    try {
        if (is_administrator)
            users->user_exist(email.toStdString(), password.toStdString(), "administrator", users->get_all_users());
        else
            users->user_exist(email.toStdString(), password.toStdString(), "user", users->get_all_users());
    }
    catch (const std::invalid_argument &e) {
        ui->ErrorMessage->setText("Пользователь с данной почтой уже существует.");
        return;
    }

    User* current_user = users->get_user(email.toStdString(), password.toStdString());

    mainWindow = new MainWindow(movies_repository, users, liked_movies, current_user);

    mainWindow->show();

    this->close();
}

void LoginWindow::on_SingUp_clicked() {

    QString email = ui->email->text();
    QString password = ui->password->text();
    QString password_administrator = ui->PasswordAdministrator->text();

    bool is_administrator;

    try {
        users->email_is_valid(email.toStdString());
        users->password_is_vaild(password.toStdString());
        is_administrator = users->password_administrator_is_valid(password_administrator.toStdString());
    }
    catch (const std::invalid_argument &e) {
        ui->ErrorMessage->setText("Ошибка. Проверьте ввод email и паролей.");
        std::cerr << "Error: " << e.what() << std::endl;
        return;
    }

    try {
        users->email_exist(email.toStdString(), users->get_all_users());
    }
    catch (const std::invalid_argument &e) {
        ui->ErrorMessage->setText("Error: This user already exist.");
        return;
    }

    password = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());

    User *current_user;

    if (is_administrator) {
        users->add_user(email.toStdString(), password.toStdString(), "administrator");
        current_user = new User(users->get_all_users()[users->get_all_users().size() - 1].get_id(),
                                      email.toStdString(), password.toStdString(), "administrator");
    }
    else {
        users->add_user(email.toStdString(), password.toStdString(), "user");
        current_user = new User(users->get_all_users()[users->get_all_users().size() - 1].get_id(),
                                email.toStdString(), password.toStdString(), "user");
    }

    mainWindow = new MainWindow(movies_repository, users, liked_movies, current_user);

    mainWindow->show();
    this->close();
}

void LoginWindow::on_CheckPassword_pressed() {
    ui->password->setEchoMode(QLineEdit::Normal);
}

void LoginWindow::on_CheckPassword_released() {
    ui->password->setEchoMode(QLineEdit::Password);
}

void LoginWindow::on_CheckPasswordAdministrator_pressed() {
    ui->PasswordAdministrator->setEchoMode(QLineEdit::Normal);
}

void LoginWindow::on_CheckPasswordAdministrator_released() {
    ui->PasswordAdministrator->setEchoMode(QLineEdit::Password);
}