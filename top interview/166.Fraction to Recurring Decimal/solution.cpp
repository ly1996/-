class Solution {
public:
    string fractionToDecimal(int num, int denom) {
        string after = "";
        long long numerator = (long long)num;
        long long denominator = (long long)denom;
        if(denominator == 0)
            return "NaN";
        if(numerator == 0)
            return "0";
        if(numerator % denominator == 0)
            return to_string(numerator/denominator);
        
        string before;
        if((numerator > 0 && denominator > 0) || (numerator < 0 && denominator < 0))
            before = "";
        else
            before = "-";
        if(numerator < 0)
            numerator = -numerator;
        if(denominator < 0)
            denominator = -denominator;
        
        long long tmp = numerator/denominator;
        before = before + to_string(tmp) + '.';
        long long rest = numerator % denominator;
        rest *= 10;
        
        map<int,int> s;
        int index = 0;
        while(rest != 0)
        {
            if(s.find(rest) != s.end())
                return before + after.substr(0,s[rest])+'(' + after.substr(s[rest]) + ')';
            s.insert(pair<int,int>(rest,index));
            index ++;
            after += (char)((rest)/denominator + '0');
            rest = (rest)%denominator * 10;
        }
        
        return before + after;
    }
};