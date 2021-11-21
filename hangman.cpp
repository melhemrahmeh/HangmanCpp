#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;

std::string word;
vector<string> v;
bool guessed = false;

class random {

    public:
        string LoadRandomWord(string path)
        {
            ifstream f{ path };
            if (f.is_open()) {
                while (getline(f, word)) {
                    if (word.length() >= 4) {
                        v.push_back(word);
                    }
                }
                srand((int)time(0));
                int randomLine = rand() % v.size();
                word = v.at(randomLine);
                f.close();
            }
            if (word.back() == ' ') {
                return word.substr(0, word.size() - 2);
            }
            else {
                return word;
            }
        }
};
string getGuessedWord(string secretWord, vector<int> v) {
    string s = "";
    for (int i = 0; i < secretWord.size(); i++) {
        bool state = false;
        for (int j = 0; j < v.size(); j++) {
            if (secretWord[i] == v.at(j)) {
                s += secretWord[i];
                state = true;
            }
        }
        if (!state)
        {
            s += "_";
        }
    }
    string w = s;
    s = "";
    return w;
}

string getAvailableLetters(int start, int length, vector<int> letters) {
    string s = "";
    for (char c = start; c < start + length; c++) {
        bool state = false;
        for (size_t i = 0; i < letters.size(); i++)
        {
            if (c == letters.at(i)) {
                state = true;
                break;
            }
        }
        if (state) {
            continue;
        }
        else {
            s += c;
        }
    }
    return s;
}

    void hanger() {
        cout << " |=====" << endl;
        cout << " |    |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "---" << endl;
    }
    void head() {
        cout << " |=====" << endl;
        cout << " |   |" << endl;
        cout << " |   O" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "---" << endl;
    }
    void torso() {
        cout << " |=====" << endl;
        cout << " |    |" << endl;
        cout << " |    O" << endl;
        cout << " |    |" << endl;
        cout << " |    |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "---" << endl;
    }
    void rightArm() {
        cout << " |=====" << endl;
        cout << " |    |" << endl;
        cout << " |    O" << endl;
        cout << " |  / |" << endl;
        cout << " |    |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "---" << endl;
    }
    void leftArm() {
        cout << " |=====" << endl;
        cout << " |    |" << endl;
        cout << " |    O" << endl;
        cout << " |  / | \\" << endl;
        cout << " |    |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "---" << endl;
    }
    void rightLeg() {
        cout << " |=====" << endl;
        cout << " |    |" << endl;
        cout << " |    O" << endl;
        cout << " |  / | \\" << endl;
        cout << " |    |" << endl;
        cout << " |   / " << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "---" << endl;
    }

    void leftLeg() {
        cout << " |=====" << endl;
        cout << " |    |" << endl;
        cout << " |    O" << endl;
        cout << " |  / | \\" << endl;
        cout << " |    |" << endl;
        cout << " |   / \\" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << "---" << endl;
    }

void (*phanger) () = &hanger;
void (*phead) () = &head;
void (*ptorso) () = &torso;
void (*prightArm) () = &rightArm;
void (*pleftArm) () = &leftArm;
void (*prightLeg) () = &rightLeg;
void (*pleftLeg) () = &leftLeg;

void (*painter[7])() = { phanger, phead, ptorso, prightArm , pleftArm , prightLeg , pleftLeg };

int main()
{
    string path = "C:/Users/student/Desktop/Fall 2021/CMPS 252/Assignments/asst2/words.txt";
    random r;
    word = r.LoadRandomWord(path);
    int i = 0;
    vector<int> lettersEntered;
    vector<int> letterGuessed;
    cout << endl;
    while (i < 6 && !guessed) {
        cout << "The availabe letters are " << getAvailableLetters(97, 26, lettersEntered) << endl;
        char n;
        cout << "Please guess a letter:" << endl;
        cin >> n;
        bool inLettersEntered = false;
        for (int i = 0; i < lettersEntered.size(); i++)
        {
            if (lettersEntered[i] == n) {
                inLettersEntered = true;
                break;
            }
        }
        if (!inLettersEntered)
        {
            lettersEntered.push_back(n);
        }
        bool state = false;
        for (int k = 0; k < word.size(); k++){
            bool other = false;
            if (word[k] == n) {
                for (int i = 0; i < letterGuessed.size(); i++)
                {
                    if (n == letterGuessed[i]) {
                        other = true;
                        break;
                    }
                }
                if (!other) {
                    int res = 0;

                    for (int cnt = 0; cnt < word.length(); cnt++)
                        if (word[cnt] == n)
                            res++;

                    for (int g = 0; g < res; g++) {
                        letterGuessed.push_back(n);
                    }
                }
                state = true;
                break;
            }
        }
        if (!state) {
            i++;
        }
        state = false;
        painter[i]();
        cout << getGuessedWord(word, lettersEntered);
        cout << endl;
        cout << endl;
        cout << endl;
        if (word.size() == letterGuessed.size()) {
            guessed = true;
            cout << "Congratulations, you won!" << endl;
        }
    }
    if (word.size() > letterGuessed.size()) {
        cout << "Sorry, you ran out of guesses. The word was """ << word << ">";
    }
    return 0;
}
