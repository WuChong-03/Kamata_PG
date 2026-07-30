#include <functional>
#include <iostream>
#include <thread>

void PrintThread1() {
	std::cout << "thread 1" << std::endl;
}

void PrintThread2(std::thread& previousThread) {
	previousThread.join();
	std::cout << "thread 2" << std::endl;
}

void PrintThread3(std::thread& previousThread) {
	previousThread.join();
	std::cout << "thread 3" << std::endl;
}

int main() {
	std::thread thread1(PrintThread1);
	std::thread thread2(PrintThread2, std::ref(thread1));
	std::thread thread3(PrintThread3, std::ref(thread2));

	thread3.join();

	return 0;
}
