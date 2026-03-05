#include "ScalarConverter.hpp"

void handlePseudoLiteral(std::string str) {
	(void)str;
	std::cout << "In handle pseudo literal" << std::endl;
}

static void	convertChar(std::string str) {
	char	type;

	type = str[0];
	std::cout << "char: ";
	if (!std::isprint(type))
		std::cout << "Non Displayable" << std::endl;
	else
		std::cout << "'" << type << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(type) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(type) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(type) << std::endl;
}

static long ft_atoi(const char *str)
{
    long num;
    int right_most;
    int sign;
    
    num = 0;
    sign = 1;
    if (*str == '+')
        str++;
    else if (*str == '-')
    {
        sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        right_most = (*str - '0') * sign;
        if (num > (INT_MAX / 10) || (num == (INT_MAX / 10) && right_most > 7))
            return (2147483648);
        if (num < (INT_MIN / 10) || (num == (INT_MIN / 10) && right_most < -8))
            return (2147483648);
        num = num * 10 + right_most;
        str++;
    }
    return (num);
}
			
static void	convertInt(std::string str) {
	int		type;

	type = ft_atoi(str.c_str());
	std::cout << "char: ";
	if (type < 0 || type > 127)
		std::cout << "Impossible" << std::endl;
	else if (!std::isprint(type))
		std::cout << "Non Displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(type) << "'" << std::endl;
	if ((int)type == INT_MIN || (int)type == INT_MAX)
		std::cout << "int: Impossible" << std::endl;
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
		std::cout << "Impossible" << std::endl;
	else if (!std::isprint(type))
		std::cout << "Non Displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(type) << "'" << std::endl;
	if ((int)type <= INT_MIN || (int)type >= INT_MAX)
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(type) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << type << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(type) << std::endl;
}

static void	convertDouble(std::string str) {
	double		type;

	type = std::atof(str.c_str());
	std::cout << "char: ";
	if (type < 0 || type > 127)
		std::cout << "Impossible" << std::endl;
	else if (!std::isprint(type))
		std::cout << "Non Displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(type) << "'" << std::endl;
	if ((int) type <= INT_MIN || (int)type >= INT_MAX)
		std::cout << "int: Impossible" << std::endl;
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
			std::cout << "Invalid Type!" << std::endl;
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