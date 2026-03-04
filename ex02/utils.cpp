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
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "A" << std::endl;
		return;
	}
	if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "B" << std::endl;
		return;
	}
	if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "C" << std::endl;
		return;
	}
}

void identify(Base& p) {
	if (typeid(p) == typeid(A))
		std::cout << "A" << std::endl;
	else if (typeid(p) == typeid(B))
		std::cout << "B" << std::endl;
	else if (typeid(p) == typeid(C))
		std::cout << "C" << std::endl;
}