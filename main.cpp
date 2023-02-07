#include <iostream>

using namespace std;

struct node
{
	int data;
	node *pre, *next;
};

class dll
{
public:
	dll()
	{
		head = tail = NULL;
	}
	void createNode(int val)
	{
		node *tmp = new node;
		if(head == NULL)
		{
			head = tail = tmp;
			tmp->data = val;
			tmp->next = tmp->pre = NULL;
		}
		else
		{
			tail->next = tmp;
			tmp->pre = tail;
			tmp->data = val;
			tail = tmp;
		}
	}
	void push(int val)
	{
		node *tmp = new node;
		tmp->data = val;
		tmp->next = head;
		head->pre = tmp;
		head = tmp;
		tmp = NULL;
	}
	
	void insert(int pos, int val)
	{
		node *curr, *pre;
		curr = head;
		node *tmp = new node;
		for(int i = 1; i < pos ; ++i)
		{
			pre = curr;
			curr = curr->next;
		}
		tmp->data = val;
		tmp->pre = pre;
		tmp->next = curr;
		pre->next = tmp;
		curr->pre = tmp;
		tmp = NULL;
	}
	void displayS()
	{
		node *tmp = new node;
		tmp = head;
		while(tmp != NULL)
		{
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		puts("");
	}
	void displayE()
	{
		node *tmp = new node;
		tmp = tail;
		while(tmp != NULL)
		{
			cout << tmp->data << " ";
			tmp = tmp->pre;
		}
		puts("");
	}
private:
	node *head, *tail;
};

int main()
{
	dll l;
	l.createNode(30);
	l.createNode(40);
	l.push(10);
	l.insert(2, 20);
	l.displayS();
	l.displayE();
	return 0;
}
