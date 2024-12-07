#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> tokenize(const string& str)
{
    vector<string> tokens;
    string token;
    bool inside_quotes = false;

    // Traverse each character in the string
    for (size_t i = 0; i < str.size(); ++i)
    {
        char current_char = str[i];

        // Check if we are inside quotes
        if (current_char == '"')
        {
            if (inside_quotes)
            {
                // Closing quote, push the token
                tokens.push_back(token);
                token.clear();
            }
            // Toggle the inside_quotes flag
            inside_quotes = !inside_quotes;
        }
        else if (inside_quotes)
        {
            // Collect characters inside quotes as one token
            token += current_char;
        }
        else if (current_char == ' ')
        {
            if (!token.empty())
            {
                tokens.push_back(token);
                token.clear();
            }
        }
        else
        {
            // Collect regular characters
            token += current_char;
        }
    }

    // If there's any token left, push it
    if (!token.empty())
    {
        tokens.push_back(token);
    }

    return tokens;
}

int main()
{
    string input;

    // Get input from the user
    cout << "Enter a string: ";
    getline(cin, input);

    // Tokenize the input string
    vector<string> tokens = tokenize(input);

    // Print the tokens
    cout << "Tokens: \n";
    for (const string& token : tokens) {
        cout << token << endl;
    }

    return 0;
}