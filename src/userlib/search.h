#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "ui_search.h"

namespace Ui {
class searchDialog;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = nullptr, const int salesFindComboBoxIndex = 0);
    ~Search();

    QString searchString;
    QString valueToSend;
    int salesFindOption;

    QSqlQuery queryForModel;
    QSqlQueryModel *queryModel;
    QString queryString;

private:
    Ui::searchDialog *ui;

public slots:
    void doSearch();
    void sendAndClose();
};

#endif // SEARCH_H
