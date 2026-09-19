/*

template <class T>
void SearchTree<T>::preorderShow() const {
    preorderShow(root);
}

template<class T>
void SearchTree<T>::preorderShow(TreeNode<T>* subTreeRoot) const{
    if (subTreeRoot != NULL)
    {
        cout << subTreeRoot-> data << " ";
        preorderShow(subTreeRoot->leftLink);
        preorderShow(subTreeRoot->rightLink);
    }
}

template<class T>
void SearchTree<T>::postorderShow() const{
    postorderShow(root);
}

template<class T>
void SearchTree<T>::postorderShow(TreeNode<T>* subTreeRoot) const
{
    if (subTreeRoot != NULL)
    {
        postorderShow(subTreeRoot->leftLink);
        postorderShow(subTreeRoot->rightLink);
        cout << subTreeRoot->data << " ";
    }
}

*/