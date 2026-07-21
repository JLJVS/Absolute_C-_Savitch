/*

a) Explain carefully why no overladed assignment operator is needed when the only data consists of built-in types.
For built ins the assignment operator is already well defined behaviour

b) now for a copy constructor 
If you only have built-ins the behaviour is already well defined

c) now for a destructor
With built-ins no dynamic memory is allocated and thus does not need to be freed.
*/