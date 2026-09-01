class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        // Base case: agar s1 bada hai toh permutation possible hi nahi
        if (n1 > n2) return false;
        
        // 'a' se 'z' ke frequency store karne ke liye do vectors
        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);
        
        for (int i = 0; i < n1; i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }
        if (s1Count == s2Count) return true;

        for (int i = n1; i < n2; i++) {
            s2Count[s2[i] - 'a']++;
            
            s2Count[s2[i - n1] - 'a']--;
            
            if (s1Count == s2Count) {
                return true;
            }
        }
        
        return false;
        
    }
};