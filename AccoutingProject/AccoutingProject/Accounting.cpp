#include "Accounting.h"
#include "IBudgetRepo.h"

Accounting::Accounting(IBudgetRepo *budgetRepo)
{
	m_repo = budgetRepo;

	auto dayInMonth = std::vector<int> {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (auto &b: m_repo->getAll())
	{
		auto month = QString(b.yearMonth.c_str()).toInt() % 100;
		bugetDB.insert(std::make_pair(b.yearMonth, b.amount / dayInMonth[month]));
	}
}

double Accounting::queryBudget(QDate start, QDate end)
{
	int sum = 0;

	for (auto month = start; month <= end; month = month.addDays(1))
	{
		if (bugetDB.find(month.toString("yyyyMM").toStdString()) != bugetDB.end())
		{
			sum += bugetDB[month.toString("yyyyMM").toStdString()];
		}
	}
	return sum;
}
