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
        m_Tail = node;
    }

    inline void InsertAtBeginning(T data)
    {
        Node<T>* temp = new Node<T>;
        temp->SetData(data);
        temp->SetNext(m_Head);
        m_Head = temp;
    }

    inline void DeleteFirst()
    {
        Node<T>* temp = new Node<T>;
        temp = m_Head;
        m_Head = m_Head->GetNext();
        delete temp;
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
    }
};

int main()
{
    LinkedList<int> ll (1984);
    ll.InsertAtBeginning(2002);
    ll.AddData(2018);
    ll.Display();
    ll.DeleteFirst();
    ll.Display();
    return 0;
}
