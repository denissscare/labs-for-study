#include <vector>
#include <map>
#include<iostream>
#include<stack>

using namespace std;

void infixToPostfix(string);



int main() {
	
	infixToPostfix("A + B * C");

	return 0;
}

void infixToPostfix(string infixstr) {
	map<char, int> priority; 
	stack<char> opStack;
	priority['('] = 1;
	priority['-'] = 2;
	priority['+'] = 2;
	priority['/'] = 3;
	priority['*'] = 3;
	vector<char> postfix_str;
	for (char token  : infixstr) {
		if ((token >= 48 && token <= 57) || (token >= 65 && token <= 90)) {
			postfix_str.push_back(token);
		}
		else if (token == '(') { opStack.push(token); }
		else if(token == ')') {
			char topToken = opStack.top();
			opStack.pop();
			while (topToken != '(') {
				postfix_str.push_back(topToken);
				topToken = opStack.top();
				opStack.pop();
			}
		}
		else {
			while (!(opStack.empty()) && (priority[opStack.top()] >= priority[token])) {
				postfix_str.push_back(opStack.top());
				opStack.pop();
			}
			opStack.push(token);
		}
	}
	while(!(opStack.empty())){
		postfix_str.push_back(opStack.top());
		opStack.pop();
	}
	for (char i : postfix_str) {
		cout << i; 
	}
	cout << endl;
}
