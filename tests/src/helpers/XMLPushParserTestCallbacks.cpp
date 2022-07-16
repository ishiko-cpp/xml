/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/xml/blob/main/LICENSE.txt
*/

#include "XMLPushParserTestCallbacks.hpp"
#include "Ishiko/XML/XMLWriter.hpp"
#include <Ishiko/Errors.hpp>

void XMLPushParserTestCallbacks::onXMLDeclaration()
{
    m_events.emplace_back("onXMLDeclaration");
}

void XMLPushParserTestCallbacks::onStartTag()
{
    m_events.emplace_back("onStartTag");
}

void XMLPushParserTestCallbacks::onEndTag()
{
    m_events.emplace_back("onEndTag");
}

void XMLPushParserTestCallbacks::exportToXML(const boost::filesystem::path& path) const
{
    Ishiko::XMLWriter xmlWriter;
    // TODO: handle errors
    Ishiko::Error error;
    xmlWriter.create(path, error);
    xmlWriter.writeXMLDeclaration();
    xmlWriter.writeElementStart("events");
    xmlWriter.increaseIndentation();
    for (const std::string& name : m_events)
    {
        xmlWriter.writeNewlineAndIndentation();

        xmlWriter.writeElementStart("callback");
        xmlWriter.increaseIndentation();
        xmlWriter.writeNewlineAndIndentation();

        xmlWriter.writeElementStart("name");
        xmlWriter.writeText(name);
        xmlWriter.writeElementEnd();

        xmlWriter.decreaseIndentation();
        xmlWriter.writeNewlineAndIndentation();
        xmlWriter.writeElementEnd();
    }
    xmlWriter.decreaseIndentation();
    xmlWriter.writeNewlineAndIndentation();
    xmlWriter.writeElementEnd();
}
