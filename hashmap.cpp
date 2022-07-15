#include<iostream>
using namespace std;

//bucket_size defines the bucket size
#define bucket_size 50000
//type represents datatype of value. typedef used so that it can be changed later.
typedef int value_type;
//type represents datatype of key. typedef used so that it can be changed later.
typedef int key_type;
//tsize_type represents datatype of total number of key-value pairs in hashmap.
typedef int size_type;


struct node
{
	key_type key;
	value_type value;
	node *next;
};

class Linkedlist
{
	node *head {nullptr};
	node *tail {nullptr};
	size_type size {0};

	node* return_node_with_key(key_type key)
	{
		node *trav = head;
		while(trav != nullptr)
		{
			if(trav -> key == key)
			{
				return trav;
			}
			trav = trav -> next;
		}
		return nullptr;
	}

public:
	bool isempty()
	{
		return size == 0;
	}

	void insert_at_tail(key_type key, value_type value)
	{
		node * required_node = return_node_with_key(key);
		if(required_node != nullptr)
		{
			required_node -> value = value;
			return;
		}

		node *newnode = new node;
		newnode -> key = key;
		newnode -> value = value;
		newnode -> next = nullptr;

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

	value_type return_value(key_type key)
	{
		node *required_node = return_node_with_key(key);
		if(required_node == nullptr)
		{
			throw 1;
		}
		return required_node->value;
	}

	void remove(key_type key)
	{
		if(head -> key == key)
		{
			node *temp = head;
			head = head -> next;
			delete temp;
		}
		else
		{
			node *trav = head;
			while(trav != tail)
			{
				if( (trav -> next) -> key == key )
				{
					break;
				}
				trav = trav -> next;
			}
			
			if(trav == tail)
			{
				cout<<"Key not found!"<<endl;
				return;
			}

			node *node_to_delete = trav -> next;
			trav -> next = node_to_delete -> next;
			delete node_to_delete;
		}
		size--;		
	}

};

class hashmap
{
    Linkedlist bucket[bucket_size];
    size_type size {0};
public:
	void insert(key_type key, value_type value)
	{
		bucket[key % bucket_size].insert_at_tail(key, value);
	}

	void show_value(key_type key)
	{
		try
		{
			value_type value = bucket[key % bucket_size].return_value(key);
			cout<<value<<endl;
		}
		catch(int i)
		{
			cout<<"Key not found!"<<endl;
		}
	}

	void remove(key_type key)
	{
		bucket[key % bucket_size].remove(key);
	}
};

int main()
{
	hashmap m;
	m.insert(1,5);
	m.insert(4,12);
	m.insert(1,89);
	m.show_value(1);
	m.remove(1);
	m.show_value(1);
}