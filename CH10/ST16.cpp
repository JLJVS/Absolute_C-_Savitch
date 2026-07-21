/*

a) How does the compiler identify a destructor?
The Compiler looks for a function with the same name as the class with ~ in front.
b) Can the destructor be called explicitly?
Yes use delete
c) What does a destructor actually do?
Whatever is defined in the destructor function in the class
d) What should a desctructor do.
Delete the dynamic variables that have been allocated for the class. Can have other behaviour defined as desired.

*/