#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Constructor called!" << std::endl;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

void handlePseudoLiteral(std::string str) {
	(void)str;
	std::cout << "In handle pseudo literal" << std::endl;
}

void	convertChar(std::string str) {
	char	type;

	type = str[0];
	std::cout << "char: ";
	if (!std::isprint(type))
		std::cout << "Non Displayable\n";
	else
		std::cout << "'" << type << "'\n";
	std::cout << "int: " << static_cast<int>(type) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(type) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(type) << "d" << std::endl;
}
			
void	convertInt(std::string str) {
	int		type;

	type = std::atoi(str.c_str());
	std::cout << "char: ";
	if (type < 0 || type > 127)
		std::cout << "Impossible\n";
	else if (!std::isprint(type))
		std::cout << "Non Displayable\n";
	else
		std::cout << "'" << static_cast<char>(type) << "'\n";
	if (type == INT_MIN || type == INT_MAX)
		std::cout << "int: Impossible\n";
	else
		std::cout << "int: " << type << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(type) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(type) << "d" << std::endl;
}			

void ScalarConverter::convert(const std::string& str)
{
	StrType type = detectType(str);

	switch (type)
	{
		case TYPE_INVALID:
			std::cout << "Invalid Type!\n";
			break;
		case TYPE_INT:
			convertInt(str);
			break;
		case TYPE_FLOAT:
			/* code */
			break;
		case TYPE_DOUBLE:
			/* code */
			break;
		case TYPE_CHAR:
			convertChar(str);
			break;
		case TYPE_PL:
			break;
	
		default:
			break;
	}
}