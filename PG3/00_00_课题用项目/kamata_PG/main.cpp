#include <stdio.h>

class Payment {
public:
	Payment(const char* name) : name_(name) {}
	virtual ~Payment() {}

	virtual void Pay(int price) {
		printf("%sで%d円を支払います。\n", name_, price);
	}

protected:
	const char* name_;
};

class Cash : public Payment {
public:
	Cash() : Payment("現金") {}

	void Pay(int price) override {
		printf("%sで%d円を支払いました。おつりを確認してください。\n", name_, price);
	}
};

class CreditCard : public Payment {
public:
	CreditCard() : Payment("クレジットカード") {}

	void Pay(int price) override {
		printf("%sで%d円を支払いました。サインは不要です。\n", name_, price);
	}
};

class ElectronicMoney : public Payment {
public:
	ElectronicMoney() : Payment("電子マネー") {}

	void Pay(int price) override {
		printf("%sで%d円を支払いました。端末にタッチしました。\n", name_, price);
	}
};

int main(void) {
	Payment* payments[3];

	payments[0] = new Cash();
	payments[1] = new CreditCard();
	payments[2] = new ElectronicMoney();

	printf("支払い処理を開始します。\n\n");

	for (int i = 0; i < 3; i++) {
		payments[i]->Pay(1200);
	}

	for (int i = 0; i < 3; i++) {
		delete payments[i];
	}

	return 0;
}
