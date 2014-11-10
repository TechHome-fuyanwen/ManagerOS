#ifndef MANAGECONTROL_H
#define MANAGECONTROL_H

#include <QWidget>
#include "DataShare.h"

namespace Ui {
class ManageControl;
}

class ManageControl : public QWidget{
    Q_OBJECT

public:
    explicit ManageControl(QWidget *parent = 0);
    ~ManageControl();

private slots:
    void on_pushButton_EntryPersonal_clicked();

    void on_pushButton_query_clicked();

    void on_comboBox_queryType_currentIndexChanged(const QString &arg1);

signals:
    void entryPersonalData();
    void queryPersonalData();

private:
    Ui::ManageControl *ui;

};


#endif // MANAGECONTROL_H
