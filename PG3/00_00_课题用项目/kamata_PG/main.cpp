#include <stdio.h>

template <typename T>
T add(T a, T b) {
	return a + b;
}

template <>
float add<float>(float a, float b) {
	return a - b;
}

float add(float a, float b) {
	return a * b;
}

int main(void) {
	printf("%d\n", add<int>(114, 514));
	printf("%f\n", add<float>(11.4f, 51.4f));
	printf("%f\n", add(11.4f, 51.4f));

	return 0;
}
