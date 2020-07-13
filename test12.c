/****************
马踏棋盘： 随机给定马的位置，根据马走的规则 ，移动，每个方格走一次 
使用的数据结构：1、栈：用于存储路径
贪心选择的最优量度标准：该点相邻点的步的路径最少最优 
**************/ 
#include<stdio.h>
#include<time.h>

#define BoardSize 8  
  int isFinished=0;
 int dirx[]={1,2,2,1,-1,-2,-2,-1};                           //数组依次记录八个可走方向的纵坐标 
 int diry[]={2,1,-1,-2,-2,-1,1,2};                           //数组依次记录八个可走方向的横坐标   
int visited [BoardSize*BoardSize] ={0}; 
  int aim_num,cur_num=0;//目标解的数目和当前解数 
  int hui=0;//回溯次数 
typedef struct Point_info{//一个元素的信息 
	int i;
	int j;
}Point;//重命名

typedef struct stack//使用顺序栈  非递归算法使用 
{
	Point data[BoardSize*BoardSize]; //存放坐标位置 
	int top;  //栈顶指针 
}SEQSTACK; 


void check_input(int *x,int *y);//检查输入 
void Visit_array(int array[][BoardSize],int n);//打印棋盘 
void Init_array(int array[][BoardSize],int n) ;//初始化棋盘 
void sort(Point *points,int size);
int  next(Point curPoint,Point *points);//根据当前的位置求后面的位置 ,返回是一个集合：包含可行的解 
Point pop(SEQSTACK *s);//元素出栈，出栈元素用e返回
int  push(SEQSTACK *s,Point data);  //元素data进栈
void initstack(SEQSTACK  *s);//顺序栈初始化
int empty(SEQSTACK *s) ;    //判断栈空
int  GetTop(SEQSTACK *s,Point *e); //获得栈顶元素 返回 0错误，返回1正确 
 void print_chessBoard(int array[BoardSize][BoardSize],int n); //加上边框打印 
void print_one_array(int *a,int n);//打印flag数组 
 void no_digui_Greed_Solve(int chessBoard [][BoardSize] ,int row,int colum) ;//、非递归实现 
  void showmenu();//显示菜单 
void InitVar(int chessBoard [][BoardSize]);//初始化全局变量  
  

/*
  chessBoard 棋盘
  row:行
  colum:列
  step:马走的步数 
*/


void Sovle_HorseChessBoard(int chessBoard [][BoardSize] ,int row,int colum,int step)
{
	Point  nextpoints[8]={};
	int i,j,k;
	Point curPoint,temp; 
	curPoint.i=row; 
	curPoint.j=colum;
	//把当前位置标记为1，被访问过 
	
		//printf("\n");
	chessBoard[row][colum]=step;
   // printf("step1=%d\n",step);
	//当前位置标记为1，被访问过 
	 visited[row*BoardSize+colum]=1;//一维数组存放二维数组的访问情况
	 j=next(curPoint,nextpoints);
	 // sort(nextpoints,j) ;
	 //step==64时不会进入这里，因为j==0 
	 while(j>0)//有方向可以走
	 {
	 	//取出当前的位置，进而可以进入下一个位置
		  temp=nextpoints[j-1];//取最后一个位置的
		  j--;//表示去除了一个点 
		//  printf("j=%d\n",j);
		  if(visited[temp.i*BoardSize+temp.j]==0) //未被访问
		  {
		  	//printf("step=%d\n",step);
		  	Sovle_HorseChessBoard(chessBoard,temp.i,temp.j,step+1) ;
		  } 
		  //怎么求出多个解，需要回溯
		  //当step==64时求出一个解	  
	
	 }
	 //无方向走了 ，打印  
	 if(step==64)
	 {
	         cur_num++;//解的数目累加 
	          if(cur_num>=aim_num)isFinished=1; //求到规定的解的个数 
	         
	 		print_chessBoard(chessBoard,BoardSize);
	 }
	
	 //回溯的时候清空标记 
	 if(isFinished==0) //未完成才进行回溯 
	 {
	 	hui++;
	  step--;
	  if(step==0) isFinished=1;//当走完所有路径退出 
	 visited[row*BoardSize+colum]=0;
	 chessBoard[row][colum]=0;
	 }	 
}

