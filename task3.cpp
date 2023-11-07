#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Reformer {
private:
    ifstream input;
    ofstream output;

public:
    Reformer(string a, string b) {
        input.open(a);
        output.open(b);
    }
    ~Reformer() {
        input.close();
        output.close();
    }
    void Reforming() {
        string line;
        bool questionAsked = false;
        while (getline(input, line)) {
            if (line[0] == '-') {
                output << line.replace(0, 1, "~") << "\n";
            }
            else if (line[0] == '+') {
                output << line.replace(0, 1, "=") << "\n";
            }
            else if (line.rfind('?') != -1) {
                if (questionAsked) {
                    output << "}\n" << line << " {\n";

                }
                else {
                    output << line << " {\n";
                    questionAsked = true;
                }
            }
        }
        output << "}\n";
    }
};



int main(){
    string nameInput;
    string nameOutput;
    cout << "Enter txt file name (with .txt) ";
    cin >> nameInput;
    cout << "Enter gift file name (with .gift) ";
    cin >> nameOutput;

    Reformer d(nameInput, nameOutput);
    d.Reforming();

    return 0;
}
