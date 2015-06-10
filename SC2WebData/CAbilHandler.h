#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/sax2/Attributes.hpp>
#include "CAbil.h"
#include <memory>
#include <iostream>
#include <fstream>
#include <vector>
using namespace xercesc;
class CAbilHandler : public DefaultHandler {
	
public:
	std::vector<CAbil> CAbilities;
	void startElement(
		const   XMLCh* const    uri,
		const   XMLCh* const    localname,
		const   XMLCh* const    qname,
		const   Attributes&     attrs
		);
	void endElement
		(
		const XMLCh* const uri,
		const XMLCh* const localname,
		const XMLCh* const qname
		);
	void fatalError(const SAXParseException&);
};