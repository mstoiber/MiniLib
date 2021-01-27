#include <iostream>
#include "list.h"

using namespace ml5::literals;
using std::cout;
using std::endl;

static void test_iterator() {
	//list<ml5::string> list;
	//ml5::container<ml5::string>& cities = list;
	ml5::vector<ml5::string> vec;
	ml5::container<ml5::string>& cities = vec;


	cities.add("Hagenberg"_v);
	cities.add("Pichl_bei_Wels"_v);
	cities.add("Wels"_v);
	cities.add("Linz"_v);
	cities.add("Moskau"_v);

	std::unique_ptr<ml5::iterator<ml5::string>> it = cities.make_iterator();
	while (it->not_at_end()) {
		cout << it->get_current() << endl;

		it->to_next();
	}

	cout << "-----------------------------------" << endl;
	for (const auto& city : cities) {
		cout << city << "\n";
	}
} // ml5::iterator<ml5::string>>()

static void test_list() {
	list<ml5::string> cities;

	cities.add("Hagenberg"_v);
	cities.add("Pichl_bei_Wels"_v);
	cities.add("Wels"_v);
	cities.add("Linz"_v);
	cities.add("Moskau"_v);

	cout << "Size: " << cities.size() << endl;
	cout << "Contains (Hagenberg): " << cities.contains("Hagenberg"_v) << endl;
	cout << "Contains (Wien): " << cities.contains("Wien"_v) << endl;
	cout << "Contains (Wels): " << cities.contains("Wels"_v) << endl;
}

int main () {


	std::cout << "list" << std::endl;
	cout << std::boolalpha;
	cout << "========================== test list     ========================== " << endl;
	test_list();

	cout << "========================== test iterator ========================== " << endl;
	test_iterator();
}