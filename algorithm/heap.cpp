#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool com(int i,int j)
{
		  return (i > j);
};
	


vector<int> v = { 1,3,2,7,4,5,6 };

int left(int a)  
{
	return 2 * a+1;
}

int right(int a)
{
	return 2 * a+2;
}

void modify(vector<int>& v ,int a,int n)
{
	int l = left(a);
	int r = right(a);
	int largest = INT_MIN;
	
	if (l<n&&v[a]<v[l])
	{
		largest = l;
	}
	else
	{
		largest = a;
	}

	if (r < n && v[largest] < v[r])
	{
		largest = r;
	}

	//cout << largest << endl;

	if (a != largest)
	{
		int tmp = v[a];
		v[a] = v[largest];
		v[largest] = tmp;

		modify(v, largest,n);
	}
	else
	{
		return;
	}

	/*for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	cout << endl;*/
}

void build(vector<int>& v,int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)    //from bottom to top
	{
		modify(v, i,n);  
	}
}



int main()
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	cout << endl;

	/*modify(v, 2);
	cout << endl;

	modify(v, 1);
	cout << endl;

	modify(v, 0);*/

	build(v, v.size());

	for (int i=v.size()-1;i>=1;i--)
	{
		swap(v[i], v[0]);
		modify(v, 0, i);
	}
	

	priority_queue<int,vector<int>,greater<int> >a;
	priority_queue<int, vector<int>,less<int> >b;
	sort(v.begin(), v.end(), com);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	cout << endl;

	system("pause");
}

