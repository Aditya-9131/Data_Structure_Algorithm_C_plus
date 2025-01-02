# include<iostream>
using namespace std;
int circleArea(int x){
    return 3.145*x*x;
}
int main(){
    int radius;
    cout<<"Enter the radius of the circle: ";
    cin>>radius;
   int area= circleArea(radius);
    cout<<"The area of the circle is: "<<area<<endl;
    return 0;
}