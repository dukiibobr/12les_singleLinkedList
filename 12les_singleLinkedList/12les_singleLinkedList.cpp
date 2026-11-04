#include <iostream>
using namespace std;

class Point {
	int x;
	int y;
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int x, int y) :x(x), y(y) {}

	void pointPrint()const {
		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
		cout << endl;
	}
	friend ostream& operator<<(ostream& out, const Point& p) {
		out << "x: " << p.x << endl;
		out << "y: " << p.y << endl;
		return out;
	}
};

template<typename T>
class List
{
	struct Node
	{
		T value;
		Node* next;
		Node() :value(0), next(nullptr) {}
		Node(T value, Node* next) :value(value), next(next) {}
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
		if (head == nullptr)return;
		Node* current = head;
		head = current->next;
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
	Point p1(2, 7);
	Point p2(9, 8);
	Vector v;
	v.addPointToHead(p1);
	v.addPointToTail(p2);
	v.show();
	v.deletePointFromHead();
	v.deletePointFromTail();
	cout << "deleted below" << endl;
	v.show();





	//List<int> l;
	///*for (int i = 0; i < 10; i++)
	//{
	//	l.addToHead(i);
	//}
	//l.print();
	//cout << endl;*/


	//l.addToTail(100);
	//l.addToTail(200);
	//l.addToTail(300);
	//l.print();

	//l.deleteFromTail();
	//l.print();
	//l.deleteFromTail();
	//l.print();
	//l.deleteFromTail();
	//l.print();







}


