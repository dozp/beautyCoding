#include "pie_sort.h"
#include "gtest/gtest.h"
using namespace std;
TEST(PieSortTest, NoReverse)
{
	int act_time=0, exp_time=0;
	vector<int> ivec={1,2,3,4,5};
	vector<int> exp_ivec={1,2,3,4,5};
	act_time=PieSort(ivec);
	ASSERT_TRUE(ivec==exp_ivec);
	EXPECT_EQ(act_time, exp_time);
}
