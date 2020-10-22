#ifndef PROPERTYSELECTIONCOMBOBOX_H
#define PROPERTYSELECTIONCOMBOBOX_H

#include "../property.h"

#include <QComboBox>

class PropertyselectionCombobox : public PropertySelectionWidget
{
public:
    PropertyselectionCombobox(QWidget *parent = nullptr);

    virtual Type type() const override;
    /*!
     * \brief setValue
     * Sets the current index of the combobox
     * \param value
     * \return 
     */
    virtual bool setValue(const QVariant &value) override;
    /*!
     * \brief value
     * Returns the current index of the combobox
     * \return 
     */
    virtual QVariant value() const override;
    virtual bool setWidgetValue(const QVariant &value) override;
    virtual QVariant widgetValue() const override;
    virtual QWidget *widget() const override { return m_cb; }

private:
    QComboBox *m_cb{nullptr};
    QString m_currentText{""};
};

#endif // PROPERTYSELECTIONCOMBBOX_H
