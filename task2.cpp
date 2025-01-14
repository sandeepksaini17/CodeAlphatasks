#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
class Chatbot {
public:
    Chatbot() {
        responses["hello"] = "Hello! How can I assist you today?";
        responses["how are you"] = "I'm just a program, but thanks for asking!";
        responses["what is your name"] = "I am a chatbot created to assist you.";
        responses["bye"] = "Goodbye! Have a great day!";
        responses["help"] = "You can ask me about the weather, news, or just chat!";
    }
    void start() {
        string userInput;
        cout << "Welcome to the AI Chatbot! Type 'exit' to end the conversation."<<endl;
        while (true) {
         cout << "You: ";
            getline(cin, userInput);
            if (userInput == "exit") break;
            string response = processInput(userInput);
            cout << "Chatbot: " << response <<endl;
        }
    }
private:
    map<string,string> responses;
    string processInput(const string& input) {
        string lowerInput = input;
        transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);
        for (const auto& pair : responses) {
            if (lowerInput.find(pair.first) != string::npos) {
                return pair.second;
            }
        }
        if (lowerInput.find("sad") !=string::npos || lowerInput.find("bad") !=string::npos) {
            return "I'm sorry to hear that. How can I help you feel better?";
        } else if (lowerInput.find("happy") !=string::npos || lowerInput.find("good") !=string::npos) {
            return "That's great to hear! What else is on your mind?";
        }
        return "I'm not sure how to respond to that. Can you ask something else?";
    }
};
int main() {
    Chatbot chatbot;
    chatbot.start();
    return 0;
}