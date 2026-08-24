namespace SavitchEmployees
{
    TitledEmployee::TitledEmployee() : SalariedEmployee(), title("No title yet")
    {

    }
    TitledEmployee::TitledEmployee(string Name, string Title, string Ssn, double Salary) : SalariedEmployee(Name, Ssn, Salary), title(Title)
    {

    }

    void Titledemployee::setName(string Name)
    {
        Employee::setName(title + Name);
    }
}