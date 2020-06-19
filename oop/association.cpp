#include <iostream>

/*
 An association is a relationship between objects.
 Aggregation and Composition are types of Association.

 Association - I have an object.
 Composition - I own the object, I created it and its doesnt exists without me.
 Aggregation - I have an object, I collected it and its existence doesnt depend on my existence.


                 /\
                /  \
               /    \
              /      \
             /        \
            /          \
           /------------\
          / composition  \
         /----------------\
        /   Aggregation    \
       /--------------------\
      /     Association      \
     --------------------------
*/

class Object {
    int x;
};

class Aggregation {
    void DoSomethingWithObj(Object obj) { }
};

class Composition {
    Object obj;
    void DoSomethingWithObj() { }
};

int main() { return 0; }
