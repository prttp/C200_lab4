#include "Node.h"

List::Node::Node() {
	pPrev = nullptr;
	pNext = nullptr;
}
List::Node::Node(Node* p, Node* n, const Circle* d):m_Data(*d){
	pPrev = p;
	pNext = n;
	if (p != 0) { p->pNext = this; };
	if (n != 0) { n->pPrev = this; };
}
List::Node::~Node() {
	if (pNext != 0) { pNext->pPrev = pPrev; };
	if (pPrev != 0) { pPrev->pNext = pNext; };
}
void List::Node::Swap(Node* n)
{
	//Node* tmpN = pNext;
	Node* tmpP = pPrev;
	pNext = n->pNext;
	pPrev = n;
	n->pPrev = tmpP;
	n->pNext = this;

}
List::List() {
	Head = Node();
	Tail = Node();
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
	m_size = 0;
}
List::~List() {
	Node* p = Head.pNext;
	while (p->pNext != 0) {
		Head.pNext = p->pNext;
		delete p;
		p = Head.pNext;
	}
}
void List::AddToHead(const Circle* c) {
	new Node(&Head, Head.pNext, c);
	m_size++;
}
void List::AddToTail(const Circle* c) {
	new Node(Tail.pPrev, &Tail, c);
	m_size++;
}
bool List::Remove(const Circle& ref) {
	Node* p = Head.pNext;
	for (int i = 0; i < m_size; i++) {
		if (ref == p->m_Data) {
			delete p;
			m_size--;
			return 1;
			};
		p = p->pNext;
	};
	return 0;
}
int List::RemoveAll(const Circle& ref) {
	Node* p = Head.pNext;
	int n = 0;
	while (p !=0) {
		Node* next = p->pNext;
		if (ref == p->m_Data) {
			delete p;
			m_size--;
			n++;
			
		};
		p = next;
	};
	return n;
}
void List::MakeEmpty() {
	//Node* p = Head.pNext;
	for (int i = 0; i < m_size; i++) {
		delete Head.pNext;
		//Node* next = p->pNext;
		//delete p;
		//p = next;
	};
	m_size = 0;
}
void List::SortBySquare() {
	if (m_size != 0) {
		Node* p1 = Head.pNext;
		while (p1->pNext->pNext != 0) {

			Node* p = Head.pNext;
			while (p->pNext->pNext != 0) {
				float s1 = p->m_Data.GetSquare();
				float s2 = (p->pNext)->m_Data.GetSquare();
				if (s1 > s2) {
					/*Circle tmp = p->m_Data;
					p->m_Data = (p->pNext)->m_Data;
					(p->pNext)->m_Data = tmp;*/
					p->Swap(p->pNext);
					((p->pPrev)->pPrev)->pNext = p->pPrev;
					(p->pNext)->pPrev = p;
					/*Node* tmpN = p->pNext;
					(p->pPrev)->pNext = p->pNext;
					((p ->pNext)->pNext)->pPrev = p;
					(p->pNext)->pPrev = p->pPrev;
					(p->pNext)->pNext = p;
					p->pNext = (p->pNext)->pNext;
					p->pPrev = tmpN;*/
					continue;
				}
				p = p->pNext;
			}
			p1 = p1->pNext;
		}
	};
}
void List::PrintToFile() {
	std::cout << "Enter Output File Name  - ";
	char ar[80];
	std::cin >> ar;
	std::ofstream fout(ar);
	fout << *this;
	//List::Node* p = Head;
	//for (int i = 0; i < m_size; i++) {
	//	p = p->pNext;
	//	fout << p->m_Data << std::endl;
	//};
	//fout << "Size of the list: " << m_size << std::endl;
	fout.close();

}
std::ostream& operator<<(std::ostream& os, const List& d) {
	if (d.m_size == 0) { return os << "EMPTY!" << std::endl; };
	const List::Node* p = &d.Head;
	for (int i = 0; i < d.m_size; i++) { 
		p = p->pNext;
		os << p->m_Data << std::endl; };
	os << "Size of the list: " << d.m_size <<  std::endl;
	return os;
}