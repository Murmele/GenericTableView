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
    m_currentText = value.toString();
    return true;
}
QVariant PropertyselectionCombobox::value() const
{
    // m_cb might be used also in other properties. So use m_currentText instead
    // of the currentText() from m_cb
    return m_currentText;
}

bool PropertyselectionCombobox::setWidgetValue(const QVariant &value)
{
    m_cb->setCurrentText(value.toString());
    return true;
}

QVariant PropertyselectionCombobox::widgetValue() const
{
    return m_cb->currentText();
}