int main()
{
int x,y;//step表示走的步骤	
int row=4,colum=2,choice;
double start,finish;
int board[BoardSize][BoardSize];//定义棋盘大小,全局变量，方便使用 	
system("color f2");//调节屏幕的颜色  第一个数表示背景颜色，第2个表前景  黑背景蓝色前景 
while(1)
{
	showmenu();
	printf("    请输入你的选择：");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
	    	check_input(&row,&colum);
		    InitVar(board)	;
		    start= clock();
		     Sovle_HorseChessBoard(board,row-1,colum-1,1); 
		     finish= clock();
		     printf("运行时间：%.3f秒\n",(finish-start)/1000);
	         printf("回溯次数=%d\n",hui);
	          //print_chessBoard(board,BoardSize);
	          printf("按任意键继续……\n");
			getch();
	         system("cls");
	           break;
       case 2:
	    	check_input(&row,&colum);
		     InitVar(board)	;//初始化棋盘 	
		    start= clock();
		     no_digui_Greed_Solve(board,row-1,colum-1);
		     finish= clock();
		     printf("运行时间：%.3f秒\n",(finish-start)/1000);
	         printf("回溯次数=%d\n",hui);
	        
	          printf("按任意键继续……\n");
			getch();
	         system("cls");	
	         break;
   	case 3:return;	
   	default:printf("输入错误！\n");
			         getch();
				    system("cls");
	}
}



 }

//显示菜单 
  void showmenu()
  {
    printf("\t***欢迎使用马踏棋盘程序******\n");
    printf("\t****制作人：计算机181 卿高军 指导老师：魏本昌*******\n"); 
	printf("\t1、递归算法实现\n");
	printf("\t2、非递归算法实现\n");
	printf("\t3、退出程序\n");	
  }

 
 //初始矩阵
 void Init_array(int array[][BoardSize],int n) 
 {
 		int i,j;
	 for(i=0;i<n;i++)
	 {
	 	for(j=0;j<n;j++)
	 	{
			array[i][j]=0;//在 8 * 8 的外层再加上两层，确保 8 * 8 方格中的每一个格子都有 8 种不同的日字选择 
		
		 }
		 
	  } 
 }
 
 //打印矩阵 
 void Visit_array(int array[BoardSize][BoardSize],int n)
 {
 	int i,j;
	 for(i=0;i<n;i++)
	 {
	 	for(j=0;j<n;j++)
	 	{
	 		printf("%3d ",array[i][j]);
		 }
		 printf("\n");
	  }
	  printf("\n"); 
 	
  } 
  //打印一个数据 
 
 //检查输入 
 void check_input(int *x,int *y)
{
   while(1)
  {
  printf("请输入一个起始位置i,j(1<=i,j<=8)：");
  scanf("%d%d",&(*x),&(*y));
  printf("x=%d,y=%d\n",*x,*y); 
  if(((*x)>=1&&(*x)<=8)&&((*y)<=8&&(*y)>=1))
  {
  	break;
  }
  printf("输入错误，请重新输入\n");
  }
  printf("请输入解的个数.(注：可求任意个解)\n");
  scanf("%d",&aim_num);
   
}

/*
  对集合中的Point进行排序，使得一个按邻接点的个数进行降序排序，因为每次取出的是最后一个元素
  points 一个数组放可行的点 
  数据较少，使用冒泡排序法效率也不错
  功能：下一步的所有下一步的位置 集合按照降序排序 
*/ 
void sort(Point *points,int size)
{
	int i,j,b,k; 
	//先得到关键字
    Point a, item[8]={0};
	int keys[size]; //关键字数组：是points中元素 的下一个节点的个数 
	for(k=0;k<size;k++)
	{
	keys[k]=next(points[k],item);	
	 } 
	// printf("\n");
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(keys[j]<keys[j+1]) //最小的移动到最后面 
			{
				a=points[j];
				points[j]=points[j+1];
				points[j+1]=a;
				for(k=0;k<size;k++) //更新关键字 
	             {
                    	keys[k]=next(points[k],item);	
	             } 
			}
		}		
	}	
}
/*
curPoint 当前点
Points :一个集合，用来返回其可走的点
当走的位置不出棋盘的空间且未被访问的节点即为加入到下一个节点的集合 
j= 代表可走点的多少 
根据当前的位置求后面的位置 ,返回是一个集合：包含可行的解 
*/ 
int  next(Point curPoint,Point *points){
    
	int j=0;  
	Point point=curPoint;
	int i;
	for(i=0;i<8;i++)//访问8个可马可移动的位置 
	{
	point.i=curPoint.i+dirx[i];
	point.j=curPoint.j+diry[i];
		if((0<=point.i&&point.i<BoardSize)&&(0<=point.j&&point.j<BoardSize)&&(visited[point.i*BoardSize+point.j]==0))
		{
		   points[j]=point;
		   j++;//表示集合大小 
		 	 } 	
	}
	//printf("curPoint i=%d,j=%d的可走路径数为%d\n",curPoint.i,curPoint.j,j); 
	return j;  
}

