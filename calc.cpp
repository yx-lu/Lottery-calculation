#include<bits/stdc++.h>
#define maxn 505
using namespace std;
char hash1[333],hash2[333];
char id[maxn][50],mail[maxn][50];
int score1[maxn],score2[maxn],lst[maxn],n;
int Full_attendance,Attendance;
void calc(char hash[],int score[])
{
	int sum=0,res=0;for (int i=1;i<=n;i++) {sum+=score[i];lst[i]=sum-1;}
	for (int i=0;hash[i]!='\0';i++) res=(res*16+((hash[i]<='9')?(hash[i]-'0'):(hash[i]-'a'+10)))%sum;
	fprintf(stderr,"%d\n",res);
	for (int i=1;i<=n;i++) if ((score[i]>0)&&(lst[i]>=res))
	{
		fprintf(stdout,"Id= %s received a guess reward!\n",id[i]);
		return;
	}
	assert(0);
}
void init()
{
	scanf("%s\n%s\n",hash1,hash2);
	for (n=1;;n++)
	{
		if (scanf("%[^\t]\t%[^\t]\t",id[n],mail[n])==EOF) {n--;break;}
		int chk=0;double tmp=0;
		scanf("%lf\t%d\t%d\t%*f\t%d\n",&tmp,&score1[n],&score2[n],&chk);
		if (chk) Full_attendance++;
		if (tmp>1e-3) Attendance++;
		
		if (!chk) score1[n]=score2[n]=0;
	}
	fprintf(stdout,"User_num=%d\n",n);
	fprintf(stdout,"Full_attendance=%d\n",Full_attendance);
	fprintf(stdout,"Attendance=%d\n",Attendance);
}
	
int main()
{
	init();
	calc(hash1,score1);
	calc(hash2,score2);
}
