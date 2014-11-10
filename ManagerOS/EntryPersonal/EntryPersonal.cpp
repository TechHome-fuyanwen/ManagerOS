#include "EntryPersonal.h"
#include "ui_EntryPersonal.h"
#include <QMessageBox>


EntryPersonal::EntryPersonal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EntryPersonal)
{
    ui->setupUi(this);
    ui->comboBox_sex->addItem("Man");
    ui->comboBox_sex->addItem("Woman");
    QStringList jobStatus;
    jobStatus<<"Not Working"<<"Working";
    ui->comboBox_jobStatus->addItems(jobStatus);
}

EntryPersonal::~EntryPersonal()
{
    delete ui;
}


void EntryPersonal::on_pushButton_back_clicked()
{
    emit backEntryPersonalPage();
}

void EntryPersonal::on_pushButton_entry_clicked()
{
    if(ui->lineEdit_name->text().isEmpty()){
        QMessageBox::warning(this,"Prompt","the name can't empty,please check it!!!",QMessageBox::Ok);
        return;
    }
    if(ui->lineEdit_mobilePhone->text().isEmpty()){
        QMessageBox::warning(this,"Prompt","the mobilePhone can't empty,please check it!!!",QMessageBox::Ok);
        return;
    }
    st_PersonalInfo personalInfo(ui->lineEdit_name->text(),
                                 ui->lineEdit_addr->text(),
                                 ui->comboBox_sex->currentText(),
                                 ui->lineEdit_mobilePhone->text(),
                                 ui->lineEdit_landline->text(),
                                 ui->lineEdit_EntryTime->text(),
                                 ui->comboBox_jobStatus->currentText(),
                                 ui->lineEdit_age->text().toInt()
                                 );
    emit entryPersonalInfo2Sql(personalInfo);
}
