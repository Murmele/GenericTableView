#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>

#include "../lib/generictabledelegator.h"
#include "../lib/generictablemodel.h"
#include "../lib/generictableview.h"

#include "../lib/Widgets/propertyselectionspinbox.h"

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

    GenericTableView *view = new GenericTableView(this);
    model = new GenericTableModel(view);
    view->setModel(model);

    view->setItemDelegate(new GenericTableDelegator(view));
    mainLayout->addWidget(view);

    ui->centralwidget->setLayout(mainLayout);

    connect(add, &QPushButton::clicked, this, &MainWindow::addProperty);
    connect(remove, &QPushButton::clicked, this, &MainWindow::removeProperty);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addProperty()
{
    Property p;
    p.name = "Property " + QString::number(propertyCounter);
    // the spinbox can also be reused
    p.widget = new PropertySelectionSpinBox(this);
    model->appendProperty(p);
    propertyCounter++;
}

void MainWindow::removeProperty()
{
    model->removeProperty(0); // remove always the first property
}
