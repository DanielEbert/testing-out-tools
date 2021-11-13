#include <iostream>
#include <string.h>

using namespace std;

class Input {
    public:
        char *input;
        int max_size;
        Input(int max_size);         

        Input(const Input& a);
        Input& operator=(const Input& a);

        Input(Input&& a);
        Input& operator=(Input&& a);
};

Input::Input(int max_size) : max_size{max_size} {
    this->input = new char[max_size]; 
    this->input[0] = 'B';
}

Input::Input(const Input& a) {
    cout << "copy constructor called" << endl;
    this->input = new char[a.max_size]; 
    memcpy(this->input, a.input, a.max_size);
    this->max_size = a.max_size;
}

Input& Input::operator=(const Input& a) {
    cout << "copy assignment called" << endl;
    delete this->input;
    this->input = new char[a.max_size]; 
    memcpy(this->input, a.input, a.max_size);
    this->max_size = a.max_size;
    return *this;
}

Input::Input(Input&& a) : input{a.input}, max_size{a.max_size} {
    cout << "move constructor called" << endl;
    a.input = nullptr;
    a.max_size = 0;
}

Input& Input::operator=(Input&& a) {
    cout << "move assignment called" << endl;
    delete this->input;
    this->input = a.input;
    this->max_size = a.max_size;
    a.input = nullptr;
    a.max_size = 0;
    return *this;
}

int main(int argc, char* argv[]) {
    cout << "Hello World!" << endl;
    Input input {100};
    Input b{100};
    b = input;
    input.input[0] = 'A';
    cout << input.input[0] << b.input[0] << endl;
    Input c = move(input);
    c.input[0] = 'C';
    cout << c.input[0] << endl;
    c = move(b);
    cout << c.input[0] << endl;
}
