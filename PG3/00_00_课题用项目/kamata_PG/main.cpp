#include <stdio.h>

int NormalTotalWage(int hour) {
	return 1072 * hour;
}

int RecursiveHourlyWage(int hour) {
	if (hour <= 1) {
		return 100;
	}

	return RecursiveHourlyWage(hour - 1) * 2 - 50;
}

int RecursiveTotalWage(int hour) {
	if (hour <= 0) {
		return 0;
	}

	return RecursiveTotalWage(hour - 1) + RecursiveHourlyWage(hour);
}

int main(void) {
	int hour = 1;

	printf("hour normal recursive\n");

	while (1) {
		int normalTotal = NormalTotalWage(hour);
		int recursiveTotal = RecursiveTotalWage(hour);

		printf("%2d %6d %9d\n", hour, normalTotal, recursiveTotal);

		if (recursiveTotal > normalTotal) {
			printf("\n%d時間働くと、再帰的な賃金体系のほうが儲かります。\n", hour);
			break;
		}

		hour++;
	}

	return 0;
}
