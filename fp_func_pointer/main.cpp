#include <iostream>

int ask() {return 42;}

typedef decltype(ask)* function_ptr;

class convertible_to_function_ptr {
public:
    operator function_ptr() const {
        return ask;
    }
};

int main(int argc, const char * argv[]) {
    auto ask_ptr = &ask;
    std::cout << ask_ptr() << std::endl;
    
    auto& ask_ref = ask;
    std::cout << ask_ref() << std::endl;
    
    convertible_to_function_ptr ask_wrapper;
    std::cout << ask_wrapper() << std::endl;
    
    return 0;
}
