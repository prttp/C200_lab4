#pragma once
#include "Circle.h"
#include <iostream>
#include <fstream>

class List
{
	class Node
	{
		friend class List;
		//ƒанные:
		Node* pPrev;		//указатель на предыдущий элемент
		Node* pNext;		//указатель на следующий элемент
		Circle m_Data;
		//ћетоды:
		friend std::ostream& operator<<(std::ostream& os, const List& l);
		Node();//скорее всего понадобитс€ дл€ создани€ вспомогательных оберток Ц Ђстражейї (Head, Tail)
		Node(Node* p, Node* n, const Circle* d);	//конструктор, посредством которого создаваемый Node Ђподключаетс€ї в список.
		~Node();//деструктор должен Ђисключатьї уничтожаемый Node из списка
		void Swap(Node* n);
	};//встроенное объ€вление класса Node

	//данные
	Node Head;	// фиктивный элемент, который €вл€етс€ признаком начала списка
	Node Tail;	// фиктивный элемент, который €вл€етс€ признаком конца списка
	size_t m_size;	//количество элементов
public:
	List();
	~List();
	void AddToHead(const Circle* c);
	void AddToTail(const Circle* c);
	bool Remove(const Circle& ref);
	int RemoveAll(const Circle& ref);
	void MakeEmpty();
	void SortBySquare();
	void PrintToFile();
	friend std::ostream& operator<<(std::ostream& os, const List& l);
	//std::ostream& PrintNodes(std::ostream& os, const List& l)
	};
