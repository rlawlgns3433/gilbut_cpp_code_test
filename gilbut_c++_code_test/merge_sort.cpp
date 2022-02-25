#include <iostream>
#include <vector>
using namespace std;

template<typename T>
vector<T> merge(vector<T>& arr1, vector<T>& arr2) {
	vector<T> merged;
	
	auto iter1 = arr1.begin();
	auto iter2 = arr2.begin();

	while (iter1 != arr1.end() && iter2 != arr2.end()) {
		if (*iter1 < *iter2) {
			merged.emplace_back(*iter1);
			iter1++;
		}
		else {
			merged.emplace_back(*iter2);
			iter2++;
		}
	}
	if (iter1 != arr1.end())
		for (auto i : arr1)
			merged.emplace_back(i);
	if (iter2 != arr2.end())
		for (auto i : arr2)
			merged.emplace_back(i);
	return merged;
}

template<typename T>
vector<T> merge_sort(vector<T> arr) {
	if (arr.size() > 1) {
		auto mid = size_t(arr.size() / 2);
		auto left_mid = merge_sort(vector<T>(arr.begin(), arr.begin() + mid));
		auto right_mid = merge_sort(vector<T>(arr.begin() + mid, arr.end()));
		return merge(left_mid, right_mid);
	}
	return arr;
}

template<typename T>
void print_vector(vector<T> arr) {
	for (auto i : arr)
		cout << i << " ";
	cout << endl;
}

void run_merge_sort_test() {
	vector<int> s1{ 45,1,3,1,2,3,45,5,1,2,44,5,7 };
	vector<float> s2{ 45.6f,1.0f,3.8f,1.01f,2.2f,3.9f,45.3f,5.5f,1.0f,2.0f,44.0f,5.0f,7.0f };
	vector<double> s3{ 45.6,1.0,3.8,1.01,2.2,3.9,45.3,5.5,1.0,2.0,44.0,5.0,7.0 };
	vector<char> C{ 'b','z','a','e','f','t','q','u','y' };

	cout << "unsorted vector : " << endl;
	print_vector(s1); print_vector(s2); print_vector(s3); print_vector(C); cout << endl;

	auto sorted_s1 = merge_sort<int>(s1);
	auto sorted_s2 = merge_sort<float>(s2);
	auto sorted_s3 = merge_sort<double>(s3);
	auto sorted_C = merge_sort<char>(C);

	print_vector<int>(sorted_s1); 
	print_vector<float>(sorted_s2); 
	print_vector<double>(sorted_s3); 
	print_vector<char>(sorted_C);
	cout << endl;
}

int merge_sort_ex()
{
	run_merge_sort_test();
	return 0;
}