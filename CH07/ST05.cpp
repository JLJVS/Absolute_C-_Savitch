/*

A call by value will create a copy in the function scope. This can be expensive when it's a class because the class needs to be constructed again with its constructor.

A call by reference with const in front of it will read the class values with the garuantee that the class values can't be touched.

*/