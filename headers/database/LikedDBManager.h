//
// Created by vova3 on 22.11.2024.
//

#ifndef LABS_2_COURS_LIKEDDBMANAGER_H
#define LABS_2_COURS_LIKEDDBMANAGER_H
#include "DBManager.h"
#include "Database.h"
#include "../models/LikedMovie.h"

class LikedDBManager : public DBManager<LikedMovie> {
public:

    LikedDBManager() = default;

    ~LikedDBManager() override = default;

    void create_table() override;

    std::vector<LikedMovie> load_data_from_DB() override;

    void save_data_to_DB(std::vector<LikedMovie> liked_movies) override;

};
#endif //LABS_2_COURS_LIKEDDBMANAGER_H
