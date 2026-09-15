class nodeType
{
    public:
        nodeType() {}
        nodeType(char theData, nodeType* theLink): data{theData}, link{theLink} {}
        nodeType* getLink() const {return link;}
        char getData() const {return data;}
        void setData(char newData) {data = newData;}
        void setLink(nodeType* newLink) {link = newLink;}
    private:
        char data {};
        nodeType* link;

};

typedef nodeType* PointerType;