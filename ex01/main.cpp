#include "Serializer.hpp"
#include <iostream>

void    printData(Data *ptr)
{
    std::cout << BLUE << ptr->_name << CYAN << " is a " << ptr->_class << " of level " << ptr->_level << NC << std::endl;
}

int main()
{
	Data        *data;
	uintptr_t   sData;
	Data        *dData;
    
    data = new Data;
    data->_name = "Chaku";
    data->_class = "warrior";
    data->_level = 42;

    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "- Original pointer:     " << GREEN << data << NC << std::endl;
    printData(data);
    sData = Serializer::serialize(data);
    std::cout << "- Serialized pointer:   " << GREEN << sData << NC << std::endl;
    dData = Serializer::deserialize(sData);
    std::cout << "- Deserialized pointer: " << GREEN << dData << NC << std::endl;
    printData(dData);
    std::cout << "------------------------------------------------" << std::endl;
    delete (data);
    
    return (0);
}