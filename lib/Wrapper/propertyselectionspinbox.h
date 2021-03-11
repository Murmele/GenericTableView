#ifndef PROPERTYSELECTIONSPINBOX_H
#define PROPERTYSELECTIONSPINBOX_H

#include "../property.h"
#include <QSpinBox>

class PropertySelectionSpinBox : public PropertySelectionWrapper
{

public:
    PropertySelectionSpinBox(QWidget *parent = nullptr);

    virtual bool setWidgetValue(const QVariant &value) override;
    virtual QVariant widgetValue() const override;
    virtual bool validValue(const QVariant &value) const override;
    virtual QVariant initialValue() const override;

private:
    QSpinBox *m_sb{nullptr};
};

#endif // PROPERTYSELECTIONSPINBOX_H
