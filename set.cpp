#include<iostream>
#include<cmath>
using namespace std;

class set {
public:
    int n1,n2,u;
    int p[10]={999,999,999,999,999,999,999,999,999,999};
    int q[10]={999,999,999,999,999,999,999,999,999,999};
    int U[10]={999,999,999,999,999,999,999,999,999,999};
    void inputSet();
    int checkDuplicate(int x, int m[]);
    void displaySet();
    string isMember(int member, int s[]);
    void powerSet();
    string subset(int a[],int b[]);
    void Union();
    void intersection();
    void complement();
    void setDifference();
    void symmetricDifference();
    void crossProduct();
};

void set :: inputSet()
{
    cout<<"Enter the size of set 1: ";
    cin>>n1;
    cout<<"Enter the size of set 2: ";
    cin>>n2;
    
    for(int i=0; i<n1; i++){
        int e;
        cout<<"Enter element no. "<<i+1<<" of set 1: ";
        cin>>e;
        p[i]=checkDuplicate(e,p);
        }
       
    for(int i=0; i<n2; i++){
        int e;
        cout<<"Enter element no. "<<i+1<<" of set 2: ";
        cin>>e;
        q[i]=checkDuplicate(e,q);
    }
}

int set :: checkDuplicate(int x,int m[])
{
    if(isMember(x,m)=="False"){return x;}
    else{
         int r;
         cout<<"Element already exists. Re-enter the element: ";
         cin>>r;
         return checkDuplicate(r,m);
        }
}

void set :: displaySet()
{
    cout<<"Set 1: "<<"{ ";
    for(int i=0; i<n1; i++){
        cout<<p[i]<<" ";
    }
    cout<<"}";
    
    cout<<endl<<"Set 2: "<<"{ ";
    for(int i=0; i<n2; i++){
        cout<<q[i]<<" ";
    }
    cout<<"}";
}

string set :: isMember(int member,int s[])
{
    int flag=0;
    for(int i=0; i<10; i++){
        if(member==s[i]){
            flag=1;
            break;
        }
    }
    
    if(flag==1){return "True";}
    else if(flag==0){return "False";}
}

void set :: powerSet()
{
    cout<<"\nPower Set of Set1: "<<"{ ";
    for(int i=0; i<pow(2,n1); i++){
        cout<<" {";
        for(int j=0; j<n1; j++){
            if( i & (1<<j)){
                cout<<" "<<p[n1-1-j]<<" ";
            }
        }
        cout<<"} ";
    }
    cout<<"}";
}

string set :: subset(int a[], int b[])
{
    int flag = 0;
    if((sizeof(a)/sizeof(a[0]))<=(sizeof(b)/sizeof(b[0]))){
        flag=1;
        for(int i=0; i<(sizeof(a)/sizeof(a[0])); i++){
                if(isMember(a[i],b)=="False"){flag=0; break;}
        }
    }else{return("No");}
    if(flag==1){return("Yes");}
    else{return("No");}
}

void set :: Union()
{
     cout<<"\nUnion of Set1 and Set2: { ";
     for(int i=0; i<n1; i++){
        cout<<p[i]<<" ";
    }
     for(int j=0; j<n2; j++){
        if(isMember(q[j],p)=="False")
        {cout<<q[j]<<" ";}
    }
    cout<<"}";
}

void set :: intersection()
{
    cout<<"\nIntersection of Set1 and Set2: { ";
    for(int i=0; i<max(n1,n2); i++){
      if(max(n1,n2)==n1){
        if(isMember(p[i],q)=="True")
        {cout<<p[i]<<" ";}
      }
      else{
        if(isMember(q[i],p)=="True")
        {cout<<q[i]<<" ";}  
        }
    }
    cout<<"}";
}
    
void set :: complement()
{
    cout<<"\nGenerating the Universal Set for set1... \n";
    cout<<"Enter the number of elements in the Universal set: ";
    cin>>u;
    for(int i=0; i<u; i++){
        int e;
        cout<<"Enter element no. "<<i+1<<" of the Universal set for Set1: ";
        cin>>e;
        U[i]=checkDuplicate(e,U); 
        }
        
    if(subset(p,U)=="Yes"){
    
    cout<<"Universal Set for Set 1: "<<"{ ";
    for(int i=0; i<u; i++){
        cout<<U[i]<<" ";
    }
    cout<<"}";
    }
    else{
    cout<<"Incompatible Universal Set. Re-computing...";
    for(int i=0; i<u; i++){U[i]=578348847878;}
    complement();}
    
    cout<<endl<<"Complement Set of Set 1: { ";
    for(int i=0; i<u; i++){
        if(isMember(U[i],p)=="False"){cout<<U[i]<<" ";}
    }
    cout<<"}";
    
}

void set :: setDifference()
{
    cout<<endl<<"Set1 - Set2 = { ";
    for(int i=0; i<n1; i++){
        if(isMember(p[i],q)=="False"){cout<<p[i]<<" ";}
    }
    cout<<"}";
}

void set :: symmetricDifference()
{
    cout<<endl<<"Symmetric Difference of Set1 and Set2 : { ";
    for(int i=0; i<n1; i++){
        if(isMember(p[i],q)=="False"){cout<<p[i]<<" ";}
    }
    for(int i=0; i<n2; i++){
        if(isMember(q[i],p)=="False"){cout<<q[i]<<" ";}
    }
    cout<<"}";
}

void set :: crossProduct()
{
    cout<<endl<<"Set1 X Set2 : { ";
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            cout<<"("<<p[i]<<","<<q[j]<<") ";
        }
    }
    cout<<"}";
}
    
int main()
{
    set s1;
    s1.inputSet();
    s1.displaySet();
    cout<<"\nIs 3 a member of set1: "<<s1.isMember(3,s1.p);
    s1.powerSet();
    cout<<"\nIs set1 a subset of set2: "<<s1.subset(s1.p,s1.q);
    s1.Union();
    s1.intersection();
    s1.complement(); 
    s1.setDifference();
    s1.symmetricDifference();
    s1.crossProduct();
    return 0;
}
/*


*/