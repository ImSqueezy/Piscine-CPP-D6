#include "ScalarConverter.hpp"

// int main(int ac, char **av) {
// 	if (ac != 2) {
// 		std::cout << "The program takes only two params!" << std::endl;
// 		return 0;	
// 	}
// 	ScalarConverter::convert(av[1]);
// 	return 0;
// }

int main()  {
    std::string tests[] = {"42", "-42", "+42", "42.0f", "42.0d", "3.14", 
                           "42f", "42.0", ".5", "0.5", "abc", "42f3"};
    
    for (const auto& str : tests) {
        NumType type = detectNumberType(str);
        std::cout << "\"" << str << "\" -> ";
        switch(type) {
            case TYPE_INT: std::cout << "INT"; break;
            case TYPE_FLOAT: std::cout << "FLOAT"; break;
            case TYPE_DOUBLE: std::cout << "DOUBLE"; break;
            case TYPE_INVALID: std::cout << "INVALID"; break;
        }
        std::cout << std::endl;
    }
    
    return 0;
}