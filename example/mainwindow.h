#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class GenericListModel;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void addProperty();
    void removeProperty();

private:
    Ui::MainWindow *ui{nullptr};
    GenericListModel *model{nullptr};
    int propertyCounter{0};
};
#endif // MAINWINDOW_H
