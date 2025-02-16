#include<bits/stdc++.h>
using namespace std;

int arr[26];
struct node{
    char ch=' ';
    int fre;
    node *left=NULL,*right=NULL,*next=NULL;
};

void preorder(node *root,string s){
    if(root->left==NULL){
        cout<<root->ch<<' '<<s<<endl;
        arr[root->ch-'a']=s.length();
        return;
    }
    preorder(root->left,s+"0");
    preorder(root->right,s+"1");
}

int main(){
    int n,fre;
    char ch;
    node *fptr=NULL,*nptr,*eptr,*tptr;
    cout<<"Enter number of character: ";
    cin>>n;
    cout<<"Enter Character & Frequency: "<<endl;
    for(int i=0;i<n;i++){
        nptr=new(node);
        cin>>ch>>fre;
        nptr->ch=ch;
        nptr->fre=fre;

        if(fptr==NULL){
            fptr=nptr;
            //eptr=nptr;
        }else{
            if(nptr->fre<=fptr->fre){
                nptr->next=fptr;
                fptr=nptr;
            }else{
                eptr=fptr;
                while(eptr->next!=NULL&&eptr->next->fre<nptr->fre){
                    eptr=eptr->next;
                }
                nptr->next=eptr->next;
                eptr->next=nptr;
            }
        }
    }

    cout<<"\nHuffman Code : "<<endl;
    while(fptr->next!=NULL){
        nptr=new(node);
        nptr->left=fptr;
        nptr->right=fptr->next;
        nptr->fre=nptr->left->fre+nptr->right->fre;
        fptr=fptr->next->next;

        if(fptr==NULL){
            fptr=nptr;
        }else if(fptr->fre>nptr->fre){
            nptr->next=fptr;
            fptr=nptr;
        }else{
            eptr=fptr;
            while(eptr->next!=NULL&&eptr->next->fre<nptr->fre){
                eptr=eptr->next;
            }
            nptr->next=eptr->next;
            eptr->next=nptr;
        }
    }

    preorder(fptr,"");

    int sum=0;
    string s;
    cout<<"\nEnter a string: ";
    cin>>s;
    for(int i=0;i<s.length();i++){
        sum+=arr[s[i]-'a'];
    }
    cout<<"Memory Saved = "<<(s.length()*8)-sum<<endl;
    return 0;
}
