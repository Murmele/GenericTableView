#ifndef PROPERTYSELECTIONDOUBLESPINBOX_H
#define PROPERTYSELECTIONDOUBLESPINBOX_H

#include "../property.h"

#include <QDoubleSpinBox>

class PropertySelectionDoubleSpinBox : public PropertySelectionWrapper
{
public:  
    PropertySelectionDoubleSpinBox(QWidget *parent = nullptr);

    virtual bool setWidgetValue(const QVariant &value) override;
    virtual QVariant widgetValue() const override;
    virtual bool validValue(const QVariant &value) const override;
    virtual QVariant initialValue() const override;

private:
    QDoubleSpinBox* m_sb{nullptr};
};

#endif // PROPERTYSELECTIONDOUBLESPINBOX_H
