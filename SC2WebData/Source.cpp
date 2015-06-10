#include "CAbilCatalog.h"
#include <iostream>
#include <memory>

using namespace xercesc;

int main(int argc, char* args[]) {
	system("MPQEditor.exe extract Test.SC2Map * .\TestDir /fp");
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

	std::unique_ptr<CAbilCatalog> Abilities(new CAbilCatalog(std::string("AbilData.xml")));
	Abilities->getData();

	return 0;
}