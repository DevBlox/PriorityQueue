#include <PriorityQueue.h>
#include <PriorityQueue_impl.h>

extern "C"
{
	template class __declspec(dllexport) Uni::PriorityQueue<int>;
	template class __declspec(dllexport) Uni::PriorityQueue<unsigned int>;
	template class __declspec(dllexport) Uni::PriorityQueue<long>;
	template class __declspec(dllexport) Uni::PriorityQueue<unsigned long>;
	template class __declspec(dllexport) Uni::PriorityQueue<long long>;
	template class __declspec(dllexport) Uni::PriorityQueue<short>;
	template class __declspec(dllexport) Uni::PriorityQueue<unsigned short>;
	template class __declspec(dllexport) Uni::PriorityQueue<char>;
	template class __declspec(dllexport) Uni::PriorityQueue<unsigned char>;
	template class __declspec(dllexport) Uni::PriorityQueue<float>;
	template class __declspec(dllexport) Uni::PriorityQueue<double>;
	template class __declspec(dllexport) Uni::PriorityQueue<bool>;
}