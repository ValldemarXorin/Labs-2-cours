//
// Created by vova3 on 22.12.2024.
//

#ifndef LABS_2_COURS_FILTERSWINDOWSEARCH_H
#define LABS_2_COURS_FILTERSWINDOWSEARCH_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class FiltersWindowSearch; }
QT_END_NAMESPACE

class FiltersWindowSearch : public QWidget {
Q_OBJECT

public:
    explicit FiltersWindowSearch(QWidget *parent = nullptr);

    ~FiltersWindowSearch() override;

public slots:
    void onApplyButtonClicked();

    void closeEvent(QCloseEvent *event) override;

signals:
    void filters_applied(const QString& genre, const QString& age_limit, const QString& rating,
                         const QString& year, const QString& runtime);

    void filters_window_close();

private:
    Ui::FiltersWindowSearch *ui;
};


#endif //LABS_2_COURS_FILTERSWINDOWSEARCH_H
