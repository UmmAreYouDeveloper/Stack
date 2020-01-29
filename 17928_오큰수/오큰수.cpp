#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	
	cin >> n;

	vector<int> seq(n+1);
	vector<int> nge(n+1,-1);
	
	for (int i = 1; i <= n; i++) {
		cin >> seq[i];
	}

	stack<int> s;

	s.push(1);

	for (int i = 2; i <= n; i++) {
		while (!s.empty() && seq[s.top()] < seq[i]) {
			// ��ū�� ã��
			nge[s.top()] = seq[i];
			s.pop();
		}
		// ���� �ε������� �ٽý���
		s.push(i);
	}

	for (int i = 1; i <= n; i++) {
		cout << nge[i] << ' ';
	}

	cout << '\n';
	return 0;
}