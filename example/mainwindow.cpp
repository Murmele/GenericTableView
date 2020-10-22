#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>

#include "../lib/genericlistmodel.h"
#include "../lib/genericlistview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout *mainLayout = new QVBoxLayout();

    QHBoxLayout *toolButtons
        = new QHBoxLayout(); // for adding tool buttons like adding/removing properties
    QPushButton *add = new QPushButton("add", this);
    toolButtons->addWidget(add);
    QPushButton *remove = new QPushButton("remove", this);
    toolButtons->addWidget(remove);

    mainLayout->addLayout(toolButtons);
    //mainLayout->addItem(new QSpacerItem())

    GenericListView *view = new GenericListView(this);
    view->setModel(new GenericListModel(view));
    mainLayout->addWidget(view);

    ui->centralwidget->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

