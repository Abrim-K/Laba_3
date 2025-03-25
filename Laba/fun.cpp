#include <string>
#include <iostream>
#include <algorithm>

std::string get_text() {
	std::string text;
	std::cout << "Enter your text: ";
	std::getline(std::cin, text);
	return text;
}


int get_count(std::string elem, std::string text) {
	std::string p_text = text;
	int elem_pos = p_text.find(elem);
	int count = 0;
	if ((elem == " m") and (p_text.find("m") == 0)) {
		count++;
	}
	while (elem_pos >= 0) {
		p_text.replace(elem_pos, elem_pos + elem.length(), "");
		count++;
		elem_pos = p_text.find(elem);
	}
	return count;
}


std::string correct(std::string text, char sim1, char sim2) {
	size_t p_begin = text.find(sim1);
	size_t p_end = text.rfind(sim2);
	if ((p_begin != std::string::npos) and (p_end != std::string::npos) and (p_begin < p_end)) {
		std::string str = text.substr(p_begin + 1, p_end - p_begin - 1);
		std::sort(str.begin(), str.end());
		text.replace(p_begin + 1, p_end - p_begin - 1, str);
	}
	else {
		std::cout << "Incorrect input" << std::endl;
	}
	return text;
}