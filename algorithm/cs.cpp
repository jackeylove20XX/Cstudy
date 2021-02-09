#include<iostream>
#include<vector>

using namespace std;

void count_sort(vector<int>&v,int k)
{
	int max_v = INT_MIN;
	
	for (int i = 0; i < k; i++)  //get max value
	{
		if (v[i] > max_v)
		{
			max_v = v[i];
		}
	}

	vector<int>b(max_v+1,0);

	for (int i = 0; i <k; i++)   //count
	{
		b[v[i]]++;
	}

	/*for (int i=1;i<=max_v;i++)
	{
		b[i] += b[i - 1]; 
	}*/

	int l = 0,r=0;
	while(l<=max_v)
	{
		if (b[l] != 0)
		{
			v[r] = l;
			r++;
			b[l]--;
		}
		else
		{
			l++;
		}

	}

}


int main()
{
	vector<int> v = { 2,5,3,0,2,3,0,3 };
	int n = v.size();
	count_sort(v,n);

	for (int i = 0; i < n; i++)
	{
		cout << v[i] ;
	}
	cout << endl;

	system("pause");
}