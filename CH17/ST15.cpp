/*
template<class T>
Stack<T>& Stack<T>::operator =(const Stack<T>& rightSide)
{
    if (top == rightSide.top)                   //if two stacks are the same
    return *this ;
else
                                                //send left side back to freestore
{
T next;
while (! isEmpty( ))
    next = pop( );                              //remove calls delete .
}
if (rightSide.isEmpty( ))
{
    top = NULL;
    return *this ;
}
else
{
    Node<T> *temp = rightSide.top;              //temp moves through
                                                //the nodes from front top to bottom of rightSide .
    Node<T> *end; //Points to end of the left-side stack .
    end = new Node<T>(temp->getData( ), NULL);
    top = end;;
                                                //First node created and filled with data .
                                                //New nodes are now added AFTER this first node .
    temp = temp->getLink( );//Move temp to second node
                                                //or set to NULL if there is no second node .
    while (temp != NULL)
    {
        end->setLink(
        new Node<T>(temp->getData( ), NULL));
        temp = temp->getLink( );
        end = end->getLink( );
    }
//end->link == NULL;
    return *this ;
}
}

*/