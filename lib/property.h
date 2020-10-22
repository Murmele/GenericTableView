#ifndef PROPERTY_H
#define PROPERTY_H

#include <QString>

class SelectionWidget
{
public:
    SelectionWidget();

    enum class Type {
        SpinBox, // derive from SpinBoxSelectionWidgetProperties
        ComboBox
    };

    virtual Type type() const = 0;
    //virtual QVariant value() const = 0;
};

struct Property
{
    QString name; // Property name
    bool required;
    SelectionWidget
        w; // Selectionwidget is an enum with all possible widgets which can be used for changing the value, for example spinbox, font selection, combobox, ....
}

#endif // PROPERTY_H
