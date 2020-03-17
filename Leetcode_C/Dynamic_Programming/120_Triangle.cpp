// malloc in <stdlib.h>. memcpy in <string.h> No need to include in Leetcode.
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){

/*
One of the important cognition is that, you have to jump out the array it gives you.
When we use Dynamic Programming, don't just imaging the giving array.
But aside it, imaging the RESULT array that we create to put the final result.
This 'res' has the same size of giving array.
And in the same position, stores the minimaltotal result when it comes to this point
from the begining. 
It's abstract to explain in language especially when english is my second language.
So just imaging two array, one is the original giving array, one is result array.
*/
    //由于不需要保存所有的状态，而且当前状态只和上一状态有关
    //因此只需要一个一维数组
    // triangleColSize is the size of column in every row
    // Like in [[2],[3,4],[6,5,7],[4,1,8,3]]
    // triangleColSize[0] == 1  2
    // triangleColSize[1] == 2  3,4
    // triangleColSize[2] == 3  6,5,7
    // triangleColSize[3] == 4  4,1,8,3
    int *res = (int*)malloc(sizeof(int) * triangleColSize[triangleSize-1]);
    //结果最后一行就是原来的最后一行
    memcpy(res, triangle[triangleSize - 1], 
                sizeof(int) * triangleColSize[triangleSize-1]);
    //从最后第2行开始递推
    for (int i = triangleSize - 2; i >= 0 ; i-- ){
        //为新的行分配内存
        for ( int j = 0 ; j < triangleColSize[i]; j++){
            //第(i,j)元素的值为(i+1,j), (i+1,j+1)中的最小值
            int min =  res[j] < res[j+1] ?res[j] : res[j+1];
            res[j] = triangle[i][j] + min;

        }
    }
    return res[0];

}

