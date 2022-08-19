#pragma once
#include <string>
#include "Categories.h"

class Categories
{
public:
	enum category
	{
		CASH,
		UTILITYBILLS,
		CREDITS,
		FOOD,
		AUTOMOBILE,
		ENTERTEIMENTS,
		EDUCATION,
		CLOTHES,
		RESTAURANTS,
		PRESENTS,
		HOBBY,
		APPLIANCES,
		OTHER
	};

	std::string getCategory(int category);
};

