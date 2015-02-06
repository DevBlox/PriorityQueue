#ifndef UNI_PRIORITY_QUEUE
#define UNI_PRIORITY_QUEUE

#include <vector>

template<class Type> class PriorityQueue // Template <[desired type]>
{
	public:
	
		/// Constructors
		PriorityQueue(bool (*func)(Type, Type)); // Empty queue
		PriorityQueue(Type*, unsigned int, bool (*func)(Type, Type)); // Queue from array
		PriorityQueue(std::vector<Type>, bool (*func)(Type, Type)); // Queue from vector
		
		/// Destructor
		~PriorityQueue();
		
	private:
	
		/// Constant
		const unsigned int startingReserve; // With what number of elements the queue should start with
		const unsigned int reserveIncrement; // How big will the increments of size be
	
		/// Main working variables
		Type *workingArray; // Working array
		unsigned int currentlyAllocated; // What size is now allocated to the array
		unsigned int lastElement; // Where is the last element located
		
		/// Determining function/method pointer
		bool (*determine)(Type, Type);
};

#endif // UNI_PRIORITY_QUEUE