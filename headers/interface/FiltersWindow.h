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

public slots:
    void onApplyButtonClicked();

    void closeEvent(QCloseEvent *event) override;

    signals:
    void filters_applied(const QString& genre, const QString& age_limit, const QString& rating,
                         const QString& year, const QString& runtime);

    void filters_window_close();

private:
    Ui::FiltersWindow *ui;
};


#endif //LABS_2_COURS_FILTERSWINDOW_H
