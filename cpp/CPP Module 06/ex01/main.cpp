#include "Serializer.hpp"

using std::cout;
using std::endl;

int main()
{
	Data data;
	data.num = 1234567;
	data.cha = 'W';
	data.msg = "Booyah steady bom bi bi";
	Data *ptr = &data; // stores address of data in ptr
	uintptr_t serial_num = Serializer::serialize(ptr); // serializes address

	cout << "Data address of pointer to data: " << ptr << endl;
	cout << "Serial number: " << serial_num << endl;
	cout << endl;

	Data *ptr2;
	ptr2 = Serializer::deserialize(serial_num); // recieves serialized address and converts it back into a usable form
	cout << "Int from ptr2: " << ptr2->num << endl;
	cout << "Char from ptr2: " << ptr2->cha << endl;
	cout << "Message from ptr2: " << ptr2->msg << endl;
}
