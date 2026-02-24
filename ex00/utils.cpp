#include "ScalarConverter.hpp"

bool	hasMultiDecimals(std::string str) {
	int	counter = 0;

	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == '.')
			counter += 1;
	}
	if (counter > 1)
		return true;
	return false;
}

StrType	detectType(const std::string& str) {
	int	len = str.length();

	if (len == 0 || hasMultiDecimals(str))
		return TYPE_INVALID;
	else if (len == 1)
		return TYPE_CHAR;
	std::string tmp = str.substr(0, len - 1);
	if (str[len - 1] == 'f' || str[len - 1] == 'F') {
		if (tmp.find_first_not_of("0123456789.+-") == std::string::npos)
			return TYPE_FLOAT;
		else {
			if (isPseudoLiteral(str))
				return TYPE_PL;
			else
				return TYPE_INVALID;
		}
		
	}
	else if (str[len - 1] == 'd' || str[len - 1] == 'D') {
		if (tmp.find_first_not_of("0123456789.+-") == std::string::npos)
			return TYPE_DOUBLE;
		else
			return TYPE_INVALID;
	}
	else {
		bool	hasDecimal = false;
		bool	hasDigit = false;

		for (int i = 0; i < len; i++) {
			if (i == 0 && (str[i] == '+' || str[i] == '-'))
				continue ;
			if (std::isdigit(str[i]))
				hasDigit = true;
			else if (str[i] == '.')
				hasDecimal = true;
			else
				return TYPE_INVALID;
		}
		if (!hasDigit) {
			if (isPseudoLiteral(str))
				return TYPE_PL;
			else
				return TYPE_INVALID;
		}
		return hasDecimal ? TYPE_DOUBLE : TYPE_INT;
	}
}

int isPseudoLiteral(std::string str) {
	
	if (str == "nan" || str == "nanf"
		||
		str == "-inf" || str == "-inff"
		||
		str == "+inf" || str == "+inff")
		return 1;
	return 0;
}