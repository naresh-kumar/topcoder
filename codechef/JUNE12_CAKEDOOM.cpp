// https://www.codechef.com/JUNE12/status/CAKEDOOM,nemausus
// https://www.codechef.com/viewplaintext/1088680
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	int cases;
	cin >> cases;
	char s[100];
	char types[10];
	for (int k = 0; k < 10; k++) {
		types[k] = (char) 48 + k;
	}
	while(cases--) {
		int num_types;
		cin >> num_types;
		scanf("%s", s);
		int length = strlen(s);
		if (length == 1) {
			if (s[0] == '?') {
				s[0] = '0';
			}
			printf("%s\n", s);
			continue;
		}
		if (num_types == 2) {
			if (length % 2 != 0) {
				printf("NO\n");
				continue;
			}
			bool startsWithZero = true;
			for (int i = 0; i < length; i++) {
				if (s[i] != '?') {
					if ((s[i] == '0' && (i % 2) == 0) || (s[i] == '1' && (i % 2) == 1)) {
						startsWithZero = true;
						break;
					} else {
						startsWithZero = false;
						break;
					}
				}
			}
			char start;
			if (startsWithZero) {
				start = '0';
			} else {
				start = '1';
			}
			bool valid = true;
			for (int i = 0; i < length; i++) {
				if (!(s[i] == '?' || s[i] == start)) {
					valid = false;
					break;
				} else {
					s[i] = start;
				}
				if (start == '0') {
					start = '1';
				} else {
					start = '0';
				}
			}
			if (valid) {
				printf("%s\n", s);
				continue;
			} else {
				printf("NO\n");
				continue;
			}
		}
		bool valid = true;
		for (int i = 0; i < length; i++) {
			char prev = s[(i - 1 + length) % length];
			char next = s[(i + 1) % length];
			if (s[i] == '?') {
				for (int j = 0; j < num_types; j++) {
					if (!(types[j] == prev || types[j] == next)) {
						s[i] = types[j];
						break;
					}
				}
			} else {
				if (s[i] == prev || s[i] == next) {
					valid = false;
					break;
				}
			}
		}
		if (valid) {
			printf("%s\n", s);
		} else {
			printf("NO\n");
		}
	}
}
