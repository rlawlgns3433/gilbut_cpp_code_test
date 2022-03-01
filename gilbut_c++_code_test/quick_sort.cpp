//#include <iostream>
//#include <iterator>
//#include <vector>
//using namespace std;
//
//template<typename T>
//auto partition(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
//	auto pivot_val = *begin;
//	auto left_iter = begin + 1;
//	auto right_iter = end;
//
//	while (true) {
//		while (*left_iter >= pivot_val && distance(left_iter, right_iter) > 0)
//			left_iter++;
//		while (*right_iter < pivot_val && distance(left_iter, right_iter) > 0)
//			right_iter--;
//
//		if (left_iter == right_iter) break;
//		else iter_swap(left_iter, right_iter);
//
//	}
//	if (pivot_val > *right_iter)
//		iter_swap(begin, right_iter);
//
//	return right_iter;
//}
//
//template<typename T>
//void quick_sort(typename vector<T>::iterator begin, typename vector<T>::iterator last) {
//	if (distance(begin, last) >= 1) {
//		auto partition_iter = partition<T>(begin, last);
//		quick_sort<T>(begin, partition_iter - 1);
//		quick_sort<T>(partition_iter, last);
//	}
//}
//
//template<typename T>
//void print_vector(vector<T> arr) {
//	for (auto i : arr)
//		cout << i << ' ';
//	cout << endl;
//}
//
//void run_quick_sort_test() {
//	vector<int> s1{ 45,1,3,1,2,3,45,5,1,2,44,5,7 };
//	vector<float> s2{ 45.6f,1.0f,3.8f,1.01f,2.2f,3.9f,45.3f,5.5f,1.0f,2.0f,44.0f,5.0f,7.0f };
//	vector<double> s3{ 45.6,1.0,3.8,1.01,2.2,3.9,45.3,5.5,1.0,2.0,44.0,5.0,7.0 };
//	vector<char> C{ 'b','z','a','e','f','t','q','u','y' };
//
//	cout << "unsorted vector : " << endl;
//	print_vector(s1); print_vector(s2); print_vector(s3); print_vector(C); cout << endl;
//
//	quick_sort<int>(s1.begin(), s1.end()-1);
//	quick_sort<float>(s2.begin(), s2.end()-1);
//	quick_sort<double>(s3.begin(), s3.end()-1);
//	quick_sort<char>(C.begin(), C.end()-1);
//
//	print_vector(s1); print_vector(s2); print_vector(s3); print_vector(C); cout << endl;
//	cout << endl;
//}
//
//int main()
//{
//	run_quick_sort_test();
//}