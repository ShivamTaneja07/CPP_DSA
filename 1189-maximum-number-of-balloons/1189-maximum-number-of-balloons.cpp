class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0, a = 0, l = 0, o = 0, n = 0;

        for (int i = 0; i < text.length(); i++) {
            if (text[i] == 'b')
                b++;
            else if (text[i] == 'a')
                a++;
            else if (text[i] == 'l')
                l++;
            else if (text[i] == 'o')
                o++;
            else if (text[i] == 'n')
                n++;
        }

        l = l / 2; 
        o = o / 2; 

        int ans = b;

        if (a < ans) ans = a;
        if (l < ans) ans = l;
        if (o < ans) ans = o;
        if (n < ans) ans = n;

        return ans;
    }
};