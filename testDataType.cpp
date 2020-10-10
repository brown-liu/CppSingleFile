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
#include<chrono>
using namespace std;

// total 1 million run per test
// time does not include declaration

#define R10M 10000000 //10million
#define RAND 10000  //10thousand random int


typedef chrono::duration<double> Duration;
typedef chrono::high_resolution_clock Clock;

// Array is dynamic and system allocating, so once become big, will crash
void testIntArray()
{
	
	srand(time(nullptr));

	int*Array=new int [R10M];

	auto start = chrono::high_resolution_clock::now();
	for (long i = 0; i < R10M; i++)
	{
		Array[i] = rand() % RAND;
	}
	auto end = chrono::high_resolution_clock::now();

    chrono::duration <double> diff =end -start;
	cout << "Fill 10 million random number in to Array" << endl;
	cout << "Total time took\t" << diff.count() << "\ts" << endl;
	cout << "sizeof(Array)\t" << sizeof(Array) << endl;
	cout << "Above is wrong, can not use sizeof() for pointer type array\n" << endl;
	delete[]Array;
}

void testVector()
{
	vector<int> V1;
	cout << "start Push_back" << endl;
	
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < R10M; i++)
	{
		V1.push_back(i);
	}
	auto end = chrono::high_resolution_clock::now();
	
	cout << "finish Push_back()" << endl;
	chrono::duration<double> temp = end - start;
	
	int size = V1.size();
	cout << "start pop_back()" << endl;
	
	auto start2 = chrono::high_resolution_clock::now();
	for (int i = 0; i < R10M; i++)
	{
		V1.pop_back();		
	}
	chrono::duration <double> temp2 = chrono::high_resolution_clock::now()-start2;
	cout << "start push_back(rand()%xxx)"<<endl;
	auto start3=chrono::high_resolution_clock::now();
	int count =0;
	for(int i=0; i<R10M;i++)
	{
		int temp0 = rand()%RAND;
		V1.push_back(temp0);
		count++;
	}	
	chrono::duration<double> temp3 =chrono::high_resolution_clock::now()-start3;
	cout << "pop_back completed" << endl;
	cout << "10 million random number in to Vector" << endl;
	cout << "Total time push_back\t" << temp.count() << "  s" << endl;
	cout << "Total time pop_back\t" << temp2.count() << "  s" << endl;
	cout << "Total time push random\t" <<temp3.count() <<"  s" <<endl;
	cout << "V1.size()\t" << size << endl;
	cout << "Count = " <<count <<endl;
	cout << "V1.capacity()\t" << V1.capacity()<< endl;
}

void testSet()
{
	typedef chrono::high_resolution_clock Clock;	
	typedef chrono::duration<double> Duration;
	set<int> S1;

	cout <<"set will auto sort"<<endl;
	cout << "start Push_back\n" << endl;

	auto start = Clock::now();
	int count=0;
	for (int i = 0; i < R10M; i++)
	{
		int temp = rand()%RAND; 
		S1.insert(temp);
		count++;
	}
	auto end =Clock::now();
	cout << "finish insert" << endl;
	Duration temp = end -start;
	int size = S1.size();
	cout << "start iteration to erase" << endl;
	start = Clock::now();
	int count2=0;
	for (set<int>::iterator it= S1.begin();it!=S1.end();it++)
	{
		S1.erase(it);
		count2++;
	}
	Duration temp2 = Clock::now() - start;
	cout << "pop_back completed" << endl;
	cout << "10 million random number in to set" << endl;
	cout << "Total time insert\t" << temp.count() << "  s" << endl;
	cout << "Total time erase(iterator)\t" << temp2.count() << "  s" << endl;
	cout << "S1.size()\t" << size << endl;
	cout << "actual count\t"<<count<<"\ttimes |  and total erasing " <<count2 <<"\ttimes"<<endl;
}

void testList()
{
	typedef chrono::high_resolution_clock Clock;
	typedef chrono::duration<double> Duration;

	cout << "list1 only declare not initalized, list2 && list3 initalized (R10M, 0 ) on declaration"<<endl;
	list<int> list1;
	list<int >list2(R10M,0);
	list<int> list3(list2);
	cout<< "list1 add element using push_back" <<endl;
	auto start = Clock::now();
	for (int i =0;i<R10M;i++)
	{
	int temp = rand()%RAND;
	list1.push_back(temp);
	}
	auto end = Clock::now();
	Duration temp1 = end -start;

	cout <<"list2 add element using push_back & push_front together" <<endl;
	start = Clock::now();
	for (int i =0;i<R10M/2;i++)
	{
	int temp = rand()%RAND;
	int temp2 = rand()%RAND;

	list2.push_front(temp);
	list2.push_back(temp2);
	}
	end = Clock::now();
	Duration temp2 = end -start;	
	
	cout << "list3 add element using pointer" <<endl;
	start = Clock::now();
	int count =0;
	for (list<int>::iterator it= list3.begin(); it != list3.end();it ++)
	{
		*it = rand()%RAND;
		count ++;
	}
	
	end =Clock::now();
	Duration temp3 = end - start;
	cout << "capacity or list1 ** list2 ** list3  "<<list1.size() <<"  **  " <<list2.size()<<"  **  " <<list3.size()<<endl;
	cout << "list1 without initialzation at decalration time spend to push BACK\t"<< temp1.count()<<endl;
	cout << "list2 initilzation at delcaration time spend to push FRONT and BACK\t"<<temp2.count()<<endl;
	cout << "list3 initilzed and used pointer to pushback\t" << temp3.count() <<endl;
	cout << "list3 count   "<<count <<endl;
	
}


