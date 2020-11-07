
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int nums[26000];
    int counter = 0;
    string line;
    getline(cin, line);
    stringstream line1(line);
    while (!line1.eof()) {
        line1 >> nums[counter++];
    }
    int first = 1;
    int stack_num = 0;
    int stack[26000];
    bool check = false;
    for (int i = 0; i < counter; ++i) {
//        cout<<stack_num<<first<<nums[i]<<stack[stack_num-1]<<"avvale<<e"<<endl;
        if (first==stack[stack_num-1]) {
            first++;
            stack[stack_num-1]=0;
            stack_num--;
            i--;
            continue;
        }
        if (nums[i] != first) {
            stack[stack_num] = nums[i];
            stack_num++;
        }

        else {
            first++;

        }
//        cout<<stack_num<<first<<nums[i]<<stack[stack_num-1]<<endl;
    }
    if (stack_num > 1) {
        for (int i = stack_num; i > 0; --i) {
            if(stack[i]==0)
                continue;
            if (stack[i]!=first) {
//                cout<<stack[i]<<stack[i-1]<<"bb"<<endl;
                check = true;
            } else
                first++;

        }
    }
    if (check)
        cout << "no" << endl;
    else
        cout << "yes" << endl;
    return 0;
}

