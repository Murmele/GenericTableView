#ifndef PROPERTY_H
#define PROPERTY_H

#include <QString>
#include <QVariant>
#include <QWidget>

/*!
 * \brief The SelectionWidget class
 * Base class for the widgets in the property
 * Inherit from this class to create your own widgets
 */
class PropertySelectionWidget
{
public:
    PropertySelectionWidget(){};

    enum class Type {
        SpinBox, // derive from SpinBoxSelectionWidgetProperties
        ComboBox
    };

    virtual Type type() const = 0;
    virtual bool setValue(const QVariant &value) = 0;
    virtual QVariant value() const = 0;
    virtual bool setWidgetValue(const QVariant &value) = 0;
    virtual QVariant widgetValue() const = 0;
    virtual QWidget *widget() const = 0;
};

struct Property
{
    Property();
    Property(const Property &p);
    bool setValue(const QVariant &value)
    {
        if (!widget)
            return false;

        widget->setValue(value);
    }
    QVariant value() const
    {
        if (!widget)
            return QVariant();
        return widget->value();
    }
    QString name{""}; // Property name
    bool required{false};
    // PropertySelectionWidget contains a Widget with all possible widgets which can be used for changing the value, for example spinbox, font selection, combobox, ....
    PropertySelectionWidget *widget{nullptr};
};

#endif // PROPERTY_H
