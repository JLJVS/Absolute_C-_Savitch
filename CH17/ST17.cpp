/*
template<class T>
void Queue::add(T item)
{
    if (isEmpty())
    {
        front = back = new Node<T>(item, NULL);
    } else
    {
        back -> setLink(new Node<T>(item, NULL));
        back = back->getLink();
    }
}

template<class T>
T Queue<T>::remove()
{
    if (isEmpty())
    {
        cout << "Error: Queue is already empty";
        exit(1);
    } 
    T result = front->getData();
    Node<T> *discard;
    discard = front;
    front = front->getLink();
    if (front == NULL){
        back = NULL;
    }
    delete discard;
    return result;
}
*/