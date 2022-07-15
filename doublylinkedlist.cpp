#include<iostream>
using namespace std;

//type represents datatype of data in the linkedlist. typedef used so that it can be changed later.
typedef int type;
//tsize_type represents datatype of size (or length) variable in the linkedlist.
typedef int size_type;

struct node
{
	type data;
	
	node *next;
	node *prev;
};

class Linkedlist
{
	node *head {nullptr};
	node *tail {nullptr};
	size_type size {0};

	node *returnnode(int index)
	{
		node *temp = head;
		for(size_type i = 0; i < index; i++)
		{
			temp = temp -> next;
		}
		return temp;
	}

public:

	void insert_at_head(type element)
	{
		node *newnode = new node;
		newnode -> data = element;
		newnode -> prev = nullptr;
		newnode -> next = head;
		
		if(size == 0)
		{
			head = tail = newnode;
		}
		else
		{
			head -> prev = newnode;
			head = newnode;
		}
		size++;
	}

	void insert_at_tail(type element)
	{
		node *newnode = new node;
		newnode -> data = element;
		newnode -> next = nullptr;
		newnode -> prev = tail;

		if(size == 0)
		{
			head = tail = newnode;
		}
		else
		{
			tail -> next = newnode;
			tail = newnode;
		}
		size++;
	}

	void insert_at_index(type element, size_type index)
	{
		if(index == 0)
		{
			insert_at_head(element);
		}
		else if(index < 0 || index >= size)
		{
			cout<<"Invalid Index."<<endl;
			return;
		}
		else
		{
			node *newnode = new node;
			newnode -> data = element;

			node *prevnode = returnnode(index - 1);
			node *nextnode = prevnode -> next;

			newnode -> next = nextnode;
			newnode -> prev = prevnode;
			prevnode -> next = newnode;
			nextnode -> prev = newnode;

			size++;
		}
	}

	bool isempty()
	{
		return size == 0;
	}

	void clear_list()
	{
		node *temp;
		while(head != nullptr)
		{
			temp = head;
			head = head -> next;
			delete temp;
		}
		tail = nullptr;
		size = 0;
	}

	size_type returnindex(type element)
	{
		node *temp = head;
		for(size_type i = 0; i < size; i++, temp = temp -> next)
		{
			if(temp -> data == element)
			{
				return i;
			}
		}
		return -1;
	}

	void search(type element)
	{
		size_type index = returnindex(element);

		if(index == -1)
		{
			cout<<element<<" was not found in the list!"<<endl;
			return;
		}

		cout<<element<<" found at index "<<index<<"!"<<endl;
	}

	size_type returnsize()
	{
		return size;
	}

	void remove_at_head()
	{
		if(size == 0)
		{
			cout<<"Underflow!"<<endl;
			return;
		}

		node *node_to_remove = head;

		if(head == tail)
		{
			head = tail =  nullptr;
		}
		else
		{
			head  = head -> next;
			head -> prev = nullptr;
		}

		delete  node_to_remove;
		size--;
	}

	void remove_at_tail()
	{
		if(size == 0)
		{
			cout<<"Underflow!"<<endl;
			return;
		}

		node *node_to_remove = tail;
		
		if(head == tail)
		{
			head = tail = nullptr;
		}
		else
		{
			tail = tail -> prev;
			tail -> next = nullptr;
		}

		delete node_to_remove;
		size--;
	}

	void remove_at_index(size_type index)
	{
		if(index < 0 || index >= size)
		{
			cout<<"Invalid index!"<<endl;
			return;
		}

		if(index == 0)
		{
			remove_at_head();
		}
		else if(index == size - 1)
		{
			remove_at_tail();
		}
		else
		{
			node  *node_to_remove  = returnnode(index);
			node *prevnode = node_to_remove -> prev;
			node  *nextnode  = node_to_remove -> next;
			prevnode -> next = nextnode;
			nextnode -> prev = prevnode;

			delete node_to_remove;
			size--;
		}
	}

	void remove(type element)
	{
		size_type index = returnindex(element);
		if(index == -1)
		{
			cout<<"Element not found!"<<endl;
			return;
		}
		remove_at_index(index);
		cout<<"Element "<<element<<" removed from index "<<index<<"!"<<endl;
	}

	void display_at_index(size_type index)
	{
		if(size == 0)
		{
			cout<<"List empty!"<<endl;
			return;
		}

		if(index < 0 || index >= size)
		{
			cout<<"Invalid index!"<<endl;
			return;
		}

		node *node_to_display = returnnode(index);
		cout<<node_to_display -> data<<endl;
	}

	void display()
	{
		if(size == 0)
		{
			cout<<"List empty!\n";
			return;
		}
		
		node *temp = head;
		while(temp != nullptr)
		{
			cout<<temp -> data<<"  ";
			temp = temp -> next;
		}
		cout<<endl;
	}

	void reverse()
	{
		node *trav = head;
		while(trav != nullptr)
		{	
			node *temp = trav -> next;
			trav -> next = trav -> prev;
			trav -> prev = temp;
			
			trav = trav -> prev;		//node that used to be next earlier in now previous
		}

		node *temp = head;
		head = tail;
		tail = temp;
	}
};

int main()
{
	Linkedlist l;
	cout<<l.isempty()<<endl;
	l.insert_at_head(23);
	l.display();
	l.insert_at_head(34);
	l.display();
	l.insert_at_tail(88);
	l.display();
	l.insert_at_index(6, 5);
	l.clear_list();
	l.display();
	l.insert_at_index(6, 0);
	l.display();
	l.insert_at_head(23);
	l.display();
	l.insert_at_head(34);
	l.display();
	l.insert_at_tail(88);
	l.display();
	l.insert_at_index(1, 3);
	l.display();
	l.display_at_index(2);
	l.remove_at_head();
	l.display();
	l.remove_at_tail();
	l.display();
	l.remove_at_index(2);
	l.display();
	l.remove(45);
	l.display();
	l.remove(23);
	l.display();
	l.display_at_index(l.returnsize() - 1);
	l.insert_at_head(23);
	l.display();
	l.insert_at_head(342);
	l.display();
	l.insert_at_tail(88);
	l.display();
	l.insert_at_head(23);
	l.display();
	l.insert_at_head(342);
	l.display();
	l.insert_at_tail(88);
	l.display();
	l.reverse();
	l.display();
	return 0;
}