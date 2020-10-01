#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string numbers) {
	int answer = 0;
	int size = numbers.length();
	vector<int> prime(10000000, 1);
	for (int i = 2; i < 5000000; i++) {
		if (prime[i] == 0) continue;
		for (int j = i + i; j < 10000000; j = j + i) {
			if (prime[j] == 1) prime[j] = 0;
		}
	}
	for (int i = 2; i < 10000000; i++) {
		if (prime[i] == 1) {
			string temp = numbers;
			string str = to_string(i);
			int prob = 0;
			int j = 0;
			for (j = 0; j < str.length(); j++) {
				for (int k = 0; k < size; k++) {
					if (str[j] == temp[k]) {
						prob = 1; temp[k] = 'x';
						break;
					}
				}
				if (prob == 0) break;
				else {
					prob = 0;
				}
			}
			if (j == str.length()) answer++;
		}
	}


	return answer;
}