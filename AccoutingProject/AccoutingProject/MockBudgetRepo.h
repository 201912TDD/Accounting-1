#pragma once
#include "IBudgetRepo.h"
#include "gmock/gmock.h"
#include "Budget.h"

class MockBudgetRepo : public IBudgetRepo
{
public:
	void setBudget(std::vector<Budget> testBudget);
	std::vector<Budget> getAll() override;

private:
	std::vector<Budget> m_mockData;
};

void MockBudgetRepo::setBudget(std::vector<Budget> testBudget)
{
	m_mockData = testBudget;
}

std::vector<Budget> MockBudgetRepo::getAll()
{
	return m_mockData;
}
