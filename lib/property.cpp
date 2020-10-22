#include "property.h"

Property::Property() {}

Property::Property(const Property &p)
{
    name = p.name;
    required = p.required;
    widget = p.widget;
}
