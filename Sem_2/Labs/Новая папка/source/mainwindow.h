#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QtDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void Add_product();
    void Delete_product();
    void Sort_Date();
    void Sort_Name();
    void Check_date();
    void Create_rand();
private:
    Ui::MainWindow  *ui;
    const QDate cur_date = QDate::currentDate();
    std::vector<QDate> vector;
    std::vector<QString> vector_str;
    QMenu *m_menu;
};

#endif // MAINWINDOW_H
