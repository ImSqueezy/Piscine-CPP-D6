#ifndef EX01_EXERCISE01_HPP
#define EX01_EXERCISE01_HPP

#include <iostream>
#include <cstdint>

struct Data {
    int number;
    char letter;
};

class Serializer {
	public:
		Serializer() = delete;
		Serializer(const Serializer& other) = delete;
		Serializer& operator=(const Serializer& other) = delete;
		~Serializer() = delete;

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif // EX01_EXERCISE01_HPP
