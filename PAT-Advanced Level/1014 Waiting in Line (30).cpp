Suppose a bank has N windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. The rules for the customers to wait in line are:

The space inside the yellow line in front of each window is enough to contain a line with M customers. Hence when all the N lines are full, all the customers after (and including) the (NM+1)st one will have to wait in a line behind the yellow line.
Each customer will choose the shortest line to wait in when crossing the yellow line. If there are two or more lines with the same length, the customer will always choose the window with the smallest number.
Customer[i] will take T[i] minutes to have his/her transaction processed.
The first N customers are assumed to be served at 8:00am.
Now given the processing time of each customer, you are supposed to tell the exact time at which a customer has his/her business done.

For example, suppose that a bank has 2 windows and each window may have 2 customers waiting inside the yellow line. There are 5 customers waiting with transactions taking 1, 2, 6, 4 and 3 minutes, respectively. At 08:00 in the morning, customer~1~ is served at window~1~ while customer~2~ is served at window~2~. Customer~3~ will wait in front of window~1~ and customer~4~ will wait in front of window~2~. Customer~5~ will wait behind the yellow line.

At 08:01, customer~1~ is done and customer~5~ enters the line in front of window~1~ since that line seems shorter now. Customer~2~ will leave at 08:02, customer~4~ at 08:06, customer~3~ at 08:07, and finally customer~5~ at 08:10.

Input
Each input file contains one test case. Each case starts with a line containing 4 positive integers: N (<=20, number of windows), M (<=10, the maximum capacity of each line inside the yellow line), K (<=1000, number of customers), and Q (<=1000, number of customer queries).

The next line contains K positive integers, which are the processing time of the K customers.

The last line contains Q positive integers, which represent the customers who are asking about the time they can have their transactions done. The customers are numbered from 1 to K.

Output
For each of the Q customers, print in one line the time at which his/her transaction is finished, in the format HH:MM where HH is in [08, 17] and MM is in [00, 59]. Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 17:00, you must output "Sorry" instead.

Sample Input
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
Sample Output
08:07
08:06
08:10
17:00
Sorry

code:

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct node{
	/*PAT上的g++编译器自己把这俩int初始化为0了，但是dec++和vs都不行，得自己初始化*/
	int poptime = 0;  //队首的人出队（办理业务完成）的时间
	/*poptime是为了让黄线外的人可以计算出哪一个队列先空出人来（poptime最小的那个先有人服务完毕）*/
	int endtime = 0; //队尾的人 办理业务完成 的时间
	/*endtime是为了入队后加上自己本身的服务所需时间可以计算出自己多久才能被服务完毕*/
	queue<int>q;
};
int main(){
	int n, m, k, q;
	int index = 1;  //表示顾客编号，从1开始
	scanf("%d%d%d%d", &n, &m, &k, &q);
	vector<int>time(k + 1), result(k + 1); //构建大小为k+1（因为编号是从1开始的）的 time数组
	/*resulet数组是存放每个顾客的询问结果，里面是分钟数，最后通过格式调整为HH:MM型*/
	/*用vector是因为，如果直接用数组，就得malloc申请空间，更麻烦，调试的时候还看不到里面*/
	for (int i = 1; i <= k; i++){
		scanf("%d", &time[i]);
	}
	vector<node>window(n + 1); //构建大小为n+1的窗口结构体 ,让窗口也从1开始编号。
	vector<bool>sorry(k + 1, false);

	for (int i = 1; i <= m; i++){  //m是队列容量
		for (int j = 1; j <= n; j++){  //n是窗口数目，每一次循环都会把每一个窗口都安排加进去一个人
			if (index <= k){ //如果还有顾客
				window[j].q.push(time[index]); //将当前编号下的顾客所要花费的办理时间入队
				if (window[j].endtime >= 540) { //8:00到17:00 一共9*60=540分钟
					sorry[index] = true;
				}
				window[j].endtime += time[index];
				if (i == 1){  //如果是第一个客户 
					window[j].poptime = window[j].endtime;
				}
				result[index] = window[j].endtime;
				index++;
			}
		}
	}

	while (index <= k){  //如果还有顾客没有进进入黄线内区域，则进入该while循环淮。（k是顾客人数）
		int tempmin = window[1].poptime;
		int tempwindow = 1;
		for (int i = 2; i <= n; i++){
			if (window[i].poptime < tempmin){ //寻找等待时间最短的柜台，也就是尽快要走一个人的那个柜台
				tempwindow = i;
				tempmin = window[i].poptime;
			}
		}
		window[tempwindow].q.pop(); //等待时间最短的柜台队伍最前面的人对应的花费时间出队
		window[tempwindow].q.push(time[index]); //把刚刚新加进来的人将要花费的时间入队
		window[tempwindow].poptime += window[tempwindow].q.front();
		if (window[tempwindow].endtime >= 540){
			sorry[index] = true;
		}
		window[tempwindow].endtime += time[index];  //更新队尾办理结束时间
		result[index] = window[tempwindow].endtime;
		index++;
	}

	for (int i = 1; i <= q; i++){ //q是咨询人数
		int query; //咨询的客户编号
		int minute; //要等待的时间
		scanf("%d", &query);
		minute = result[query];
		if (sorry[query] ==true) printf("Sorry\n");
		else printf("%02d:%02d\n", (minute + 480) / 60, (minute + 480) % 60);
		/*8小时是8*60=480分钟，故(minute + 480) / 60是8点加目前分钟数所得的时刻，余数是剩余分钟数*/
	}

	return 0;
}
