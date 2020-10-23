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
class PropertySelectionWrapper
{
public:
    PropertySelectionWrapper(){};

    //    enum class Type {
    //        SpinBox, // derive from SpinBoxSelectionWidgetProperties
    //        ComboBox
    //    };

    //    enum class DataType {
    //	String,
    //	Integer,
    //	Double
    //    };

    //    /*!
    //     * \brief type
    //     * Currently not used, because it limits the extendible
    //     * \return
    //     */
    //    virtual Type type() const = 0;
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
public:
    Property();
    Property(QString name,
             QString datatype,
             QSharedPointer<PropertySelectionWrapper> widget = nullptr);
    Property(const Property &p);

    /*!
     * \brief setValue
     * Sets the value of the property
     * \param value
     */
    void setValue(const QVariant &value) { m_value = value; }

    /*!
     * \brief value
     * Returns the current value of the property
     * \return 
     */
    QVariant value() const { return m_value; }

    /*!
     * \brief widget
     * Access the widget inside the wrapper. This can be used
     * to set specific properties to the widget. For example
     * minimum and maximum in a spinbox
     * \return 
     */
    QWidget *widget() { return wrapper->widget(); }

    // desired to be public
public:
    /*!
     * \brief m_name
     * Name of the property
     */
    QString m_name{""};

    /*!
     * \brief m_datatype
     * Datatype of the property. Can be used to convert the QVariant
     * to the appropriate datatype. It lies in the programmers hand to convert
     * the value to the appropriate datatype. This variable is just that the programmer
     * knows the datatype the property has.
     * 
     */
    QString m_datatype;

    /*!
     * \brief m_required
     * true means, the property cannot be deleted. So deleteProperty() returns false
     */
    bool m_required{false};
    /*!
     * \brief m_value
     * Value of the property is stored in this variable
     */
    QVariant m_value;
    /*!
     * \brief wrapper
     * This is a wrapper for different widgets to get a common interface.
     * Contains a Widget with all possible widgets which can be used for changing the value, 
     * for example spinbox, font selection, combobox, ....
     */
    QSharedPointer<PropertySelectionWrapper> wrapper{nullptr};
};

#endif // PROPERTY_H
