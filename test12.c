/****************
��̤���̣� ����������λ�ã��������ߵĹ��� ���ƶ���ÿ��������һ�� 
ʹ�õ����ݽṹ��1��ջ�����ڴ洢·��
̰��ѡ����������ȱ�׼���õ����ڵ�Ĳ���·���������� 
**************/ 
#include<stdio.h>
#include<time.h>

#define BoardSize 8  
  int isFinished=0;
 int dirx[]={1,2,2,1,-1,-2,-2,-1};                           //�������μ�¼�˸����߷���������� 
 int diry[]={2,1,-1,-2,-2,-1,1,2};                           //�������μ�¼�˸����߷���ĺ�����   
int visited [BoardSize*BoardSize] ={0}; 
  int aim_num,cur_num=0;//Ŀ������Ŀ�͵�ǰ���� 
  int hui=0;//���ݴ��� 
typedef struct Point_info{//һ��Ԫ�ص���Ϣ 
	int i;
	int j;
}Point;//������

typedef struct stack//ʹ��˳��ջ  �ǵݹ��㷨ʹ�� 
{
	Point data[BoardSize*BoardSize]; //�������λ�� 
	int top;  //ջ��ָ�� 
}SEQSTACK; 


void check_input(int *x,int *y);//������� 
void Visit_array(int array[][BoardSize],int n);//��ӡ���� 
void Init_array(int array[][BoardSize],int n) ;//��ʼ������ 
void sort(Point *points,int size);
int  next(Point curPoint,Point *points);//���ݵ�ǰ��λ��������λ�� ,������һ�����ϣ��������еĽ� 
Point pop(SEQSTACK *s);//Ԫ�س�ջ����ջԪ����e����
int  push(SEQSTACK *s,Point data);  //Ԫ��data��ջ
void initstack(SEQSTACK  *s);//˳��ջ��ʼ��
int empty(SEQSTACK *s) ;    //�ж�ջ��
int  GetTop(SEQSTACK *s,Point *e); //���ջ��Ԫ�� ���� 0���󣬷���1��ȷ 
 void print_chessBoard(int array[BoardSize][BoardSize],int n); //���ϱ߿��ӡ 
void print_one_array(int *a,int n);//��ӡflag���� 
 void no_digui_Greed_Solve(int chessBoard [][BoardSize] ,int row,int colum) ;//���ǵݹ�ʵ�� 
  void showmenu();//��ʾ�˵� 
void InitVar(int chessBoard [][BoardSize]);//��ʼ��ȫ�ֱ���  
  

/*
  chessBoard ����
  row:��
  colum:��
  step:���ߵĲ��� 
*/


void Sovle_HorseChessBoard(int chessBoard [][BoardSize] ,int row,int colum,int step)
{
	Point  nextpoints[8]={};
	int i,j,k;
	Point curPoint,temp; 
	curPoint.i=row; 
	curPoint.j=colum;
	//�ѵ�ǰλ�ñ��Ϊ1�������ʹ� 
	
		//printf("\n");
	chessBoard[row][colum]=step;
   // printf("step1=%d\n",step);
	//��ǰλ�ñ��Ϊ1�������ʹ� 
	 visited[row*BoardSize+colum]=1;//һά�����Ŷ�ά����ķ������
	 j=next(curPoint,nextpoints);
	 // sort(nextpoints,j) ;
	 //step==64ʱ������������Ϊj==0 
	 while(j>0)//�з��������
	 {
	 	//ȡ����ǰ��λ�ã��������Խ�����һ��λ��
		  temp=nextpoints[j-1];//ȡ���һ��λ�õ�
		  j--;//��ʾȥ����һ���� 
		//  printf("j=%d\n",j);
		  if(visited[temp.i*BoardSize+temp.j]==0) //δ������
		  {
		  	//printf("step=%d\n",step);
		  	Sovle_HorseChessBoard(chessBoard,temp.i,temp.j,step+1) ;
		  } 
		  //��ô�������⣬��Ҫ����
		  //��step==64ʱ���һ����	  
	
	 }
	 //�޷������� ����ӡ  
	 if(step==64)
	 {
	         cur_num++;//�����Ŀ�ۼ� 
	          if(cur_num>=aim_num)isFinished=1; //�󵽹涨�Ľ�ĸ��� 
	         
	 		print_chessBoard(chessBoard,BoardSize);
	 }
	
	 //���ݵ�ʱ����ձ�� 
	 if(isFinished==0) //δ��ɲŽ��л��� 
	 {
	 	hui++;
	  step--;
	  if(step==0) isFinished=1;//����������·���˳� 
	 visited[row*BoardSize+colum]=0;
	 chessBoard[row][colum]=0;
	 }	 
}

