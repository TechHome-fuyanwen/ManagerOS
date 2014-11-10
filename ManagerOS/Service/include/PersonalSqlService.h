#ifndef PERSONALSQLSERVICE_H
#define PERSONALSQLSERVICE_H
#include <QObject>
#include <QtSql>
#include "DataShare.h"

class PersonalSqlService : public QObject{
    Q_OBJECT
public:
    explicit PersonalSqlService(QObject *parent = 0);
    ~PersonalSqlService();

public:
    QSqlDatabase GetPersonalSqlDB ();

private:
    inline void initPersonalDB();

public slots:
    void onEntryPersonalInfo(st_PersonalInfo);

private:
    QSqlDatabase personalDB;
    bool    bOpenDB;

};

#endif // PERSONALSQLSERVICE_H
