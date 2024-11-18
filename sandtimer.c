#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node{
    int a;
    int b;
    int t;
    struct Node* left;
    struct Node* right;
};  
int A,B,target;
struct Node* createnode(int t,int a,int b){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->a=a;
    newnode->b=b;
    newnode->t=t;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
int will_have_babies(int t,int a,int b){
    if(t>target){
        return 0;
    }
    return 1;
}
int compare(int a ,int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    if(a<b){
        return a;
    }
    return b;
}
int search_key(struct Node* root,int key,int arr[],int *ind){
    if(root==NULL)return 0;
    if(root->t==key){
        arr[(*ind)++]=100;
        return 1;
    }
    int x1=search_key(root->left,key,arr,ind);
    if(x1){
        arr[(*ind)++]=A;
        return 1;
    }
    int x2=search_key(root->right,key,arr,ind);
    if(x2){
        arr[(*ind)++]=B;
        return 1;
    }
    return 0;
}
struct Node* add_possibilites(struct Node* root,int t,int a,int b){
    int x,a1,b1,t1,a2,b2,t2;
    root=createnode(t,a,b);
    if(will_have_babies(t,a,b)){
        a1=A-a;
        t1=t+compare(a1,b);
        b1=b-compare(a1,b);
        a1-=compare(a1,b);
        if(a1<0)a1=0;
        if(b1<0)b1=0;
        root->left=add_possibilites(root->left,t1,a1,b1);
        b2=B-b;
        t2=t+compare(a,b2);
        a2=a-compare(a,b2);
        b2-=compare(a,b2);
        if(a2<0)a2=0;
        if(b2<0)b2=0;
        root->right=add_possibilites(root->right,t2,a2,b2);
    }
    return root;
}
int decide(int x,int x2,int ind,int ind2){
    if(!x)return 0;
    if(!x2)return 1;
    if(ind>ind2)return 0;
    return 1;
}
void main(){
    struct Node* root=NULL;
    struct Node* root2=NULL;
    int arr[30];int ind=0;
    int arr2[30];int ind2=0;
    int flag=0;
    printf("Enter the duration of sandtimer A(in minutes):");
    scanf("%d",&A);
    printf("Enter the duration of sandtimer B(in minutes):");
    scanf("%d",&B);
    if(A>B){
        int temp2=A;
        A=B;
        B=temp2;
    }
    printf("Enter the minutes to be measured:");
    scanf("%d",&target);
    printf("\n");
    int temp=compare(A,B);
    root=add_possibilites(root,temp,A-temp,B-temp);
    root2=add_possibilites(root,0,A,B);
    int x=search_key(root,target,arr,&ind);
    int x2=search_key(root2,target,arr2,&ind2);
    flag=decide(x,x2,ind,ind2);
    if(flag){
    if(!x){
        printf("Cannot measure %d minutes",target);
    }
    else{
        printf("Start the %d minute and %d minute sand-timer together.\n\n",A,B);
        for(int i=ind-1;i>=0;i--){
            printf("Wait for any one sandtimer to run out.Then, ");
            if(arr[i]==100)printf("Exactly %d minutes are measured!!\n",target);
            else printf("Flip the %d minute sand-timer\n",arr[i]);
            printf("\n");
        }
    }}
    else{
       if(!x2){
        printf("Cannot measure %d minutes",target);
    }
    else{
        printf("Start the %d minute and %d minute sand-timer together.\n\n",A,B);
        for(int i=ind2-2;i>=0;i--){
            printf("If both the sandtimers runs out.Then, ");
            if(arr2[i]==100)printf("Exactly %d minutes are measured!!\n",target);
            else printf("Flip the %d minute sand-timer\n",arr2[i]);
            printf("\n");
        }
    }   
  
    }
}