//出栈
   Point pop(SEQSTACK *s)//元素出栈，出栈元素用e返回
{
	Point e={0};
	if(empty(s)==1)
	{
		printf("栈中元素已空，出栈元素失败！\n");
		
	    return e;
	}
	else
	{

		 e=s->data[s->top] ;//将栈顶元素赋值给变量e
		 s->top=s->top-1 ;//栈顶指针减1
  //printf("出栈： ");
 //printf("stop=%d,x=%d,y=%d\n",s->top,e.i,e.j);
		return e;
	}

}


   
     //元素data进栈
 int  push(SEQSTACK *s,Point data)
{

	if(s->top>=BoardSize*BoardSize-1)
	{
			printf("存储空间已满，元素进栈失败！\n");
			return 0;
	} 	
	else
	{
	 s->top=s->top+1   ;//栈顶指针加1
     s->data[s->top]=data ;//将元素x送到栈顶位置  
   //printf("压入 ");
    //printf("stop=%d,x=%d,y=%d\n",s->top+1,data.i,data.j);
    return 1;
		}		
}
  //初始化栈 
 void initstack(SEQSTACK  *s)
 {
 s->top=-1;	//将栈顶指针指向初始的位置
 } 
 //栈空判断 返回1：栈空 返回 0：栈非空 
int empty(SEQSTACK *s)  
{
	if(s->top==-1)
		return 1;
	else 
		return 0;
}


 //获得栈顶元素 返回 0错误，返回1正确 
 int  GetTop(SEQSTACK *s,Point *e)
 {
 	if(s->top==-1)return 0;//执行错误
	 *e=s->data[s->top];
	 return 1;//正确返回 
  } 
   void print_chessBoard(int array[BoardSize][BoardSize],int n)
 {
 	int i,j,k;
 	printf("第%d个解\n",cur_num);
	 for(i=0;i<n;i++)
	 {
	 	 for(k=0;k<n;k++)printf(" ——");
	 	  printf("\n");
	 	for(j=0;j<n;j++)
	 	{
	 		printf("|%3d ",array[i][j]);
		 }
		 printf("|\n");
	  }
	  for(k=0;k<n;k++)printf(" ——");
	  printf("\n\n"); 
 	
  }

  void print_one_array(int *a,int n)
{
	int i;
	printf("flag的值：\n");
	for(i=0;i<n;i++)
	{
		printf("flag[%d]=%d ",i,a[i]);
		if(i+1%20==0)
		{
			printf("\n");	
		}
	}
	printf("\n");
}

