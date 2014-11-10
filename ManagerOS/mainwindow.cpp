#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "PersonalSqlService.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Manager OS");
    setCurrebtWidget(PAGE_MANAGECONTROL);
    pPersonalSqlService = new PersonalSqlService();
    ui->QueryModifyPage->initSqlTab(pPersonalSqlService->GetPersonalSqlDB());
    initConntct();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLoginSuccessful(){
    setCurrebtWidget(PAGE_MANAGECONTROL);
}
void MainWindow::onEntryPersonalData(){
    setCurrebtWidget(PAGE_ENTRYPERSONAL);
}
void MainWindow::onQueryModifySql(){
    setCurrebtWidget(PAGE_QUERYMODIFY);
}
void MainWindow::onBackManageControl(){
    setCurrebtWidget(PAGE_MANAGECONTROL);
}

void MainWindow::initConntct()
{
    connect(ui->LoginPage,SIGNAL(loginSuccessful()),
            SLOT(onLoginSuccessful()));

    connect(ui->ManageControlPage,SIGNAL(entryPersonalData()),
            SLOT(onEntryPersonalData()));

    connect(ui->ManageControlPage,SIGNAL(queryPersonalData()),
            SLOT(onQueryModifySql()));

    connect(ui->EntryPersonalPage,SIGNAL(backEntryPersonalPage()),
            SLOT(onBackManageControl()));

    connect(ui->QueryModifyPage,SIGNAL(backQueryModifyPage()),
            SLOT(onBackManageControl()));

    connect(ui->EntryPersonalPage,SIGNAL(entryPersonalInfo2Sql(st_PersonalInfo)),
            pPersonalSqlService,SLOT(onEntryPersonalInfo(st_PersonalInfo)));

}

void MainWindow::setCurrebtWidget(WIDGET_PAGE page){
    switch(page){
    case PAGE_LOGIN: {
        ui->stackedWidget->setCurrentWidget(ui->LoginPage);
        break;
    }
    case PAGE_MANAGECONTROL: {
        ui->stackedWidget->setCurrentWidget(ui->ManageControlPage);
        break;
    }
    case PAGE_ENTRYPERSONAL: {
        ui->stackedWidget->setCurrentWidget(ui->EntryPersonalPage);
        break;
    }
    case PAGE_QUERYMODIFY: {
        ui->stackedWidget->setCurrentWidget(ui->QueryModifyPage);
        break;
    }
    }
}
