#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include "MySAX2Handler.h"

#include <iostream>
#include <memory>

using namespace xercesc;

int main(int argc, char* args[]) {

	try {
		XMLPlatformUtils::Initialize();
	}
	catch (const XMLException& toCatch) {
		char* message = XMLString::transcode(toCatch.getMessage());
		std::cout << "Error during initialization! :\n";
		std::cout << "Exception message is: \n"
			<< message << "\n";
		XMLString::release(&message);
		return 1;
	}

	std::unique_ptr<std::string> xmlFile(new std::string("AbilData.xml"));
	std::unique_ptr<SAX2XMLReader> parser(XMLReaderFactory::createXMLReader());
	parser->setFeature(XMLUni::fgSAX2CoreValidation, true);
	parser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);   // optional

	std::unique_ptr<MySAX2Handler> defaultHandler(new MySAX2Handler());
	parser->setContentHandler(defaultHandler.get());
	parser->setErrorHandler(defaultHandler.get());

	try {
		parser->parse(xmlFile->c_str());
	}
	catch (const XMLException& toCatch) {
		char* message = XMLString::transcode(toCatch.getMessage());
		std::cout << "Exception message is: \n"
			<< message << "\n";
		XMLString::release(&message);
		return -1;
	}
	catch (const SAXParseException& toCatch) {
		char* message = XMLString::transcode(toCatch.getMessage());
		std::cout << "Exception message is: \n"
			<< message << "\n";
		XMLString::release(&message);
		return -1;
	}
	catch (...) {
		std::cout << "Unexpected Exception \n";
		return -1;
	}

	return 0;
}