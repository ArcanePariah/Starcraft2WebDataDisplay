#include "CAbilCatalog.h"

CAbilCatalog::CAbilCatalog(std::string fileName) : parser(XMLReaderFactory::createXMLReader()), handler(new CAbilHandler())
{
	xmlFile.assign(fileName);
	parser->setFeature(XMLUni::fgSAX2CoreValidation, true);
	parser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);   // optional
	parser->setContentHandler(handler.get());
	parser->setErrorHandler(handler.get());
}

void CAbilCatalog::getData()
{
	try{
		parser->parse(xmlFile.c_str());
	}
	catch (const XMLException& toCatch) {
		char* message = XMLString::transcode(toCatch.getMessage());
		std::cout << "Exception message is: \n"
			<< message << "\n";
		XMLString::release(&message);
		return;
	}
	catch (const SAXParseException& toCatch) {
		char* message = XMLString::transcode(toCatch.getMessage());
		std::cout << "Exception message is: \n"
			<< message << "\n";
		XMLString::release(&message);
		return;
	}
	catch (...) {
		std::cout << "Unexpected Exception \n";
		return;
	}

	CAbilities = (*(handler.get())).CAbilities;
	std::cout << CAbilities.size();
}