#include <vector>

//using namespace std;

template <class T, class Comparator>
void merge(std::vector<T>& myArray, int start, int middle, int end, Comparator comp){
   
   std::vector<T> temp(end-start+1);
   int i = start;
   int j = middle + 1;
   int k = 0;
   
   while(i<=middle || j<=end){
      
      //if(i<=middle && (j>end || myArray[i] < myArray[j])){
      if(i<=middle && (j>end || comp(myArray[i], myArray[j]))){
         temp[k] = myArray[i];
         i++;
         k++;
      }
      else{
         temp[k] = myArray[j];
         j++;
         k++;
      }
   
   }
   
   for(k=0; k<end-start+1; k++){
      
      myArray[start+k] = temp[k];   
      
   }


}

template <class T, class Comparator>
void mergeSort_helper(std::vector<T>& myArray, int start, int end, Comparator comp){
   
   if(start >= end){
      return;
   }
   
   int middle = ((start+end)/2);
   mergeSort_helper(myArray, start, middle, comp);
   mergeSort_helper(myArray, middle + 1, end, comp);
   merge(myArray, start, middle, end, comp);

}



template <class T, class Comparator>
void mergeSort(std::vector<T>& myArray, Comparator comp){

   mergeSort_helper(myArray, 0, myArray.size() - 1, comp);  
      
}


