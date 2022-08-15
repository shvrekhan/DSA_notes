#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*next;
};

class stack{
    public:
    Node* top;
    stack()
    {
        top==NULL;
    }
    void push(int data)
    {
        Node *temp = new Node();
        if(!temp)
        {
            cout<<"Stack Over flow ";
            exit(1);
        } 
        temp->data = data;
        temp->next = top;
        top = temp;
    }

    int is_empty()
    {
        return top == NULL;
    }

    int peek()
    {
        if(!is_empty())return top->data;
        else exit(1);
    }

    void pop(){
        Node*temp;
        if(top==NULL)
        {
            cout<<"stack under flow";
            exit(1);
        }
        else{
            temp = top;
            top=top->next;
            free(temp);
        }
    }

};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.peek();
    s.pop();
    // cout<<s.peek();
    s.pop();
    cout<<s.peek();
    s.pop();
    cout<<s.peek();
    s.pop();

}