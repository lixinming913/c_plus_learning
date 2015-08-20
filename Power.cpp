/*整数的n次方*/

class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent == 0)
            return 1.0;
        
    	if(base == 0)
            return 0; 
        
        if(exponent == 1)
            return base;
        
        if(exponent == -1)
            return 1/base;
        
        double result = Power(base, exponent/2);
        result *= result;
        
        return result * Power(base, exponent % 2);
    }
};