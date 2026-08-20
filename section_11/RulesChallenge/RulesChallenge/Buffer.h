#ifndef BUFFER_H
#define BUFFER_H

#include <cstring>
#include <iostream>
using namespace std;

class Buffer {
  public:
    Buffer(const char* input) {
        cout << "Constructor called" << endl;
        length = strlen(input);
        data = new char[length + 1];
        strcpy(data, input);
    } // end ctor

    ~Buffer() {
        cout << "Destructor called!" << endl;
        delete[] data;
    } // end dtor

    // copy ctor
    Buffer(const Buffer& other) {
        cout << "Copy constructor called" << endl;
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    // copy assignment
    Buffer& operator=(const Buffer& other) {
        cout << "Copy assignment called" << endl;
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }

        return *this;
    }

    // move constructor
    Buffer(Buffer&& other) noexcept {
        cout << "Move constructor called" << endl;
        data = other.data;
        length = other.length;
        other.data = nullptr;
        other.length = 0;
    }

    // move assignment
    Buffer& operator=(Buffer&& other) noexcept {
        cout << "Move assignment called" << endl;
        if (this != &other) {
            delete[] data;
            data = other.data;
            length = other.length;
            other.data = nullptr;
            other.length = 0;
        }

        return *this;
    }

    // print
    void print() const { cout << "Buffer contents: " << (data ? data : "null") << endl; }

  private:
    char* data;
    size_t length;
};

#endif
