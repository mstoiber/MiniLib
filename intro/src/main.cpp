#include <iostream>
#include <ml5/ml5.h>

using std::cout;
using std::endl;

using namespace std::string_literals;

static void test_containers() {
    ml5::vector<std::string> cont;
    ml5::container<ml5::string>& cont = cont;

    // ml5::container<ml5::string>& cont = v;

    cont.add("Linz"s);
    cont.add("Innsbruck"s);
    cont.add("New York"s);
    cont.add("Salzburg"s);
    cont.add("Wien"s);

    cont.remove("New York"s);

    //cout << "-------------------------------- operator[] --------------------------------" << endl;
    //for (std::size_t i = 0; i < cont.size(); i++) {
    //    cout << cont[i] << endl;
    //}

    cout << "-------------------------------- iterator(1) --------------------------------" << endl;
    auto it1 = cont.make_iterator();
    while (it1->not_at_end()) {
        cout << it1->get_current() << endl;
        it1->to_next();
    }

    cout << "-------------------------------- iterator(2) --------------------------------" << endl;

    for (auto it2 = cont.make_iterator(); it2->not_at_end(); it2->to_next()) {
        cout << it2->get_current() << endl;
    }

    cout << "-------------------------------- iterator(3) --------------------------------" << endl;

    for (auto it3 = cont.begin(); it3 != cont.end(); it3++) {
        cout << *it3 << endl;
    }

    cout << "-------------------------------- iterator(4) --------------------------------" << endl;

    for (const auto &city : cont) {
        cout << city << endl;
    }

}

class my_class : public ml5::object, MI5_DERIVE(my_class, ml5::object) {
    MI5_INJECT(my_class)
public:
    my_class() = default;
    ~my_class() = default;
};


static void test_metadata() {
    ml5::string str{ "Hello" };

    cout << "-------------------------------- is a --------------------------------" << endl;
    cout << std::boolalpha;
    cout << "str.is_a<ml5::string>() -> " << str.is_a<ml5::string>() << endl;
    cout << "str.is_a<ml5::object>() -> " << str.is_a<ml5::object>() << endl;
    cout << "str.is_a<ml5::vector>() -> " << str.is_a<ml5::vector<int>>() << endl;

    cout << "-------------------------------- meta info(1) --------------------------------" << endl;
    ml5::object* obj1 = new my_class();
    const auto &meta_inf1 = obj1->get_metainfo();
    cout << "class.name() = " << meta_inf1.name() << endl;
    cout << "class.bases() = ";
    for (const auto& mi : meta_inf1.bases()) {
        cout << mi->get().name() << " ";
    }
    cout << endl;

    cout << "-------------------------------- meta info(2) --------------------------------" << endl;
    const auto& meta_inf2 = ml5::get_metainfo<my_class>();
    cout << "class.name() = " << meta_inf2.name() << endl;
    cout << "class.bases() = ";
    for (const auto& mi : meta_inf2.bases()) {
        cout << mi->get().name() << " ";
    }
    cout << endl;

    delete obj1;
}

static void test_dynamic_cast() {
    ml5::object* obj = new my_class();

    my_class* m = dynamic_cast<my_class*>(obj);
    cout << "m = " << m << endl;

    ml5::string* s = dynamic_cast<ml5::string *>(obj);
    cout << "s = " << s << endl;

}


int main () {
 std::cout << "detected os:       " << ml5::util::detected_os_as_string () << "\n"
              "detected compiler: " << ml5::util::detected_compiler_as_string () << "\n"
              "MiniLib version:   " << ml5::version << "\n" << std::endl;

 ml5::string hello{ "Hello ml5" };
 cout << hello << endl;

 cout << "============================ test containers ============================" << endl;
 test_containers();

 cout << "============================ test metadata ============================" << endl;
 test_metadata();
}
