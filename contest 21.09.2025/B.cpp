#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
 
int main() {

std::string input;
int one, two, three;
std::cin >> input;
// std::cout << input;
if (input[2] != ':') {
    int a = std::stoi(input);
    // std::cout << "\n" << a;
    one = a / 3600;
    a %= 3600;
    two = a / 60;
    three = a % 60;
    
    std::string hours = std::to_string(one);
    std::string minutes = std::to_string(two);
    std::string seconds = std::to_string(three);
    
    if (one < 10) hours = "0" + hours;
    if (two < 10) minutes = "0" + minutes;
    if (three < 10) seconds = "0" + seconds;
    
    std::string amogus = hours + ":" + minutes + ":" + seconds;
    std::cout << amogus;
}

else {
    std::string hoursStr = input.substr(0, 2);
    std::string minutesStr = input.substr(3, 2);
    std::string secondsStr = input.substr(6, 2);

    one = std::stoi(hoursStr);
    two = std::stoi(minutesStr); 
    three = std::stoi(secondsStr);

    int bob = one * 3600 + two * 60 + three;
    std::cout << bob;
}

    return 0;
}