/*
  chessBoard 棋盘
  row:行
  colum:列 
  提示：选择下一步结点使用贪心法的 
  非递归算法实现 ：先访问一个位置x，如果该位置的相邻位置y有位置可走，(第一个位置例外) 
  访问该邻接点 ，如果邻接点未被访问， 再判断该邻接点是否有相邻点未被访问，如果有，将该结点入栈(选择更加合理)
  并将访问标志制1 
  如果没有： 继续访问其他的相邻结点 .  
*/
void no_digui_Greed_Solve(int chessBoard [][BoardSize] ,int row,int colum) 
{
	Point  nextpoints[8]={};
	int flag[BoardSize*BoardSize+1]={0};//记录点是否走访 
    int i,anwer_num,k=0;
	Point curPoint,temp;
	SEQSTACK stack;
     initstack(&stack);//初始栈 
	curPoint.i=row; 
	curPoint.j=colum;
	 push(&stack,curPoint);//起始节点入栈 
    chessBoard[curPoint.i][curPoint.j]=stack.top+1;
	 visited[row*BoardSize+colum]=1;//一维数组存放二维数组的访问情况
	 while(!empty(&stack))//栈不空 
	 { 
	    anwer_num=next(curPoint,nextpoints);   //遍历相邻的点，如果未被访问，就访问 
	     // printf("anwer_num1=%d\n",anwer_num);
	     sort(nextpoints,anwer_num) ; //第一次排序将最优的位置防止最后面，防止flag去的位置出错 
	    anwer_num=anwer_num-flag[stack.top];  //f范围 
	    sort(nextpoints,anwer_num) ;
	   //  printf("anwer_num2=%d\n",anwer_num);
	  
	 	  while(anwer_num>0)
	     {
		   curPoint=nextpoints[anwer_num-1];//取最后一个位置的
		   // printf("答案空间：\n");
			  	 //for(k=0;k<anwer_num+1;k++)
			  	// {
			  	 //	printf("答案%d ,x=%d,y=%d\n",k,nextpoints[k].i,nextpoints[k].j);
				//   }
		   anwer_num--;//表示去除了一个点  ，
		
              anwer_num=next(curPoint,nextpoints);//当下一个节点有点可以访问时，入栈 
			  if(anwer_num>0||(stack.top==BoardSize*BoardSize-2))//最后一个元素入栈 
			  {
			  //	 printf("入栈前top=%d,%d入栈  temp.i=%d ,temp.j=%d\n",stack.top,stack.top+1,temp.i,temp.j);
			    // printf("j=%d\n",j); 
			  //	 printf("入栈：top=%d,x=%d,y=%d\n",stack.top,temp.i,temp.j);
			  	
			  	 push(&stack,curPoint);//当前节点入栈
			  
			  	  visited[curPoint.i*BoardSize+curPoint.j]=1;//表示访问过
		 		chessBoard[curPoint.i][curPoint.j]=stack.top+1;
		 	
			   }
			   
			    anwer_num=anwer_num-flag[stack.top];  	
		       sort(nextpoints,anwer_num) ;	      
		   // printf("在循环中：top=%d,j=%d\n",stack.top,j);
		     // printf("矩阵：\n");
            //  Visit_array(chessBoard,BoardSize);  
	    }
	 
			
	    
	    //当无方向走时，进行出栈 
	    if(stack.top<BoardSize*BoardSize-1&&!isFinished)//未完成 任务棋盘为0 
	 {
	    //printf("top=%d,curPoint.i=%d,curPoint.j=%d\n",stack.top,curPoint.i,curPoint.j);
	 	  hui++;
	 	  
	 	  	 GetTop(&stack,&curPoint) ;
          //  printf("栈顶元素为x=%d，y=%d\n",curPoint.i,curPoint.j);
	 	       flag[stack.top]++; //当前节点换个位置 
		   	  flag[stack.top+1]=0; 
	 	 
	 
	     //出栈一个可以走的点,如果无相邻可走点，就继续出栈，直到遇到一个可走点 
	 	  while((next(curPoint,nextpoints)-flag[stack.top])<=0)
		   {hui++;
		  //	printf("while关键num=%d\n",(next(curPoint,nextpoints)-flag[stack.top]));
		   	  pop(&stack);
		   	  flag[stack.top]++; //当前节点换个位置 
		   	  flag[stack.top+1]=0; 
		  
		   	   visited[curPoint.i*BoardSize+curPoint.j]=0;//表示访问过 
	          chessBoard[curPoint.i][curPoint.j]=0;
		   //print_one_array(flag,BoardSize*BoardSize);
		   	  GetTop(&stack,&curPoint) ;
        //  printf("栈顶元素为x=%d，y=%d,关键num=%d",curPoint.i,curPoint.j,(next(curPoint,nextpoints)-flag[stack.top]));
	 	  	 
		 //  printf("矩阵：\n");
            //Visit_array(chessBoard,BoardSize);  
		    //怎么寻找另一路径 
			} 

	 	 
	 
	  } else{//求出一个解 栈满 

      cur_num++;//表示求处一个解
     print_chessBoard(chessBoard,BoardSize);
      //Visit_array(chessBoard,BoardSize);
     //print_stack(&stack,chessBoard);
	 
	  if(cur_num>=aim_num)	 //求到规定的解的个数 
	  {
	  		isFinished=1;//	
			  break;   
	  }
	    
	  	else{ //否则出栈 
	  		curPoint=pop(&stack);	
	  	   // flag[stack.top]=1+flag[stack.top];//当前节点换个位置 
	  	  //  printf("top1=%d,curPoint.i=%d,curPoint.j=%d\n",stack.top,curPoint.i,curPoint.j);
	  	    visited[curPoint.i*BoardSize+curPoint.j]=0;//表示访问过 
	  	    chessBoard[curPoint.i][curPoint.j]=0;
		  } 
	 }
	 
}
}

  void InitVar(int chessBoard [][BoardSize])
  {
  	int i;
  	cur_num=0;
  	//step=1;
  	isFinished=0;
  	hui=0;
  //	visited [BoardSize*BoardSize] ={0}; 
  	 Init_array(chessBoard,BoardSize);//初始化棋盘 
	   for(i=0;i<BoardSize*BoardSize;i++)
	   {
	   	visited [i]=0;
		   }	
   } 
