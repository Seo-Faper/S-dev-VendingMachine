#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<int, QString> menu;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->pbCoffe->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
    ui->pbReset->setEnabled(false);
    menu[100] = "커피";
    menu[150] = "차";
    menu[200] = "우유";
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::changeMoney(int diff){
    if (money + diff < 0){
        return;
    }
    money +=diff;
    if(diff < 0) mb.information(this,"자판기",menu[-diff]+"를 구매하였습니다.");

    ui->lcdNumber->display(money);

    if(money > 0) ui->pbReset->setEnabled(true);
    else ui->pbReset->setEnabled(false);

    if(money >= 100) ui->pbCoffe->setEnabled(true);
    else ui->pbCoffe->setEnabled(false);

    if(money >= 150) ui->pbTea->setEnabled(true);
    else ui->pbTea->setEnabled(false);

    if(money >= 200) ui->pbMilk->setEnabled(true);
    else ui->pbMilk->setEnabled(false);

}

void MainWindow::on_pb10_clicked()
{
   changeMoney(10);
}

void MainWindow::on_pb50_clicked()
{
   changeMoney(50);
}


void MainWindow::on_pb100_clicked()
{
    changeMoney(100);
}


void MainWindow::on_pb500_clicked()
{
    changeMoney(500);
}


void MainWindow::on_pbCoffe_clicked()
{
    changeMoney(-100);
}


void MainWindow::on_pbTea_clicked()
{
    changeMoney(-150);
}


void MainWindow::on_pbMilk_clicked()
{
    changeMoney(-200);
}


void MainWindow::on_pbReset_clicked()
{
    int pb500 = money / 500;
    money %= 500;
    int pb100 = money / 100;
    money %= 100;
    int pb50 = money / 50;
    money %= 50;
    int pb10 = money / 10;
    money %= 10;
    QString message;
    message += (pb500 ? QString("%1원 : \t%2개\n").arg(500).arg(pb500) : "") +
               (pb100 ? QString("%1원 : \t%2개\n").arg(100).arg(pb100) : "") +
               (pb50 ? QString("%1원 : \t%2개\n").arg(50).arg(pb50) : "") +
               (pb10 ? QString("%1원 : \t%2개\n").arg(10).arg(pb10) : "");
    mb.information(this, "잔돈 반환", message);
    changeMoney(0);
    ui->lcdNumber->display(0);

}

