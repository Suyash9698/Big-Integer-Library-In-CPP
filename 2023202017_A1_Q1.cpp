#include<iostream>
#include<string>
#include<stdlib.h>
#include<iostream>
using namespace std;
class map{
public:
    int get(char ch){
        if(ch=='+'){
           return 0;
        }
        else if(ch=='-'){
            return 0;
        }
        else if(ch=='x'){
            return 1;
        }
        else if(ch=='/'){
            return 1;
        }
        return -1;
    } 
};
class stack1{
public:
    string ar[10000];
    int tope=-1;
    stack1(){
        tope=-1;
    }
    void push(string str){
        tope++;
        ar[tope]=str;
    }
    string top(){
        if(tope==-1){
            return "";
        }
        string ele=ar[tope];
        return ele;
    }
    void pop(){
        if(tope==-1){
            return ;
        }
        tope--;
    }
    int size(){
        return tope+1;
    }
};

class stack2{
public:
    char ar[10000];
    int tope=-1;
    stack2(){
        tope=-1;
    }
    void push(char ch){
        tope++;
        ar[tope]=ch;
    }
    char top(){
        if(tope==-1){
            return ' ';
        }
        char ele=ar[tope];
        return ele;
    }
    void pop(){
        if(tope==-1){
            return;
        }
        tope--;
    }
    
