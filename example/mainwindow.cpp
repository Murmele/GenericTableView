#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDialog>
#include <QLineEdit>

#include "../lib/generictabledelegator.h"
#include "../lib/generictablemodel.h"
#include "../lib/generictableview.h"

#include "../lib/Wrapper/propertyselectioncombobox.h"
#include "../lib/Wrapper/propertyselectiondoublespinbox.h"
#include "../lib/Wrapper/propertyselectionlineedit.h"
#include "../lib/Wrapper/propertyselectionspinbox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout *mainLayout = new QVBoxLayout();

    QHBoxLayout *toolButtons
        = new QHBoxLayout(); // for adding tool buttons like adding/removing properties
    QPushButton *add = new QPushButton("Add", this);
    toolButtons->addWidget(add);
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

    connect(add, &QPushButton::clicked, this, &MainWindow::addProperty);
    connect(remove, &QPushButton::clicked, this, &MainWindow::removeProperty);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addProperty()
{
    QDialog dialog(this);

    QVBoxLayout* layout = new QVBoxLayout();

    QComboBox* cb = new QComboBox(&dialog);
    cb->addItems({"Text", "Integer", "Double", "Selection"});
    layout->addWidget(cb);

    QLineEdit* le = new QLineEdit("Property name", &dialog);
    layout->addWidget(le);

    QPushButton* btn = new QPushButton("OK");
    layout->addWidget(btn);

    // capture a reference (&)
    connect(btn, &QPushButton::clicked, [&] { dialog.accept(); });

    dialog.setLayout(layout);

    dialog.exec();

    QString name = le->text();
    QString datatype = cb->currentText();

    Property p(name, datatype);
    if (datatype == "Text") {
        p.wrapper = QSharedPointer<PropertySelectionWrapper>(new PropertySelectionLineEdit(this));

    } else if (datatype == "Integer") {
        p.wrapper = QSharedPointer<PropertySelectionWrapper>(new PropertySelectionSpinBox(this));
        // Set initial value
        // Also ranges and whatever you want can be done here
        static_cast<QSpinBox *>(p.widget())->setValue(10);

    } else if (datatype == "Double") {
        p.wrapper = QSharedPointer<PropertySelectionWrapper>(
            new PropertySelectionDoubleSpinBox(this));
    } else if (datatype == "Selection") {
        p.wrapper = QSharedPointer<PropertySelectionWrapper>(new PropertyselectionCombobox(this));
        // set items in the combobox
        QComboBox *cb = static_cast<QComboBox *>(p.widget());
        cb->addItems({"Test1", "Test2"});
    }

    model->appendProperty(p);
}

void MainWindow::removeProperty()
{
    model->removeProperty(0); // remove always the first property
}
