#include "CAbilHandler.h"

using namespace xercesc;


void CAbilHandler::startElement(const   XMLCh* const    uri,
	const   XMLCh* const    localname,
	const   XMLCh* const    qname,
	const   Attributes&     attrs)
{
	unsigned short index = 0;
	std::ofstream newFile("Test.txt", std::ios::app);
	std::string message = XMLString::transcode(qname);


	if (message.compare(0, 5, "CAbil") == 0)
	{
		//std::unique_ptr<CAbil> tempAbil(new CAbil(message));
		CAbil tempAbil = CAbil(message);
		CAbilities.push_back(tempAbil);
		newFile << "I saw element: " << message.c_str() << std::endl;
	}
	/*if (attrs.getLength() != 0)
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
	}*/
}

void CAbilHandler::fatalError(const SAXParseException& exception)
{
	char* message = XMLString::transcode(exception.getMessage());
	std::cout << "Fatal Error: " << message
		<< " at line: " << exception.getLineNumber()
		<< std::endl;
	XMLString::release(&message);
}

void CAbilHandler::endElement(const XMLCh* const uri,
	const XMLCh* const localname,
	const XMLCh* const qname)
{
}