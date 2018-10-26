#include<cstdio>
#include <iostream>
//选择排序在大部分情况下优于冒泡排序，但是冒泡排序也有小优化，如果第一次遍历发现数组有序，那么直接停止。
void swap(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

//bubble sort
/*
以下所实现的冒泡排序，从左往右遍历，那么较大的元素(rabbit)很容易到达队尾，
较小的元素(turtle)则在一次遍历只能向右移动一个单位。
冒泡排序总是相邻的两个元素比较并交换.
冒泡的本质在于交换，每次通过交换把当前剩余元素中的最大元素移到固定的一端。
*/
void bubble_sort(int a[],int n){
    bool hasSwap = 0;
    for(int i = 0;i<n-1;i++){//冒泡要执行n-1趟，因此这么写，并没有将i用于下标。但是更清晰的写法是换成while。
        hasSwap = 0;
        for(int j = 0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                if(!hasSwap){
                    hasSwap = 1;
                }
            }
        }
        if(!hasSwap){
            break;
        }
    }
}

void bubble_sort2(int a[],int n){
    bool hasSwap = 0;
    for(int iter_idx = 1;iter_idx <= n-1;iter_idx++){
        hasSwap = 0;
        for(int j = 0;j<n-iter_idx;j++){
            if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
                if(!hasSwap)
                    hasSwap = 1;
            }
        }
        if(!hasSwap)
            break;
    }
}

void bubble_sort3(int a[],int n){
    bool hasSwap = 0;
    int last_idx = n;
    while(last_idx--){//每次冒泡都在划分数组，化为两部分，一部分是无序部分，[0,last_idx],另一部分是有序部分(last_idx:]
        hasSwap = 0;//每次冒泡所要做的工作就是让无序部分中的最大元素调到无序部分的最末尾。
        for(int j = 0;j <= last_idx -1;j++){
            if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
                if(!hasSwap)
                    hasSwap = 1;
            }
        }
        if(!hasSwap)
            break;
    }
}

/*
假设在新生报到的时候，我们将新生按照身高排好队(也就是排序)。如果这时有一名学生加入，我们将该名学生加入到队尾。
如果这名学生比前面的学生低，那么就让该学生和前面的学生交换位置。这名学生最终会换到应在的位置。这就是插入排序的基本原理。
对于起始数组来说，我们认为最初，有一名学生，也就是最左边的元素(i=0)，构成一个有序的队伍。(所以i从1开始(从第二个人开始)，一个人的时候不需要排序)
随后有第二个学生(i=1)加入队伍，第二名学生交换到应在的位置；随后第三个学生加入队伍，第三名学生交换到应在的位置……
当n个学生都加入队伍时，我们的排序就完成了。
*/
void insert_sort(int a[],int n){
    for(int i = 1;i < n;i++){
        int j = i;
        while(j >= 1){
            if(a[j] < a[j-1]){
                swap(a[j],a[j-1]);
            }
            else break;
            j--;
        }
    }
}


//find the value for each position(once for a position)
void select_sort(int a[],int n){
    int the_val;
    int pos;
    for(int i = 0;i<n-1;i++){
        pos = i;
        the_val = a[i];
        for(int j = i;j<n;j++){
            if(a[j]<the_val){
                the_val = a[j];
                pos = j;
            }
        }
        if(pos != i){
            swap(a[i],a[pos]);
        }
    }
}

