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
};

class Linkedlist
{
	node *head {nullptr};
	node *tail {nullptr};
	size_type size {0};


	node *returnnode(size_type index)
	{
		node *temp = head;
		for(size_type i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		return temp;
	}

public:
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
			head = head->next;
			delete temp;
		}
		tail = nullptr;
		size = 0;
	}

	void insert_at_head(type element)
	{
		node *newnode = new node;;
		newnode -> data = element;
		newnode -> next = head;
		head = newnode;

		if(size == 0)
		{
			tail = head;
		}
		size++;
	}

	void insert_at_tail(type element)
	{
		node *newnode = new node;
		newnode -> data = element;
		newnode -> next = nullptr;

		if(size == 0)
		{
			tail = head = newnode;
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
		if(index == 0)							//writing this condition before because when size=0, index=0 should work
		{
			insert_at_head(element);
		}
		else if(index < 0 || index >= size)			//Index can be between 0 and size - 1 (inclusive)
		{
			cout<<"Invalid index!\n";
		}
		else
		{
			node *prevnode = returnnode(index - 1);		//node at index - 1
			node *newnode = new node;
			newnode -> data = element;
			newnode -> next = prevnode -> next;
			prevnode -> next = newnode;
			size++;
		}
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
			cout<<element<<" was not found in the linked list!\n";
			return;
		}
		
		cout<<element<<" found at index "<<index<<"!\n";
	}

	size_type returnsize()
	{
		return size;
	}

	void remove_at_head()
	{
		if(size == 0)
		{
			cout<<"Underlow!\n";
			return;
		}

		node *node_to_remove = head;

		if(head == tail)
		{
			head = tail = nullptr;
		}
		else
		{
			head = head -> next;
		}

		delete node_to_remove;
		size--;
	}

	void remove_at_tail()
	{
		if(size == 0)
		{
			cout<<"Underflow!\n";
			return;
		}

		if(head == tail)
		{
			delete tail;
			head = tail = nullptr;
		}
		else
		{
			node *prevnode = returnnode(size - 2);	//node before tail
			delete tail;
			prevnode -> next = nullptr;
			tail = prevnode;
		}
		size--;
	}

	void remove_at_index(size_type index)
	{
		if(index < 0 && index >= size)			//Index can be between 0 and size - 1 (inclusive)
		{
			cout<<"Invalid index!\n";
			return;
		}



		//Here we handled cases for head and tail differently 
		//because in those cases we need to reconfigure the hrad/tail pointers.
		
		//If this is not done the program will remove elements from index 0 and size - 1 without fixing head/tail pointers
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
			node *prevnode = returnnode(index - 1);						//for node at index-1
			node *node_to_remove = prevnode -> next;
			prevnode -> next = node_to_remove -> next;
			delete node_to_remove;
			size--;
		}
	}

	void remove(type element)
	{
		size_type index = returnindex(element);
		if(index == -1)
		{
			cout<<"Element not found!\n";
			return;
		}
		remove_at_index(index);
		cout<<"Element "<<element<<" removed from index "<<index<<"!\n";
	}

	void display_at_index(size_type index)
	{
		if(size == 0)
		{
			cout<<"List empty!\n";
			return;
		}

		if(index < 0 && index >= size)
		{
			cout<<"Invalid Index!\n";
			return;
		}

		node *node_to_display = returnnode(index);
		cout<<node_to_display->data<<endl;
	}

	void display()
	{
		if(size == 0)
		{
			cout<<"List Empty!\n";
			return;
		}

		node *temp = head;
		while(temp != nullptr)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}

	void reverse()
	{
		node *cur_node;
		node *next_node;
		node *prev_node;

		prev_node = nullptr;
		cur_node = head;
		while(cur_node != nullptr)
		{
			next_node = cur_node -> next;
			cur_node -> next = prev_node;
			prev_node = cur_node;
			cur_node = next_node;
		}

		//At end prev_node will contain address of former tail
		tail = head;
		head = prev_node;
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

// int main()
// {
// 	Linkedlist l;
// 	cout<<l.isempty()<<endl;
// 	l.insert_at_head(23);
// 	l.insert_at_head(34);
// 	l.insert_at_tail(88);
// 	l.insert_at_index(6, 5);
// 	l.clear_list();
// 	l.insert_at_index(6, 0);
// 	l.insert_at_head(23);
// 	l.insert_at_head(34);
// 	l.insert_at_tail(88);
// 	l.insert_at_index(1, 3);
// 	l.display();
// 	l.display_at_index(2);
// 	l.remove_at_head();
// 	l.display();
// 	l.remove_at_tail();
// 	l.display();
// 	l.remove_at_index(2);
// 	l.display();
// 	l.remove(45);
// 	l.display();
// 	l.remove(23);
// 	l.display();
// 	l.display_at_index(l.returnsize() - 1);
// 	l.insert_at_head(23);
// 	l.display();
// 	l.insert_at_head(342);
// 	l.display();
// 	l.insert_at_tail(88);
// 	l.display();
// 	l.insert_at_head(23);
// 	l.display();
// 	l.insert_at_head(342);
// 	l.display();
// 	l.insert_at_tail(88);
// 	l.display();
// 	return 0;
// }