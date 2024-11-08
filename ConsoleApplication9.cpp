#include <iostream>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;

class String {
public:
    String() : length(80) {
        str = new char[length + 1];
        str[0] = '\0';
        ++object_count;
    }

    String(int len) : length(len) {
        str = new char[length + 1];
        str[0] = '\0';
        ++object_count;
    }

    String(const char* input) : length(strlen(input)) {
        str = new char[length + 1];
        strcpy_s(str, length + 1, input);
        ++object_count;
    }

    ~String() {
        delete[] str;
        --object_count;
    }

    static int getObjectCount() {
        return object_count;
    }

    void input() {
        cout << "Enter string: ";
        cin.getline(str, length + 1);
    }

    void display() const {
        cout << "String: " << str << endl;
    }

private:
    char* str;
    size_t length;
    static int object_count;
};

int String::object_count = 0;

int main() {
    String defaultString;
    String customSizeString(100);
    String initializedString("Hello, world!");

    defaultString.input();
    defaultString.display();

    customSizeString.input();
    customSizeString.display();

    initializedString.display();

    cout << "Total String objects created: " << String::getObjectCount() << endl;

    return 0;
}
