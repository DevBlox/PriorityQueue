#ifndef UNI_PRIORITY_QUEUE
#define UNI_PRIORITY_QUEUE

#include <vector>
#include <cstddef>

namespace Uni
{
	template<typename Type> class PriorityQueue // Template <[desired type]>
	{
		public:
		
			/// Constructors
			PriorityQueue(bool (*func)(Type, Type)); // Empty queue
			PriorityQueue(Type*, unsigned int, bool (*func)(Type, Type)); // Queue from array
			PriorityQueue(std::vector<Type>, bool (*func)(Type, Type)); // Queue from vector
			
			/// Destructor
			~PriorityQueue();
			
			/// Adding elements
			void Add(Type); // Adds element according to the determining function
			void Add(Type*, unsigned int); // Adds multiple elements at once, mustn't be in order
			void Add(std::vector<Type>); // Same as above, but for vectors
			
			/// Overloaded operators
			PriorityQueue<Type>& operator<<(Type); // These two do the same thing as Add() method
			PriorityQueue<Type>& operator<<(std::vector<Type>);
			Type operator[](unsigned int); // Same as At()
			
			/// Getting elements
			Type Next(); // Retrieves the next element in queue and removes it
			Type At(unsigned int); // Retrieves the element at index without removing it
			
			/// Whole class cleaning
			void Clear(); // Clears the entire queue
			
			/// Joining
			void Join(PriorityQueue<Type>&); // Joint two PriorityQueue together
			
			/// Checks
			bool IsEmpty(); // Check if empty
			unsigned int Size(); // Get number of elements
			
		protected:
		
			/// Linked list structures
			struct Node
			{
				Node(Type); // Constructor
			
				Type data;
				Node *next;
				Node *prev;
			};
			
			struct Pointer
			{
				Pointer();
				Pointer(Node*, Node*);
				
				Node *head;
				Node *tail;
			} pointer;
		
			unsigned int numElements; // Where is the last element located
			
			/// Determining function/method pointer
			bool (*determine)(Type, Type);
			
			void DeleteListRecursive(Node*); // Used for recursive list deletion
	};
}


#endif // UNI_PRIORITY_QUEUE