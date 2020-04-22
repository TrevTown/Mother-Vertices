#include <string>



struct Address

{

	int houseNumber = 0;

	std::string street = " ";

	std::string city = " ";

	std::string state = " ";

	int zipcode = 0;

};



class House

{

public:

	House();

	House(Address, int, int, int, int);

	Address address;

	int numBeds;

	int numBaths;

	int sqft;

	int price;

};
