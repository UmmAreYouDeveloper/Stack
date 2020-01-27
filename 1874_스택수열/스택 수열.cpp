#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	string solution;
	stack<int> s;
	int m = 0; // ���ÿ� �� ������ ��

	while (n--) {
		int x;
		cin >> x;
		if (x > m) {
			while (x > m) {
				s.push(m+=1); // ������ m+1 ~ x���� ä���.
				solution += '+'; // push �ϱ� '+'
			}
			s.pop(); // x�� pop
			solution += '-'; // pop �̴ϱ� '-'
		}
		else { // x <= m
			// �� ���� ������ x <= m �̶��, x == m�̾�� �Ѵ�. 
			// m���� ���� ���� pop�Ϸ� �ϸ�
			// ���� ������ ���ǿ� ����ȴ�.
			bool found = false;
			if (!s.empty()) { // stack�� �����ʾ�����,
				int top = s.top(); // top�� ������
				s.pop(); // pop ��Ų��.
				solution += '-'; // pop �̴ϱ� '-'
				if (x == top) { // �������� x�� ���ٸ�
					found = true; // ã�� ����
				}
			}
			if (!found) {
				cout << "NO" << '\n';
				return 0;
			}
		}

		
	}

	for (char ch : solution) {
		cout << ch << '\n';
	}

	return 0;
}