int main()
{
int x,y;//step��ʾ�ߵĲ���	
int row=4,colum=2,choice;
double start,finish;
int board[BoardSize][BoardSize];//�������̴�С,ȫ�ֱ���������ʹ�� 	
system("color f2");//������Ļ����ɫ  ��һ������ʾ������ɫ����2����ǰ��  �ڱ�����ɫǰ�� 
while(1)
{
	showmenu();
	printf("    ���������ѡ��");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
	    	check_input(&row,&colum);
		    InitVar(board)	;
		    start= clock();
		     Sovle_HorseChessBoard(board,row-1,colum-1,1); 
		     finish= clock();
		     printf("����ʱ�䣺%.3f��\n",(finish-start)/1000);
	         printf("���ݴ���=%d\n",hui);
	          //print_chessBoard(board,BoardSize);
	          printf("���������������\n");
			getch();
	         system("cls");
	           break;
       case 2:
	    	check_input(&row,&colum);
		     InitVar(board)	;//��ʼ������ 	
		    start= clock();
		     no_digui_Greed_Solve(board,row-1,colum-1);
		     finish= clock();
		     printf("����ʱ�䣺%.3f��\n",(finish-start)/1000);
	         printf("���ݴ���=%d\n",hui);
	        
	          printf("���������������\n");
			getch();
	         system("cls");	
	         break;
   	case 3:return;	
   	default:printf("�������\n");
			         getch();
				    system("cls");
	}
}



 }

//��ʾ�˵� 
  void showmenu()
  {
    printf("\t***��ӭʹ����̤���̳���******\n");
    printf("\t****�����ˣ������181 ��߾� ָ����ʦ��κ����*******\n"); 
	printf("\t1���ݹ��㷨ʵ��\n");
	printf("\t2���ǵݹ��㷨ʵ��\n");
	printf("\t3���˳�����\n");	
  }

 
 //��ʼ����
 void Init_array(int array[][BoardSize],int n) 
 {
 		int i,j;
	 for(i=0;i<n;i++)
	 {
	 	for(j=0;j<n;j++)
	 	{
			array[i][j]=0;//�� 8 * 8 ������ټ������㣬ȷ�� 8 * 8 �����е�ÿһ�����Ӷ��� 8 �ֲ�ͬ������ѡ�� 
		
		 }
		 
	  } 
 }
 
 //��ӡ���� 
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
  //��ӡһ������ 
 
 //������� 
 void check_input(int *x,int *y)
{
   while(1)
  {
  printf("������һ����ʼλ��i,j(1<=i,j<=8)��");
  scanf("%d%d",&(*x),&(*y));
  printf("x=%d,y=%d\n",*x,*y); 
  if(((*x)>=1&&(*x)<=8)&&((*y)<=8&&(*y)>=1))
  {
  	break;
  }
  printf("�����������������\n");
  }
  printf("�������ĸ���.(ע�������������)\n");
  scanf("%d",&aim_num);
   
}

/*
  �Լ����е�Point��������ʹ��һ�����ڽӵ�ĸ������н���������Ϊÿ��ȡ���������һ��Ԫ��
  points һ������ſ��еĵ� 
  ���ݽ��٣�ʹ��ð������Ч��Ҳ����
  ���ܣ���һ����������һ����λ�� ���ϰ��ս������� 
*/ 
void sort(Point *points,int size)
{
	int i,j,b,k; 
	//�ȵõ��ؼ���
    Point a, item[8]={0};
	int keys[size]; //�ؼ������飺��points��Ԫ�� ����һ���ڵ�ĸ��� 
	for(k=0;k<size;k++)
	{
	keys[k]=next(points[k],item);	
	 } 
	// printf("\n");
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(keys[j]<keys[j+1]) //��С���ƶ�������� 
			{
				a=points[j];
				points[j]=points[j+1];
				points[j+1]=a;
				for(k=0;k<size;k++) //���¹ؼ��� 
	             {
                    	keys[k]=next(points[k],item);	
	             } 
			}
		}		
	}	
}
/*
curPoint ��ǰ��
Points :һ�����ϣ�������������ߵĵ�
���ߵ�λ�ò������̵Ŀռ���δ�����ʵĽڵ㼴Ϊ���뵽��һ���ڵ�ļ��� 
j= ������ߵ�Ķ��� 
���ݵ�ǰ��λ��������λ�� ,������һ�����ϣ��������еĽ� 
*/ 
int  next(Point curPoint,Point *points){
    
	int j=0;  
	Point point=curPoint;
	int i;
	for(i=0;i<8;i++)//����8��������ƶ���λ�� 
	{
	point.i=curPoint.i+dirx[i];
	point.j=curPoint.j+diry[i];
		if((0<=point.i&&point.i<BoardSize)&&(0<=point.j&&point.j<BoardSize)&&(visited[point.i*BoardSize+point.j]==0))
		{
		   points[j]=point;
		   j++;//��ʾ���ϴ�С 
		 	 } 	
	}
	//printf("curPoint i=%d,j=%d�Ŀ���·����Ϊ%d\n",curPoint.i,curPoint.j,j); 
	return j;  
}