    int size(){
        return tope+1;
    }
};
int a[10000];
string removeZero(string s){
    bool pre=false;
    string res="";
    for(int i=0;i<s.length();i++){
        if(s[i]!='0'){
            pre=true;
        }
        if(pre==true){
            res+=s[i];
        }
    }
    return res;
}
int fact(int num,int n){
    int rem=num;
    int carry=0;
    int i=0;
     for(i=0;i<n;i++){
        if(a[i]==-1){
            int store=(1*num)+carry;
            a[i]=store%10;
            carry=store/10;
        }
        else{
            int store=(a[i]*num)+carry;
            a[i]=store%10;
            carry=store/10;
        }
     }
     while(carry>0){
        if(a[i]==-1){
            int store=1*carry;
            a[i]=store%10;
            carry=store/10;
        }
        else{
            int store=a[i]*carry;
            a[i]=store%10;
            carry=store/10;
        }
        i++;
     }
     return i;
}
void factorial(int n){
    int size=1;
    for(int i=2;i<=n;i++){
        size=fact(i,size);
    }
    for(int i=size-1;i>=0;i--){
        cout<<a[i]<<"";
    }
    cout<<endl;
}
//--------------------------------------------------------------------------------------
string doMultiply(string s1,string s2){
    string ans="";
    int res[s1.length()+s2.length()];
    std::fill_n(res,s1.length()+s2.length(),0);
    int i=0,j=0;
    for(i=s1.length()-1;i>=0;i--){
        int carry=0;
        for(j=s2.length()-1;j>=0;j--){
            int f=s1[i]-'0';
            int s=s2[j]-'0';
            int prev=res[i+j+1];
            int toStore=f * s + carry + prev;
            res[i+j+1]=toStore%10;
            carry=toStore/10;
        }
        res[i+j+1]=carry;
    }
    bool pre=true;
    for(int i=0;i<s1.length()+s2.length();i++){
        if(res[i]!=0){
            pre=false;
        }
        if(pre==false){
            ans+=res[i]+'0';
        }
    }
    //cout<<ans;
    if(ans.length()==0){
        return "0";
    }
    return ans;
}
//-----------------------------------------------------------------
string doAddition(string s1,string s2){
    string ans="";
    int n=max(s1.length(),s2.length());
    int carry=0;
    int i=s1.length()-1;
    int j=s2.length()-1;
    while(i>=0 && j>=0){
        int f=s1[i]-'0';
        int s=s2[j]-'0';
        int toStore=f+s+carry;
        ans.insert(ans.begin(),(toStore%10)+'0');
        carry=toStore/10;
        i--;
        j--;
    }
    while(i>=0){
        int f=s1[i]-'0';
        int toStore=f+carry;
        ans.insert(ans.begin(),(toStore%10)+'0');
        carry=toStore/10;
        i--;
    }
    while(j>=0){
        int f=s2[j]-'0';
        int toStore=f+carry;
        ans.insert(ans.begin(),(toStore%10)+'0');
        carry=toStore/10;
        j--;
    }

    if(carry>0){
        ans.insert(ans.begin(),carry+'0');
    }
    ans=removeZero(ans);
    if(ans.length()==0){
        return "0";
    }
    return ans;
}
string subtract(string a,string b){
    string ans="";
    int i=a.length()-1;
    int j=b.length()-1;
    int borrow=0;
    while(i>=0 && j>=0){
        int f=a[i]-'0';
        int s=b[j]-'0';
        //cout<<f<<endl;
        int toStore=f-s-borrow;
        if(toStore<0){
            toStore+=10;
            borrow=1;
        }
        else{
            borrow=0;
        }
        // cout<<f<<endl;
        ans.insert(ans.begin(),toStore+'0');
        i--;
        j--;
    }
    while(i>=0){
        int f=a[i]-'0';
          int toStore=f-borrow;
        if(toStore<0){
            toStore+=10;
            borrow=1;
        }
        else{
            borrow=0;
        }
      
        ans.insert(ans.begin(),toStore+'0');
        i--;
    }
    while(j>=0){
        int f=b[j]-'0';
          int toStore=f-borrow;
        if(toStore<0){
            toStore+=10;
            borrow=1;
        }
        else{
            borrow=0;
        }
      
        ans.insert(ans.begin(),toStore+'0');
        j--;
    }
    ans=removeZero(ans);
    if(ans.length()==0){
        return "0";
    }
    return ans;
}
//whatever you pass in first argument i will say that is greater or not than s2
bool greaterThan(string s1,string s2){
    bool ans=true;
    if(s1.length()<s2.length()){
        return false;
    }
    if(s1.length()>s2.length()){
        return true;
    }
    else{
        for(int i=0;i<s1.length();i++){
            int f=s1[i]-'0';
            int s=s2[i]-'0';
            if(f!=s){
                ans=(f>s)?true:false;
                break;
            }
        }
        return ans;
    }
}
bool strictGreaterThan(string s1,string s2){
    bool ans=false;
    if(s1.length()<s2.length()){
        return false;
    }
    if(s1.length()>s2.length()){
        return true;
    }
    else{
        for(int i=0;i<s1.length();i++){
            int f=s1[i]-'0';
            int s=s2[i]-'0';
            if(f!=s){
                ans=(f>s)?true:false;
                break;
            }
        }
        return ans;
    }
}
bool isequal(string s1,string s2){
    bool ans=false;
    if(s1.length()<s2.length()){
        return false;
    }
    if(s1.length()>s2.length()){
        return false;
    }
    else{
        for(int i=0;i<s1.length();i++){
            int f=s1[i]-'0';
            int s=s2[i]-'0';
            if(f!=s){
                return false;
            }
        }
       return true;
    }
}

string doSubtraction(string s1,string s2){
    if(greaterThan(s1,s2)){
        return subtract(s1,s2);
    }
    else{
        return "-"+subtract(s2,s1);
    }
}
string doExponent(string x,long long y){
    if(y==0){
        return "1";
    }
    if(y==1){
        return x;
    }
    if(y%2==0){
        string here=doExponent(x,y/2);
        return doMultiply(here,here);
    }
    else{
        return doMultiply(x,doExponent(x,y-1));
    }
}

