#include "property.h"

Property::Property() {}

Property::Property(const Property &p)
{
    m_name = p.m_name;
    m_required = p.m_required;
    widget = p.widget;
}
