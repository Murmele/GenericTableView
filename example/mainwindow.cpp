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

namespace  {
    /*!
     * \brief The PropertyDialog class
     * Simple dialog to select the datatype and the name of the property
     */
    class PropertyDialog: public QDialog
    {
    public:
        PropertyDialog(QWidget *parent = nullptr): QDialog(parent) {
            QVBoxLayout* layout = new QVBoxLayout();

            cb = new QComboBox(this);
            cb->addItems({"Text", "Integer", "Double", "Selection"});
            layout->addWidget(cb);

            le = new QLineEdit("Property name", this);
            layout->addWidget(le);

            QPushButton* btn = new QPushButton("OK");
            layout->addWidget(btn);

            // capture a reference (&)
            connect(btn, &QPushButton::clicked, [&] { this->accept(); });

            this->setLayout(layout);
        };

        QString name() {return le->text();}
        QString datatype() {return cb->currentText();}

    private:
        QLineEdit* le;
        QComboBox* cb;
    };
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVBoxLayout *mainLayout = new QVBoxLayout();

    QHBoxLayout *toolButtons = new QHBoxLayout(); // for adding tool buttons like adding/removing properties
    QPushButton *add = new QPushButton("Add", this);
    toolButtons->addWidget(add);
    QPushButton *remove = new QPushButton("remove", this);
    toolButtons->addWidget(remove);
    QPushButton *removeAll = new QPushButton("removeAll", this);
    toolButtons->addWidget(removeAll);
    connect(add, &QPushButton::clicked, this, &MainWindow::addProperty);
    connect(remove, &QPushButton::clicked, this, &MainWindow::removeProperty);
    connect(removeAll, &QPushButton::clicked, this, &MainWindow::removeAll);

    mainLayout->addLayout(toolButtons);

    // Create new GenericTableView and the model.
    GenericTableView *view = new GenericTableView(this);
    model = new GenericTableModel(view);
    QStringList header = {"Name", "Value"};
    model->setHeader(header);
    view->setModel(model);

    view->setItemDelegate(new GenericTableDelegator(view));
    mainLayout->addWidget(view);

    ui->centralwidget->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*!
 * \brief MainWindow::addProperty
 * Opens a dialog to create a new property.
 * After the property was selected, the corresponding wrapper will be created. This wrapper is used to
 * modify the value afterwards
 */
void MainWindow::addProperty()
{
    PropertyDialog dialog(this);
    dialog.exec();
    // Get name and datatype from the dialog
    QString name = dialog.name();
    QString datatype = dialog.datatype();

    Property* p = new Property(name, datatype);
    if (datatype == "Text") {
        p->wrapper = QSharedPointer<PropertySelectionWrapper>(new PropertySelectionLineEdit(this));

    } else if (datatype == "Integer") {
        p->wrapper = QSharedPointer<PropertySelectionWrapper>(new PropertySelectionSpinBox(this));
        // Set initial value
        // Also ranges and whatever you want can be done here
        static_cast<QSpinBox *>(p->widget())->setValue(10);

    } else if (datatype == "Double") {
        p->wrapper = QSharedPointer<PropertySelectionWrapper>(
            new PropertySelectionDoubleSpinBox(this));
    } else if (datatype == "Selection") {
        p->wrapper = QSharedPointer<PropertySelectionWrapper>(new PropertyselectionCombobox(this));
        // set items in the combobox
        QComboBox *cb = static_cast<QComboBox *>(p->widget());
        cb->addItems({"Test1", "Test2"});
    }

    model->appendProperty(p);
}

void MainWindow::removeAll()
{
  while(model->removeProperty(0))
  {}
}

void MainWindow::removeProperty()
{
    model->removeProperty(0); // remove always the first property
}
