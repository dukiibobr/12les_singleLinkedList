#include <iostream>
using namespace std;


template<typename T>
class List
{
	struct Node
	{
		int value;
		Node* next;
		Node() :value(0), next(nullptr) {}
		Node(int value, Node* next) :value(value), next(next) {}
	};
	Node* head;
	
public:
	List() {
		head = nullptr;
	}

	void addToHead(T val) {
		Node* newNode = new Node(val,head);
		
		head = newNode;
	}
	void print() {
		Node* current = head;
		while (current!=nullptr)
		{
			cout << current->value << " ";
			current = current->next;
		}
		cout << endl;
	}

	void addToTail(T val) {
		Node* newNode = new Node(val, nullptr);

		if (head==nullptr)
			head = newNode;
		
		else
		{
			Node* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}

	void deleteFromTail() {
		if (head == nullptr)return;
		if (head->next == nullptr) {
			delete head;
			head = nullptr;
		}
		else
		{
			Node* current = head;
			while (current->next->next != nullptr)
			{
				current = current->next;
			}
			delete current->next;
			current->next = nullptr;
		}
	}


	void deleteFromHead() {
		current = head;
		head = current.next;
		delete current;
	}



	~List() {
		Node* current = nullptr;
		while (head !=nullptr)
		{
			current = head;
			head = head->next;
			delete current;
		}
	}
};











class Point {
	int x;
	int y;
};
class Vector
{
	int size;
	List<Point> points;
public:
	void addPointToHead(Point p) {
		points.addToHead( p);
	}

	void addPointToTail(Point p) {
		points.addToTail( p);
	}

	void deletePointFromHead() {
		points.deleteFromHead();
	}

	void deletePointFromTail() {
		points.deleteFromTail();
	}

	void show() {
		points.print();
	}
};
int main()
{
	List<int> l;
	/*for (int i = 0; i < 10; i++)
	{
		l.addToHead(i);
	}
	l.print();
	cout << endl;*/


	l.addToTail(100);
	l.addToTail(200);
	l.addToTail(300);
	l.print();

	l.deleteFromTail();
	l.print();
	l.deleteFromTail();
	l.print();
	l.deleteFromTail();
	l.print();







}


