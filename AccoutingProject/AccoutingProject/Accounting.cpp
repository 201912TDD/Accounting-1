#include "Accounting.h"
#include "IBudgetRepo.h"

Accounting::Accounting(IBudgetRepo *budgetRepo)
{
	m_repo = budgetRepo;

	//
	for (auto &b: m_repo->getAll())
	{
		QDate aaa = QDate::fromString(, QString("yyyyMM"));

		bugetDB.insert(std::make_pair(b.yearMonth, b.amount));
	}
}

double Accounting::queryBudget(QDate start, QDate end)
{
	int sum = 0;

	for (auto month = start; month <= end; month = month.addMonths(1))
	{
		if (bugetDB.find(month.toString("yyyyMM").toStdString()) != bugetDB.end())
		{
			sum += bugetDB[month.toString("yyyyMM").toStdString()];
		}
	}

	if (start.toString("yyyyMM") == end.toString("yyyyMM"))
	{
		auto stDay = start.toString("dd").toInt();
		auto edDay = end.toString("dd").toInt();
		double _amount = bugetDB[start.toString("yyyyMM").toStdString()] / 31;
		sum = _amount * (edDay - stDay + 1);
	}
	return sum;
}
