#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <chrono>
using namespace std;

bool linear_search(int N, vector<int>& S) {
	for (auto& i : S)
		if (i == N) return true;
	return false;
}

bool binary_search(int N, vector<int>& S) {
	auto left = S.begin();
	auto right = S.end();
	while (true) {
		auto range_length = distance(left, right);
		auto mid_element_index = floor(range_length/2);
		auto mid_element = *(left + mid_element_index);

		if (mid_element == N) return true;
		else if (mid_element < N) advance(left, mid_element_index);
		else advance(right, -mid_element_index);

		if (range_length == 1)
			return false;
	}
}

void run_small_search_test() {
	auto N = 2; vector<int> S{ 1,3,2,4,5,7,9,8,6 };
	sort(S.begin(), S.end());
	if (linear_search(N, S)) cout << "found(linear)" << endl;
	else cout << "not found(linear)" << endl;
	if (binary_search(N, S)) cout << "found(binary)" << endl;
	else cout << "not found(binary)" << endl;
}

void run_large_search_test(int size, int N) {
	vector<int> S; random_device rd; mt19937 rand(rd());
	uniform_int_distribution<mt19937::result_type> uniform_dist(1, size);
	for (auto i = 0; i < N; i++)
		S.emplace_back(uniform_dist(rand));
	sort(S.begin(), S.end());
	chrono::steady_clock::time_point begin = chrono::steady_clock::now();
	bool search_binary = binary_search(N, S);
	chrono::steady_clock::time_point end = chrono::steady_clock::now();
	auto diff = chrono::duration_cast<chrono::microseconds>(end - begin);
	cout << "이진 검색 수행 시간 : " << diff.count() << endl;
	if (search_binary) cout << "found" << endl;
	else cout << "not found" << endl;
}



int main()
{
	run_small_search_test();
	run_large_search_test(100000, 36543);
	run_large_search_test(1000000, 36543);
	run_large_search_test(10000000, 36543);
}