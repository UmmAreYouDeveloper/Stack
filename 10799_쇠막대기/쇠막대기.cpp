#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string input;

	cin >> input;

	stack<char> s;

	int cnt = 0;
	// ���ڿ� �ε���
	int i = 0;
	for (char ch : input) {
		if (ch == '(') {
			s.push(ch);
		}
		else {
			// �����, ������ ����
			// ������
			if (input.at(i - 1) == '(') {
				s.pop();
				// ������
				cnt += s.size();
			}
			// �����
			else {
				s.pop();
				cnt += 1;
			}
		}
		i++;
	}

	cout << cnt <<'\n';

	return 0;
}