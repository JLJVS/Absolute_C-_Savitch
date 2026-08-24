#include <iostream>
#include "salariedemployee.h"
using namespace std;
namespace SavitchEmployee
{
    class TitledEmployee : public SalariedEmployee
    {
        public:
            TitledEmployee();
            TitledEmployee(string Name, string Title, string Ssn, double Salary);
            string getTitle() const;
            void setTitle(string newTitle);
            void setName(string newName);
        private:
        string title;

    }
}