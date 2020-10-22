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

    /*!
     * \brief type
     * Currently not used, because it limits the extendible
     * \return
     */
    virtual Type type() const = 0;
    /*!
     * \brief setValue
     * Sets the value of the property
     * \param value
     * \return
     */
    virtual bool setValue(const QVariant &value) = 0;
    /*!
     * \brief value
     * Returns the value of this property
     * \return
     */
    virtual QVariant value() const = 0;
    /*!
     * \brief setWidgetValue
     * Sets the value to the edit widget (Spinbox, Combobox, ...)
     * \param value
     * \return
     */
    virtual bool setWidgetValue(const QVariant &value) = 0;
    /*!
     * \brief widgetValue
     * Returns the value of the edit widget (Spinbox, Combobox, ...)
     * \return
     */
    virtual QVariant widgetValue() const = 0;
    /*!
     * \brief widget
     * Returns the widget which is used to modify the table cell
     * \return
     */
    virtual QWidget *widget() const = 0;
    /*!
     * \brief validValue
     * Validates the value. If \p value is valid, true is returned, otherwise false
     * \param value Value which should be validated
     * \return
     */
    virtual bool validValue(const QVariant &value) const = 0;
    /*!
     * \brief initialValue
     * Returns an arbitrary valid value. It is used to set an initial value
     * \return
     */
    virtual QVariant initialValue() const = 0;
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
        return true;
    }
    QVariant value() const
    {
        if (!widget)
            return QVariant();
        return widget->value();
    }
    QString name{""}; // Property name
    bool required{false}; // true means, the property cannot be deleted. So deleteProperty() returns false
    // PropertySelectionWidget contains a Widget with all possible widgets which can be used for changing the value, for example spinbox, font selection, combobox, ....
    // TODO: use smartpointer!
    PropertySelectionWidget *widget{nullptr};
};

#endif // PROPERTY_H
