#include "MayaGlyph.hpp"
#include <limits>

int main() {

	constexpr uint8_t num{ std::numeric_limits<uint8_t>::max() };
	std::vector<unsigned char> maya_num;

	maya::mayaNumber(num, maya_num);
	maya::mayaNumberOutput(maya_num);
	std::cout << std::endl;

	std::string str8;
	maya::mayaNumberUTF(maya_num, str8);
	std::cout << str8;

	return 0;
}