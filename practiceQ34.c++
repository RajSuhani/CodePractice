#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
        int startWith0 = 0;  
        int startWith1 = 0; 
        
        for(int i = 0; i < n; i++) {
            char expected0 = (i % 2 == 0) ? '0' : '1';
            char expected1 = (i % 2 == 0) ? '1' : '0';
            
            if(s[i] != expected0) startWith0++;
            if(s[i] != expected1) startWith1++;
        }
        
        return min(startWith0, startWith1);
    }
};

int main() {
    Solution obj;
    
    string s;
    cout << "Enter binary string: ";
    cin >> s;
    
    cout << "Minimum operations: " 
         << obj.minOperations(s) << endl;

    return 0;
}