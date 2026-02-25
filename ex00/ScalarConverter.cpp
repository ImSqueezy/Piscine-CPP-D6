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

static void	convertChar(std::string str) {
	char	type;

	type = str[0];
	std::cout << "char: ";
	if (!std::isprint(type))
		std::cout << "Non Displayable\n";
	else
		std::cout << "'" << type << "'\n";
	std::cout << "int: " << static_cast<int>(type) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(type) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(type) << std::endl;
}
			
static void	convertInt(std::string str) {
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
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(type) << std::endl;
}			

static void	convertFloat(std::string str) {
	float		type;

	type = std::atof(str.c_str());
	std::cout << "char: ";
	if (type < 0 || type > 127)
		std::cout << "Impossible\n";
	else if (!std::isprint(type))
		std::cout << "Non Displayable\n";
	else
		std::cout << "'" << static_cast<char>(type) << "'\n";
	if (type <= INT_MIN || type >= INT_MAX)
		std::cout << "int: Impossible\n";
	else
		std::cout << "int: " << static_cast<int>(type) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << type << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(type) << std::endl;
}

static void	convertDouble(std::string str) {
	float		type;

	type = std::atof(str.c_str());
	std::cout << "char: ";
	if (type < 0 || type > 127)
		std::cout << "Impossible\n";
	else if (!std::isprint(type))
		std::cout << "Non Displayable\n";
	else
		std::cout << "'" << static_cast<char>(type) << "'\n";
	if (type <= INT_MIN || type >= INT_MAX)
		std::cout << "int: Impossible\n";
	else
		std::cout << "int: " << static_cast<int>(type) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(type) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << type << std::endl;
}

static void convertPl(const std::string& str)
{
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: Impossible" << std::endl;
    
    if (str == "nan" || str == "nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (str == "+inf" || str == "+inff") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (str == "-inf" || str == "-inff") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (str == "inf" || str == "inff") {
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
    }
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
			convertFloat(str);
			break;
		case TYPE_DOUBLE:
			convertDouble(str);
			break;
		case TYPE_CHAR:
			convertChar(str);
			break;
		case TYPE_PL:
			convertPl(str);
			break;
	
		default:
			break;
	}
}