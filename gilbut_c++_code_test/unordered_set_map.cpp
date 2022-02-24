//#include <iostream>
//#include <unordered_set>
//#include <unordered_map>
//using namespace std;
//
//void print(const unordered_set<int>& container) {
//	for (const auto& element : container)
//		cout << element << ' ';
//	cout << endl;
//}
//void print(const unordered_map<int, int>& container) {
//	for (const auto& element : container)
//		cout << element.first << " -> " << element.second << ", ";
//	cout << endl;
//}
//void find(const unordered_set<int>& container, const int element) {
//	if (container.find(element) == container.end())
//		cout << element << " �˻� : ����" << endl;
//	else cout << element << " �˻� : ����" << endl;
//}
//void find(const unordered_map<int, int>& container, const int element) {
//	auto it = container.find(element);
//	if (it == container.end())
//		cout << element << " �˻� : ����" << endl;
//	else
//		cout << element << " �˻� : ����, �� = " << it->second << endl;
//}
//
//
//int main()
//{
//	unordered_set<int> set1 = { 1,2,3,4,5 };
//	cout << "set1 �ʱⰪ : "; print(set1);
//	set1.insert(2);
//	cout << "2 ���� : "; print(set1);
//	set1.insert(10);
//	set1.insert(300);
//	cout << "10, 300 ���� : "; print(set1);
//	find(set1, 4);
//	find(set1, 100);
//	set1.erase(2);
//	cout << "2 ���� : "; print(set1);
//
//	find(set1, 2);
//	cout << endl;
//	unordered_map<int, int> squareMap;
//	squareMap.insert({ 2,4 });
//	squareMap[3] = 9;
//	cout << "2, 3�� ���� ���� : "; print(squareMap);
//
//	squareMap[20] = 400;
//	squareMap[30] = 900;
//	cout << "20, 30�� ���� ���� : "; print(squareMap);
//
//	find(squareMap, 10);
//	find(squareMap, 20);
//	cout << "squareMap[3] = " << squareMap[3] << endl;
//	cout << "squareMap[100] = " << squareMap[100] << endl;
//	print(squareMap);
//}