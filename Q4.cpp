#include <iostream>
#include <sstream>
using namespace std;
int main() {

    int *nums;
    nums=new int [100000]();
    int *stack=new int [1000000]();
    int counter = 0;

    string line;
    getline(cin, line);

    stringstream line1(line);
    while (!line1.eof()) {
        line1 >> nums[counter++];
    }
    int first_index=0;
    int last_index=counter-1;
    int array_index=0;
    for (int i = 0; i <=(counter/2); ++i) {
        stack[array_index]=nums[last_index];
        stack[array_index+1]=nums[first_index];
        array_index+=2;
        first_index++;
        last_index--;

    }
    if(counter%2==1){
        stack[counter-1]=nums[(counter/2)];
    }
    for (int j = 0; j <counter ; ++j) {
        cout<<stack[j]<<" ";
    }
    return 0;
}