//
// Created by vova3 on 28.10.2024.
//
#include "../../headers/auth_models/User.h"

User::User(int id, std::string_view email, std::string_view password, std::string_view role)
        : email(email), password(password), role(role), id(id) {};

int User::get_id() const { return id; }

std::string User::get_email() const { return email; }

std::string User::get_password() const { return password; }

std::string User::get_role() const { return role; }

void User::set_email(std::string& new_email) {
    email = new_email;
}

void User::set_password(std::string& new_password) {
    password = new_password;
}

void User::set_role(std::string_view new_role) { role = new_role; }

bool User::operator==(const User& other) const {
    return this->get_email() == other.get_email() && this->get_id() == other.get_id() &&
    this->get_password() == other.get_password() && this->get_role() == other.get_role();
}