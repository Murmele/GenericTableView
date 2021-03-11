#include "propertyselectionlineedit.h"

PropertySelectionLineEdit::PropertySelectionLineEdit(QWidget *parent)
    : PropertySelectionWrapper(new QLineEdit(parent)), m_le(static_cast<QLineEdit*>(widget()))
{}

bool PropertySelectionLineEdit::setWidgetValue(const QVariant &value)
{
    m_le->setText(value.toString());
    return true;
}

QVariant PropertySelectionLineEdit::widgetValue() const
{
    return m_le->text();
}

bool PropertySelectionLineEdit::validValue(const QVariant &value) const
{
    // Every Qvariant is true
    return true;
}

QVariant PropertySelectionLineEdit::initialValue() const
{
    return "";
}
