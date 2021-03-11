#include "propertyselectionspinbox.h"

PropertySelectionSpinBox::PropertySelectionSpinBox(QWidget *parent)
    : PropertySelectionWrapper(new QSpinBox(parent))
{
    m_sb = static_cast<QSpinBox*>(widget());
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

bool PropertySelectionSpinBox::validValue(const QVariant &value) const
{
    bool ok;
    int v = value.toInt(&ok);

    if (!ok)
        return false;

    if (v < m_sb->minimum() || v > m_sb->maximum())
        return false;

    return true;
}

QVariant PropertySelectionSpinBox::initialValue() const
{
    return m_sb->minimum();
}
