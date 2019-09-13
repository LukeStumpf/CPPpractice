#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool f(int x, int y)
{
	return x > y;
}

void vectorDemo()
{
	vector<int> A = { 11,2,3,14 };

	cout << A[1] << endl;

	sort(A.begin(), A.end()); // O(NlogN)

	//2,3,11,14
	//O(logN)
	bool present = binary_search(A.begin(), A.end(), 3); //true
	present = binary_search(A.begin(), A.end(), 4); //false

	A.push_back(100);
	present = binary_search(A.begin(), A.end(), 100); //true

	//2,3,11,14,100
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	//2,3,11,14,100, 100, 100, 100, 100, 123
	A.push_back(123);

	auto it = lower_bound(A.begin(), A.end(), 100); // >=
	auto it2 = upper_bound(A.begin(), A.end(), 100); // >

	cout << *it << " " << *it2 << endl;
	cout << it2 - it << endl; //5

	sort(A.begin(), A.end(), f);

	for (int &x : A) // reference
	{
		x++;
	}
	for (int x : A)
	{
		cout << x << " ";
	}
	cout << endl;
}

void setDemo()
{
	set<int> S;
	S.insert(1); //O(logn)
	S.insert(2);
	S.insert(-1);
	S.insert(-10);

	for (int x : S)
		cout << x << " ";

	cout << endl;

	//-10 -1 1 2
	auto it = S.find(-1);
	if (it == S.end())
	{
		cout << "not present\n";
	}
	else {
		cout << "present\n";
		cout << *it << endl;
	}

	auto it2 = S.upper_bound(-1);
	auto it3 = S.upper_bound(0);
	cout << *it2 << " " << *it3 << endl;

	auto it4 = S.upper_bound(2);
	if (it4 == S.end())
	{
		cout << "oops! sorry cant find something like that\n";
	}
}

void mapDemo()
{
	map<int, int> A;
	A[1] = 100;
	A[2] = -1;
	A[3] = 200;
	A[100000232] = 1;

	map<char, int> cnt;
	string x = "rachit jain";

	for (char c : x) {
		cnt[c]++;
	}

	cout << cnt['a'] << " " << cnt['z'] << endl; //O(logn)
}

void PowerOfStl()
{
	// [x, y]
	/*add[2, 3]
		add[10, 20]
		add[30, 400]
		add[401, 450]
		give me the interval 401*/
	set< pair<int, int> > S;
	
	
	S.insert({ 401, 450 });
	S.insert({ 10, 20 });
	S.insert({ 2, 3 });
	S.insert({ 30, 400 });

	// 2, 3
	// 10, 20
	// 30, 400
	// 401, 450

	int point = 35;

	auto it = S.upper_bound({ point, INT_MAX });
	if (it == S.begin()) {
		cout << "the current point is not lying in any interval..\n";
		return;
	}

	it--;
	pair<int, int> current = *it;
	if (current.first <= point && point <= current.second)
		cout << "yes its present" << current.first << " " << current.second << endl;
	else
		cout << "the current point is not lying in any interval..\n";

}

void mapVsUnorderedMap() 
{
	map<char, int> M;
	unordered_map<char, int> U;

	string s = "Rachit Jain";
	//add(key, value) - logN, O(1)
	//erase(key) - logN, O(1)
	for (char c : s) M[c]++; //O(NlogN) N = |s|

	for (char c : s) U[c]++; // O(N)

}

int main()
{
	// HEAPS ------------------------------
	// use heaps to get max value of collection in little time
	vector<int> numbers;
	
	// converts collection into a heap
	std::make_heap(begin(numbers), end(numbers));
	
	numbers.push_back(8.88);

	// bubbles up value through a heap
	std::push_heap(begin(numbers), end(numbers));

	// max element of collection is the front
	// swaps front and back elemnts
	// can sort collection by calling pop_heap continuously 
	std::pop_heap(begin(numbers), end(numbers));
	// actually removes element from the back side
	numbers.pop_back();

	// SORTING --------------------------------
	std::sort();

	// sorts collection from beginning to point
	std::partial_sort();

	// to the left of the element, everything is unspecified
	// order but smaller, to the right unspecified order but larger
	std::nth_element();

	// repeadtedly calls pop_heap()
	std::sort_heap();

	// incremental step in a merge sort
	implace_merge();

	// PARTITIONING ---------------------------------------
	// putting all in one and the rest in another
	std::partition();

	// end of true range, beginning of false
	std::partition_point();

	// OTHER PERMUTATIONS ---------------------------------
	// brings end element to front
	std::rotate();

	// rearranges collection in random order
	std::shuffle();

	std::next_permutation();

	std::prev_permutation();
	
}