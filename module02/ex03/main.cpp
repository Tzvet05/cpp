#include <iostream>
#include "Point.hpp"
#include "bsp.hpp"

int	main(void)
{
	Point	a(0.0f,0.0f), b(4.0f,0.0f), c(2.0f,3.0f);
	Point	p1(0.0f,0.0f), p2(2.0f, 0.0f), p3(2.0f, -1.0f), p4(2.0f, 3.0f), p5(3.9f, 0.2f);
	Point	p6(2.0f, 1.5f), p7(2.0f, 2.9f), p8(3.9f, 0.1f);

	std::cout << bsp(a, b, c, p1) << std::endl;
	std::cout << bsp(a, b, c, p2) << std::endl;
	std::cout << bsp(a, b, c, p3) << std::endl;
	std::cout << bsp(a, b, c, p4) << std::endl;
	std::cout << bsp(a, b, c, p5) << std::endl;
	std::cout << bsp(a, b, c, p6) << std::endl;
	std::cout << bsp(a, b, c, p7) << std::endl;
	std::cout << bsp(a, b, c, p8) << std::endl;
	return (0);
}
