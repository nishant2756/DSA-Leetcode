class Solution {
public:
    std::string smallestPalindrome(string s) {
        int n = s.length();
      
        sort(s.begin(), s.end());

        string result(n, ' ');
        int left = 0;
        int right = n - 1;

        int i = 0;
        while (i < n) {
           
            if (i + 1 < n && s[i] == s[i + 1]) {
                result[left] = s[i];
                result[right] = s[i + 1];
                left++;
                right--;
                i += 2; 
            } else {
               
                result[n / 2] = s[i];
                i++;
            }
        }

        return result;
    }
};