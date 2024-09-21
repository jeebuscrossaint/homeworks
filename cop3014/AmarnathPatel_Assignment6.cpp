#include <iostream>
#include <cstring>

class StringVar {
private:
    char* text;
    int max_length;

public:
    // Constructor
    StringVar(int length = 100) {
        max_length = length;
        text = new char[max_length + 1];
        text[0] = '\0';
    }

    // Destructor
    ~StringVar() {
        delete[] text;
    }

    // Function to copy a specified substring
    void copy_piece(const char* location, int num_chars) {
        strncpy(text, location, num_chars);
        text[num_chars] = '\0';
    }

    // Function to return a specified single character indicated by location
    char one_char(int location) const {
        if (location >= 0 && location < strlen(text)) {
            return text[location];
        }
        return '\0';
    }

    // Function to change a specified character indicated by location
    void set_char(int location, char new_char) {
        if (location >= 0 && location < strlen(text)) {
            text[location] = new_char;
        }
    }

    // Overloaded == operator
    bool operator==(const StringVar& other) const {
        return strcmp(text, other.text) == 0;
    }

    // Overloaded + operator for concatenation
    StringVar operator+(const StringVar& other) const {
        StringVar result(max_length + other.max_length);
        strcat(result.text, text);
        strcat(result.text, other.text);
        return result;
    }

    // Overloaded >> operator to read one word
    friend std::istream& operator>>(std::istream& input, StringVar& str) {
        input >> str.text;
        return input;
    }

    // Display the string
    void display() const {
        std::cout << text << std::endl;
    }
};

int main() {
    // Test program
    StringVar str1, str2;

    // Test copy_piece function
    str1.copy_piece("Hello, World!", 5);
    std::cout << "copy_piece: ";
    str1.display();

    // Test one_char function
    std::cout << "one_char(2): " << str1.one_char(2) << std::endl;

    // Test set_char function
    str1.set_char(0, 'h');
    std::cout << "set_char(0, 'h'): ";
    str1.display();

    // Test == operator
    str2.copy_piece("Hello, World!", 5);
    std::cout << "str1 == str2: " << (str1 == str2) << std::endl;

    // Test + operator
    StringVar str3 = str1 + str2;
    std::cout << "str1 + str2: ";
    str3.display();

    // Test >> operator
    std::cout << "Enter a word: ";
    std::cin >> str1;
    std::cout << "You entered: ";
    str1.display();

    return 0;
}
