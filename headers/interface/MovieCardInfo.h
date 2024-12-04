//
// Created by vova3 on 24.11.2024.
//

#ifndef LABS_2_COURS_MOVIECARDINFO_H
#define LABS_2_COURS_MOVIECARDINFO_H

#include <QWidget>
#include "../models/Movie.h"
#include "../MyStack.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MovieCardInfo; }
QT_END_NAMESPACE

class MovieCardInfo : public QWidget {
Q_OBJECT

public:
    explicit MovieCardInfo(QWidget *parent = nullptr);

    ~MovieCardInfo() override;

    void SetIconLikeButton();

    void set_information(QString title, QString genre, QString rating, QString release_year, QString runtime,
                         QString age_limit, QString description);

private:
    Ui::MovieCardInfo *ui;
};


#endif //LABS_2_COURS_MOVIECARDINFO_H
