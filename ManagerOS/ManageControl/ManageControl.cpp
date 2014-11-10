#include "ManageControl.h"
#include "ui_ManageControl.h"

ManageControl::ManageControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManageControl)
{
    ui->setupUi(this);
    QStringList queryType;
    queryType<<"All"<<"Name"<<"MobilePhone"<<"EntryTime"<<"Sex"<<"Landline"<<"JobStatus";
    ui->comboBox_queryType->addItems(queryType);
}

ManageControl::~ManageControl()
{
    delete ui;
}

void ManageControl::on_pushButton_EntryPersonal_clicked()
{
    emit entryPersonalData();
}

void ManageControl::on_pushButton_query_clicked()
{
    emit queryPersonalData();
}

void ManageControl::on_comboBox_queryType_currentIndexChanged(const QString &arg1)
{
    DBG(arg1);
}
