#ifndef PROPERTYSELECTIONSPINBOX_H
#define PROPERTYSELECTIONSPINBOX_H

#include "../property.h"
#include <QSpinBox>

class PropertySelectionSpinBox : public PropertySelectionWidget
{

public:
    PropertySelectionSpinBox(QWidget *parent = nullptr);

    virtual Type type() const override;
    virtual bool setValue(const QVariant &value) override;
    virtual QVariant value() const override;
    virtual QWidget *widget() const override { return m_sb; }

private:
    QSpinBox *m_sb{nullptr};
};

#endif // PROPERTYSELECTIONSPINBOX_H
