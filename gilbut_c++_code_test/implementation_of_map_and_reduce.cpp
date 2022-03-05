#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

void transform_test(vector<int> S) {
	vector<int> Tr;
	for (auto i : S) cout << i << " ";
	cout << endl;

	transform(S.begin(), S.end(), back_inserter(Tr), [](int x) {return x = pow(x, 2.0); });
	for (auto i : Tr) cout << i << " ";
	cout << endl;

	for_each(S.begin(), S.end(), [](int& x) {x = pow(x, 2.0); });
	for (auto i : S) cout << i << " ";
	cout << endl;
}


void reduce_test(vector<int> S) {
	for (auto i : S) cout << i << " ";
	cout << endl;

	auto ans = accumulate(S.begin(), S.end(), 0, [](int acc, int x) {return acc + x; });
	cout << "accumulate(), ans : " << ans << endl;
}
void implementation_of_map_and_reduce()
{
	vector<int> S{ 1,10,4,7,3,5,6,9,8,2 };
	transform_test(S);
	cout << endl;
	reduce_test(S);
}