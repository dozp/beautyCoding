#include "pie_sort.h"


int PieSort(vector<int> &ivec)
{
	
	int reverse_times=0;
	// each pie is considered as an element in vector
	// the bottom pie is v[0], larger index is at upper layer
	// the indexes is divided into 3 parts
	// 0, 1, 2,..., n1 | n2, n2+1, ..., n3 | n4,...n
	// |--range1--------|-----range2--------|---range3--|
	//  b0		     b1			 b2	     b3
	// range1: in Descending order
	// range2: unsorted
	// range3: in ascending order
	// for example: 10,9,8|0,4,3,2|6,7
	// range1[i]>range3[j]>range2[k]
	vector<int>::iterator b0, b1, b2, b3;
	b0=b1=ivec.begin();
	b2=b3=ivec.end();

	while(b1<b3-1)
	{
		vector<int>::iterator r2_max_it=max_element(b1, b2);
		if(r2_max_it==b1)	//max is at the head of r2
		{
			if(b2==b3)
			{
				++b1;	//transplant max from r2 to r1
			}
			else
			{
				reverse(b1, b3);
				reverse_times++;
				size_t r3_len=b3-b2;
				b1+=r3_len;
				b2=b3;	//empty r3
			}
		}
		else if(r2_max_it==b2-1)	//max is at end
		{
			// transplant max from r2 to r3
			--b2;
		}
		else //max is in the middle	
		{
			if(b2<b3)	// r3 is not empty
			{
				// reverse r3 to r1
				reverse(b1, b3);
				reverse_times++;
				size_t r3_len=b3-b2;
				b1+=r3_len;
				b2=b3;	//empty r3
			}
			else
			{
				// move max to the end
				reverse(r2_max_it, b3);
				++reverse_times;
				--b2;
			}
		}
	}
	return reverse_times;
}

