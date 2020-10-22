#include "propertyselectioncombobox.h"

PropertyselectionCombobox::PropertyselectionCombobox(QWidget *parent)
    : PropertySelectionWidget(), m_cb(new QComboBox(parent))
{}

PropertySelectionWidget::Type PropertyselectionCombobox::type() const
{
    return PropertySelectionWidget::Type::ComboBox;
}
bool PropertyselectionCombobox::setValue(const QVariant &value)
{
    int index = value.toInt();
    if (index < 0 || index >= m_cb->count())
        return false;

    m_cb->setCurrentIndex(index);
    return true;
}
QVariant PropertyselectionCombobox::value() const
{
    return m_cb->currentText();
}
