#include "./Data.hpp"
#include "./Serializer.hpp"

int	main()
{
	Data		obj;
	uintptr_t	ptr;
	Data		*objPtr;

	ptr = Serializer::serialize(&obj);
	objPtr = Serializer::deserialize(ptr);
	std::cout << obj.getRandomNumber() << std::endl;
	std::cout << &obj << std::endl;
	std::cout << ptr << std::endl;
	std::cout << objPtr << std::endl;
	std::cout << (*objPtr).getRandomNumber() << std::endl;
}