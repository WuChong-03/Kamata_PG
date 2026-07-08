#include <stdio.h>

class IShape {
public:
	virtual ~IShape() {}

	virtual void Size() = 0;
	virtual void Draw() = 0;
};

class Circle : public IShape {
public:
	Circle(double radius) : radius_(radius), area_(0.0) {}

	void Size() override {
		const double pi = 3.14;
		area_ = radius_ * radius_ * pi;
	}

	void Draw() override {
		printf("Circleの面積: %.2f\n", area_);
	}

private:
	double radius_;
	double area_;
};

class Rectangle : public IShape {
public:
	Rectangle(double width, double height) : width_(width), height_(height), area_(0.0) {}

	void Size() override {
		area_ = width_ * height_;
	}

	void Draw() override {
		printf("Rectangleの面積: %.2f\n", area_);
	}

private:
	double width_;
	double height_;
	double area_;
};

int main(void) {
	IShape* shapes[2];

	shapes[0] = new Circle(5.0);
	shapes[1] = new Rectangle(4.0, 6.0);

	for (int i = 0; i < 2; i++) {
		shapes[i]->Size();
		shapes[i]->Draw();
	}

	for (int i = 0; i < 2; i++) {
		delete shapes[i];
	}

	return 0;
}
