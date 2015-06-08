#include "MySAX2Handler.h"
#include <iostream>
#include <fstream>
using namespace xercesc;


void MySAX2Handler::startElement(const   XMLCh* const    uri,
	const   XMLCh* const    localname,
	const   XMLCh* const    qname,
	const   Attributes&     attrs)
{
	unsigned short index = 0;
	std::ofstream newFile("Test.txt", std::ios::app);
	char* message = XMLString::transcode(localname);
	newFile << "I saw element: " << message << std::endl;
	if (attrs.getLength() != 0)
	{
		for (index = 0; index < attrs.getLength(); index++)
		{
			char* name = XMLString::transcode(attrs.getLocalName(index));
			char* value = XMLString::transcode(attrs.getValue(index));
			newFile << "Element Attribute: " << name << std::endl;
			newFile << "Element Value: " << value << std::endl;
			XMLString::release(&value);
			XMLString::release(&name);
		}
	}
}

void MySAX2Handler::fatalError(const SAXParseException& exception)
{
	char* message = XMLString::transcode(exception.getMessage());
	std::cout << "Fatal Error: " << message
		<< " at line: " << exception.getLineNumber()
		<< std::endl;
	XMLString::release(&message);
}

void MySAX2Handler::endElement(const XMLCh* const uri,
	const XMLCh* const localname,
	const XMLCh* const qname)
{
}