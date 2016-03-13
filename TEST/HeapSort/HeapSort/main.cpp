#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<functional>
#define MAXN 105

using namespace std;

int original[MAXN],temp[MAXN],ans[MAXN];
int n;

bool isEqual(int a[],int b[]){
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}

void output(int a[]){
    printf("%d",a[0]);
    for(int i=1;i<n;i++){
        printf(" %d",a[i]);
    }
    printf("\n");
}

bool isInsert(){
    int flag=0;
    for(int i=2;i<=n;i++){
        if(flag&&!isEqual(ans,temp)){
            printf("Insertion Sort\n");
            output(ans);
            return true;
        }
        sort(ans,ans+i);
        if(isEqual(ans,temp)){
            flag=1;
        }
    }
    return false;
}

bool isHeapSort(){
    int flag=0;
    for(int i=n;i>=2;i--){
        if(flag&&!isEqual(original,temp)){
            printf("Heap Sort\n");
            output(original);
            return true;
        }
        make_heap(original,original+i);
        pop_heap(original,original+i);
        if(isEqual(original,temp)){
            flag=1;
        }
    }
    return false;
}

int main(int argc,char *argv[]){
    
    freopen("/Users/chengfeng/Dev/Algorithm/TEST/HeapSort/HeapSort/in", "r", stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&original[i]);
        ans[i]=original[i];
    }
    for(int i=0;i<n;i++){
        scanf("%d",&temp[i]);
    }
    if(!isInsert()){
        isHeapSort();
    }
    return 0;
}
