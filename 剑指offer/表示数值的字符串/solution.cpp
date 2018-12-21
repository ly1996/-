class Solution {
public:
    bool isNumeric(char* string)
    {
        if(string == nullptr)
            return false;
        bool numeric = scanInteger(&string);
        if(*string == '.')
        {
            ++ string;
            numeric = scanUnsignedInteger(&string) || numeric;
        }
        
        if(*string == 'e' || *string == 'E')
        {
            ++ string;
            numeric = scanInteger(&string) && numeric;
        }
        
        return numeric && *string == '\0';
    }
    
    bool scanUnsignedInteger(char** str)
    {
        char * before = *str;
        while(**str != '\0' && **str >= '0' && **str <= '9')
        {
            ++(*str);
        }
        
        //代表是否有一个及以上的数字
        return *str > before;
    }
    
    bool scanInteger(char** str){
        if(**str == '+' || **str == '-')
        {
            ++(*str);
        }
        return scanUnsignedInteger(str);
    }
};