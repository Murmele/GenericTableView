#include "propertyselectioncombobox.h"

PropertyselectionCombobox::PropertyselectionCombobox(QWidget *parent)
    : PropertySelectionWrapper(), m_cb(new QComboBox(parent))
{}

//PropertySelectionWrapper::Type PropertyselectionCombobox::type() const
//{
//    return PropertySelectionWrapper::Type::ComboBox;
//}

bool PropertyselectionCombobox::setWidgetValue(const QVariant &value)
{
    m_cb->setCurrentText(value.toString());
    return true;
}

QVariant PropertyselectionCombobox::widgetValue() const
{
    return m_cb->currentText();
}

bool PropertyselectionCombobox::validValue(const QVariant &value) const
{
    QString text = value.toString();

    for (int i = 0; i < m_cb->count(); i++) {
        if (text == m_cb->itemText(i))
            return true;
    }
    return false;
}

QVariant PropertyselectionCombobox::initialValue() const
{
    if (m_cb->count() > 0)
        return m_cb->itemText(0);
    return QVariant();
}