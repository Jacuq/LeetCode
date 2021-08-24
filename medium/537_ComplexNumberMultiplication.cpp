class Solution {
public:
    //complex number definition to simplify code
    struct complex{
        int real;
        int im;
        complex(int r, int i) : real(r), im(i) {};
        complex(string num)
        {
            int real_index = num.find("+");
            real = atoi((num.substr(0, real_index)).c_str());
            im = atoi((num.substr(real_index+1, num.length()-real_index-2)).c_str());
        }
    };
    
    string complexNumberMultiply(string num1, string num2) {
        //convert to struct for convienience and readability
        complex n1 = complex(num1);
        complex n2 = complex(num2);
    
        int result_real = n1.real * n2.real - n1.im * n2.im;
        int result_im = n1.im * n2.real + n1.real * n2.im;
        
        return to_string(result_real) + "+" + to_string(result_im)+"i";
    }
};