#include "propertyselectiondoublespinbox.h"

PropertySelectionDoubleSpinBox::PropertySelectionDoubleSpinBox(QWidget *parent)
    : PropertySelectionWrapper(new QDoubleSpinBox(parent)), m_sb(static_cast<QDoubleSpinBox*>(widget()))
{}

bool PropertySelectionDoubleSpinBox::setWidgetValue(const QVariant &value)
{
    bool ok = false;
    double val = value.toDouble(&ok);
    if (ok) {
        m_sb->setValue(val);
        return true;
    }
    return false;
}

QVariant PropertySelectionDoubleSpinBox::widgetValue() const
{
    return m_sb->value();
}

bool PropertySelectionDoubleSpinBox::validValue(const QVariant &value) const
{
    bool ok;
    double v = value.toDouble(&ok);

    if (!ok)
        return false;

    // rounding of the value is done in the SpinBox it self

    if (v < m_sb->minimum() || v > m_sb->maximum())
        return false;

    return true;
}

QVariant PropertySelectionDoubleSpinBox::initialValue() const
{
    return m_sb->minimum();
}
