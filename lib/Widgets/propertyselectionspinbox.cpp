#include "propertyselectionspinbox.h"

PropertySelectionSpinBox::PropertySelectionSpinBox(QWidget *parent)
    : PropertySelectionWidget(), m_sb(new QSpinBox(parent))
{}

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
        m_value = val;
        return true;
    }
    return false;
}

QVariant PropertySelectionSpinBox::value() const
{
    return m_value;
}

bool PropertySelectionSpinBox::setWidgetValue(const QVariant &value)
{
    bool ok = false;
    int val = value.toInt(&ok);
    if (ok) {
        m_sb->setValue(val);
        return true;
    }
    return false;
}

QVariant PropertySelectionSpinBox::widgetValue() const
{
    return m_sb->value();
}
