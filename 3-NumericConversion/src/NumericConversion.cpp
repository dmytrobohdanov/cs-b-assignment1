#include <iostream>
#include <string>
#include "console.h"
using namespace std;

// Function prototypes
string intToString(int n);
string intToStringSubProg(int n);

int stringToInt(string str);
int stringToIntSubProg(string str);

int main() {
    while(true){
//    int x;
//    cin>>x;
//    cout<<"the string is "<<intToString(x)<<endl;
    string str;
    cin>>str;
    cout<<stringToInt(str)<<endl;
    }
    return 0;
}



//int stringToInt(string str){
//    int result=0;
//    int rankCounter=1;

//    //get int from string
//    for (int i = str.length()-1; i >= 0 ; i--){
//        int temp = str[i]-'0'; //get current value from char
//        result=result+rankCounter*temp;
//        rankCounter *=10;
//    }
//    return result;
//}


int stringToInt(string str){
    if (str[0] == '-')
        return (-1)*stringToIntSubProg(str.substr(1, str.length() - 1));

    return stringToIntSubProg(str);
}

int stringToIntSubProg(string str){
    int x=0;
    if(str == "")
        return x;
    int lengthOfString = str.length();
    x = (int)(str[lengthOfString - 1]- '0');
    return x + stringToInt(str.substr(0,lengthOfString-1)) * 10;
}



string intToString(int n){
    if (n == 0)
        return "0";
    if (n < 0){
        n=n*(-1);
        return "-"+intToStringSubProg(n);
    }
    return intToStringSubProg(n);
}

string intToStringSubProg(int n){
    string str;
    if(n == 0){
        return "";
    }
    char temp='0'+n%10;
    return intToStringSubProg((int)n/10)+temp+str;
}
