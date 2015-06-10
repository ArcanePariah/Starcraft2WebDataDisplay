#include <vector>
#include <memory>
#include "CAbilHandler.h"
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <iostream>

class CAbilCatalog
{
	std::string xmlFile;						// XML File to parse, must be the Ability Data
	std::unique_ptr<SAX2XMLReader> parser;		// Each catalog will have its own parser, to allow background changes/parsing of all data files, in case of changes of id's in other catalogs
	std::unique_ptr<CAbilHandler> handler;		// Handler specific to this data type. As a pointer, this can be made into a default handler most likely. Can probably make a virtual catalog class for all catalogs to inherit from.
	std::vector<CAbil> CAbilities;				// Vector to store each data entry in. Storing them will allow export to other formats beyond XML. As far as I'm aware, ordering is not relevant.

public:
	CAbilCatalog(std::string fileName);
	void getData();


};