//��ջ
   Point pop(SEQSTACK *s)//Ԫ�س�ջ����ջԪ����e����
{
	Point e={0};
	if(empty(s)==1)
	{
		printf("ջ��Ԫ���ѿգ���ջԪ��ʧ�ܣ�\n");
		
	    return e;
	}
	else
	{

		 e=s->data[s->top] ;//��ջ��Ԫ�ظ�ֵ������e
		 s->top=s->top-1 ;//ջ��ָ���1
  //printf("��ջ�� ");
 //printf("stop=%d,x=%d,y=%d\n",s->top,e.i,e.j);
		return e;
	}

}


   
     //Ԫ��data��ջ
 int  push(SEQSTACK *s,Point data)
{

	if(s->top>=BoardSize*BoardSize-1)
	{
			printf("�洢�ռ�������Ԫ�ؽ�ջʧ�ܣ�\n");
			return 0;
	} 	
	else
	{
	 s->top=s->top+1   ;//ջ��ָ���1
     s->data[s->top]=data ;//��Ԫ��x�͵�ջ��λ��  
   //printf("ѹ�� ");
    //printf("stop=%d,x=%d,y=%d\n",s->top+1,data.i,data.j);
    return 1;
		}		
}
  //��ʼ��ջ 
 void initstack(SEQSTACK  *s)
 {
 s->top=-1;	//��ջ��ָ��ָ���ʼ��λ��
 } 
 //ջ���ж� ����1��ջ�� ���� 0��ջ�ǿ� 
