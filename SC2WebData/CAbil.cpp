#include "CAbil.h"

CAbil::CAbil(std::string abilType)
{
	type.assign(abilType);
}

void CAbil::debugType(std::string fileName)
{
	std::ofstream newFile(fileName, std::ios::app);
	newFile << type << std::endl;
}