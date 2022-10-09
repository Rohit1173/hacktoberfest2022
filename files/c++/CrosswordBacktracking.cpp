#include <iostream>
using namespace std;

char crossword[10][10];

bool isValidHorizontal(int row, int col, string word)
{
    if(10 - col < word.length())
    {
        return false;
    }
    int j = col;
    for(int i=0; i<word.length(); i++)
    {
        if(crossword[row][j] != '-' && crossword[row][j] != word[i])
        {
            return false;
        }
        j++;
    }
    return true;
}
void setHorizontal(int row, int col, string word, bool state[])
{
    int j = col;
    for(int i=0; i<word.length(); i++)
    {
        if(crossword[row][j] == '-')
        {
            crossword[row][j] = word[i];
            state[i] = true;
        }
        else if(crossword[row][j] == word[i])
        {
            state[i] = false;
        }
        j++;
    }
}
void resetHorizontal(int row, int col, bool state[], int size)
{
    int j = col;
    for(int i=0; i<size; i++)
    {
        if(state[i] == true)
        {
            crossword[row][j] = '-';
            state[i] = false;
        }
        j++;
    }
}

bool isValidVertical(int row, int col, string word)
{
    if(10 - row < word.length())
    {
        return false;
    }
    int j = row;
    for(int i=0; i<word.length(); i++)
    {
        if(crossword[j][col] != '-' && crossword[j][col] != word[i])
        {
            return false;
        }
        j++;
    }
    return true;
}
void setVertical(int row, int col, string word, bool state[])
{
    int j = row;
    for(int i=0; i<word.length(); i++)
    {
        if(crossword[j][col] == '-')
        {
            crossword[j][col] = word[i];
            state[i] = true;
        }
        else if(crossword[j][col] == word[i])
        {
            state[i] = false;
        }
        j++;
    }
}
void resetVertical(int row, int col, bool state[], int size)
{
    int j = row;
    for(int i=0; i<size; i++)
    {
        if(state[i] == true)
        {
            crossword[j][col] = '-';
            state[i] = false;
        }
        j++;
    }
}

void solveCrossword(string input[], int index, int length)
{
    if(index == length)
    {
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
            {
                cout<<crossword[i][j];
            }
            cout<<endl;
        }
        return;
    }
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(crossword[i][j] == '-' || crossword[i][j] == input[index][0])
            {
                int size = input[index].length();
                bool state[size];

                if(isValidHorizontal(i, j, input[index]))
                {
                    setHorizontal(i, j, input[index], state);
                    solveCrossword(input, index + 1, length);
                    resetHorizontal(i, j, state, size);
                }
                if(isValidVertical(i, j, input[index]))
                {
                    setVertical(i, j, input[index], state);
                    solveCrossword(input, index + 1, length);
                    resetVertical(i, j, state, size);
                }
            }
        }
    }
}
int main()
{
    for(int i=0; i<10; i++)
    {
        string str;
        cin>>str;
        for(int j=0; j<str.length(); j++)
        {
            crossword[i][j] = str[j];
        }
    }
    string names, input[6], word = "";
    cin>>names;
    int len = 0;
    for(int i=0; i<names.length(); i++)
    {
        if(names[i] == ';')
        {
            input[len++] = word;
            word = "";
        }
        else
        {
            word += names[i];
        }
    }
    input[len++] = word;
    solveCrossword(input, 0, len);
    return 0;
}