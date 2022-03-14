#pragma once
#include "Circle.h"
#include <iostream>
#include <fstream>

class List
{
	class Node
	{
		friend class List;
		//������:
		Node* pPrev;		//��������� �� ���������� �������
		Node* pNext;		//��������� �� ��������� �������
		Circle m_Data;
		//������:
		friend std::ostream& operator<<(std::ostream& os, const List& l);
		Node();//������ ����� ����������� ��� �������� ��������������� ������� � �������� (Head, Tail)
		Node(Node* p, Node* n, const Circle* d);	//�����������, ����������� �������� ����������� Node �������������� � ������.
		~Node();//���������� ������ ����������� ������������ Node �� ������
		void Swap(Node* n);
	};//���������� ���������� ������ Node

	//������
	Node Head;	// ��������� �������, ������� �������� ��������� ������ ������
	Node Tail;	// ��������� �������, ������� �������� ��������� ����� ������
	size_t m_size;	//���������� ���������
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
