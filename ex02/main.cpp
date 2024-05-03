#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "D.hpp"
#include <iostream>
#include <cstdlib>

Base *generate(void) 
{
	std::srand(time(0));
	int i = rand() % 3 + 1;
    if (i == 1)
    {
        std::cout << "- Generated:  " << GREEN << "A class" << NC << std::endl;
        return (new A);
    }
    else if (i == 2)
    {
        std::cout << "- Generated:  " << GREEN << "B class" << NC << std::endl;
        return (new B);
    }
    std::cout << "- Generated:  " << GREEN << "C class" << NC << std::endl;
    return (new C);
}

void identify(Base *p) 
{
	if (dynamic_cast<A *>(p)) 
        std::cout << "- Identified: " << GREEN << "A class" << NC << std::endl;
	else if (dynamic_cast<B *>(p)) 
        std::cout << "- Identified: " << GREEN << "B class" << NC << std::endl;
	else if (dynamic_cast<C *>(p)) 
        std::cout << "- Identified: " << GREEN << "C class" << NC << std::endl;
	else 
        std::cout << "- Identified: " << RED << "another class" << NC << std::endl;
}

void identify(Base& p) 
{
	try 
	{
		A &tmp = dynamic_cast<A &>(p);
        std::cout << "- Identified: " << GREEN << "A class" << NC << std::endl;
        (void)tmp;
		return ;
	} 
	catch (...) {}
	try 
	{
		B &tmp = dynamic_cast<B &>(p);
        std::cout << "- Identified: " << GREEN << "B class" << NC << std::endl;
        (void)tmp;
		return ;
	} 
	catch (...) {}
	try 
	{
		C &tmp = dynamic_cast<C&>(p);
        std::cout << "- Identified: " << GREEN << "C class" << NC << std::endl;
        (void)tmp;
		return ;
	} 
	catch (...) {}
    std::cout << "- Identified: " << RED << "another class" << NC << std::endl;
}

int main()
{
    Base *base;
    
    std::cout << "------------------------------------------------" << std::endl;
    base = generate();
    identify(base);
    identify(*base);
    delete (base);
    std::cout << "------------------------------------------------" << std::endl;
    base = new D;
    std::cout << "- Created:    " << GREEN << "D class" << NC << std::endl;
    identify(base);
    identify(*base);
    delete (base);
    std::cout << "------------------------------------------------" << std::endl;
 
    return (0);
}