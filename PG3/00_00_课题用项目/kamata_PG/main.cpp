#include <stdio.h>

template <typename T>
T Min(T a, T b) {
	return (a < b) ? a : b;
}

template <>
char Min<char>(char, char) {
	printf("数字以外は代入できません\n");
	return '\0';
}

int main(void) {
	int intA = 114;
	int intB = 514;
	float floatA = 11.4f;
	float floatB = 51.4f;
	double doubleA = 1.14;
	double doubleB = 5.14;
	char charA = 'a';
	char charB = 'b';

	printf("%d\n", Min<int>(intA, intB));
	printf("%f\n", Min<float>(floatA, floatB));
	printf("%f\n", Min<double>(doubleA, doubleB));
	Min<char>(charA, charB);

	return 0;
}
