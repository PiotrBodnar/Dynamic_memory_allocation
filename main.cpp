// Adam Geppert, Piotr Bodnar AiR Grupa 7 

#include "List.h"
#include "Point.h"
#include <iostream> 

int main()  
{
	List cos;
	Point p1(1.0, 2.0, 3.0), p2(5.0, 4.0, 3.0), p3(10.0, 11.0, 12.0);
	cos.push_back(p1);
	cos.push_back(p2);
	cos.insert(p3, 2);
	cos = cos * 0;
	std::cout << "cos";
	std::cout <<"Size: " << cos.getSize() << std::endl;
	Point wynik;
	cos.find(wynik, 0);
	std::cout << wynik.x << wynik.y << wynik.z << std::endl;

	/*List test;
	Point p1(1.0, 2.0, 3.0);
	while (true)
	{
		test.push_back(p1);
		test.pop_back();
	}*/

	return 0;
}