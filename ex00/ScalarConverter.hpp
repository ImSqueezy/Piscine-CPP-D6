#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string.h>
# include <iomanip>

enum NumType {
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

		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);

		static void convert(const std::string& str);
};

NumType	detectNumberType(const std::string& str);
bool	hasMultiDecimals(std::string str);

#endif