string doDivision(string s1,string s2){
    if(strictGreaterThan(s2,s1)){
        return "0";
    }
    string ans="";
    string rem="";
    for(int i=0;i<s1.length();i++){
        int dig=s1[i]-'0';
        rem+=dig+'0';
        if(strictGreaterThan(s2,rem)){
            if(ans.length()>0){
                ans+='0';
            }
        }
        else{
            size_t cnt=0;
           // cout<<rem<<endl;
            while(greaterThan(rem,s2)){
                rem=doSubtraction(rem,s2);
                cnt++;
            }
           // cout<<cnt<<endl;
            ans+=cnt+'0';
        }
    }
    return ans;
}
string doModular(string s1,string s2){
    if(isequal(s1,s2)){
        return "0";
    }
    string ans="";
    string div=doDivision(s1,s2);
    string mul=doMultiply(div,s2);
    if(greaterThan(mul,s1))
    ans=doSubtraction(mul,s1);
    else
    ans=doSubtraction(s1,mul);
    if(ans.length()==0){
        return "0";
    }
    return ans;
}
string gcd(string a,string b){
    if(isequal(a,"0")){
        return b;
    }
    if(isequal(b,"0")){
        return a;
    }
    if(isequal(a,b)){
        return a;
    }
    if(a.size() > b.size() || (a.size() == b.size() && greaterThan(a,b))){
        return gcd(doSubtraction(a,b),b);
    }
    else{
        return gcd(a,doSubtraction(b,a));
    }
}
//-------------------------------------------
void f(string s){
    map m;
    stack1 s1;
    stack2 s2;
    string to="";  
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(isdigit(ch)){
            to+=ch;
            if((i+1)>=s.length()){
                s1.push(to);
            }
            continue;
        }
        if(to.length()>0){
            s1.push(to);
            to="";
            i--;
        }
        else{
           if(s2.size()==0){
                s2.push(ch);
            }
            else if(m.get(ch)>m.get(s2.top())){
                s2.push(ch);
            }
            else{
                while(s2.size()>0 && s1.size()>0&& m.get(ch)<=m.get(s2.top())){
                //   cout<<s1.size()<<" "<<s2.size()<<endl;
                    char c=s2.top();
                    s2.pop();
                    string f=s1.top();
                    s1.pop();
                    string sec=s1.top();
                    s1.pop();
                    if(c=='+'){
                        s1.push(doAddition(sec,f));
                    }
                    else if(c=='-'){
                        s1.push(doSubtraction(sec,f));
                    }
                    else if(c=='x'){
                        s1.push(doMultiply(sec,f));
                    }
                   else if(c=='/'){
                        s1.push(doDivision(sec,f));
                    }
                }
                s2.push(ch);
            }

        }
    }
    //cout<<s1.size()<<endl;
    while(s2.size()>0){

        char c=s2.top();
        s2.pop();
        string f=s1.top();
        s1.pop();
        string sec=s1.top();
        s1.pop();
        
        if(c=='+'){
           // cout<<f<<"   "<<sec<<endl;
             string v=doAddition(f,sec);
            // cout<<v<<"  aa gaya"<<endl;
             s1.push(v);
        }
        else if(c=='-'){
             s1.push(doSubtraction(sec,f));
        }
        else if(c=='x'){
            s1.push(doMultiply(sec,f));
        }
        else if(c=='/'){
            s1.push(doDivision(sec,f));
        }   

    }
    cout<<s1.top()<<endl;
}

//------------------------------------------
int main(){
    int t;
    cin>>t;
    if(t==1){
        string s1;
        cin>>s1;
        f(s1);
    }
    else if(t==2){
        string s1;
        long long x;
        cin>>s1>>x;
        cout<<doExponent(s1,x)<<endl;
    }
    else if(t==3){
        string s1;
        string s2;
        cin>>s1;
        cin>>s2;
        cout<<gcd(s1,s2)<<endl;
    }
    else if(t==4){
        int n;
        cin>>n;
        fill_n(a,10000,-1);
        factorial(n);
    }
    else{
        return -1;
    }
   
}

