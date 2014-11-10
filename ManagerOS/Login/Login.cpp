#include "Login.h"
#include "ui_Login.h"

#include <QMessageBox>

Login::Login(QWidget *parent) :
    QWidget(parent),
    qsUserName(""),
    qsPassword(""),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowTitle("Login");
    ui->lineEdit_UserName->setText(qsUserName);
    ui->lineEdit_Password->setText(qsPassword);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushbotton_Login_clicked()
{
    if(qsUserName.isEmpty()){
        QMessageBox::warning(this,"Prompt","The user name can't empty",QMessageBox::Ok);
        return;
    }
    if(qsPassword.isEmpty()){
        QMessageBox::warning(this,"Prompt","The Password can't empty",QMessageBox::Ok);
        return;
    }
    if(qsUserName != "fuhaitao" || qsPassword != "19880928"){
        QMessageBox::warning(this,"Prompt","The user name or password is invaild!",QMessageBox::Ok);
        return;
    }
    emit loginSuccessful();
}

void Login::on_pushbotton_Register_clicked()
{

}

void Login::on_lineEdit_UserName_textChanged(const QString &arg1)
{
    qsUserName = arg1;
}

void Login::on_lineEdit_Password_textChanged(const QString &arg1)
{
    qsPassword = arg1;
}
