#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void PieSort(vector<int> &ivec)
{
	cout<<"Input vector:";
	for(auto i : ivec)
		cout<< i<<" ";
	cout<<endl;
	int reverse_times=0;
	vector<int>::iterator it=ivec.begin(), it_reverse_last=ivec.end();
	vector<int>::iterator it_search_last=it_reverse_last;
	vector<int>::iterator it_reverse_first=it;
	//int cnt=0;
	while(it<it_search_last)
	{
		vector<int>::iterator max_it=max_element(it, it_search_last);
		if(it_search_last-it==1)//there is only one element in the range
		{
			if(it_search_last!=ivec.end())//array is in ascending order
			{

				reverse(it_reverse_first,ivec.end());
				++reverse_times;
			}
			++it;
		}
		else if(max_it!=it_search_last-1) //max is not at the end of search range
		{
			if(it_search_last!=ivec.end())//there is  sorted tail part

			{
				reverse(it_reverse_first, ivec.end());//move sorted tail part to bottom
				++reverse_times;
				it_reverse_first+=(ivec.end()-it_search_last);
				it=it_reverse_first;//set new search head	
				it_search_last=ivec.end();//reset end of search range			
			}
			else if(max_it==it)//max is at the head of search range
			{
				++it_reverse_first;//the first ones are already in right position
				++it;
			}
			else//max is within the search range
			{
				//move max to tail/(top of heap)
				reverse(max_it, ivec.end());
				++reverse_times;
			}
		}
		else if(max_it==it_search_last-1)//max is at the tail of search range, the tail part is already in ascending order
		{
			--it_search_last; 
		}
	}
	cout<<"reverse times:"<<reverse_times<<endl;
	cout<<"Output vector:";
	for(auto i : ivec)
		cout<< i<<" ";
	cout<<endl;
}

int main()
{
	//cout<<"Please input integers to sort:"<<endl;
	cout<<"output is"<< endl;
	//int value;
	//while(cin>>value)
	//	ivec.push_back(value);
	vector<int> ivec{1,2,3,4,5};
	PieSort(ivec);
	vector<int> ivec2{5,4,3,2,1};
	PieSort(ivec2);
	vector<int> ivec3{1,2,4,3,5};
	PieSort(ivec3);
	vector<int> ivec4{1,2,3,5,4};
	PieSort(ivec4);
	vector<int> ivec5{3,2,1,6,5,4,9,8,7,0};
	PieSort(ivec5);
}
