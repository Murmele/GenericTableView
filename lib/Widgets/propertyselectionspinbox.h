#ifndef PROPERTYSELECTIONSPINBOX_H
#define PROPERTYSELECTIONSPINBOX_H

#include "../property.h"
#include <QSpinBox>

class PropertySelectionSpinBox : public PropertySelectionWidget, public QSpinBox
{

public:
    PropertySelectionSpinBox(QWidget *parent = nullptr);

    virtual Type type() const override;
    virtual bool setValue(const QVariant &value) override;
    virtual QVariant value() const override;
};

#endif // PROPERTYSELECTIONSPINBOX_H
