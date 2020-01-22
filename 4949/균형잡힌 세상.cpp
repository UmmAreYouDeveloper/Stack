#include <iostream>
#include <string>
#include <stack>

using namespace std;

string valid(string str) {
	
	stack<char> s;

	for (char ch : str) {

		if (ch == '(' || ch == '[') {
				s.push(ch);
				
		}
		else if (ch == ']') {
			if (!s.empty() && s.top() == '[')
				s.pop();
			else
				return "no";
		}
		else if (ch == ')') {
			if (!s.empty() && s.top() == '(')
				s.pop();
			else
				return "no";
		}
		else {
			continue;
		}		
	}
	
	if (s.size() == 0) {
		return "yes";
	}
	else {
		return "no";
	}
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string input;

	while (1) {
		// string class�� ����������� ���ڿ��� ���еǾ�
		// �Է����� �� �� ��ü�� ���� ���� getline�� ���!
		getline(cin, input);
		if (input == ".") break;
		cout << valid(input) << '\n';
	}

	return 0;
}