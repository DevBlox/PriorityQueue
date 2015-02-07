#include <PriorityQueue.h>
#include <PriorityQueue_impl.h> // <- Include for implicit instantiation

// This code compiles all needed type instances of a template.
// This is the explicit method of compilation for this code.
// You can implicitly instantiate code, for that
// you need to add the second include to your source file.
// You can add any type of template you want,
// it's also recommended to remove unused ones,
// because it generates useless code.

template class PriorityQueue<int>;