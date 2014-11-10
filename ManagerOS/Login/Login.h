#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

public:

private:

private slots:
    void on_pushbotton_Login_clicked();

    void on_pushbotton_Register_clicked();

    void on_lineEdit_UserName_textChanged(const QString &arg1);

    void on_lineEdit_Password_textChanged(const QString &arg1);

signals:
    void loginSuccessful();

private:
    QString qsUserName;
    QString qsPassword;

private:
    Ui::Login *ui;

};

#endif // LOGIN_H
