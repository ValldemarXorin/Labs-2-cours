//
// Created by vova3 on 28.11.2024.
//

#ifndef LABS_2_COURS_FILTERSWINDOW_H
#define LABS_2_COURS_FILTERSWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class FiltersWindow; }
QT_END_NAMESPACE

class FiltersWindow : public QWidget {
Q_OBJECT

public:
    explicit FiltersWindow(QWidget *parent = nullptr);

    ~FiltersWindow() override;

private:
    Ui::FiltersWindow *ui;
};


#endif //LABS_2_COURS_FILTERSWINDOW_H
