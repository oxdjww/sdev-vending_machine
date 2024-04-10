#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    this->balance = 0;
    this->coffee_price = 100;
    this->tea_price = 150;
    this->milk_price = 200;

    ui->setupUi(this);
    ui->pb_coffee->setDisabled(true);
    ui->pb_tea->setDisabled(true);
    ui->pb_milk->setDisabled(true);

    ui->pb_coffee->setStyleSheet("background-color: red");
    ui->pb_tea->setStyleSheet("background-color: red");
    ui->pb_milk->setStyleSheet("background-color: red");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::update_button_status(QPushButton *pb, int value)
{
    if (this->balance>=value)
    {
        pb->setEnabled(true);
        pb->setStyleSheet("background-color: blue");
    }
    else
    {
        pb->setDisabled(true);
        pb->setStyleSheet("background-color: red");
    }
}

void Widget::update_balance(int amount)
{
    this->balance += amount;
    update_button_status(this->ui->pb_coffee, this->coffee_price);
    update_button_status(this->ui->pb_tea, this->tea_price);
    update_button_status(this->ui->pb_milk, this->milk_price);

    ui->lcdNumber->display(this->balance);
}

void Widget::on_pb_10_clicked()
{
    update_balance(10);
}

void Widget::on_pb_50_clicked()
{
    update_balance(50);
}

void Widget::on_pb_100_clicked()
{
    update_balance(100);
}

void Widget::on_pb_500_clicked()
{
    update_balance(500);
}

void Widget::on_pb_coffee_clicked()
{
    update_balance(-100);
}


void Widget::on_pb_tea_clicked()
{
    update_balance(-150);
}


void Widget::on_pb_milk_clicked()
{
    update_balance(-200);
}

void Widget::return_balance(int balance, int *coin_500, int *coin_100, int *coin_50, int *coin_10) {
    *coin_500 = balance / 500;
    balance %= 500;

    *coin_100 = balance / 100;
    balance %= 100;

    *coin_50 = balance / 50;
    balance %= 50;

    *coin_10 = balance / 10;
}

void Widget::on_pb_reset_clicked()
{
    int coin_500, coin_100, coin_50, coin_10;
    return_balance(balance, &coin_500, &coin_100, &coin_50, &coin_10);

    QString balance_format = QString("500won coin : %1\n"
                                    "100won coin : %2\n"
                                    "50won coin  : %3\n"
                                    "10won coin  : %4\n")
                                .arg(coin_500).arg(coin_100).arg(coin_50).arg(coin_10);

    QMessageBox::information(nullptr, "Exchange state", balance_format);

    update_balance(-(this->balance));
    ui->lcdNumber->display(balance);
}


