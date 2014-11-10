#ifndef DATASHARE_H
#define DATASHARE_H
#include <QDebug>

#define DBG(X) qDebug()<<X;

typedef struct PersonalInfo{
    QString name;
    QString addr;
    QString sex;
    QString mobilePhone;
    QString landline;
    QString entryTime;
    QString jobStatus;
    int     age;

    PersonalInfo(){
        name = addr = sex = mobilePhone = landline = entryTime = "";
        age = 0;
    }
    PersonalInfo(   QString f_name,
                    QString f_addr,
                    QString f_sex,
                    QString f_mobilePhone,
                    QString f_landline,
                    QString f_entryTime,
                    QString f_jobStatus,
                    int     f_age)
        :
        name(f_name),
        addr(f_addr),
        sex(f_sex),
        mobilePhone(f_mobilePhone),
        landline(f_landline),
        entryTime(f_entryTime),
        jobStatus(f_jobStatus),
        age(f_age)
    {}

}st_PersonalInfo;

enum WIDGET_PAGE{
    PAGE_LOGIN,
    PAGE_MANAGECONTROL,
    PAGE_ENTRYPERSONAL,
    PAGE_QUERYMODIFY,

    WIDGET_PAGE_Max
};

enum QUERY_TYPE{
    QUERY_BY_ALL,
    QUERY_BY_NAME,
    QUERY_BY_MOBILEPHONE,
    QUERY_BY_ENTRYTIME,
    QUERY_BY_SEX,
    QUERY_BY_LANDLINE,
    QUERY_BY_JOBSTATUS,
};

#endif // DATASHARE_H
