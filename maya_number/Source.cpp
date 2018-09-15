#include "MayaGlyph.hpp"

int main() {

	uint8_t num = UINT8_MAX;
	std::vector<unsigned char> maya_num;

	maya::mayaNumber(num, maya_num);
	maya::mayaNumberOutput(maya_num);
	std::cout << std::endl;

	std::string str8;
	maya::mayaNumberUTF(maya_num, str8);
	std::cout << str8;

	return 0;
}