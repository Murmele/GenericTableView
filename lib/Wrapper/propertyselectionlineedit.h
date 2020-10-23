#ifndef PROPERTYSELECTIONLINEEDIT_H
#define PROPERTYSELECTIONLINEEDIT_H

#include "../property.h"

#include <QLineEdit>

class PropertySelectionLineEdit : public PropertySelectionWrapper
{
public:
    PropertySelectionLineEdit(QWidget *parent = nullptr);

    virtual bool setWidgetValue(const QVariant &value) override;
    virtual QVariant widgetValue() const override;
    virtual QWidget *widget() const override { return m_le; }
    virtual bool validValue(const QVariant &value) const override;
    virtual QVariant initialValue() const override;

private:
    QLineEdit *m_le{nullptr};
};

#endif // PROPERTYSELECTIONLINEEDIT_H
