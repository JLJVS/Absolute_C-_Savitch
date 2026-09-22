/*

int waitTime =46;

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

first enters the try bock;
second Exception thrown
waitTime equal to 46;
After catch block;

*/