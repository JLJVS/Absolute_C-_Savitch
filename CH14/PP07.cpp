#include <iostream>
#include <string>
#include <iomanip>

using std::cout, std::endl;
using std::string;

class Document
{
    public:
        Document() = default;
        Document(string newText);

        string getText() const;
        void setText(string newText);

        Document& operator=(const Document& rhs);
    
    
    private:
        string text {};
};

Document::Document(string newText): text{newText} {}
void Document::setText(string newText){text=newText;}
string Document::getText() const {return text;}
Document& Document::operator=(const Document& rhs)
{
    if (this == &rhs) return *this;
    text = rhs.text;
    return *this;
}


class Email : public Document
{
    public:
        // constructors
        Email() = default;
        Email(string newSender, string newRecipient, string newTitle, string newBody);

        // getters and setters
        string getSender() const {return sender;}
        void setSender(string newSender) {sender=newSender;}
        string getRecipient() const {return recipient;}
        void setRecipient(string newRecipient) {recipient=newRecipient;}
        string getTitle() const {return title;}
        void setTitle(string newTitle){title=newTitle;}
        
        // assignment operator
        Email& operator=(const Email& rhs);

    private:
        string sender;
        string recipient;
        string title;
        
};

Email::Email(string newSender, string newRecipient, string newTitle, string newBody) : Document{newBody}, sender{newSender}, recipient{newRecipient}, title{newTitle} {}
Email& Email::operator=(const Email& rhs){
    if (this == &rhs) return *this;

    Document::operator=(rhs);
    sender = rhs.sender;
    recipient = rhs.recipient;
    title = rhs.title;
    return *this;
}

class File : public Document
{
    public:
        // constructors
        File() = default;
        File(string newPath, string newBody);
        // setters and getters
        string getPath() const {return path;}
        void setPath(string newPath){path=newPath;}
        // assignment operator
        File& operator=(const File& rhs);
    private:
        string path;
};

File::File(string newPath, string newBody) : Document{newBody}, path{newPath} {}
File& File::operator=(const File& rhs){
    if (this == &rhs) return *this;

    Document::operator=(rhs);
    path = rhs.path;
    return *this;
}

bool ContainsKeyword(const Document& docObject, string keyword)
{
    if (docObject.getText().find(keyword) != string::npos)
        return true;
    return false;
}


static int failures = 0;

void check(const char* label, bool got, bool want)
{
    if (got != want) ++failures;
    cout << (got == want ? "  ok   " : "  FAIL ") << label
         << "  -> " << (got ? "true" : "false") << "\n";
}
void checkStr(const char* label, const string& got, const string& want)
{
    if (got != want) ++failures;
    cout << (got == want ? "  ok   " : "  FAIL ") << label
         << "  -> \"" << got << "\"\n";
}

int main()
{
    cout << "--- 1. construction ---\n";
    Email mail{"jon@x.com", "kim@y.com", "C++ question",
               "how do I overload operator= in c++?"};
    File  doc {"/home/jon/notes.txt", "some notes about templates and c++"};
    checkStr("mail sender   ", mail.getSender(), "jon@x.com");
    checkStr("mail title    ", mail.getTitle(),  "C++ question");
    checkStr("mail body     ", mail.getText(),   "how do I overload operator= in c++?");
    checkStr("file path     ", doc.getPath(),    "/home/jon/notes.txt");
    checkStr("file body     ", doc.getText(),    "some notes about templates and c++");

    cout << "\n--- 2. default construction ---\n";
    Email empty;
    checkStr("empty sender  ", empty.getSender(), "");
    checkStr("empty body    ", empty.getText(),   "");

    cout << "\n--- 3. mutators, including the inherited setText ---\n";
    empty.setSender("a@b.com");
    empty.setText("body set through the INHERITED setter");
    checkStr("set sender    ", empty.getSender(), "a@b.com");
    checkStr("set body      ", empty.getText(),   "body set through the INHERITED setter");

    cout << "\n--- 4. assignment copies base part AND derived part ---\n";
    Email m2;
    m2 = mail;
    checkStr("m2 sender     ", m2.getSender(), mail.getSender());
    checkStr("m2 title      ", m2.getTitle(),  mail.getTitle());
    checkStr("m2 body       ", m2.getText(),   mail.getText());     // the base part

    cout << "\n--- 5. the copies are independent ---\n";
    m2.setText("changed");
    m2.setSender("someone@else.com");
    checkStr("m2 body       ", m2.getText(),     "changed");
    checkStr("mail body     ", mail.getText(),   "how do I overload operator= in c++?");
    checkStr("mail sender   ", mail.getSender(), "jon@x.com");

    cout << "\n--- 6. chaining and self-assignment ---\n";
    Email m3, m4;
    m4 = m3 = mail;
    checkStr("m3 body       ", m3.getText(),   mail.getText());
    checkStr("m4 sender     ", m4.getSender(), mail.getSender());
    mail = mail;
    checkStr("self-assigned ", mail.getText(), "how do I overload operator= in c++?");

    File f2;
    f2 = doc;
    checkStr("f2 path       ", f2.getPath(), "/home/jon/notes.txt");
    checkStr("f2 body       ", f2.getText(), doc.getText());

    cout << "\n--- 7. assigning from a const object and from a temporary ---\n";
    const Email constMail{"c@x.com", "d@y.com", "const", "const body"};
    Email m5;
    m5 = constMail;                        // needs the const Email& parameter
    checkStr("from const    ", m5.getText(), "const body");
    m5 = Email{"t@x.com", "u@y.com", "temp", "temporary body"};
    checkStr("from temporary", m5.getText(), "temporary body");

    cout << "\n--- 8. substitution: Email and File as const Document& ---\n";
    check("mail contains \"c++\"     ", ContainsKeyword(mail, "c++"),      true);
    check("mail contains \"python\"  ", ContainsKeyword(mail, "python"),   false);
    check("doc  contains \"template\"", ContainsKeyword(doc,  "template"), true);
    check("doc  contains \"balrog\"  ", ContainsKeyword(doc,  "balrog"),   false);
    check("empty doc contains \"\"   ", ContainsKeyword(Document{}, ""),   true);

    cout << "\n--- 9. a heterogeneous collection through the base ---\n";
    const Document* library[] { &mail, &doc, &m2 };
    int hits = 0;
    for (const Document* d : library) if (ContainsKeyword(*d, "c++")) ++hits;
    cout << "  documents mentioning \"c++\": " << hits << " of 3\n";
    if (hits != 2) ++failures;

    cout << (failures ? "\nSOME CHECKS FAILED\n" : "\nall checks passed\n");
    return failures;
}