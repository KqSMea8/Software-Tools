#1.Implement a function product to multiply 
#2 numbers recursively using + and -operators only

#!/usr/bin/env python
import sys



def product(a, b):
    if(a<b):
        return product(b,a)
    elif(b!=0):
        return(a+product(a,b-1))
    else:
        return 0



if __name__ == "__main__":
     num1 = int(sys.argv[1])
     num2 = int(sys.argv[2])
     num3 = product(num1, num2)
     print "The Product is " + str(product(num1, num2))