void testStack ()
{
typedef chrono::high_resolution_clock Clock;
typedef chrono::duration<double> Duration;
 stack<int>  st1;
cout << "declared 1 stacks, start to push to st1 " <<endl;
 auto start = Clock::now();
 for (int i =0;i<R10M;i++)
 {
	 st1.push(rand()%RAND);
 }
 stack <int> st2 (st1);

 auto end = Clock::now();
 Duration temp = end -start;
 cout <<"start to pop" <<endl;
 start =Clock::now();
 for (int i =0; i<R10M;i++)
 {
	 st1.pop();
 }
 end =Clock::now();
 Duration temp2= end -start;
cout <<"time spend push" <<temp.count() <<endl;
cout << "time spend pop" <<temp2.count() <<endl;

}

void testQueue()
{
	typedef chrono::high_resolution_clock Clock;
	typedef chrono::duration<double> Duration;
	queue<int >Q1;
	cout <<"Created Q1"<<endl;
	auto start =Clock::now();
	for (int i =0;i<R10M;i++)
	{
		Q1.push(rand()%RAND);
	}
	auto end= Clock::now();
	Duration temp =end -start;
	start = Clock::now();
	for (int i =0;i<R10M;i++)
	{
		Q1.pop();
	}
	end =Clock::now();
	Duration temp2 = end -start;
	cout <<"Queue push take time  "<< temp.count()<<endl;
	cout <<"Queue pop take time  "<< temp2.count()<<endl;
		
	
}

void testDeque()
{

deque<int> d1;
deque <int> d2;
cout << "deque d1, start to push back and front"<<endl;
auto start = Clock::now();
int count=0;
for (int i=0;i<R10M/2;i++)
{
	int temp = rand()%RAND;
	d1.push_back(temp);
	count ++;
	d1.push_front(temp);
	count ++;
}
auto end =Clock::now();
Duration temp = end -start;
cout << "d2 start to normal push_back"<<endl;
start = Clock::now();
int count2=0;
for (int i=0;i<R10M;i++)
{
	int temp = rand()%RAND;
	d2.push_back(temp);
	count2++;
}
end =Clock::now();
Duration temp2 = end -start;
cout << "using both push_back and push_front. time: "  <<temp.count() <<endl;
cout << "using only push front. time :   " <<temp2.count() <<endl;
cout << "d1.size() = >" << d1.size() <<endl;
cout << "d2.size() =>" << d2.size() <<endl;
cout << "actual count on d1:  "<< count << "  and on d2:  " << count2 <<endl;

}

void testMap()
{
cout << "start to test map, 2 map created, mfloat<float,float> ,mint <int,int> "<<endl;
map<float, float > mfloat;
map<int,int >mint;
auto start = Clock::now();
for (int i =0;i<R10M;i++)
{
mfloat.insert(make_pair(i,i*0.5));
}
auto end = Clock::now();
Duration temp =end -start;
start =Clock::now();
for (int i =0;i<R10M;i++)
{
	mint.insert(make_pair(i,i+10000));
}
end =Clock::now();
Duration temp2 = end -start ;
cout << " integer key and value insert" << temp.count() <<endl;
cout << " float key and value insert" << temp2.count() <<endl; 
cout << " mfloat size  " << mfloat.size() <<"  *** mint  "<< mint.size()<<endl;
}

int main()
{
	system("clear");
	cout<<"\n";
	cout<< "**********************************************************************" <<endl;
	cout << "start testing Array // int * Array = new Array[100.......]\n" << endl;
	testIntArray();
		cout<< "**********************************************************************" <<endl;
	cout << "\nstart testing Vector\n" << endl;
	testVector();
	cout<< "**********************************************************************" <<endl;
	cout <<"\nstart testing Set\n" <<endl;
	testSet();
	cout<< "**********************************************************************" <<endl;
	cout <<"\n start testing List \n" <<endl;
	testList();
	cout<< "**********************************************************************" <<endl;
	cout <<"\nstart testing Queue \n" <<endl;
	testQueue();
	cout<< "**********************************************************************" <<endl;
	cout <<"\nstart testing Deque \n" <<endl;
	testDeque();
	cout<< "**********************************************************************" <<endl;
	cout <<"\nstart testing Map \n" <<endl;
	testMap();


	
	
	
	
	
	system("pause");

	return 0;

}
