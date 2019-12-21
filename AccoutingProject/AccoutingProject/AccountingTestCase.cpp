#include "gtest/gtest.h"
#include <QString>
#include <QDate>
#include "MockBudgetRepo.h"
#include "Accounting.h"

using ::testing::_;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SaveArg;

class AccoutingTestCase : public testing::Test
{
protected:
	void SetUp() override {}

	void TearDown() override {}
};

Budget MyMethod(std::string date, int amount)
{
	Budget test1;
	test1.yearMonth = date;
	test1.amount = amount;
	return test1;
}

TEST_F(AccoutingTestCase, Find_Whole_Month)
{
	auto mockRepo = new MockBudgetRepo();

	auto testData = std::vector<Budget>();
	testData.push_back(MyMethod("201901", 31));
	testData.push_back(MyMethod("201902", 280));
	testData.push_back(MyMethod("201903", 3100));

	mockRepo->setBudget(testData);

	Accounting accounting(mockRepo);

	auto budget = accounting.queryBudget(QDate(2019, 01, 01), QDate(2019, 01, 31));

	ASSERT_EQ(budget, 31);
}

TEST_F(AccoutingTestCase, Find_Two_Month)
{
	auto mockRepo = new MockBudgetRepo();

	auto testData = std::vector<Budget>();
	testData.push_back(MyMethod("201901", 31));
	testData.push_back(MyMethod("201902", 280));
	testData.push_back(MyMethod("201903", 3100));

	mockRepo->setBudget(testData);

	Accounting accounting(mockRepo);

	auto budget = accounting.queryBudget(QDate(2019, 01, 01), QDate(2019, 02, 28));

	ASSERT_EQ(budget, 311);
}

TEST_F(AccoutingTestCase, Find_Partial_Month)
{
	auto mockRepo = new MockBudgetRepo();

	auto testData = std::vector<Budget>();
	testData.push_back(MyMethod("201901", 31));
	testData.push_back(MyMethod("201902", 280));
	testData.push_back(MyMethod("201903", 3100));

	mockRepo->setBudget(testData);

	Accounting accounting(mockRepo);

	auto budget = accounting.queryBudget(QDate(2019, 01, 01), QDate(2019, 01, 15));

	ASSERT_EQ(budget, 15);
}

TEST_F(AccoutingTestCase, Find_Partial_CrossingMonth)
{
	auto mockRepo = new MockBudgetRepo();

	auto testData = std::vector<Budget>();
	testData.push_back(MyMethod("201901", 31));
	testData.push_back(MyMethod("201902", 280));
	testData.push_back(MyMethod("201903", 3100));

	mockRepo->setBudget(testData);

	Accounting accounting(mockRepo);

	auto budget = accounting.queryBudget(QDate(2019, 01, 31), QDate(2019, 03, 01));

	ASSERT_EQ(budget, 381);
}
