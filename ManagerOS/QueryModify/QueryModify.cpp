#include "QueryModify.h"
#include "ui_QueryModify.h"
#include <QSqlTableModel>

QueryModify::QueryModify(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QueryModify)
{
    ui->setupUi(this);
}

QueryModify::~QueryModify()
{
    delete ui;
}

void QueryModify::initSqlTab(QSqlDatabase &db){
    sqlModel = new QSqlTableModel(this,db);
    sqlModel->setTable("PERSONALINFO");
    sqlModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
}

void QueryModify::on_pushButton_backQuery_clicked()
{
    emit backQueryModifyPage();
}

void QueryModify::on_pushButton_saveModifiy_clicked()
{
    sqlModel->select();
    ui->tableView->setModel(sqlModel);
}

void QueryModify::on_pushButton_cancelModify_clicked()
{

}
