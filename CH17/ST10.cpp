/*

If we insert into a linked list we need to:
- move to the desired position
- note the next pointer
- create the new node
- connect the current to the new node
- move to the new node 
- connect to the original next pointer

If we insert into an array:
- we need to move all entries after the insert to the right
- insert into the now vacant entry.

*/