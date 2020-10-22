#include "propertyselectionspinbox.h"

PropertySelectionSpinBox::PropertySelectionSpinBox(QWidget *parent)
    : PropertySelectionWidget(), QSpinBox(parent)
{
  
}

PropertySelectionWidget::Type PropertySelectionSpinBox::type() const
{
    return PropertySelectionWidget::Type::SpinBox;
}
bool PropertySelectionSpinBox::setValue(const QVariant &value)
{
    // TODO: needed?
    bool ok = false;
    int val = value.toInt(&ok);
    if (ok) {
        QSpinBox::setValue(val);
        return true;
    }
    return false;
}
QVariant PropertySelectionSpinBox::value() const
{
    return QSpinBox::value();
}