/*
希尔排序是冒泡/插入排序的改进，以更大的间隔来比较和交换元素。冒泡/插入排序比较和交换的间隔为1.
这样，大的元素在交换的时候，可以向右移动不止一个位置，从而更快的移动乌龟元素。
比如，可以将数组分为4个子数组（i=4k, i=4k+1, i=4k+2, i=4k+3），对每个子数组进行冒泡排序。比如子数组i=0，4，8，12...。此时，每次交换的间隔为4（step = 4）。
完成对四个子数组的排序后，数组的顺序并不一定能排列好。希尔排序会不断减小间隔，重新形成子数组，并对子数组冒泡排序……
当间隔减小为1时，就相当于对整个数组进行了一次冒泡排序。随后，数组的顺序就排列好了。

希尔排序不止可以配合冒泡排序，还可以配合其他的排序方法完成。
Shell Sorting依赖于间隔(step)的选取。一个常见的选择是将本次间隔设置为上次间隔的1/1.3
*/
void shell_sort(int a[],int n){
    int step;
    int i,j;
    int n_sub;
    int *a_sub;
    step = 1;
    while(step < n) step = 3*step +1;

    while(step > 1){
        step = step/3 +1;//最后肯定会变为1；其他情况会比原来大个1 后面因为正好是i<step。
        for(int i = 0;i < step;i++){
            n_sub = (n-1-i)/step + 1;//子数组的元素个数，有可能最后一个组的个数比其他组少

            //malloc free 是c的写法，在.cpp中会报错
            //a_sub = (int*)malloc(n_sub * sizeof(int));
            //C++提供了new[]与delete[]来专门处理数组类型:
            a_sub = new int[n_sub];
            for(int j = 0; j<n_sub; j++){
                a_sub[j] = a[j*step + i];
            }
            bubble_sort(a_sub,n_sub);
            for(int j = 0;j<n_sub;j++){
                a[j*step + i] = a_sub[j];
            }
            //free(a_sub);
            //使用new[]分配的内存必须使用delete[]进行释放：
            delete [] a_sub;
        }
    }
}


/*
如果我们要将一副扑克按照数字大小排序。
此前已经有两个人分别将其中的一半排好顺序。那么我们可以将这两堆扑克向上放好，假设小的牌在上面。
此时，我们将看到牌堆中最上的两张牌。
我们取两张牌中小的那张取出放在手中。
两个牌堆中又是两张牌暴露在最上面，继续取小的那张放在手中……
直到所有的牌都放入手中，那么整副牌就排好顺序了。这就是归并排序。
*/
void merge_sort(int* a,int n){
    if( n<=1 ) return;

    int i,j,sub_n1,sub_n2,idx;
    int *sub_a1,*sub_a2;
    int *buf;

    sub_n1 = n/2;
    sub_n2 = n - sub_n1;
    sub_a1 = a;
    sub_a2 = a + sub_n1;

    merge_sort(sub_a1,sub_n1);
    merge_sort(sub_a2,sub_n2);
    //after the two lines of codes,we can assume that we have sorted the sub array


    //merge
    i = 0;
    j = 0;
    idx = 0;
    buf = new int[n];
    while(i<sub_n1 && j<sub_n2){
        if(sub_a1[i] <= sub_a2[j]){
            buf[idx++] = sub_a1[i++];
        }
        else{
            buf[idx++] = sub_a2[j++];
        }
    }
    while(i<sub_n1) buf[idx++] = sub_a1[i++];
    while(j<sub_n2) buf[idx++] = sub_a2[j++];

    for(i = 0;i<n;i++){a[i] = buf[i];}
    delete [] buf;
}

/*
我们依然考虑按照身高给学生排序。在快速排序中，我们随便挑出一个学生，以该学生的身高为参考(pivot)。
然后让比该学生低的站在该学生的右边，剩下的站在该学生的左边。
很明显，所有的学生被分成了两组。该学生右边的学生的身高都大于该学生左边的学生的身高。
我们继续，在低身高学生组随便挑出一个学生，将低身高组的学生分为两组(很低和不那么低)。
样，将高学生组也分为两组(不那么高和很高)。
如此继续细分，直到分组中只有一个学生。当所有的分组中都只有一个学生时，则排序完成。


理想的pivot是采用分组元素中的中位数。
中位数的算法需要另行实现。也可以随机选取元素作为pivot，随机选取也需要另行实现。
为了简便，我每次都采用中间位置的元素作为pivot。
*/

