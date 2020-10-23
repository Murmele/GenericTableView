#include "property.h"

Property::Property() {}

Property::Property(QString name, QString datatype, QSharedPointer<PropertySelectionWrapper> widget)
    : m_name(name), m_datatype(datatype), wrapper(widget)
{}

Property::Property(const Property &p)
    : m_name(p.m_name), m_datatype(p.m_datatype), m_required(p.m_required), m_value(p.m_value),
      wrapper(p.wrapper)
{
}
