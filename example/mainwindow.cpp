#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>

#include "../lib/generictabledelegator.h"
#include "../lib/generictablemodel.h"
#include "../lib/generictableview.h"

#include "../lib/Widgets/propertyselectioncombobox.h"
#include "../lib/Widgets/propertyselectionspinbox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout *mainLayout = new QVBoxLayout();

    QHBoxLayout *toolButtons
        = new QHBoxLayout(); // for adding tool buttons like adding/removing properties
    QPushButton *addSB = new QPushButton("Add Spinbox Property", this);
    toolButtons->addWidget(addSB);
    QPushButton *addCB = new QPushButton("Add Combobox Property", this);
    toolButtons->addWidget(addCB);
    QPushButton *remove = new QPushButton("remove", this);
    toolButtons->addWidget(remove);

    mainLayout->addLayout(toolButtons);
    //mainLayout->addItem(new QSpacerItem())

    GenericTableView *view = new GenericTableView(this);
    model = new GenericTableModel(view);
    QStringList header = {"Name", "Value"};
    model->setHeader(header);
    view->setModel(model);

    view->setItemDelegate(new GenericTableDelegator(view));
    mainLayout->addWidget(view);

    ui->centralwidget->setLayout(mainLayout);

    connect(addSB, &QPushButton::clicked, this, &MainWindow::addSBProperty);
    connect(addCB, &QPushButton::clicked, this, &MainWindow::addCBProperty);
    connect(remove, &QPushButton::clicked, this, &MainWindow::removeProperty);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addSBProperty()
{
    Property p;
    p.m_name = "Property " + QString::number(propertyCounter);
    // the spinbox can also be reused
    p.widget = QSharedPointer<PropertySelectionWidget>(new PropertySelectionSpinBox(this));
    model->appendProperty(p);
    propertyCounter++;
}

void MainWindow::addCBProperty()
{
    Property p;
    p.m_name = "Property " + QString::number(propertyCounter);
    // the spinbox can also be reused
    p.widget = QSharedPointer<PropertySelectionWidget>(new PropertyselectionCombobox(this));
    QComboBox *cb = static_cast<QComboBox *>(p.widget->widget());
    cb->addItems({"Test1", "Test2"});
    model->appendProperty(p, "Test3");
    propertyCounter++;
}

void MainWindow::removeProperty()
{
    model->removeProperty(0); // remove always the first property
}
