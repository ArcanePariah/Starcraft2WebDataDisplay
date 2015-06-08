#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/sax2/Attributes.hpp>
using namespace xercesc;
class MySAX2Handler : public DefaultHandler {
public:
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