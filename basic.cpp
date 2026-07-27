#include <iostream>
using namespace std;

//count digit
int countdigit(int num){
    int count=0;
    if(num==0) return 1;
    while (num>0)
    {
        num=floor(num/10);
        count++;
    }
    cout<<count;   
}
int main() {
    int num=99020;
    countdigit(num);
    return 0;
}


//count odd digits
 int odddigit(int num){
    int countodd=0;
    while(num>0){
        int lastdigit=num%10;
        if(lastdigit%2==1) countodd=countodd + 1;
        num=num/10;
    }
    cout<<countodd;
}
 int main(){
    int num=2115;
    odddigit(num);
    return 0;
}


//reverse a number
int reversenum(int num){
    if(num==0){
        cout<<0;
    }
    int revnum=0;
    while(num>0){
        int lastdigit=num%10;
        revnum=(revnum*10)+lastdigit;
        num/=10;
    }
    cout<<revnum;
}
int main(){
    int num=98207;
    reversenum(num);
}


//palindrome number
int palindrome(int num){
    int original =num;
        if(num==0){
        cout<<0;
    }
    int revnum=0;
    while(num>0){
        int lastdigit=num%10;
        revnum=(revnum*10)+lastdigit;
        num/=10;
    }
    cout<<revnum<<endl;
    if(original==revnum){
        cout<<"This is palindrome!";
    }
    else{
        cout<<"This is not a palindrome";
    }
}
int main(){
    int num=535;
    palindrome(num);
}


//largest in the num
int largest(int num){
    int largestnum=0;
    while(num>0){
        int rev=num%10;
        num=num/10;
        if(largestnum < rev){
            largestnum=rev;
        }
    }
    cout<<largestnum;
}
int main(){
    int num=439;
    largest(num);
}


//factorial of a number
int factorial(int num){
    if(num==0 or num==1){
        return 1;
    }
    else{
        return num * factorial(num-1);
    }           
}
int main(){
    int num=5;
    cout<<factorial(num);
}


//armstrong number
int armstrong(int num){
    int sum=0;
    int original = num;
    int count=(num==0)?1:(log10(num)+1);
    while (num>0)
    {
        int lastdigit=num % 10;
        sum = sum + pow(lastdigit,count);
        num=num/10;
    }
    if(original==sum){
        cout<<"This is armstrong number";
    }else{
        cout<<"This is not an armstrong number";
    }
}
int main(){
    int num=9;
    armstrong(num);
}


//perfect number - brutforce
int perfect_number(int num){
    int sum=0;
    for(int i=1; i<num; i++){
        if(num%i==0){
            sum=sum+i;
        }
    }
    if(sum==num){
        cout<<"This is the perfect number";
    }else{
        cout<<"This is not a perfect number";
    }
}
int main(){
    int num=6;
    perfect_number(num);
}


//perfect number - optimal
int perfect_number(int num){
    int sum=1;
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            sum=sum+i;
            if(i!=(num/2)) sum=sum+(num/2);
        }
    }
    if(sum==num){
        cout<<"This is the perfect number";
    }else{
        cout<<"This is not a perfect number";
    }
}
int main(){
    int num=12;
    perfect_number(num);
}


//check for prime number
void prime_number(int num){
    if(num<=1) {
        cout<<"false";
        return;
    }
    for(int i=2; i*i<=num; i++){
        if(num%i==0) {
            cout<<"false"; 
            return;
        }
    }
    cout<<"true";
}
int main(){
    int num=73;
    prime_number(num);
    return 0;
}


//count of prime numbers till n
bool is_prime(int num){
    if(num<=1) return false;
    for(int i=2; i*i<=num; i++){
        if(num%i==0) return false;
    }
    return true;
}
int count_prime(int n){
    int count=0;
    for(int i=2; i<=n; i++){
        if(is_prime(i)){
            count++;
        }
    }
    cout<<count;
    return count;
}
int main(){
    int num=200;
    count_prime(num);
    return 0;
}


//GCD - Good
int gcd(int n1,int n2){
    int largest=1;
    for(int i=2;i<min(n1,n2);i++){
        if(n1%i==0 && n2%i==0) largest=i;
    }
    cout<<largest;
}
int main(){
    int n1=10;
    int n2=6;
    gcd(n1,n2);
}


//GCD - optimal (method)
int gcd(int n1,int n2){
    while (n1!=0 && n2!=0)
    {
        if(n1>n2) {
            n1= n1%n2;
        }
        else {
            n2=n2%n1;
        }
    }
    if(n1==0) return n2;
    return n1;
}
int main(){
    int n1=35;
    int n2=10;
    cout<<gcd(n1,n2);
    return 0;
}


//LCM
int lcm(int n1, int n2){
    int i=1;
    int maxnum=max(n1,n2);
    do{
        int multiple=i*maxnum;
        if(multiple%n1==0 && multiple%n2==0) return multiple;
        i += 1;
    }while(1);
}
int main(){
    int n1=3;
    int n2=5;
    cout<<lcm(n1,n2);
}