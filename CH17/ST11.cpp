class DoublyLinkedIntNode{
    public:
        DoublyLinkedIntNode(int newData, DoublyLinkedIntNode* previous=nullptr, DoublyLinkedIntNode* newNext=nullptr): data{newData}, prev {previous}, next{newNext} {}
        
        int getData() const {return data;}
        void setData(int newData) {data=newData;}
        DoublyLinkedIntNode* getPrev() const {return prev;}
        void setPrev(DoublyLinkedIntNode* newPrev) {prev=newPrev;}
        DoublyLinkedIntNode* getNext() const {return next;}
        void setNext(DoublyLinkedIntNode* newNext) {next=newNext;}
        void insert(DoublyLinkedIntNode* afterMe, int theData){
            DoublyLinkedIntNode* after   = afterMe->getNext();
            DoublyLinkedIntNode* newNode = new DoublyLinkedIntNode(theData, afterMe, after);
            afterMe->setNext(newNode);
            if (after) after->setPrev(newNode);
        }
    private:
        int data;
        DoublyLinkedIntNode* prev;
        DoublyLinkedIntNode* next;
};