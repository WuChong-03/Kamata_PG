#include <stdio.h>
#include <type_traits>

template <typename T1, typename T2>
class MinClass {
public:
	using ResultType = typename std::common_type<T1, T2>::type;

	ResultType Min(T1 a, T2 b) {
		if (a < b) {
			return static_cast<ResultType>(a);
		}

		return static_cast<ResultType>(b);
	}
};

int main(void) {
	MinClass<int, int> intIntMin;
	MinClass<float, float> floatFloatMin;
	MinClass<double, double> doubleDoubleMin;
	MinClass<int, float> intFloatMin;
	MinClass<int, double> intDoubleMin;
	MinClass<float, double> floatDoubleMin;

	printf("int, int: %d\n", intIntMin.Min(114, 514));
	printf("float, float: %f\n", floatFloatMin.Min(11.4f, 51.4f));
	printf("double, double: %f\n", doubleDoubleMin.Min(1.14, 5.14));
	printf("int, float: %f\n", intFloatMin.Min(114, 51.4f));
	printf("int, double: %f\n", intDoubleMin.Min(114, 5.14));
	printf("float, double: %f\n", floatDoubleMin.Min(11.4f, 5.14));

	return 0;
}
