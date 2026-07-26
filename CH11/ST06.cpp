/*

No we can't replace bigGreeting with greeting. bigGreeting is defined in the global namespace and at one point we're in both the global and the space1 /space2 namespaces. This will result in a conflict.

*/