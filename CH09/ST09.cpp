/*

a) This code assumes that \0 is correctly set at the end of data, but that is not garuanteed due to how the string is instantiated
    e.g. char ourString[Size] = "Hi there blablabla..."; would automatically insert \0 at the end but not 
    char ourString[Size];

b) 
    while (ourString[index] != '\0' && index < Size)
    {
        ourString[index] = 'X';
        index++;
    }


*/