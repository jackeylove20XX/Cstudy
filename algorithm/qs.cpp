#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int partition(int a[], int l, int r)
{
	int cur = l;
	l++;

	while (l <= r)
	{
		while (l <= r && a[r] >= a[cur])
		{
			r--;
		}
		while (l <= r && a[l] < a[cur])
		{
			l++;
		}
		swap(a[l], a[r]);
	}
	swap(a[l], a[r]);
	swap(a[cur], a[r]);

	return l;
}

void qs(int a[], int l, int r)
{
	if (l >= r) { return; }
	int k = partition(a, l, r);
	qs(a, l, k - 1);
	qs(a, k, r);

}

void summ(int a[], int l, int mid, int r)
{
	int *arr = new int[r - l + 1];
	int i = 0, s = l, e = mid + 1;

	for (; s <= mid && e <= r;)
	{
		if (a[s] < a[e])
		{
			arr[i++] = a[s++];
		}
		else
		{
			arr[i++] = a[e++];
		}
	}
	for (; s <= mid;)
	{
		arr[i++] = a[s++];
	}
	for (; e <= r;)
	{
		arr[i++] = a[e++];
	}

	for (int j = l, i = 0; j <= r; j++)
	{
		a[j] = arr[i++];
		//cout << a[j] << "  ";
	}

	//cout << endl;

	free(arr);
}

void merge(int a[], int l, int r)
{
	if (r - l < 1) { return; }
	int mid = (l + r) / 2;
	//cout << mid << endl;
	merge(a, l, mid);
	merge(a, mid + 1, r);
	summ(a, l, mid, r);
}



int main()
{
	int a[8] = { 3,4,6,1,5,2,3,2 };
	merge(a, 0, 7);
	for (int i = 0; i < 8; i++)
	{
		cout << a[i] << "  ";
	}

	system("pause");
}