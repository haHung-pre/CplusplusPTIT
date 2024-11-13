#include<iostream>
using namespace std;

template<typename T>
struct Node{
    T data;
    Node*next;
    Node(T val):data(val),next(nullptr){}
};

template<typename T>
class Stack{
    Node<T>*top;
public:
    Stack():top(nullptr){}
    void push(T val){
        Node<T>*newNode=new Node<T>(val);
        newNode->next=top;
        top=newNode;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty.\n";
            return;
        }
        Node<T>*temp=top;
        top=top->next;
        delete temp;
    }
    T peek(){
        if(isEmpty()){
            cout<<"Stack is empty.\n";
            return T();
        }
        return top->data;
    }
    bool isEmpty(){
        return top==nullptr;
    }
};

template<typename T>
class Queue{
    Node<T>*front;
    Node<T>*rear;
public:
    Queue():front(nullptr),rear(nullptr){}
    void enqueue(T val){
        Node<T>*newNode=new Node<T>(val);
        if(isEmpty()){
            front=rear=newNode;
        }else{
            rear->next=newNode;
            rear=newNode;
        }
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty.\n";
            return;
        }
        Node<T>*temp=front;
        front=front->next;
        if(front==nullptr)rear=nullptr;
        delete temp;
    }
    T getFront(){
        if(isEmpty()){
            cout<<"Queue is empty.\n";
            return T();
        }
        return front->data;
    }
    bool isEmpty(){
        return front==nullptr;
    }
};

template<typename T>
class LinkedList{
    Node<T>*head;
public:
    LinkedList():head(nullptr){}
    void insertAtEnd(T val){
        Node<T>*newNode=new Node<T>(val);
        if(isEmpty()){
            head=newNode;
        }else{
            Node<T>*temp=head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    void deleteValue(T val){
        if(isEmpty()){
            cout<<"List is empty.\n";
            return;
        }
        if(head->data==val){
            Node<T>*temp=head;
            head=head->next;
            delete temp;
            return;
        }
        Node<T>*current=head;
        while(current->next!=nullptr&&current->next->data!=val){
            current=current->next;
        }
        if(current->next==nullptr){
            cout<<"Value not found.\n";
            return;
        }
        Node<T>*temp=current->next;
        current->next=current->next->next;
        delete temp;
    }
    void display(){
        if(isEmpty()){
            cout<<"List is empty.\n";
            return;
        }
        Node<T>*temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
    bool isEmpty(){
        return head==nullptr;
    }
};

int main(){
	
    Stack<int>stack;
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout<<"Stack top element: "<<stack.peek()<<"\n";
    stack.pop();
    cout<<"Stack top element after pop: "<<stack.peek()<<"\n";
    
    Queue<int>queue;
    
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    cout<<"Queue front element: "<<queue.getFront()<<"\n";
    queue.dequeue();
    cout<<"Queue front element after dequeue: "<<queue.getFront()<<"\n";

    LinkedList<int>list;
    
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    cout<<"Linked List elements: ";
    list.display();
    list.deleteValue(20);
    cout<<"Linked List after deletion: ";
    list.display();

}

