#include "Base.hpp"
#include "ADerived.hpp"
#include "CDerived.hpp"
#include "BDerived.hpp"

Base* generate(void) {
	int randNum = std::rand() % 3;
	
	switch (randNum) {
		case 0:
			std::cout << "Generated class A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generated class B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generated class C" << std::endl;
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p) {
	(void)p;
}

void identify(Base& p) {
	(void)p;
}