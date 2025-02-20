#include <iostream>
#include <string>
using namespace std;

int main(){
    char quant[4] = {'\0' , '\0' , '\0' , '\0'};
    int index = 0;
    int numbers_left = 245;
    int digit = log10(numbers_left);
    cout << digit << endl;
    for(int i = digit ; i >= 0 ; i--){
        quant[i] = numbers_left % 10 + '0';
        numbers_left = numbers_left / 10;
    }
    for(int i = 0 ; i < 4 ; i++){
        cout << "quant[i] = " << quant[i] << endl;
    }
}