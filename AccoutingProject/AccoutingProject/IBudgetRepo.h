#pragma once
#include "Budget.h"
#include <vector>

class IBudgetRepo
{
public:
	virtual std::vector<Budget> getAll() = 0;
};
