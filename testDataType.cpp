// this cpp file is to test the standard data types 
// it include int [], vector,list , stack , deque , queue, set and map
// i will also check out the performance of each by push and pop 1 million random int.
//

#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<deque>
#include<queue>
#include<ctime>
#include<cstdlib>
using namespace std;

// total 1 million run per test
// time does not include declaration

#define R10M 1000000
#define RAND 10000  //10thousand random int




// Array is dynamic and system allocating, so once become big, will crash
void testIntArray()
{

	srand(time(nullptr));
	time_t  start, end;
	int*Array=new int [R10M];

	start = clock();
	for (long i = 0; i < R10M; i++)
	{
		Array[i] = rand() % RAND;
	}
	end = clock();

	cout << "Fill 10 million random number in to Arran" << endl;
	cout << "Total time took\t" << (end - start) << "\tms" << endl;
	cout << "sizeof(Array)\t" << sizeof(Array) << endl;
	cout << "Above is wrong, can not use sizeof() for pointer type array" << end;
	delete[]Array;
}

void testVector()
{
	time_t start, end;
	vector<int> V1;
	cout << "start Push_back\n" << endl;
	start = clock();
	for (int i = 0; i < R10M; i++)
	{
		V1.push_back(i);
	}
	end = clock();
	cout << "finish Push_back()" << endl;
	int temp = end - start;
	int size = sizeof(V1);
	cout << "start pop_back()" << endl;
	start = clock();
	for (int i = 0; i < R10M; i++)
	{
		V1.pop_back();
	}
	int temp2 = clock() - start;
	cout << "pop_back completed" << endl;
	cout << " 10 million random number in to Vector" << endl;
	cout << "Total time push_back\t" << temp << "\tms" << endl;
	cout << "Total time pop_back\t" << temp2 << "\tms" << endl;
	cout << "sizeof(V1)\t" << size << endl;
	cout << "length of V1\t" <<size/sizeof(int)<< endl;

}









int main()
{
	cout << "start testing Array // int * Array = new Array[100.......]\n" << endl;
	testIntArray();
	cout << "start testing Vector\n" << endl;
	testVector();
	system("pause");
	return 0;

}
