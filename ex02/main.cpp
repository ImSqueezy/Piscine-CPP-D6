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

	std::cout << "\nTesting identify(Base* p)..." << std::endl;
	identify(p1);
	identify(p2);
	identify(p3);

	std::cout << "\nTesting identify(Base& p)..." << std::endl;
	if (p1)
		identify(*p1);
	if (p2)
		identify(*p2);
	if (p3)
		identify(*p3);

	delete p1;
	delete p2;
	delete p3;
	return 0;
}
