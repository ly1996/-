    /*
     * 8. String to Integer (atoi)
     * Implement atoi to convert a string to an integer.
     * 2016-2-20
     */
    public static int myAtoi(String str) {
        if (str == null || str.length() < 1) {
            return 0;
        }
        str = str.trim();   // kill add white spaces
        int i = 0;          // index of str
        char flag = '+';    // default positive
        if (str.charAt(0) == '-') {
            flag = '-';
            i++;
        } else if (str.charAt(0) == '+') {
            i++;
        }
        double res = 0;
        // abandon the non-digit char; calculate the result
        while (str.length() > i && str.charAt(i) >= '0' && str.charAt(i) <= '9') {
            res = res * 10 + str.charAt(i) - '0';
            i++;
        }
        if (flag == '-') res = -1 * res;
        if (res > Integer.MAX_VALUE) {
            return Integer.MAX_VALUE;
        } else if (res < Integer.MIN_VALUE) {
            return Integer.MIN_VALUE;
        }
        return (int) res;
    }