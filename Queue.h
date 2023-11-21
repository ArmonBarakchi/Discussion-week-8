#ifndef WEEK8_QUEUE_H
#define WEEK8_QUEUE_H
using namespace std;
template<class T>
class Queue {
private:
    struct Node {
        T element;
        Node* next;

        Node(T _element, Node* aNextptr = NULL){
            element = _element;
            next = aNextptr;
        }
    };

    Node* front;
    Node* back;
    int numNodes;

public:
    Queue();
    ~Queue();
    void enqueue(T);
    void dequeue(T &);
    bool isEmpty();
    void clear();
};

//************************************************
// Constructor                                   *
//************************************************
template <class T>
Queue<T>::Queue(){
   numNodes = 0;
   front = NULL;
   back = NULL;
}

//************************************************
// Destructor                                    *
//************************************************
template <class T>
Queue<T>::~Queue(){
    clear();
}

//************************************************
// Function enqueue inserts the value in num     *
// at the rear of the queue.                     *
//************************************************
template <class T>
void Queue<T>::enqueue(T num) {

    Node *newNode = new Node(num);

    if(isEmpty()) {
        front = newNode;
        back = newNode;
    }

    else {
        back -> next = newNode;
        back = newNode;
    }

    numNodes++;


}
//************************************************
// Function dequeue removes the value at the     *
// front of the queue, and copies it into num.   *
//************************************************
template <class T>
void Queue<T>::dequeue(T &num) {
    if (numNodes==0) {
        cout << "Queue is empty" << endl;
        return;
    }
    else {
        Node *nodePtr = NULL;
        num = front->element;
        nodePtr = front->next;
        delete front;
        front = nodePtr;
        numNodes--;
    }


}
//************************************************
// Function isEmpty returns true if the queue    *
// is empty, and false otherwise.                *
//************************************************
template <class T>
bool Queue<T>::isEmpty() {
    if (numNodes == 0 ) {
        return true;
    }
}
//************************************************
// Function clear dequeues all the elements      *
// in the queue.                                 *
//************************************************
template <class T>
void Queue<T>::clear() {
    T value; //placeholder
    while (!isEmpty()){
        dequeue(value);
    }

}

#endif //WEEK8_QUEUE_H
