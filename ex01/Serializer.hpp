#ifndef EX01_EXERCISE01_HPP
#define EX01_EXERCISE01_HPP

#include <iostream>

class Serializer {
public:
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();
};

#endif // EX01_EXERCISE01_HPP
