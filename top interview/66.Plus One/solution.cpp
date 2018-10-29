class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.size() == 0){
            return vector<int> {1};
        }
        
        if (digits.back() == 9){
            digits.pop_back();
            digits = plusOne(digits);
            digits.push_back(0);
            return digits;
        }
        else{
            digits.back()++;
            return digits;
        }
    }
};