#include <string>
#include <fstream>
class CAbil
{
	std::string type;
public:
	CAbil(std::string abilType);
	void debugType(std::string fileName);
};