#include "Serializer.hpp"

int main() {
	Data data;

	data.number = 42;
	data.letter = 'A';

	std::cout << "Original Data address: " << &data << std::endl;
	std::cout << "Original Data: " << data.number << ", " << data.letter << std::endl;

	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "Serialized value: " << serialized << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized Data: " << deserialized->number << ", " << deserialized->letter << std::endl;

	if (deserialized == &data) {
		std::cout << "SUCCESS: Pointers match!" << std::endl;
		std::cout << "Deserialized address: " << deserialized << std::endl;
    } else {
		std::cout << "ERROR: Pointers don't match!" << std::endl;
		std::cout << "Deserialized address: " << deserialized << std::endl;
	}
	return 0;
}