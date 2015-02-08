#ifndef UNI_PRIORITY_QUEUE
#define UNI_PRIORITY_QUEUE

#include <vector>
#include <string>

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
			
			/// Manipulating elements
			void Add(Type); // Adds element according to the determining function
			void Add(Type*, unsigned int); // Adds multiple elements at once, mustn't be in order
			void Add(std::vector<Type>); // Same as above, but for vectors
			PriorityQueue<Type>& operator<<(Type); // These two do the same thing as Add() method
			PriorityQueue<Type>& operator<<(std::vector<Type>);
			Type Next(); // Retrieves the next element in queue and removes it
			Type At(unsigned int); // Retrieves the element at index without removing it
			void Erase(unsigned int); // Erases element at index
			void Erase(Type); // Erases matching element
			Type operator[](unsigned int); // Same as At()
			void Clear(); // Clears the entire queue
			
		private:
		
			/// Constant
			const unsigned int startingReserve; // With what number of elements the queue should start with
			const unsigned int reserveIncrement; // How big will the increments of size be
		
			/// Main working variables
			Type *workingArray; // Working array
			unsigned int currentlyAllocated; // What size is now allocated to the array
			unsigned int numElements; // Where is the last element located
			
			/// Determining function/method pointer
			bool (*determine)(Type, Type);
			
			void Reallocate(); // Increases the allocated memory for the array
			void Offset(unsigned int); // Pushes the array by one element from index
	};
}

#endif // UNI_PRIORITY_QUEUE