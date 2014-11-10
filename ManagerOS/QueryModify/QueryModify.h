#ifndef QUERYMODIFY_H
#define QUERYMODIFY_H
#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class QueryModify;
}

class QSqlTableModel;

class QueryModify : public QWidget{
    Q_OBJECT
public:
    explicit QueryModify(QWidget * parent = 0);
    ~QueryModify();

    void initSqlTab(QSqlDatabase &db);

private slots:
    void on_pushButton_backQuery_clicked();

    void on_pushButton_saveModifiy_clicked();

    void on_pushButton_cancelModify_clicked();

signals:
    void backQueryModifyPage();

private:
    Ui::QueryModify *ui;

    QSqlTableModel *sqlModel;
};

#endif // QUERYMODIFY_H
