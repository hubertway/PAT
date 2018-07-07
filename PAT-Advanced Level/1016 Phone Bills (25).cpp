A long-distance telephone company charges its customers by the following rules:

Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.

Input Specification:
Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.

The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00

02:00, and so on for each hour in the day.
The next line contains a positive number N (<= 1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word "on-line" or "off-line".

For each test case, all dates will be within a single month. Each "on-line" record is paired with the chronologically next record for the same customer provided it is an "off-line" record. Any "on-line" records that are not paired with an "off-line" record are ignored, as are "off-line" records not paired with an "on-line" record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.

Output Specification:
For each test case, you must print a phone bill for each customer.

Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.

Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80

code:

#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
using namespace std;
struct node {
	string name;
	int month, day, hour, minute;
	int time;
	int status;
};
bool cmp(node a, node b) {  
	/*比较函数，a结构和b的名字是否一样？不一样则按照字典序排名，一样的话a的总体时间是否更靠前（也是从小到大排）*/
	return a.name != b.name ? a.name < b.name : a.time < b.time;
}
double billFromZero(node call, int *rate) {
	double total = rate[call.hour] * call.minute + rate[24] * 60 * call.day;  //day天的花费，加上和第hour时间段minute分钟的的花费
	for (int i = 0; i < call.hour; i++) //再加上当天从0-hour时间短之间的所有花费
		total += rate[i] * 60;
	return total / 100.0;  //转化成美元
}
int main(){
	int rate[25] = {0},n;
	for (int i = 0; i < 24; i++) {
		scanf("%d", &rate[i]);
		rate[24] += rate[i]; //为了解决跨天问题，如果一通电话持续超过1天的话，直接用rate[24]*60*day计算day天的花费
	}
	scanf("%d", &n);
	vector<node>data(n);
	for (int i = 0; i < n; i++){
		cin >> data[i].name;
		scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].minute);
		string temp;
		cin >> temp;
		data[i].status = (temp == "on-line") ? 1 : 0;
		data[i].time = data[i].day * 24 * 60 + data[i].hour * 60 + data[i].minute; //以分钟为单位计算一个月每个状态的时间
	}
	sort(data.begin(), data.end(), cmp); // 将给出的数据先按照姓名排序，再按照时间的先后顺序排列，
	/*遍历的时候，前后两个名字相同且前面的状态为on-line后面一个的状态为off-line的就是合格数据*/
	map<string, vector<node> > custom;  //建立客户名称 与 总体状态的 映射关系
	for (int i = 1; i < n; i++) {
		if (data[i].name == data[i - 1].name && data[i - 1].status == 1 && data[i].status == 0) {
			/*同一个客户，且前一个是on，后一个是off的话（合格状态）*/
			custom[data[i - 1].name].push_back(data[i - 1]); //map[string]对应的vector后添加on状态
			custom[data[i].name].push_back(data[i]); //再添加off状态
		}
	}
	for (auto it : custom) {
		/* auto it : custom  相当于 map<string, vector<node> >::itertator it =custom.begin()，总之是建立的map型custom的迭代器it，只要it!=NULL,进入循环*/
		vector<node> temp = it.second; //将it.first映射的存储客户状态的node型vector赋值给临时的temp
		cout << it.first;
		printf(" %02d\n", temp[0].month);  //打印出名字和月份
		double total = 0.0;
		for (int i = 1; i < temp.size(); i += 2) { //一对一对的打印出on-off时间，以及花费。不成对的直接忽略
			double t = billFromZero(temp[i], rate) - billFromZero(temp[i - 1], rate); //计算花费 = off时刻的花费 -on时候的花费
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i].time - temp[i - 1].time, t);
			total += t;  //累计总花费
		}
		printf("Total amount: $%.2f\n", total);
	}
	return 0;
}
