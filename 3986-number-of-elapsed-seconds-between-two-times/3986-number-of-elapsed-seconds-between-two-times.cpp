#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    int timeToSeconds(const string& t) {
        // Extract hours, minutes, and seconds using substring
        int h = stoi(t.substr(0, 2));
        int m = stoi(t.substr(3, 2));
        int s = stoi(t.substr(6, 2));
        
        return (h * 3600) + (m * 60) + s;
    }

public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int startSeconds = timeToSeconds(startTime);
        int endSeconds = timeToSeconds(endTime);
        
        return endSeconds - startSeconds;
    }
};