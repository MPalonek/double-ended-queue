#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdexcept>


template <class T>
class doubleEndedQueue
{
private:
    struct node
    {
        node* previousNode = nullptr;
        node* nextNode = nullptr;
        T elem;

        node(T e)
        {
            elem = e;
        }
    };

    int m_size = 0; //How many elements are in queue
    node* head = nullptr;
    node* tail = nullptr;

public:
    doubleEndedQueue();
    ~doubleEndedQueue();

    T operator[](int index);
    void push_back(T elem); //insert at the end
    T pop_back(); //removes from the end
    void push_front(T elem); //insert at the begining
    T pop_front(); //removes from the begining
    T& at(int index);
    int size();
};

template <class T>
doubleEndedQueue<T>::doubleEndedQueue()
{
}

template <class T>
doubleEndedQueue<T>::~doubleEndedQueue()
{
    while (head != nullptr)
    {
        node* newTail = tail->previousNode;
        delete tail;
        if (newTail == nullptr)
        {
            head = nullptr;
        }
        tail = newTail;
    }
}

template <class T>
T doubleEndedQueue<T>::operator[](int index)
{
    // check bounds
    if ((index < 0) || (index > m_size))
        throw std::out_of_range("Out of Q bounds");
    int i = 0;
    node* nodePtr = head;
    while (i != index)
    {
        nodePtr = nodePtr->nextNode;
        i++;
    }
    return nodePtr->elem;
}

template <class T>
void doubleEndedQueue<T>::push_back(T elem)
{
    node* newNodePtr = new node(elem);
    // Q is empty, this is first node
    if (tail == nullptr)
    {
        head = newNodePtr;
        tail = newNodePtr;
    }
    else
    {
        newNodePtr->previousNode = tail;
        tail->nextNode = newNodePtr;
        tail = newNodePtr;
    }
    // increment size of Q
    m_size++;
}

template <class T>
T doubleEndedQueue<T>::pop_back()
{
    if (tail == nullptr)
    {
        throw std::out_of_range("Q empty");
    }

    T elem = tail->elem;
    if (tail == head)
    {
        delete tail;
        tail = nullptr;
        head = nullptr;
    }
    else
    {
        node* nodePtr = tail;
        tail = nodePtr->previousNode;
        delete nodePtr;
    }
    m_size--;
    return elem;
}

template <class T>
void doubleEndedQueue<T>::push_front(T elem)
{
    node* newNodePtr = new node(elem);
    // Q is empty, this is first node
    if (tail == nullptr)
    {
        head = newNodePtr;
        tail = newNodePtr;
    }
    else
    {
        newNodePtr->nextNode = head;
        head->previousNode = newNodePtr;
        head = newNodePtr;
    }
    // increment size of Q
    m_size++;
}

template <class T>
T doubleEndedQueue<T>::pop_front()
{
    if (head == nullptr)
    {
        throw std::out_of_range("Q empty");
    }

    T elem = head->elem;
    if (head == tail)
    {
        delete head;
        tail = nullptr;
        head = nullptr;
    }
    else
    {
        node* nodePtr = head;
        head = nodePtr->nextNode;
        delete nodePtr;
    }
    m_size--;
    return elem;
}

template <class T>
T& doubleEndedQueue<T>::at(int index)
{
    // check bounds
    if ((index < 0) || (index > m_size))
        throw std::out_of_range("Out of Q bounds");
    int i = 0;
    node* nodePtr = head;
    while (i != index)
    {
        nodePtr = nodePtr->nextNode;
        i++;
    }
    return nodePtr->elem;
}

template <class T>
int doubleEndedQueue<T>::size()
{
    return m_size;
}
