/*----------------------------------
* Program Name: RemoveDuplicatesFromArray.java
* Programmer Name: Josh Clemens
* Description: This program reads an int array and will sort and remove and duplicate elements and display the original array and new array.
* Date: 07-23-22
-----------------------------------*/

import java.util.*; //used for scanner and Arrays.sort(); 

class Main {

    public static int removeDuplicates(int arr[], int len){
        
        int [] tempArr = new int[len];
        int j = 0;
        for (int i = 0; i < len -1; i++){
            //checks to see if the next index is same and only writes to temp array if current element != next element
            if (arr[i] != arr[i+1]){
                tempArr[j++] = arr[i];
            }
        }
    
        tempArr[j++] = arr[len-1];
        //change the values stored in tempArray and write them to arr[]
        for (int i = 0; i < j; i++){
            arr[i] = tempArr[i];
        }

        //returns new lenght of array
        return j;
    }
    public static void main(String[] args) {

        int arr[] = {55,37,90,65,34,12,90,77,55,37,90,65,91,90,75,10};
        //find length of array to pass to method for processing and used in for loops
        int len = arr.length;
        System.out.println("The original array contains: ");
        //prints array before processing
        for (int i = 0; i < len; i++){
            System.out.print(arr[i] + " ");
        }
        //add a new line after for loop display
        System.out.println("");

        //sort array to process for doubles
        Arrays.sort(arr);
        len = removeDuplicates(arr, len);
        System.out.println("The array after being sorted and removing doubles: ");
        
        for (int i = 0; i < len; i++){
            System.out.print(arr[i] + " ");
        }
    
    }
}