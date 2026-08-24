/*

No, if you don't define an overloaded assignment operator or a copy constructor for the derived class then a default assignment operator and a default copy constructor will be defined for the derived class. This can be a problem if you have pointers, dynamic arrays or other dynamic data because the default assigned constructor will have a high chance of not having the expected behaviour.

*/