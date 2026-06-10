#include <stdio.h>

// 一般的な時給
const int NORMAL_WAGE = 1072;

// 再帰的な賃金体系の時給を求める関数
int RecursiveWage(int hour) {
    if (hour <= 1) {
        return 100;
    }

    return RecursiveWage(hour - 1) * 2 - 50;
}

// 再帰的な賃金体系の合計金額を求める関数
int RecursiveTotal(int hour) {
    if (hour <= 1) {
        return RecursiveWage(1);
    }

    return RecursiveTotal(hour - 1) + RecursiveWage(hour);
}

int main(void) {
    int hour = 1;

    while (true) {
        int normalTotal = NORMAL_WAGE * hour;
        int recursiveTotal = RecursiveTotal(hour);

        printf("%d時間働いた場合\n", hour);
        printf("一般的な賃金体系：%d円\n", normalTotal);
        printf("再帰的な賃金体系：%d円\n\n", recursiveTotal);

        if (recursiveTotal > normalTotal) {
            printf("再帰的な賃金体系のほうが儲かるのは%d時間働いたときです。\n", hour);
            break;
        }

        hour++;
    }

    return 0;
}