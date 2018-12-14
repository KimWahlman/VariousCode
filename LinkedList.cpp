#include <iostream>
#include <vector>

template <class T>
class LinkedList
{
    template <class U>
    class Node
    {
        T m_Data;
        Node<T>* m_Next;
        public:
            inline Node(T data) : m_Data(data) { }
            inline Node() { }

            inline void SetData(T data) { m_Data = data; }
            inline T GetData() const { return m_Data; }

            inline void SetNext(Node* next) { m_Next = next; }
            inline Node<T>* GetNext() { return m_Next; }
    };

    Node<T> *m_Head, *m_Tail;

public:
    inline LinkedList(T data)
    {
        Node<T>* node = new Node<T>(data);
        m_Head = node;
        m_Tail = node;
        node->SetNext(NULL);
    }

    inline ~LinkedList() { }

    inline void AddData(T data)
    {
        Node<T>* node = new Node<T>(data);
        m_Tail->SetNext(node);
        //m_Tail = node;
    }

    inline void InsertAtBeginning(T data)
    {
        Node<T>* temp = new Node<T>;
        temp->SetData(data);
        temp->SetNext(m_Head);
        m_Head = temp;
    }

    // This function will not change the head.
    // So index = 0 will not change the first node.
    // Nor will it change the last one.
    inline void InsertAtPosition(T data, int index)
    {
        Node<T> *current = new Node<T>,     // our current node
                *previous = new Node<T>,    // our previous node
                *temp = new Node<T>;        // The node we will insert at index.

        current = m_Head;

        for(unsigned int i = 1; i < index; i++)
        {
            // Protection against insertion beyond the end of the list.
            if(current->GetNext() == NULL) break;
            previous = current;
            current = current->GetNext();
        }
        temp->SetData(data);
        previous->SetNext(temp);
        temp->SetNext(current);
    }

    inline void DeleteFirst()
    {
        Node<T>* temp = new Node<T>;
        temp = m_Head;
        m_Head = m_Head->GetNext();
        delete temp;
        std::cout << "\nNode deleted at beginning.\n";
    }

    inline void DeleteAt(unsigned int index)
    {
        // These nodes are used to traverse the linked list
        //
        Node<T> *current = new Node<T>,
                *previous = new Node<T>;
        current = m_Head;

        for(unsigned int i = 0; i < index; i++)
        {
            if(current->GetNext() == NULL) break;
            previous = current;
            current = current->GetNext();
        }
        previous->SetNext(current->GetNext());
        delete current;
        std::cout << "\nNode deleted at position: " << index << ".\n";
    }

    inline void DeleteLast()
    {
        Node<T> *current = new Node<T>,
                *prev = new Node<T>;
        current = m_Head;
        while(current->GetNext() != NULL)
        {
            prev = current;
            current = current->GetNext();
        }
        m_Tail = prev;
        prev->SetNext(NULL);
        delete current;
        std::cout << "\nNode deleted at end.\n";
    }

    inline void Display()
    {
        Node<T>* temp = new Node<T>;
        temp = m_Head;
        while(temp != NULL)
        {
            std::cout << temp->GetData() << "\n";
            temp = temp->GetNext();
        }
        std::cout << "\n";
    }
};

int main()
{
    LinkedList<int> ll (1984);
    ll.Display();
    ll.InsertAtBeginning(2002);
    ll.Display();
    ll.AddData(2018);
    ll.InsertAtPosition(3986, 4);
    ll.Display();
    return 0;
}
