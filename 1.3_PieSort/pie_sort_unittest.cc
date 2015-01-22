#include "pie_sort.h"
#include "gtest/gtest.h"
using namespace std;
TEST(PieSortTest, OneTimeReserse)
{
	int act_time=0, exp_time=1;
	vector<int> ivec={1,2,3,4,5};
	vector<int> exp_ivec={5,4,3,2,1};
	act_time=PieSort(ivec);
	EXPECT_EQ(exp_ivec,ivec);
	EXPECT_EQ(exp_time,act_time);
}
TEST(PieSortTest, NoReverse)
{
	int act_time=0, exp_time=0;
	vector<int> ivec={5,4,3,2,1};
	vector<int> exp_ivec={5,4,3,2,1};
	act_time=PieSort(ivec);
	EXPECT_EQ(exp_ivec,ivec);
	EXPECT_EQ(exp_time,act_time);
}
TEST(PieSortTest, test1)
{
	int act_time=0, exp_time=1;
	vector<int> ivec={5,4,3,1,2};
	vector<int> exp_ivec={5,4,3,2,1};
	act_time=PieSort(ivec);
	EXPECT_EQ(exp_ivec,ivec);
	EXPECT_EQ(exp_time,act_time);
}
TEST(PieSortTest, test2)
{
	int act_time=0, exp_time=2;
	vector<int> ivec={1,2,3,5,4};
	vector<int> exp_ivec={5,4,3,2,1};
	act_time=PieSort(ivec);
	EXPECT_EQ(exp_ivec,ivec);
	EXPECT_EQ(exp_time,act_time);
}
