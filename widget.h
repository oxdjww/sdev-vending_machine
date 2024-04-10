#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    int balance;
    int coffee_price;
    int tea_price;
    int milk_price;
    ~Widget();

private slots:
    void on_pb_50_clicked();

    void on_pb_10_clicked();

    void on_pb_coffee_clicked();

    void on_pb_500_clicked();

    void on_pb_100_clicked();

    void on_pb_tea_clicked();

    void on_pb_milk_clicked();

    void on_pb_reset_clicked();

    void update_balance(int);

    void update_button_status(QPushButton*, int);

    void return_balance(int, int*, int*, int*, int*);




private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
