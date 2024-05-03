#pragma once

#include <string>
#include <stdint.h>

#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define VIOLET "\e[35m"
#define CYAN "\e[36m"
#define NC "\e[0m"

struct Data
{
    std::string _name;
    std::string _class;
    int         _level;
};

class Serializer
{
	public:
		~Serializer();
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
	private:
		Serializer();
		Serializer(Serializer const &other);
		Serializer &operator=(Serializer const &other);
};