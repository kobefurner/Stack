#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H
#include <iostream> 

template <class Type>
struct Node
{
  Type data;
  Node<Type>* next{nullptr};
};

template <class Type>
class Stack;

template <class Type>
std::ostream& operator<<(std::ostream&, const Stack<Type>& stack);

template <class Type>
class Stack
{
friend std::ostream& operator<< <>(std::ostream&, const Stack<Type>& list);
public:
  Stack();
  Stack(const Stack& other);
  Stack<Type>& operator=(const Stack<Type>& other);
  ~Stack();

  int size() const;
  bool empty() const;
  Type top() const;
  void push(const Type&);
  void pop();
  void pop(int);
  Type topPop();
  void clear();
private:
  Node<Type>* head;
  int count;
  void printStack(Node<Type>* node, std::ostream& os) const;
};

template <class Type>
Stack<Type>::Stack()
{
  head = nullptr;
  count = 0;
}

template <class Type>
Stack<Type>::Stack(const Stack<Type>& other)
{
  head = nullptr;
  count = 0;

  Stack<Type> tempStack;
  Node<Type>* temp = other.head;
  while (temp != nullptr)
  {
    tempStack.push(temp->data);
    temp = temp->next;
  }

  temp = tempStack.head;
  while (temp != nullptr)
  {
    push(temp->data);
    temp = temp->next;
  }
}

template <class Type>
Stack<Type>& Stack<Type>::operator=(const Stack& other)
{
  if (this != &other)
  {
    clear();
    Stack<Type> tempStack;
    Node<Type>* temp = other.head;
    while (temp != nullptr)
    {
      tempStack.push(temp->data);
      temp = temp->next;
    }

    temp = tempStack.head;
    while (temp != nullptr)
    {
      push(temp->data);
      temp = temp->next;
    }
  }
  return *this;
}

template <class Type>
Stack<Type>::~Stack()
{
  clear();
}

template <class Type>
int Stack<Type>::size() const
{
  return count;
}

template <class Type>
bool Stack<Type>::empty() const
{
  if (count == 0){
    return true;
  }
  else {
    return false;
  }
}

template <class Type>
Type Stack<Type>::top() const
{
  if (head != nullptr){
    return head->data;
  }
  else {
    throw std::logic_error("Stack is empty");
  }
}

template <class Type>
void Stack<Type>::push(const Type& item)
{
  Node<Type> * newNode = new Node<Type>;
  newNode->data = item;
  newNode->next = head;
  head = newNode;
  count++;
}

template <class Type>
void Stack<Type>::pop()
{
  if (head != nullptr){
    Node<Type>* temp = head;
    head = head->next;
    delete temp;
    count--;
  }
  else {
    return;
  }
}

template <class Type>
void Stack<Type>::pop(int count)
{
  for (int i = 0; i < count; i++){
    pop();
  }
  if(empty()){
    return;
  }
}

template <class Type>
Type Stack<Type>::topPop()
{
  if (head != nullptr){
    Type ret = head->data;
    pop();
    return ret;
  }
  else {
    throw std::logic_error("Stack is empty");
  
  }
}

template <class Type>
void Stack<Type>::clear()
{
  while (head != nullptr){
    Node<Type>* temp = head;
    head = head->next;
    delete temp;
  }
  count = 0;
}

template <class Type>
void Stack<Type>::printStack(Node<Type>* node, std::ostream& os) const
{
  if (node == nullptr){
    return;
  }
  printStack(node->next, os);
  if (node->next != nullptr){
    os << "->";
  }
  os << node->data;
}

template <class Type>
std::ostream& operator<<(std::ostream& out, const Stack<Type>& list)
{
  list.printStack(list.head, out);
  return out;
}
#endif
