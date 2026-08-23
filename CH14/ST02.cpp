
class Staff
{
    public:
        Staff();
        void printAnswer() const;
    private:
        int StaffID;
        int BasicSal;

};

class TemporaryStaff : public Staff 
{
    public:
        TemporaryStaff();
        TemporaryStaff( int newA, int newB, bool newMarried);
        bool isMarried() const;
    private:
        bool Married;

};