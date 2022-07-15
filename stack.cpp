#include<iostream>
using namespace std;

//type represents datatype of data in the stack. typedef used so that it can be changed later.
typedef int type;
//tsize_type represents datatype of size (or length) variable in the stack.
typedef int size_type;

struct node
{
    type data;
    node *next;
};


class stack
{
    node *top {nullptr};
    size_type size {0};

    void recursive_reverse(node *curr, node *prev)
    {
        if(curr == nullptr)
        {
            top = prev;
            return;
        }
        recursive_reverse(curr -> next, curr);
        curr -> next = prev;
    }

public:
    void push(type element)
    {
        node *newnode = new node;
        newnode -> data = element;
        newnode -> next = top;
        top = newnode;
        size++;
    }

    void pop()
    {
        if(top == nullptr)
        {
            cout<<"Stack Underflow!"<<endl;
            return;
        }

        node *node_to_delete = top;
        top = top -> next;
        delete node_to_delete;
        size--;
    }

    void display()
    {
        if(top == nullptr)
        {
            cout<<"Empty stack"<<endl;
            return;
        }

        node *temp = top;
        while(temp != nullptr)
        {
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }

    void peek()
    {
        if(top == nullptr)
        {
            cout<<"Empty stack"<<endl;
            return;
        }

        cout<<top -> data<<endl;
    }

    void reverse()
    {
        recursive_reverse(top, nullptr);
    }
};

int main()
{
    stack s;
    s.pop();
    s.display();
    s.push(23);
    s.push(45);
    s.push(78);
    s.display();
    s.peek();
    s.pop();
    s.peek();
    s.push(23);
    s.push(45);
    s.push(78);
    s.display();
    s.reverse();
    s.display();
    return 0;
}