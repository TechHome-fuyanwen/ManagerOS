#include "PersonalSqlService.h"

PersonalSqlService::PersonalSqlService(QObject *parent) :
    QObject(parent)
{
    initPersonalDB();
}

PersonalSqlService::~PersonalSqlService()
{
    if(bOpenDB)
        personalDB.close();
}

QSqlDatabase PersonalSqlService::GetPersonalSqlDB (){
    return personalDB;
}

void PersonalSqlService::initPersonalDB()
{
    QSqlDatabase personalDB = QSqlDatabase::addDatabase("QSQLITE");
    personalDB.setDatabaseName("./test.db");
    bOpenDB = personalDB.open();
    if(bOpenDB){
        DBG("OPEN DB SUCCESSFUL");
    }
    else{
        DBG(personalDB.lastError().text());
        return;
    }
    QSqlQuery query;
    QString state = "CREATE TABLE IF NOT EXISTS PERSONALINFO (          \
            Name VARCHAR,        \
            MobilePhone VARCHAR, \
            Landline VARCHAR,    \
            Addr VARCHAR,   \
            Sex VARCHAR,     \
            EntryTime VARCHAR,  \
            JobStatus VARCHAR,    \
            Age int             \
            )";
    if (query.exec(state) == false)
    {
        bOpenDB = false;
        personalDB.close();
        DBG("Create table fail");
        return;
    }
}

void PersonalSqlService::onEntryPersonalInfo(st_PersonalInfo personalInfo)
{
    if(!bOpenDB)        return;
    QSqlQuery query;
    query.prepare("INSERT INTO PERSONALINFO (Name, MobilePhone,Landline,Addr,Sex,EntryTime,JobStatus,Age) "
                  "VALUES (:Name, :MobilePhone, :Landline, :Addr, :Sex, :EntryTime, :JobStatus, :Age)");
    query.bindValue(":Name", personalInfo.name);
    query.bindValue(":MobilePhone", personalInfo.mobilePhone);
    query.bindValue(":Landline", personalInfo.landline);
    query.bindValue(":Addr", personalInfo.addr);
    query.bindValue(":Sex", personalInfo.sex);
    query.bindValue(":EntryTime", personalInfo.entryTime);
    query.bindValue(":JobStatus", personalInfo.jobStatus);
    query.bindValue(":Age", personalInfo.age);
    query.exec();
}
