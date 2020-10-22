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
    virtual bool setWidgetValue(const QVariant &value) override;
    virtual QVariant widgetValue() const override;
    virtual QWidget *widget() const override { return m_sb; }

private:
    QSpinBox *m_sb{nullptr};
    int m_value{0};
};

#endif // PROPERTYSELECTIONSPINBOX_H
