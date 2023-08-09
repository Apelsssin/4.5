#include <vector>
#include <algorithm>
#include <iostream>
#include <any>
#include <variant>
#include <string>

template <class T>
T squaring(T n) {
	n = n * n;
	return n;
}
template <class T>
std::vector<T> squaring(std::vector<T> v) {
	for (T& it : v) {
		it *= it;
	}
	return v;
}
template <class T>
void print(std::vector<T> v) {
	for (T& it : v) {
		std::cout << it << ", ";
	}
	std::cout << std::endl;
}

int main() {
	std::cout << "[IN]: ";
	std::string str;
	//std::cin >> str;
	str = "-1, 4, 8"; //
	std::cout << str << std::endl; //
	bool doubl = false;
	bool one = true;
	size_t counter = 1;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == 46) doubl = true; // "." - 46
		if (str[i] == 32) { // " " - 32. 
			one = false;
			++counter;
		}
	}
	std::cout << "[OUT]: ";
	if (one && doubl) {
		double n = std::atof(str.c_str());
		std::cout << squaring(n);
	}
	else if (one && !doubl) {
		int n = std::atoi(str.c_str());
		std::cout << squaring(n);
	}
	else {
		if (doubl) {
			std::string s;
			std::vector  <double> v;
			v.resize(counter);
			size_t j = 0;
			for (size_t i = 0; i < str.length(); ++i) {
				if (str[i] != 32 && str[i] != 44) {
					s += str[i];
				}
				if (str[i] == 32) {
					v[j] = std::stof(s);
					++j;
					s = "";
				}
				if (i == str.length() - 1)
					v[j] = std::stof(s);
			}

			v = squaring(v);
			print(v);
		}
		else {
			std::string s;
			std::vector  <int> v;
			v.resize(counter);
			size_t j = 0;
			for (size_t i = 0; i < str.length(); ++i) {
				if (str[i] != 32 && str[i] != 44) {
					s += str[i];
				}
				if (str[i] == 32) {
					v[j] = std::stoi(s);
					++j;
					s = "";
				}
				if (i == str.length() - 1) 
					v[j] = std::stoi(s);
			}

			v = squaring(v);
			print(v);
		}
	}
}