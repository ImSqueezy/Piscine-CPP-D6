#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string.h>
# include <iomanip>
# include <limits.h>

enum StrType {
    TYPE_INT,
	TYPE_CHAR,
    TYPE_FLOAT,
    TYPE_DOUBLE,
	TYPE_PL,
    TYPE_INVALID
};

class ScalarConverter
{
	public:

		ScalarConverter() = delete;
		~ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& other) = delete;
		ScalarConverter& operator=(const ScalarConverter& other) = delete;

		static void convert(const std::string& str);
};

int		isPseudoLiteral(std::string str);
StrType	detectType(const std::string& str);
bool	hasMultiDecimals(std::string str);

#endif