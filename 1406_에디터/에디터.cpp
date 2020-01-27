#include <iostream>
#include <stack>
#include <cstring>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string init;
	cin >> init;

	stack<char>left, right;
	// ��ɾ ������ �� Ŀ���� ������ ������ ���� ��ġ
	for (char ch : init) {
		left.push(ch);
	}

	int m;
	cin >> m;

	while (m--) {
		char inst;
		cin >> inst;
		if (inst == 'L') {
			// Ŀ���� ������ �� ���̸� ���õ�
			// �� ���� ������ �� ��.
			if (!left.empty()) { 
			// �������� �ű�� ������ ���� ������ ���� Ǫ��
			// ������ �������� ��
				right.push(left.top());
				left.pop();
			}
		}
		else if (inst == 'D') {
			// Ŀ���� ������ �� �ڸ� ���õ�
			// ������ ������ �� ��
			if (!right.empty()) {
			// ������ ������ ���� �� �Ǿ�
			// ���� �������� ��
				left.push(right.top());
				right.pop();
			}
		}
		else if (inst == 'B') {
			// Ŀ�� ������ ���ڸ� ����
			// ���� ���ÿ��� POP��
			// Ŀ���� ������ �� ���̸� ���õ�
			if (!left.empty()) {
				left.pop();
			}
		}
		else if (inst == 'P') {
			// ���ڸ� Ŀ�� ���ʿ� �߰�
			char ch;
			cin >> ch;
			left.push(ch);
		}
	}

	// ���ʰ� ������ ������ �������� �ϳ��� ���ڿ��� �Ǿ��ϰ�
	// ������ ù��° ���ں��� ���;� �ϹǷ�
	// �����غ��� ������ ������ ���� �����ʿ� �˵ǰ�
	// �������� top���� ������ ���ڿ��� �� -> �� ������� ������ �ȴ�.

	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}

	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}

	return 0;
}