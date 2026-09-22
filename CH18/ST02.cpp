/*

int waitTime = 12;

try 
{
    cout << "Try block entered.\n";
    if (waitTime > 30){
        throw waitTime;
    }
    cout << "Leaving Try block.\n";

}

catch(int thrownValue)
{
    cout << "Exception thrown with \n" << "waitTime equal to " << thrownValue << endl;
}

cout << "After catch block" << endl;

Try block entered.
Leaving try block.
After try block.

*/