class Node
{
    public:
        Node (double theData, Node* theLink) : data(theData), next(theLink) {}
        Node* getLink() const {return next;}
        double getData() const {return data;}
        void setData(double newData) {data=newData;}
        void setLink(Node* pointer) {next=pointer;}
    private:
        double data;
        Node* next;
};

typedef Node* Pointer;

int main()
{
    Pointer p1, p2;
    p1 = new Node(1, nullptr);
    p2 = new Node(2, nullptr);
    p1->setLink(p2);

    return 0;
}
