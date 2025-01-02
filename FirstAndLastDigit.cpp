# include<iostream>
using namespace std;
void fun(int x, int* first_digits, int* last_digits){
    *last_digits = x%10;
    while(x>9){
        x/=10;
        *first_digits = x%10;
    }
    return;
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int first_digits, last_digits;
    int* ptr1 = &first_digits;
    int* ptr2 = &last_digits;
    fun(n, &first_digits, &last_digits);
    cout<<first_digits<<" "<<last_digits;
    return 0;
}