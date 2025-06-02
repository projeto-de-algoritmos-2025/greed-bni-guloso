#include <stdio.h>
#include <stdbool.h>

bool isMatch(char *s, char *p) {
	int is = 0, ip = 0, si = -1, mi = 0;
	while (s[is] != '\0')
		if (p[ip] == '?' || p[ip] == s[is]) is++, ip++;
		else if (p[ip] == '*') si = ip, mi = is, ip++;
		else if (si != -1) ip = si + 1, is = mi + 1, mi++;
		else return false;
	while (p[ip] == '*') ip++;
	return p[ip] == '\0';
}

int main(void) {
	printf("%d\n", isMatch("a", "*"));
	return 0;
}
