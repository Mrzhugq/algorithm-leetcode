#include<iostream>
using namespace std;

//函数模板案例-排序


//交换 
template<typename T>
void MySwap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
} 

//选择排序 (降序) 
template<typename T>
void MySort(T* arr, int Size)
{
	for(int i=0; i<Size; i++)
	{
		int Max = i;
		for(int j=i+1; j<Size; j++)
		{
			if(arr[j] > arr[Max])
			{
				Max = j;
			}
		}
		if(Max != i)
		{
			MySwap(arr[Max],arr[i]);
		}
	}
} 

//打印模板 
template<typename T>
void MyPrint(T* arr, int Size)
{
    for(int i=0; i<Size; i++)
	{
		cout << arr[i] << " "; 
	}
	cout << endl;
}

int main()
{
	char ch[] = "fdera";
	int Size = sizeof(ch)/sizeof(ch[0]);
	MySort(ch,Size);
	MyPrint(ch,Size); 
	
	int arr[] = {2,6,4,1,8,6,0}; 
	Size = sizeof(arr)/sizeof(arr[0]);
	MySort(arr,Size);
	MyPrint(arr,Size); 
	return 0;
}

