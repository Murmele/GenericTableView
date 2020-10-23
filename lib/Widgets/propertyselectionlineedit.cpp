#include "propertyselectionlineedit.h"

PropertySelectionLineEdit::PropertySelectionLineEdit(QWidget *parent)
    : PropertySelectionWrapper(), m_le(new QLineEdit(parent))
{}

//PropertySelectionWrapper::Type PropertySelectionLineEdit::type() const
//{
//    return PropertySelectionWrapper::Type::LineEdit;
//}

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
