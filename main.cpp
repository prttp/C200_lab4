#include "Point.h"
#include "Circle.h"
#include "Node.h"
#define	  stop __asm nop

int main() {
	List list;
	Circle c1(0, 0, 2);
	Circle c2(0, 0, 3);
	Circle c3(0, 0, 4);
	Circle c4(0, 0, 5);
	Circle c5(0, 0, 6);
	list.AddToHead(&c1);
	list.AddToTail(&c2);
	list.AddToHead(&c5);
	list.AddToHead(&c3);
	std::cout << list;
	list.Remove(c1);
	std::cout << list;
	list.AddToTail(&c2);
	list.AddToTail(&c2);
	std::cout << list;
	list.RemoveAll(c2);
	list.AddToHead(&c4);
	list.AddToHead(&c1);
	list.AddToHead(&c1);
	std::cout << list;
	list.MakeEmpty();
	std::cout << list;
	list.SortBySquare();
	std::cout << list;
	list.PrintToFile();
	return 0;
}