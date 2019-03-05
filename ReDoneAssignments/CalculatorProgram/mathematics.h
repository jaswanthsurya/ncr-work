#pragma once
#ifndef MATHEMATICS_H
#define MATHEMATICS_H
#include <iostream>
class Mathematics
{
	int result;
public:
	int add(int num1, int num2);
	int sub(int num1, int num2);
	int mul(int num1, int num2);
	int div(int num1, int num2);
};
#endif