#ifndef ENTRYPERSONAL_H
#define ENTRYPERSONAL_H

#include <QWidget>
#include "DataShare.h"

namespace Ui {
class EntryPersonal;
}

class EntryPersonal : public QWidget{
    Q_OBJECT

public:
    explicit EntryPersonal(QWidget *parent = 0);
    ~EntryPersonal();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_entry_clicked();

signals:
    void backEntryPersonalPage();
    void entryPersonalInfo2Sql(st_PersonalInfo);


private:
    Ui::EntryPersonal *ui;

};
#endif // ENTRYPERSONAL_H
