#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMenu>
#include <ctime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->Add_Btn, SIGNAL(clicked()), this, SLOT(Add_product()));
    connect(ui->Delete_Btn,SIGNAL(clicked()), this, SLOT(Delete_product()));

    Create_rand();

    m_menu = new QMenu(ui->Sorts_Btn);
    m_menu->addAction("По дате", this, SLOT(Sort_Date()));
    m_menu->addAction("По алфавиту",this, SLOT(Sort_Name()));


    ui->Sorts_Btn->setMenu(m_menu);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Add_product(){
    QString name = ui->Name_lineEdit->text();
    QString date = ui->dateEdit->text();
    if (name=="" or date ==""){
        QMessageBox msgBox;
        msgBox.setText("Заполнены не все поля");
        msgBox.exec();
        return;
    }
    if(cur_date > ui->dateEdit->date()){
        QMessageBox msgBox;
        msgBox.setText("Cрок годности товара истёк :(");
        msgBox.exec();
        return;
    }
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(name));
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(date));
    ui->Name_lineEdit->clear();
    vector.push_back(ui->dateEdit->date());
    vector_str.push_back(name);
    Check_date();
}
void MainWindow::Delete_product(){
    QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
    if(selectedRows.empty()){
        QMessageBox msgBox;
        msgBox.setText("Выделите строку которую хотите удалить");
        msgBox.exec();
        return;
    }
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Предупреждение", "Вы уверены что хотите удалить выделенную(ые) строку(и)?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::No) {
        return;
      }

        while (!selectedRows.empty()) {

            ui->tableWidget->removeRow(selectedRows[0].row());
            selectedRows = ui->tableWidget->selectionModel()->selectedRows();
        }

       vector.clear();
       vector_str.clear();
       for(int i = 0; i < ui->tableWidget->rowCount(); i++){
           QTableView* myTable = ui->tableWidget;
           QVariant myData;
           QModelIndex myIndex;
           myIndex = myTable->model()->index(i, 1 , QModelIndex());
           myData = myTable->model()->data( myIndex, Qt::DisplayRole);
           QString tmp = myData.toString();
           QDate temp = QDate::fromString(tmp, "dd.MM.yyyy");
           vector.push_back(temp);
           QVariant myData2;
           QModelIndex myIndex2;
           myIndex2 = myTable->model()->index(i, 0 , QModelIndex());
           myData2 = myTable->model()->data( myIndex2, Qt::DisplayRole);
           QString tmp2 = myData2.toString();
           vector_str.push_back(tmp2);
       }
}
void MainWindow::Sort_Date(){
    int c =vector.size();
    while(c--){
        bool swapped = true;
        for(int i = 0; i < vector.size()-1; i++){
            if(vector[i] > vector[i+1]){
                std::swap(vector[i],vector[i+1]);
                std::swap(vector_str[i],vector_str[i+1]);
                swapped = false;
            }
        }
        if(swapped == true){
            break;
        }
    }

    while(ui->tableWidget->rowCount() > 0){
        ui->tableWidget->removeRow(0);
    }
    for(int i = 0; i < vector.size();i++){
        QString name = vector_str[i];
        QString date = vector[i].toString("dd.MM.yyyy");
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(name));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(date));
    }
    Check_date();
}
void MainWindow::Check_date(){
    for(int i =0; i < vector.size(); i++){
        QString str = ui->tableWidget->item(i,1)->text();
        QDate product_date = QDate::fromString(str, "dd.MM.yyyy");

        if(cur_date >= product_date){
            ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);
            ui->tableWidget->item(i,1)->setBackgroundColor(Qt::red);
        }
        else if(cur_date.daysTo(product_date) <= 3){
            ui->tableWidget->item(i,0)->setBackgroundColor(Qt::yellow);
            ui->tableWidget->item(i,1)->setBackgroundColor(Qt::yellow);
        }
    }
}
void MainWindow::Sort_Name(){
    int c =vector.size();
    while(c--){
        bool swapped = true;
        for(int i = 0; i < vector.size()-1; i++){
           if(vector_str[i][0] > vector_str[i+1][0]){
               std::swap(vector_str[i], vector_str[i+1]);
               std::swap(vector[i], vector[i+1]);
               swapped = false;
           }
        }
        if(swapped == true){
            break;
        }
    }
    while(ui->tableWidget->rowCount() > 0){
        ui->tableWidget->removeRow(0);
    }
    for(int i = 0; i < vector.size();i++){
        QString name = vector_str[i];
        QString date = vector[i].toString("dd.MM.yyyy");
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(name));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(date));
    }
    Check_date();
}
void MainWindow::Create_rand(){
    srand(time(0));
    QString products[30] = {"Молоко", "Хлеб", "Яблоки", "Мясо", "Яйца", "Рис", "Картофель", "Вода", "Сахар", "Масло","Соль", "Сыр", "Огурцы", "Творог", "Колбаса","Чай", "Кофе", "Мандарины", "Гречка", "Помидоры","Бананы", "Макароны", "Кефир", "Сок", "Йогурт","Пельмени", "Сливки", "Апельсины", "Капуста", "Фасоль"};
    for(int i = 0; i< 50; i++){
        int r = rand()%30;
        int day = rand()%27+1;
        int month = rand()%11+1;
        int year = rand()%15+2020;
        QString d = QString::number(day);
        QString m = QString::number(month);
        QString y = QString::number(year);
        QString date;
        if(day<10 and month<10){
            date ='0'+ d+'.' + '0' + m + '.' + y;
        }
        else if(day < 10){
            date ='0'+ d+'.' + m + '.' + y;
        }
        else if(month < 10){
             date = d+'.'+ '0' + m + '.' + y;
        }
        else{
             date = d+'.' + m + '.' + y;
        }

        ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, new QTableWidgetItem(products[r]));
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, new QTableWidgetItem(date));
        QDate temp = QDate::fromString(date, "dd.MM.yyyy");
        vector.push_back(temp);
        vector_str.push_back(products[r]);
    }
    Check_date();
}
