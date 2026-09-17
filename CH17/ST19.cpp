/*

template<class T>
Queue<T>::Queue(const Queue<T>& aQueue)
{
    if (aQueue.isEmpty())
    {
        front = back = NULL;
    }else 
    {
        Node<T> *temp = aQueue.front;
        back = new Node<T>(temp->getData(), NULL);
        front = back;
        temp = temp->getLink();
        while (temp!= NULL){
            back->setLink(new Node<T>(temp->getData(), NULL));
            back = back->getLink();
            temp = temp->getLink();
        }
    }
}

*/