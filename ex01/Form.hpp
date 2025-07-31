#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Form
{
private:
	const std::string _name;
public:
	Form();
	~Form();
	Form(const Form &source);
	Form &operator = (const Form &source);
};

#endif