#include <iostream>
#include <memory>

using namespace std;

class Song{
    public:
        volatile int duration;
        volatile char* buf;
        Song(int duration) {
            this->duration = duration;
            this->buf = new char(10);
        }
        ~Song() {
            cout << "Song destructor called" << endl;
            delete this->buf;
        }
};

int main(int argc, char* argv[]) {
    cout << "Hello World!" << endl;

    unique_ptr<Song> song(new Song{3}); 
    cout << song->duration << endl;

}
