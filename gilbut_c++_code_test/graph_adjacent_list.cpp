#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum class city : int
{
	MOSCOW, LONDON, SEOUL, SEATTLE, DUBAI, SYDNEY
};

ostream& operator<<(ostream& os, const city c) {
	switch (c) {
	case city::MOSCOW: os << "모스크바"; return os;
	case city::LONDON: os << "런던"; return os;
	case city::SEOUL: os << "서울"; return os;
	case city::SEATTLE: os << "시애틀"; return os;
	case city::DUBAI: os << "두바이"; return os;
	case city::SYDNEY: os << "시드니"; return os;
	default: return os;
	}
}

struct graph {
	vector<vector<pair<int, int>>> data;
	graph(int n) {
		data = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
	}
	void addEdge(const city c1, const city c2, int dis) {
		cout << "에지 추가 : " << c1 << " - " << c2 << " = " << dis << endl;
		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		data[n1].push_back({ n2, dis });
		data[n2].push_back({ n1, dis });
	}

	void removeEdge(const city c1, const city c2) {
		cout << "에지 삭제 : " << c1 << " - " << c2 << endl;
		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		remove_if(data[n1].begin(), data[n1].end(), [n2](const auto& pair) {return pair.first == n2; });
		remove_if(data[n2].begin(), data[n2].end(), [n1](const auto& pair) {return pair.first == n1; });
	}
};

int main() {
	graph g(6);
	g.addEdge(city::LONDON, city::MOSCOW, 2500);
	g.addEdge(city::LONDON, city::SEOUL, 9000);
	g.addEdge(city::LONDON, city::DUBAI, 5500);
	g.addEdge(city::SEOUL, city::MOSCOW, 6600);
	g.addEdge(city::SEOUL, city::SEATTLE, 8000);
	g.addEdge(city::SEOUL, city::DUBAI, 7000);
	g.addEdge(city::SEOUL, city::SYDNEY, 8000);
	g.addEdge(city::SEATTLE, city::MOSCOW, 8400);
	g.addEdge(city::SEATTLE, city::SYDNEY, 12000);
	g.addEdge(city::DUBAI, city::SYDNEY, 1200);

	g.addEdge(city::SEATTLE, city::LONDON, 8000);
	g.removeEdge(city::SEATTLE, city::LONDON);
}