# include <iostream>
using namespace std;
class stack{
    public:
    int top;
    int *arr;
    int size;
    stack(int size){
        top=-1;
        this ->size=size;
        arr=new int[size];
    }
    friend stack operator+(stack,int );
     friend stack operator-(stack);
    friend ostream&operator<<(ostream& out,stack s);
};
stack operator+(stack s,int a){
    if(s.top==s.size-1)
    cout<<"Stack Overflow!!"<<endl;
    else{
        s.arr[++s.top]=a;
    }
    return s;
}
stack operator-(stack s){
    if(s.top==-1)
    cout<<"Stack Underflow!!";
    else {
        cout<<"deleted elements is: "<<s.arr[s.top--]<<endl;
    }
    return s;
}
ostream &operator<<(ostream&out,stack s){
        int t=s.top;
        while(t!=-1)
        {
            out<<s.arr[t]<<" ";
            t--;
        }
    return out;
}
int main(){
stack s(5);
s=s+14;
s=s+40;
s=s+54;
s=s+49;
s=s+41.;,lkm  ;
cout<<s<<endl;
s=-(s);
cout<<s<<endl;

return 0;
}