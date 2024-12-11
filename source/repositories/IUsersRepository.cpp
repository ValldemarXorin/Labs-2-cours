//
// Created by vova3 on 30.10.2024.
//

#include "../../headers/repositories/IUsersRepository.h"

IUserRepository::IUserRepository() : user_db_manager(new UsersDBManager) {
    users = user_db_manager->load_data_from_DB();
}

IUserRepository::~IUserRepository() {
    user_db_manager->save_data_to_DB(users);
}

void IUserRepository::add_user(const std::string &new_email, const std::string &new_password,
                               const std::string &new_role) {
    users.emplace_back(User(users[users.size() - 1].get_id() + 1, new_email, new_password, new_role));
}

void IUserRepository::delete_user(const std::string &email, const std::string &password,
                                  const std::string &role) {
    for (int i = 0; i < users.size(); ++i) {
        if (users[i].get_email() == email && users[i].get_password() == password &&
            users[i].get_role() == role) {
            users.erase(users.begin() + i);
            return;
        }
    }
    std::cout << "This user doesn't exist.";
}

bool IUserRepository::user_exist(const std::string& email, const std::string& password, const std::string& role) const {
    for (const User& user: users) {
        if (user.get_email() == email && user.get_password() == password &&
            user.get_role() == role)
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

User* IUserRepository::get_user(std::string email, std::string password) {
    for (auto &user: users) {
        if (user.get_email() == email && user.get_password() == password)
            return &user;
    }
}

std::vector<User> IUserRepository::get_all_users() {
    return users;
}