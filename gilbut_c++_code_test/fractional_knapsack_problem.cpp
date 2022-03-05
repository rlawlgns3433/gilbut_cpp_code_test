#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Object {
	int id, weight;
	double value;
	double value_per_unit_weight;
	
	Object(int i, int w, double v) : id(i), weight(w), value(v), value_per_unit_weight(v / w) {};
	
	inline bool operator<(const Object& obj) const {
		return this->value_per_unit_weight < obj.value_per_unit_weight;
	}

	friend ostream& operator<<(ostream& os, const Object& obj);

};

ostream& operator<<(ostream& os, const Object& obj) {
	os << "[" << obj.id << "] 가격 : " << obj.value << " \t무게 : " << obj.weight << " kg\t단위 무게 당 가격 : " << obj.value_per_unit_weight;
	return os;
}

auto fill_knapsack(vector<Object>& objects, int knapsack_capacity) {
	vector<Object> knapsack_contents;
	knapsack_contents.reserve(objects.size());

	sort(objects.begin(), objects.end());
	reverse(objects.begin(), objects.end());

	auto current_object = objects.begin();
	int current_total_weight = 0;
	while (current_total_weight < knapsack_capacity && current_object != objects.end()) {
		knapsack_contents.emplace_back(*current_object);

		current_total_weight += current_object->weight;
		current_object++;
	}

	int weight_of_last_obj_to_remove = current_total_weight - knapsack_capacity;
	Object& last_object = knapsack_contents.back();
	if (weight_of_last_obj_to_remove > 0) {
		last_object.weight -= weight_of_last_obj_to_remove;
		last_object.value -= last_object.value_per_unit_weight * weight_of_last_obj_to_remove;
	}
	return knapsack_contents;
}

void fractional_knapsack_problem(int argc, char* argv[])
{
	vector<Object> objects;
	objects.reserve(7);

	vector<int> weights{ 1,2,5,9,2,3,4 };
	vector<double> values{ 10,7,15,10,12,11,5 };
	for (auto i = 0; i < 7; i++) {
		objects.push_back(Object(i + 1, weights[i], values[i]));
	}

	cout << "[사용할 수 있는 물건 정보]" << endl;
	for (auto& o : objects)
		cout << o << endl;
	cout << endl;

	int knapsack_capacity = 7;
	auto solution = fill_knapsack(objects, knapsack_capacity);
	cout << "[배낭에 넣을 물건들 (최대 용량 = " << knapsack_capacity << ")]" << endl;
	for (auto& o : solution)
		cout << o << endl;
	cout << endl;
}