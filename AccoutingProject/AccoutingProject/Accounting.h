#pragma once
#include "IBudgetRepo.h"
#include "QDateTime"

#include <map>

class Accounting
{
public:
	Accounting(IBudgetRepo *budgetRepo);

	~Accounting() = default;

protected:
private:
	IBudgetRepo *m_repo;
	std::map<std::string, int> bugetDB;

public:
	double queryBudget(QDate, QDate);
};
