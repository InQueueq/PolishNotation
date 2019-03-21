#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cmath>
using namespace std;




void showStack(stack <double> st)
{
	while (!st.empty())
	{
		cout << '\t' << st.top();
		st.pop();
	}
	cout << '\n';
}


void zapis(string input, stack<string>stck,string &output,int length) {
	for (int i = 0;i < length;i++) {
		if (input[i] >= '0' && input[i] <='9'){
			if (input[i + 1] >= '0' && input[i + 1] <= '9') {
				output += input[i];
				output += input[i + 1];
				output += " ";
			}
			else if (i!=0 && input[i - 1] >= '0' && input[i - 1] <= '9') {
				continue;
			}
			else {
				output += input[i];
				output += " ";
			}
		}
		else if(input[i] == '+'){
			for (int j = 0;j < stck.size();j++) {
				if (stck.top()[0] == '+'|| stck.top()[0] == '-') {
					output += stck.top();
					output += " ";
					stck.pop();
				}
				else if (stck.top()[0] == '*' || stck.top()[0] == '/' || stck.top()[0] == '^' || stck.top()[0] == 's') {
					output += stck.top();
					output += " ";
					stck.pop();
				}

			}
			string s(1, input[i]);
			stck.push(s);
		}
		else if (input[i] == '-') {
			for (int j = 0;j < stck.size();j++) {
				if (stck.top()[0] == '+' || stck.top()[0] == '-') {
					output += stck.top();
					output += " ";
					stck.pop();
				}
				else if (stck.top()[0] == '*' || stck.top()[0] == '/'|| stck.top()[0] == '^' || stck.top()[0] == 's') {
					output += stck.top();
					output += " ";
					stck.pop();
				}
			}
			string s(1, input[i]);
			stck.push(s);
		}
		else if (input[i] == '(') {
			string s(1, input[i]);
			stck.push(s);
		}
		else if (input[i] == ')'){
			while (stck.top()[0] != '(') {
				output += stck.top();
				output += " ";
				stck.pop();
			}
			stck.pop();
		}
		else if (input[i] == '/') {
			for (int j = 0;j < stck.size();j++) {
				if (stck.top()[0] == '*' || stck.top()[0] == '/' || stck.top()[0] == 's') {
					output += stck.top();
					output += " ";
					stck.pop();
				}
				else if (stck.top()[0] == '^') {
					output += stck.top();
					output += " ";
					stck.pop();
				}
			}
			string s(1, input[i]);
			stck.push(s);
		}
		else if (input[i] == '*') {
			for (int j = 0;j < stck.size();j++) {
				if (stck.top()[0] == '*' || stck.top()[0] == '/' || stck.top()[0] == 's') {
					output += stck.top();
					output += " ";
					stck.pop();
				}
				else if (stck.top()[0] == '^') {
					output += stck.top();
					output += " ";
					stck.pop();
				}
			}
			string s(1, input[i]);
			stck.push(s);
		}
		else if (input[i] == '^') {
			for (int j = 0;j < stck.size();j++) {
				if (stck.top()[0] == '^') {
					output += stck.top();
					output += " ";
					stck.pop();
				}
			}

			string s(1, input[i]);
			stck.push(s);
		}
		else if (input[i] == 's') {
			for (int j = 0;j < stck.size();j++) {
				if (stck.top()[0] == 's') {
					output += stck.top();
					output += " ";
					stck.pop();
			}
		}
			string s(1, input[i]);
			stck.push(s);
}
	}
	for (int i = 0;i < stck.size();i++) {
		output += stck.top();
		output += " ";
		stck.pop();
	}
}

void operationDoing(stack<double>calculate,string input,int length,string &output) {
	for (int i = 0;i < length;i++) {
		if (input[i] >= '0' && input[i] <= '9') {
			if (input[i + 1] >= '0'&& input[i + 1] <= '9') {
				string reTyper(1, input[i]);
				string reTyper2(1, input[i + 1]);
				string temp = reTyper + reTyper2;
				int tempr = stoi(temp);
				calculate.push(tempr);
			}
			else if (i != 0 && input[i - 1] >= '0'&& input[i - 1] <= '9') {
				continue;
			}
			else {
				int temp;
				temp = input[i] - '0';
				calculate.push(temp);
			}
		}
		else if (input[i] == ' ') {
			continue;
		}
		else if (input[i] == '+') {
			int temp = calculate.top();
			calculate.pop();
			calculate.top() += temp;
		}
		else if (input[i] == '-') {
			int temp = calculate.top();
			calculate.pop();
			calculate.top() -= temp;
		}
		else if (input[i] == '*') {
			int temp = calculate.top();
			calculate.pop();
			calculate.top() *= temp;
		}
		else if (input[i] == '/') {
			int temp = calculate.top();
			calculate.pop();
			calculate.top() /= temp;
		}
		else if (input[i] == '^') {
			int temp = calculate.top();
			calculate.pop();
			calculate.top() = pow(calculate.top(), temp);
		}
		else if (input[i] == 's') {
			int temp = calculate.top();
			calculate.top() = sin(calculate.top());
		}
	}
	showStack(calculate);
	cout << endl;
}

int main() {
	stack<string> st;
	stack<double>calSt;
	string inputString = "-2*5";
	int leng = inputString.length();
	string resultString;

	zapis(inputString, st, resultString, leng);

	cout << resultString << endl;

	int lengOfresult=resultString.length();
	string outputCalc;
	operationDoing(calSt, resultString, lengOfresult,outputCalc);

	
	system("pause");
	return 2;
}
