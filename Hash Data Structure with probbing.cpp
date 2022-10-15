#include <iostream>

using namespace std;

class Hash{
    int arr[10];
    public:
    Hash(){
        for(int i = 0; i < 10; i++){
            arr[i] = -1;
        }
    }
    void print(){
        for(int i = 0; i < 10; i++){
            if(arr[i] != -1){ cout<<arr[i]<<" "; }
        }
        cout<<endl;
    }
    
    int hashFunction(int key){
        return key % 10;
    }
    
    void insert(int val){
        int index = hashFunction(val);
        if(arr[index] == -1){
            arr[index] = val;
        }
        else{
            int i = index;
            while(i < 10){
                if(arr[i] == -1){
                    arr[i] = val;
                    return;
                }
                i++;
            }
            i = 0;
            while(i < index){
                if(arr[i] == -1){
                    arr[i] = val;
                    return;
                }
                i++;
            }
        }
    }
    
    bool deleteVal(int val){
        int index = hashFunction(val);
        if(arr[index] == val){
            arr[index] = -1;
            return true;
        }
        int i = index;
        while(i < 10){
            if(arr[i] == val){
                arr[i] = -1;
                return true;
            }
            i++;
        }
        i = 0;
        while(i < index){
            if(arr[i] == val){
                arr[i] = -1;
                return true;
            }
        }
        return false;
    }
    
};

int main()
{
    Hash h1;
    h1.insert(5);
    h1.insert(10);
    h1.insert(15);
    h1.insert(20);
    h1.print();
    
    h1.deleteVal(15);
    h1.print();

    return 0;
}