void quick_sort(int *a,int n){
    int idx;
    swap(*a,*(a+n/2));
    int behind_pivot_idx = 1;
    for(idx = 1;idx<n;idx++){
        if(a[idx] < a[0]){  //a[0]:pivot_val
            swap(*(a+behind_pivot_idx),*(a+idx));
            behind_pivot_idx++;
        }
    }

    //the codes above ensure that
    //a[1],a[2]....a[behind_pivot_idx-1]  all < pivot_val
    //and a[behind_pivot_idx],a[behind_pivot_idx+1],... all >= pivot_val

    swap(*a,*(a+behind_pivot_idx-1));

    if(n<=2) return;
    //int sub_n1 = behind_pivot_idx-1 + 1-1;
    int sub_n1 = behind_pivot_idx-1;
    int sub_n2 = n -1 -sub_n1;
    //exclude the pivot
    quick_sort(a,sub_n1);
    quick_sort(a+sub_n1+1,sub_n2);

}

/*

堆排序
数据结构+算法
堆(heap)是常见的数据结构。
它是一个有优先级的队列。最常见的堆的实现是一个有限定操作的Complete Binary Tree。
这个Complete Binary Tree保持堆的特性，也就是父节点(parent)大于子节点(children)。
因此，堆的根节点是所有堆元素中最小的。堆定义有插入节点和删除根节点操作，这两个操作都保持堆的特性。
我们可以将无序数组构成一个堆，然后不断取出根节点，最终构成一个有序数组。



for a node i, its children are i*2 and i*2+1 (if exists)
its parent is i/2


*/
//父节点的值总小于等于子节点的值
static void percolate_up(int heap[]){
    int light_idx,parent_idx;
    light_idx = heap[0];
    parent_idx = light_idx/2;
    while(parent_idx > 0 &&(heap[light_idx] < heap[parent_idx])){
        swap(*(heap+light_idx),*(heap+parent_idx));
        light_idx = parent_idx;
        parent_idx = light_idx/2;

    }
}

static void percolate_down(int heap[]){
    int heavy_idx;
    int child_idx1,child_idx2,min_child_idx;
    bool isSwapped;
    heavy_idx = 1;
    do{
        isSwapped = false;
        child_idx1 = heavy_idx*2;
        child_idx2 = child_idx1+1;
        if(child_idx1 > heap[0]) break;
        else if(child_idx2 > heap[0]){
            min_child_idx = child_idx1;
        }
        else{
            if(heap[child_idx1]<heap[child_idx2]){
                min_child_idx = child_idx1;
            }
            else min_child_idx = child_idx2;
        }

        if(heap[heavy_idx] > heap[min_child_idx]){
            swap(heap[heavy_idx],heap[min_child_idx]);
            isSwapped = true;
            heavy_idx = min_child_idx;
        }

    }while (isSwapped);
}


void insert(int new_val,int heap[]){
    heap[0]++;//heap[0] : total number of nodes in the heap
    //printf("%d",heap[0]);
    heap[heap[0]] = new_val;//插入的值暂时放入堆底
    percolate_up(heap);
}




int delete_min(int heap[]){
    int min;
    if(heap[0] < 1){
        printf("Error : heap is empty\n");
        exit(1);
    }
    min = heap[1];
    swap(*(heap+1),*(heap+heap[0]));
    heap[0]--;
    percolate_down(heap);

    return min;
}




void Print(int a[],int n){
    printf("\n");
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
}



int main(){
    int num[] = {0,2,1,8,5,3,5,9,6};
    int n = 9;
    Print(num,n);
    //bubble_sort(num,n);
    //insert_sort(num,n);
    //select_sort(num,n);
    //shell_sort(num,n);
    //merge_sort(num,n);
    //quick_sort(num,n);

    int sorted_num[20]; //sorted_num[20] 不一定会被初始化为0,如CXX_STANDARD
    sorted_num[0] = 0;
    for(int i =0;i<n;i++){
        insert(num[i],sorted_num);
    }

    printf("\n");
    for(int i = 1;i<n+1;i++){
        printf("%d ",sorted_num[i]);
    } //这时候只是建堆，只能保证堆顶元素是最小的

    printf("\n");
    int tmp;
    for(int i = 0;i<n;i++){
        tmp = delete_min(sorted_num);
        printf("%d ",tmp);
    }

    Print(num,n);
    return 0;
}
