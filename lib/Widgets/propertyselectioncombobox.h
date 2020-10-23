#ifndef PROPERTYSELECTIONCOMBOBOX_H
#define PROPERTYSELECTIONCOMBOBOX_H

#include "../property.h"

#include <QComboBox>

class PropertyselectionCombobox : public PropertySelectionWidget
{
public:
    PropertyselectionCombobox(QWidget *parent = nullptr);

    virtual Type type() const override;
    virtual bool setWidgetValue(const QVariant &value) override;
    virtual QVariant widgetValue() const override;
    virtual bool validValue(const QVariant &value) const override;
    virtual QWidget *widget() const override { return m_cb; }
    virtual QVariant initialValue() const override;

private:
    QComboBox *m_cb{nullptr};
};

#endif // PROPERTYSELECTIONCOMBBOX_H
