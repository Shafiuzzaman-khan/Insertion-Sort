#include <iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

void insertionSort(int arr[], int arr_size){
  if(arr_size > 1){
    int size = arr_size;
    for(int i = 1; i < size; ++i){
      int j = i - 1;
      int key = arr[i];
      while(j >= 0 && arr[j] > key){
        arr[j+1] = arr[j];
        --j;
      }
      arr[j+1] = key;
    }
  }
}
int main()
{

    ifstream fileInput;// read from file
    srand(98563254);
    fileInput.open("1M.txt");
    int n=1000000;

    int *arr=new int[n];
    for(int i=0; i< n; i++)
    {
        fileInput >> arr[i];
    }
    // after completing reading
    fileInput.close();


//track start time
    clock_t starTime=clock();
    insertionSort(arr, n);
// track end time
    clock_t endTime=clock();
    // count the time lapse
    double timeLapse=double(endTime-starTime)/CLOCKS_PER_SEC;
    cout <<"It takes :"<< timeLapse;

    ofstream fileOutput;

    fileOutput.open("1M_output.txt");

    for(int i=0; i<n; i++)
    {
        fileOutput << arr[i]<<endl;

    }
    fileOutput.close();

    delete[] arr;

    return 0;
}




