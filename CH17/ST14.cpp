/*

template< class T>
stack<T>::Stack(const Stack<T>& aStack)
{
    if (aStack.isEmpty( ))
        top = NULL;
    else
    {
        Node<T> *temp = aStack.top; //temp moves through
                                    //the nodes from top to bottom of aStack .
        Node<T> *end;               //Points to end of the new stack .
        end = new Node<T>(temp->getData( ), NULL);
        top = end;
                                    //First node created and filled with data .
                                    //New nodes are now added AFTER this first node .
        temp = temp->getLink( );//move temp to second node
                                    //or NULL if there is no second node .
        while (temp != NULL)
        {
            end->setLink(
            new Node<T>(temp->getData( ), NULL));
            temp = temp->getLink( );
            end = end->getLink( );
        }
        //end->link == NULL;
    }
}

*/