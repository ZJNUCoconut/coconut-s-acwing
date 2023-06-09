#include <iostream>
using namespace std;
//单调队列 滑动窗口（最大值最小值）
const int N = 1e6 + 10;//数据规模
int n,k;//n:数组元素个数 k:滑动窗口长度
int a[N],q[N];//数组 和 （数组模拟的）单调队列(存的是数组下标)

int main() {
    scanf("%d%d",&n,&k);
    for(int i = 0;i < n; i++)scanf("%d",&a[i]);

    int hh = 0,tt = -1;//初始化队头 = 0 队尾 = -1
    for(int i = 0;i < n;i++){//这个i 指向滑动窗口的最右边（队尾元素下标）
        //判断队头是否已经划出窗口，q[hh]队头下标
       if(hh <= tt && i - k + 1 > q[hh]){//栈不空 并且 i-k+1是窗口满了的起点 i-k+1 > q[hh]意味着头已经出了窗口
            hh ++;
       }while(hh <=tt && a[q[tt]]>= a[i])tt--;//如果队尾里的元素比当前元素大，那他就没有用了，我们要保证队列单调性
       q[++tt] = i;//把当前的下标丢给队尾
       if(i >= k - 1)printf("%d ",a[q[hh]]);//右端点坐标大于2窗口才是满的，才能打印  由于保证了队列单调性，所以队头是最小的
    }
    puts("");

    hh = 0,tt = -1;//初始化队头 = 0 队尾 = -1
    for(int i = 0;i < n;i++){//这个i 指向滑动窗口的最右边（队尾元素）
        //判断队头是否已经划出窗口
        if(hh <= tt && i - k + 1 > q[hh]){//栈不空 并且 i-k+1是窗口的起点 i-k+1 > q[hh]意味着头已经出了窗口
            hh ++;
        }while(hh <=tt && a[q[tt]]<= a[i])tt--;//这里的符号和上面相反 所以起始改变的是单调性 从#12-#20单调递增到现在单调递减
        q[++tt] = i;
        if(i >= k - 1)printf("%d ",a[q[hh]]);//此时，队头是最大值
    }

    return 0;
}
