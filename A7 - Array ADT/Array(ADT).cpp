#include<cstdio>
#include<algorithm>
using namespace std;

struct Array{
    int* A; int size; int length;
    Array(int s){
        size = s;
        A = new int[s];
    }
    void displayArray(){
        printf("Elements of Array, Length = (%d), Size = (%d) ", length, size);
        for(int i = 0; i < length; i++)
            printf("%d ", A[i]);
        printf("\n");
    }
    void append(int x){
        A[length++] = x;
    }
    void insert(int index, int x){
        for(int i = length - 1; i >= index; i--)
            A[i + 1] = A[i];
        A[index] = x; 
        length++;
    }
    void remove(int index){
        for(int i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
    }
    void LinearSearch(int x){
        int index = -1;
        for(int i = 0; i < length; i++)
            if(A[i] == x)
                index = i;
        if(index == -1)
            printf("Element %d Not Found:\n", x);
        else
            printf("Element %d Found:\n", x);
    }
    void BinarySearch(int x){
        sort(A, A + length);
        int L = 0, H = length - 1; int index = -1;
        while(L <= H){
            int M = (L + H)/2;
            if(A[M] == x){
                index = M;
                break;
            }
            else if(x > A[M])
                L = M + 1;
            else
                H = M - 1;
        }
        if(index == -1)
            printf("Element %d Not Found:\n", x);
        else
            printf("Element %d Found:\n", x);
    }
    void Max(){
        int best = A[0];
        for(int i = 1; i < length; i++)
            best = max(best, A[i]);
        printf("Max Element: %d\n", best);
    }
    void Min(){
        int best = A[0];
        for(int i = 1; i < length - 1; i++)
            best = min(best, A[i]);
        printf("Min Element: %d\n", best);
    }
    void reverse(){
        for(int i = 0, j = length - 1; i < j; i++, j--){
            int T = A[i];
            A[i] = A[j]; A[j] = T;
        }
        displayArray();
    }
    void rotateL(int T){
        for(int j = 0; j < T; j++){
            int F = A[0];
            for(int i = 0; i < length; i++)
                A[i] = A[i + 1];
            A[length - 1] = F;
        }
        displayArray();
    }
    void rotateR(int T){
        for(int j = 0; j < T; j++){
            int L = A[length - 1];
            for(int i = length - 1; i >=0; i--)
                A[i] = A[i - 1];
            A[0] = L;
        }
        displayArray();
    }
    void increaseSize(int s){
        int* B = new int[size * s];
        size = size * s;
        for(int i = 0; i < length; i++)
            B[i] = A[i];
        *A = *B;
        free(B);
    }
    void sortedCheck(){
        bool flag = true;
        for(int i = 0; i < length - 1; i++)
            if(A[i] > A[i + 1])
                flag = false;
        if(flag)
            printf("Sorted\n");
        else
            printf("Not Sorted\n");
    }

    void mergeArray(int B[], int N){
        for(int j = 0, i = length; j < N; j++, i++)
            A[i] = B[j];
        length = length + N;
    }

    void find_min_max(){
        int _min = A[0], _max = A[0];
        for(int i = 1; i < length - 1; i++){
            _max = max(_max, A[i]);
            _min = min(_min, A[i]);
        }
        printf("_Max_value: %d, _Min_value: %d\n", _max, _min);
    }
};
int main(){
    struct Array arr(20);
    int N;
    printf("Enter N "); scanf("%d", &N);

    //Building Array
    for(int i = 0; i < N; i++)
        scanf("%d", &arr.A[i]);
    
    arr.length = N;
    arr.append(10);
    arr.insert(2, 15);
    arr.displayArray();
    arr.remove(2);
    arr.displayArray();
    arr.LinearSearch(4);
    arr.LinearSearch(15);
    arr.Max(); arr.Min();
    //arr.BinarySearch(4);
    //arr.BinarySearch(15);
    //arr.displayArray();
    arr.increaseSize(2);
    arr.reverse();
    arr.rotateL(2);
    arr.rotateR(2);
    sort(arr.A, arr.A + arr.length);
    arr.sortedCheck();

    int B[] = {100, 104, 111, 134, 145, 199, 172}; int NB = 7;
    arr.mergeArray(B, NB);
    arr.displayArray();

    arr.find_min_max();
    return 0;
}