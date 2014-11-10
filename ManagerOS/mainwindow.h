#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DataShare.h"

class PersonalSqlService;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onLoginSuccessful();
    void onEntryPersonalData();
    void onQueryModifySql();
    void onBackManageControl();

private:
    void initConntct();
    void setCurrebtWidget(WIDGET_PAGE);
    
private:
    Ui::MainWindow *ui;

    //personal sql store
    PersonalSqlService * pPersonalSqlService;

};

#endif // MAINWINDOW_H
