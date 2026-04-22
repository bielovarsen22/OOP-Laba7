#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

int main() {
    SinglyLinkedList<int> sList;
    DoublyLinkedList<int> dList;

    // Однозв’язний список
    sList.push_back(10);
    sList.push_back(20);
    sList.push_front(5);

    sList.print();

    sList.insert(1, 15);
    sList.print();

    sList.remove(2);
    sList.print();

    // Двозв’язний список
    dList.push_back(100);
    dList.push_back(200);
    dList.push_front(50);

    dList.print();

    dList.insert(3, 150);
    dList.print();

    dList.remove(2);
    dList.print();

    return 0;
}