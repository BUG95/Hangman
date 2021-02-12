#include <iostream>
#include <string>
#include <list>
#include <iterator>
using namespace std;

class Hangman
{
private:
    int lives;
    string word;
    list<char> listOfTries;
    int *v;
    bool gameOver = false;

    bool wordContains(char letter)
    {
        bool found = false;
        for(unsigned int i = 0; i < word.size(); i++)
        {
            if(word[i] == letter)
            {
                v[i] = 1;
                found = true;
            }
        }
        return found;
    }

    void init()
    {
        for(unsigned int i = 0; i < word.size(); i++)
        {
            v[i] = 0;
        }
    }

    void displayWord()
    {
        list<char>::iterator it;
        cout << "List of characters you typed: ";
        for(it = listOfTries.begin(); it != listOfTries.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
        for(unsigned int i = 0; i < word.size(); i++)
        {
            if(v[i] == 0)
            {
                cout << "-";
            }
            else
            {
                cout << word[i];
            }
        }
    }

    bool isGameCompleted()
    {
        for(unsigned int i = 0; i < word.size(); i++)
        {
            if(v[i] == 0)
            {
                return false;
            }
        }
        return true;
    }
    void displayLives()
    {
        cout << "Lives: " << lives << endl;
    }
    void giveFirstLetter()
    {
        wordContains(word[0]);
    }
    void readLetter()
    {
        cout << endl;
        char c;
        cin >> c;
        listOfTries.push_back(c);
        if(!wordContains(c))
        {
            lives--;
            if(lives < 0)
            {
                cout << "OUT OF LIVES\n";
                gameOver = true;
            }
        }
        if(isGameCompleted())
        {
            gameOver = true;
            displayWord();
            cout << endl;
            cout << "YOU WIN" << endl;
        }
    }
public:
    Hangman(int lives, string word)
    {
        this->lives = lives;
        this->word = word;
        v = new int[word.size()];
        init();
    }

    void start()
    {
        giveFirstLetter();
        do
        {
            displayLives();
            displayWord();
            readLetter();
        }while(!gameOver);
    }
};

int main()
{
    Hangman h(3, "abracadabra");
    h.start();
    return 0;
}
