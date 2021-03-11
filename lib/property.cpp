#include "property.h"

Property::Property() {}

Property::Property(QString name, QString datatype, QSharedPointer<PropertySelectionWrapper> widget)
    : m_name(name), m_datatype(datatype), wrapper(widget)
{}
