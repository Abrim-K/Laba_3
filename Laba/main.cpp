#include <iostream>
#include <algorithm>
#include <limits>
#include "date.h"
using namespace std;

int main() {
	cout << "1. Task #1" << "\n" << "2. Task #2" << "\n" << "3. Task #3" << "\n" << "4. Task #4" << "\n" << "0. Exit " << endl;
	int task = -1;
	do {
		cout << "\n" << "Select task (number): ";
		cin >> task;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;
		switch (task) {
		case 1:
		{
			string text1 = get_text();
			cout << "count 'm' = " << get_count(m, text1) << endl;
			cout << "count 'computer' or 'Computer' = " << get_count(pcs, text1) + get_count(pcb, text1) << endl;
			cout << "count 'sentence' = " << get_count(sent, text1) << endl;
			break;
		}
		case 2:
		{
			string text2 = get_text();
			string correct_text2;
			int count_sent = 0, count_word = 0;
			bool inword = false;
			for (int i = 0; i < text2.length(); ++i) {
				correct_text2 += text2[i];
				if (text2[i] == '.') {
					count_sent++;
					if (((i + 1) < text2.length()) and (text2[i + 1] != ' ')) {
						correct_text2 += ' ';
					}
				}
				if ((text2[i] == ' ') or (text2[i] == '.')) {
					inword = false;
				}
				else {
					if (!inword) {
						count_word++;
						inword = true;
					}
				}
			}
			cout << "correct text: " << correct_text2 << "\n" << "count sentence: " << count_sent << "\n" << "count word: " << count_word << endl;
			break;
		}
		case 3: 
		{
			string text3 = get_text();
			text3 = correct(text3, elem_begin, elem_end);
			cout << "Result: " << text3 << endl;
			break;
		}
		case 4: 
		{
			string text4_1 = get_text();
			string text4_2 = get_text();
			for (char sim1 : text4_1) {
				int count = 0;
				for (char sim2 : text4_2) {
					if (sim1 == sim2) {
						count++;
					}
				}
				cout << "count '" << sim1 << "': " << count << endl;
			}
			break;
		}
		default: cout << "Error" << endl; break;
		}
	} while (task != 0);
	return 0;
}
