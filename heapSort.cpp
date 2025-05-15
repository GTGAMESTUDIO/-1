#include <iostream>
using namespace std;
  
void heapify(int list[], int listLength, int root)
{
	int largest = root;
	int l = 2*root + 1;
	int r = 2*root + 2;
	  
	if (l < listLength && list[l] > list[largest])
		largest = l;
	  
	if (r < listLength && list[r] > list[largest])
		largest = r;

	if (largest != root)
	{
		swap(list[root], list[largest]);
		heapify(list, listLength, largest);
	}
}
  
void heapSort(int list[], int listLength)
{
	for(int i = listLength / 2 - 1; i >= 0; i--)
		heapify(list, listLength, i);
	 
	for(int i = listLength - 1; i >= 0; i--)
	{
		swap(list[0], list[i]);
		heapify(list, i, 0);
	}
}
  
int main()
{
	int list[5] = {3,19,8,0,48};
	cout<<"Input array ..."<<endl;
	for(int i = 0; i < 5; i++)
		cout << list[i] << '\t';
	cout << endl;
	
	heapSort(list, 5);
	
	cout << "Sorted array"<<endl;
	for(int i = 0; i < 5; i++)
		cout << list[i] << '\t';
	cout << endl;
}
