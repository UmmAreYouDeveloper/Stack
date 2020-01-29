#include <iostream>
#include <stack>
#include <string>

using namespace std;

void word_printer(stack<char>& s) {
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string input;
	stack<char> s;
	getline(cin, input);
	bool tag = false;

	for (char ch : input) {
		if (ch == '<') {
			// open tag�� �� �������� ���ڸ� ����ϰ�
			word_printer(s);
			// �±� ������ �˸�
			tag = true;
			// < ���
			cout << ch;
		}
		else if (ch == '>') {
			// �±� ���� �˸�
			tag = false;
			// > ���
			cout << ch;
		}
		else if (tag) {
			// �±� ���� ���ڵ�
			cout << ch;
		}
		else {
			// �±� �ܺ� ���ڵ�
			if (ch == ' ') {
				word_printer(s);
				cout << ch;
			}
			else {
				s.push(ch);
			}
		}
	}
	// ���ڿ��� ���� ������ �ƴ϶�� ������
	// ���ó����� ���ڵ��� �ѹ� �� ������� �ʿ䰡�ִ�
	// �ݺ��� ���ο����� ������ ������ �ø� ����� �Ǳ⶧��
	word_printer(s);
	cout << '\n';
	return 0;
}