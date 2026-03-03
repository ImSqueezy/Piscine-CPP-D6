#include "Base.hpp"

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

int main() {
	std::srand(std::time(0));

	std::cout << "Testing generate()..." << std::endl;
	Base* p1 = generate();
	Base* p2 = generate();
	Base* p3 = generate();

	delete p1;
	delete p2;
	delete p3;
	return 0;
}
