#include <iostream>
#include <string>
//A
const char* _strchr(const char* string, int c) {
    while (*string != '\0') {
        if (*string == static_cast<char>(c)) {
            return string;
        }
        string++;
    }
    if (c == '\0') {
        return string;
    }
    return nullptr;
}
//B
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}
bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
bool isValidDate(const char* word) {
    int length = 0;
    const char* temp = word;
    while (*temp != '\0' && *temp != ' ') {
        length++;
        temp++;
    }
    if (length != 10) return false;
    if (word[2] != '/' || word[5] != '/') return false;
    for (int i = 0; i < 10; i++) {
        if (i != 2 && i != 5 && !isDigit(word[i])) {
            return false;
        }
    }
    int day = (word[0] - '0') * 10 + (word[1] - '0');
    int month = (word[3] - '0') * 10 + (word[4] - '0');
    int year = (word[6] - '0') * 1000 + (word[7] - '0') * 100 +
               (word[8] - '0') * 10 + (word[9] - '0');
    if (month < 1 || month > 12) return false;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeap(year)) {
        daysInMonth[1] = 29;
    }
    if (day < 1 || day > daysInMonth[month - 1]) {
        return false;
    }
    return true;
}
int countDates(const char* str) {
    int count = 0;
    bool inWord = false;
    const char* wordStart = nullptr;
    while (*str != '\0') {
        if (*str != ' ') {
            if (!inWord) {
                inWord = true;
                wordStart = str;
            }
        } else {
            if (inWord) {
                if (isValidDate(wordStart)) {
                    count++;
                }
                inWord = false;
            }
        }
        str++;
    }
    if (inWord && isValidDate(wordStart)) {
        count++;
    }
    return count;
}
//--------------------------------------------------
int main() {
    //A
    const char* str = "Hello world!";
    char c;
    std::cout << "vvedite c ";
    std::cin >> c;
    std::cin.ignore();
    const char* result = _strchr(str, c);
    if (result != nullptr) {
        std::cout << "Simvol nayden"<< std::endl;
    } else {
        std::cout << "Simvol ne nayden" << std::endl;
    }
    //B
    char input[301];
    std::cout << "vvedite stroku(max 300 simvolov): ";
    std::cin.getline(input, 301);
    int dateCount = countDates(input);
    std::cout << "kol-vo dat: " << dateCount << std::endl;

    return 0;
}
