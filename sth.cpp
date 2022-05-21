#include "vector.h"
using namespace std;

template <class T>
Node<T>* vector<T>::getHead() {
    return head;
}

template <class T>
Node<T>* vector<T>::getTail() {
    return tail;
}

template <class T>
void vector<T>::refreshTail() {
    Node<T>* temp = new Node <T>;
    temp = head;
    while (temp->getNext() != nullptr)
        temp = temp->getNext();
    tail->setPreview(temp);
}

template <class T>
void vector<T>::push_front(T data) {
    Node<T>* node = new Node<T> ,* tmp;
    node->createNode(data);
    tmp = head->getNext();
    head->setNext(node);
    node->setNext(tmp);
    if (tmp != NULL)
        tmp->setPreview(node);
    if (node != NULL)
        node->setPreview(head);
}

template <class T>
void vector<T>::push_back(T data) {
    Node<T>* node = new Node<T>;
    Node<T>* tmp = head;
    node->createNode(data);
    while (tmp->getNext() != nullptr)
        tmp = tmp->getNext();
    tmp->setNext(node);
    if (node != NULL)
        node->setPreview(tmp);
    refreshTail();
}

template <class T>
void vector<T>::pop_front() {
    if (head->getNext() != nullptr) {
        head->setNext(head->getNext()->getNext());
        if (head->getNext() != NULL)
            head->getNext()->setPreview(head);
    }
}

template <class T>
void vector<T>::pop_back() {
    if (head->getNext() != nullptr) {
        Node<T>* tmp = head;
        while (tmp->getNext()->getNext() != nullptr)
            tmp = tmp->getNext();
        tmp->setNext(NULL);
    }
    refreshTail();
}

template <class T>
void vector<T>::insert(T data, int index) {
    Node<T>* node = new Node<T>;
    Node<T>* tmp = head, * temp;
    node->createNode(data);
    for (int i = 0; i < index; i++) {
        if (tmp->getNext() == nullptr) {
            cout << "invalid input size!" << endl << endl;
            return;
        }
        tmp = tmp->getNext();
    }
    if (tmp->getNext() == nullptr)
        tmp->setNext(NULL);
    temp = tmp->getNext();
    tmp->setNext(node);
    node->setNext(temp);
    if (temp != NULL)
        temp->setPreview(node);
    if (node != NULL)
        node->setPreview(tmp);
    refreshTail();
}

template <class T>
void vector<T>::delet(int index) {
    Node<T>* tmp = head;
    for (int i = 0; i < index; i++) {
        if (tmp->getNext() == nullptr) {
            cout << "invalid input size!" << endl << endl;
            return;
        }
        tmp = tmp->getNext();
    }
    if (tmp->getNext() == nullptr)
        cout << "invalid input size!" << endl << endl;
    else {
        if (tmp->getNext()->getNext() == nullptr)
            tmp->getNext()->setNext(NULL);
        tmp->setNext(tmp->getNext()->getNext());
        if (tmp->getNext() != NULL)
            tmp->getNext()->setPreview(tmp);
    }
    refreshTail();
}

template <class T>
int vector<T>::search(T data) const {
    Node<T>* tmp = head->getNext();
    int index = 0;
    while (tmp != nullptr) {
        if (tmp->getData() == data)
            return index;
        index++;
        tmp = tmp->getNext();
    }
    return -1;
}

template <class T>
Node<T>* vector<T>::max() const {
    Node<T>* max = head;
    Node<T>* temp = head;
    while (temp->getNext() != NULL) {
        temp = temp->getNext();
        if (temp->getData() > max->getData())
            max = temp;
    }
    return max;
}

Node<string>* vector<string>::max() const {
    Node<string>* max = head;
    Node<string>* temp = head;
    while (temp->getNext() != NULL) {
        temp = temp->getNext();
        if (max->getData().length() < temp->getData().length())
            max = temp;
    }
    return max;
}

template <class T>
double vector<T>::average() const {
    T sum = 0;
    int n = 0;
    Node<T>* tmp = head->getNext();
    while (tmp != nullptr) {
        n++;
        sum += tmp->getData();
        tmp = tmp->getNext();
    }
    return (double)sum / n;
}

double vector<char>::average() const {
    int sum = 0, n = 0;
    Node<char>* temp = head->getNext();
    while (temp->getNext() != NULL) {
        temp = temp->getNext();
        n++;
        sum += (int)temp->getData();
    }
    return (double)sum / n;
}

