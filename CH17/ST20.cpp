/*

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rightside)
{
    if (front == rightside.front){
        return *this;
    } 
    else
    {
        T next;
        while (! isEmpty()){
            next = remove();
        }
        if (rightside.isEmpty()){
            front = back = NULL;
            return *this;
        }
        else 
        {
            Node<T> *temp = rightside.front;
            back =  new Node<T>(temp->getData(), NULL);
            front = back;
            temp = temp -> getLink();
            while (temp != NULL){
                back->setLink(new Node<T>(temp->getData(), NULL));
                back = back->getLink();
                temp = temp->getLink();
            }
        }
        return *this;
    }

}

*/