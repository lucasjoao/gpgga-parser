#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>

class GPGGAConstants {

private:

    std::vector<std::string> _messages;

public:

    GPGGAConstants() {
        _messages = {"$GPGGA,134658.00,5106.9792,N,11402.3003,W,2,09,1.0,1048.47,M,-16.27,M,08,AAAA*60",
                     "$GPGGA,183730,3907.356,N,12102.482,W,1,05,1.6,646.4,M,-24.1,M,,*75",
                     "$GPGGA,002454,3553.5295,N,13938.6570,E,1,05,2.2,18.3,M,39.0,M,,*7F",
                     "$GPGGA,023042,3907.3837,N,12102.4684,W,1,04,2.3,507.3,M,-24.1,M,,*75",
                     "$GPGGA,152926,6027.8259,N,02225.6713,E,8,09,2.0,44.7,M,20.6,M,,*79"};
    }

    std::string random_message() {
        // generate random number
        std::srand(std::time(nullptr));
        int rand = std::rand() % _messages.size();
        // return random message
        return _messages.at(rand);
    }

};

class Parser {

private:
    // size will be always 15
    std::vector<std::string> _split_message;
    std::string _delimiter = ",";

private:

    // split message argument using the _delimiter
    void split(std::string message) {
        size_t last = 0;
        size_t next = 0;
        while ((next = message.find(_delimiter, last)) != std::string::npos) {
            _split_message.push_back(message.substr(last, next-last));
            last = next + _delimiter.length();
        }
       _split_message.push_back(message.substr(last));
    }

    void calculate() {

    }

public:

    Parser() {}

    void run(std::string message) {
        split(message);
        calculate();
    }

    void print_result() {

    }
};

int main(int argc, char *argv[]) {
    GPGGAConstants *constants = new GPGGAConstants();
    Parser *parser = new Parser();

    if (argc == 2 && strcmp(argv[1], "show") == 0) {
        // just show a random gpgga message
        std::cout << constants->random_message() << "\n";
        return 0;
    } else if (argc == 2) {
        parser->run(argv[1]);
        parser->print_result();
        return 0;
    } else if (argc == 1) {
        parser->run(constants->random_message());
        parser->print_result();
        return 0;
    } else {
        std::cout << "Argumentos incorretos! Favor ver makefile e começo do main em parser.cpp";
        return 1;
    }
}
