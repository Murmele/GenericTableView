#include "propertyselectionlineedit.h"

PropertySelectionLineEdit::PropertySelectionLineEdit(QWidget *parent)
    : PropertySelectionWidget(), m_le(new QLineEdit(parent))
{}

//PropertySelectionWidget::Type PropertySelectionLineEdit::type() const
//{
//    return PropertySelectionWidget::Type::LineEdit;
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
