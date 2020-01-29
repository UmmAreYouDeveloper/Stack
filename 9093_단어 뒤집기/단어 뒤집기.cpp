#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int tc;
	cin >> tc;
	cin.ignore(); // tc ������ ���๮�� ����
	string str;
	stack<char> s; // ���� ����
	while (tc--) {
		getline(cin, str);
		str += '\n';
		for (char ch : str) { // string ���ں��� �ȱ�
			if(ch == '\n' || ch == ' ') {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << ch;
			}
			else {
				s.push(ch);
			}
		}
	}
	return 0;
}