double vector<string>::average() const {
    int sum = 0, n = 0;
    Node<string>* temp = head->getNext();
    while (temp->getNext() != NULL) {
        temp = temp->getNext();
        n++;
        sum += temp->getData().length();
    }
    return (double)sum / n;
}

template <class T>
void vector<T>::swap(int index1, int index2) {
    Node<T>* tmp1= head;
    Node<T>* tmp2 = head;
    T temp;
    for (int i = 0; i < index1; i++) {
        if (tmp1->getNext() == nullptr) {
            cout << "invalid input size!" << endl << endl;
            return;
        }     
        tmp1 = tmp1->getNext();
    }
    for (int i = 0; i < index2; i++) {
        if (tmp2->getNext() == nullptr) {
            cout << "invalid input size!" << endl << endl;
            return;
        }
        tmp2 = tmp2->getNext();
    }
    if (tmp1->getNext() == nullptr || tmp2->getNext() == nullptr)
        cout << "invalid input size!" << endl << endl;
    else {
        temp = tmp1->getNext()->getData();
        tmp1->getNext()->createNode(tmp2->getNext()->getData());
        tmp2->getNext()->createNode(temp);
    }
    refreshTail();
}

template <class T>
void vector<T>::print() const {
    if (head->getNext() != nullptr) {
        Node<T>* tmp1 = head->getNext();
        tmp1->printNode();
        while (tmp1->getNext() != nullptr) {
            cout << " -> ";
            tmp1->getNext()->printNode();
            tmp1 = tmp1->getNext();
        }
    }
    cout << endl << endl;
}

template <class T>
int vector<T>::length() const {
    int n = 0;
    Node<T>* temp = head;
    while (temp->getNext() != NULL) {
        temp = temp->getNext();
        n++;
    }
    return n;
}

template <class T>
void vector<T>::clear() {
    Node<T>* temp = head->getNext();
    Node<T>* node;
    temp = head->getNext();
    while (temp->getNext() != NULL) {
        node = temp;
        temp = temp->getNext();
        delete node;
    }
    head->setNext(NULL);
    tail->setPreview(NULL);
}

void vector<string>::sort() {
    int len = vector<string>::length();
    Node<string>* tmp1 = head;
    Node<string>* tmp2 = head;
    for (int i = 0; i < len + 1; i++) {
        for (int j = 0; j < len; j++) {
            if (tmp2->getData().size() > tmp1->getData().size()) {
                string temp = tmp1->getData();
                tmp1->createNode(tmp2->getData());
                tmp2->createNode(temp);
            }
            tmp2 = tmp2->getNext();
        }
        tmp2 = head;
        tmp1 = head->getNext();
        for (int n = 0; n < i; n++)
            tmp1 = tmp1->getNext();
    }
    refreshTail();
}

void vector<char>::sort() {
    int len = vector<char>::length();
    Node<char>* tmp1 = head;
    Node<char>* tmp2 = head;
    for (int i = 0; i < len + 1; i++) {
        for (int j = 0; j < len; j++) {
            if (int(tmp2->getData()) > int(tmp1->getData())) {
                char temp = tmp1->getData();
                tmp1->createNode(tmp2->getData());
                tmp2->createNode(temp);
            }
            tmp2 = tmp2->getNext();
        }
        tmp2 = head;
        tmp1 = head->getNext();
        for (int n = 0; n < i; n++)
            tmp1 = tmp1->getNext();
    }
    refreshTail();
}

template <class T>
void vector<T>::sort() {
    int len = vector<T>::length();
    Node<T>* tmp1 = head;
    Node<T>* tmp2 = head;
    for (int i = 0; i < len + 1; i++) {
        for (int j = 0; j < len; j++) {
            if (tmp2->getData() > tmp1->getData()) {
                T temp = tmp1->getData();
                tmp1->createNode(tmp2->getData());
                tmp2->createNode(temp);
            }
            tmp2 = tmp2->getNext();
        }
        tmp2 = head;
        tmp1 = head->getNext();
        for (int n = 0; n < i; n++)
            tmp1 = tmp1->getNext();
    }
    refreshTail();
}

template <class T>
vector<T>::~vector() {
    cout << "Cleared" << endl;
}
template class vector<int>;
template class vector<double>;
template class vector<char>;
template class vector<string>;