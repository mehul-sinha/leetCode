class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char, int> mp; //hashmap solution
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int sum = 0;
        
        if(s.size()==1)
            return mp[s[0]];
        
        for(int i = 0; i<s.size()-1; i++)
        {
            if(((s[i] == 'I' && s[i+1] == 'V') || (s[i] == 'I' && s[i+1] == 'X'))
                || ((s[i] == 'X' && s[i+1] == 'L') || (s[i] == 'X' && s[i+1] == 'C'))
               || ((s[i] == 'C' && s[i+1] == 'D') || (s[i] == 'C' && s[i+1] == 'M')))
            {
                sum = sum - mp[s[i]];
            }
            else
            {
                sum = sum + mp[s[i]];
            }
        }
        
        sum = sum + mp[s[s.length()-1]];
        
        return sum;
    }
};