int empty(SEQSTACK *s)  
{
	if(s->top==-1)
		return 1;
	else 
		return 0;
}


 //���ջ��Ԫ�� ���� 0���󣬷���1��ȷ 
 int  GetTop(SEQSTACK *s,Point *e)
 {
 	if(s->top==-1)return 0;//ִ�д���
	 *e=s->data[s->top];
	 return 1;//��ȷ���� 
  } 
   void print_chessBoard(int array[BoardSize][BoardSize],int n)
 {
 	int i,j,k;
 	printf("��%d����\n",cur_num);
	 for(i=0;i<n;i++)
	 {
	 	 for(k=0;k<n;k++)printf(" ����");
	 	  printf("\n");
	 	for(j=0;j<n;j++)
	 	{
	 		printf("|%3d ",array[i][j]);
		 }
		 printf("|\n");
	  }
	  for(k=0;k<n;k++)printf(" ����");
	  printf("\n\n"); 
 	
  }

  void print_one_array(int *a,int n)
{
	int i;
	printf("flag��ֵ��\n");
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
  chessBoard ����
  row:��
  colum:�� 
  ��ʾ��ѡ����һ�����ʹ��̰�ķ��� 
  �ǵݹ��㷨ʵ�� ���ȷ���һ��λ��x�������λ�õ�����λ��y��λ�ÿ��ߣ�(��һ��λ������) 
  ���ʸ��ڽӵ� ������ڽӵ�δ�����ʣ� ���жϸ��ڽӵ��Ƿ������ڵ�δ�����ʣ�����У����ý����ջ(ѡ����Ӻ���)
  �������ʱ�־��1 
  ���û�У� �����������������ڽ�� .  
*/
void no_digui_Greed_Solve(int chessBoard [][BoardSize] ,int row,int colum) 
{
	Point  nextpoints[8]={};
	int flag[BoardSize*BoardSize+1]={0};//��¼���Ƿ��߷� 
    int i,anwer_num,k=0;
	Point curPoint,temp;
	SEQSTACK stack;
     initstack(&stack);//��ʼջ 
	curPoint.i=row; 
	curPoint.j=colum;
	 push(&stack,curPoint);//��ʼ�ڵ���ջ 
    chessBoard[curPoint.i][curPoint.j]=stack.top+1;
	 visited[row*BoardSize+colum]=1;//һά�����Ŷ�ά����ķ������
	 while(!empty(&stack))//ջ���� 
	 { 
	    anwer_num=next(curPoint,nextpoints);   //�������ڵĵ㣬���δ�����ʣ��ͷ��� 
	     // printf("anwer_num1=%d\n",anwer_num);
	     sort(nextpoints,anwer_num) ; //��һ���������ŵ�λ�÷�ֹ����棬��ֹflagȥ��λ�ó��� 
	    anwer_num=anwer_num-flag[stack.top];  //f��Χ 
	    sort(nextpoints,anwer_num) ;
	   //  printf("anwer_num2=%d\n",anwer_num);
	  
	 	  while(anwer_num>0)
	     {
		   curPoint=nextpoints[anwer_num-1];//ȡ���һ��λ�õ�
		   // printf("�𰸿ռ䣺\n");
			  	 //for(k=0;k<anwer_num+1;k++)
			  	// {
			  	 //	printf("��%d ,x=%d,y=%d\n",k,nextpoints[k].i,nextpoints[k].j);
				//   }
		   anwer_num--;//��ʾȥ����һ����  ��
		
              anwer_num=next(curPoint,nextpoints);//����һ���ڵ��е���Է���ʱ����ջ 
			  if(anwer_num>0||(stack.top==BoardSize*BoardSize-2))//���һ��Ԫ����ջ 
			  {
			  //	 printf("��ջǰtop=%d,%d��ջ  temp.i=%d ,temp.j=%d\n",stack.top,stack.top+1,temp.i,temp.j);
			    // printf("j=%d\n",j); 
			  //	 printf("��ջ��top=%d,x=%d,y=%d\n",stack.top,temp.i,temp.j);
			  	
			  	 push(&stack,curPoint);//��ǰ�ڵ���ջ
			  
			  	  visited[curPoint.i*BoardSize+curPoint.j]=1;//��ʾ���ʹ�
		 		chessBoard[curPoint.i][curPoint.j]=stack.top+1;
		 	
			   }
			   
			    anwer_num=anwer_num-flag[stack.top];  	
		       sort(nextpoints,anwer_num) ;	      
		   // printf("��ѭ���У�top=%d,j=%d\n",stack.top,j);
		     // printf("����\n");
            //  Visit_array(chessBoard,BoardSize);  
	    }
	 
			
	    
	    //���޷�����ʱ�����г�ջ 
	    if(stack.top<BoardSize*BoardSize-1&&!isFinished)//δ��� ��������Ϊ0 
	 {
	    //printf("top=%d,curPoint.i=%d,curPoint.j=%d\n",stack.top,curPoint.i,curPoint.j);
	 	  hui++;
	 	  
	 	  	 GetTop(&stack,&curPoint) ;
          //  printf("ջ��Ԫ��Ϊx=%d��y=%d\n",curPoint.i,curPoint.j);
	 	       flag[stack.top]++; //��ǰ�ڵ㻻��λ�� 
		   	  flag[stack.top+1]=0; 
	 	 
	 
	     //��ջһ�������ߵĵ�,��������ڿ��ߵ㣬�ͼ�����ջ��ֱ������һ�����ߵ� 
	 	  while((next(curPoint,nextpoints)-flag[stack.top])<=0)
		   {hui++;
		  //	printf("while�ؼ�num=%d\n",(next(curPoint,nextpoints)-flag[stack.top]));
		   	  pop(&stack);
		   	  flag[stack.top]++; //��ǰ�ڵ㻻��λ�� 
		   	  flag[stack.top+1]=0; 
		  
		   	   visited[curPoint.i*BoardSize+curPoint.j]=0;//��ʾ���ʹ� 
	          chessBoard[curPoint.i][curPoint.j]=0;
		   //print_one_array(flag,BoardSize*BoardSize);
		   	  GetTop(&stack,&curPoint) ;
        //  printf("ջ��Ԫ��Ϊx=%d��y=%d,�ؼ�num=%d",curPoint.i,curPoint.j,(next(curPoint,nextpoints)-flag[stack.top]));
	 	  	 
		 //  printf("����\n");
            //Visit_array(chessBoard,BoardSize);  
		    //��ôѰ����һ·�� 
			} 

	 	 
	 
	  } else{//���һ���� ջ�� 

      cur_num++;//��ʾ��һ����
     print_chessBoard(chessBoard,BoardSize);
      //Visit_array(chessBoard,BoardSize);
     //print_stack(&stack,chessBoard);
	 
	  if(cur_num>=aim_num)	 //�󵽹涨�Ľ�ĸ��� 
	  {
	  		isFinished=1;//	
			  break;   
	  }
	    
	  	else{ //�����ջ 
	  		curPoint=pop(&stack);	
	  	   // flag[stack.top]=1+flag[stack.top];//��ǰ�ڵ㻻��λ�� 
	  	  //  printf("top1=%d,curPoint.i=%d,curPoint.j=%d\n",stack.top,curPoint.i,curPoint.j);
	  	    visited[curPoint.i*BoardSize+curPoint.j]=0;//��ʾ���ʹ� 
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
  	 Init_array(chessBoard,BoardSize);//��ʼ������ 
	   for(i=0;i<BoardSize*BoardSize;i++)
	   {
	   	visited [i]=0;
		   }	
   } 
