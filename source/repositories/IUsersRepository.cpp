//
// Created by vova3 on 30.10.2024.
//

#include "../../headers/repositories/IUsersRepository.h"

IUserRepository::IUserRepository(const std::string &db_name) : UsersDBManager(db_name) {
    users = UsersDBManager::load_data_from_DB();
}

IUserRepository::~IUserRepository() {
    UsersDBManager::save_data_to_DB(users);
}

void IUserRepository::add_user(const std::string &new_email, const std::string &new_password,
                               const std::string &new_role) {
    users.emplace_back(User(new_email, new_password, new_role));
}

void IUserRepository::delete_user(const std::string &email, const std::string &password,
                                  const std::string &role) {
    User user_to_del(email, password, role);
    for (int i = 0; i < users.size(); ++i) {
        if (users[i] == user_to_del) {
            users.erase(users.begin() + i);
            return;
        }
    }
    std::cout << "This user doesn't exist.";
}

bool IUserRepository::user_exist(const std::string& email, const std::string& password, const std::string& role) const {
    User check_user(email, password, role);
    for (const User& user: users) {
        if (user == check_user)
            return true;
    }
    return false;
}

bool IUserRepository::email_exist(const std::string &email) {
    for (const User& user: users) {
        if (user.get_email() == email)
            return true;
    }
    return false;
}