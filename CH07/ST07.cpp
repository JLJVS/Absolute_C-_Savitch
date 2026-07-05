class DayOfYear
{
    public:
        DayOfYear(int monthValue, int dayValue);
        DayOfYear(int monthValue);
        DayOfYear( );
        void input();
        void output( );
        int getMonthNumber(){ return month;}
        int getDay( ){ return day;}
    private:
        int month;
        int day;
        void testDate( );
};