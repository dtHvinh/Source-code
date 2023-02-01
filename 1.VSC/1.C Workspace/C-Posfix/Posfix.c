// #include<stdio.h>                        viet them ham stack
// //#include"AStack.c"
// int priority(char x)
// {
// 	if (x == '(')
// 		return 0;
// 	if (x == '+' || x == '-')
// 		return 1 ;
// 	if (x == '*' || x == '/' || x == '%')
// 		return 2;
// 	return 3;
// }

// void infix2posfix(char in[],char pos[]){
//     //Stack S;
//     makenullStack(&S);
//     char token,x;
//     int j=0;
//     for(int i=0;in[i]!='\0';i++){
//         token = in[i];
//         if(token == ' ') continue;
//         if(token <= '9' && token >= '0') pos[j++] =token;        
//         else if(token =='(') push(token,&S);                          
//         else if(token ==')'){                                        
//             while((x=top(S))!='('){
//                 pos[j++] = x;
//                 pop(&S);
//             }
//             pop(&S);
//         }
//         else{                                                   
//             while(priority(top(S)) >= priority(token) && !emptyStack(S)){
//                 x=top(S);
//                 pop(&S);
//                 pos[j++] = x;
//             }
//             push(token,&S);
//         }
//     }
//     while(!emptyStack(S)){
//         x=top(S);
//         pop(&S);
//         pos[j++] = x;
//     }
//     pos[j] = '\0';
// }

// float tinh2(float n,float m,char c){
//     float res=0.0;
//     switch(c){
//         case '+': res = m + n; break;
//         case '-': res = m - n; break;
//         case '*': res = m * n; break;
//         case '/': res = m / n; break;
//         case '%': res = (int)m % (int)n; break;
//     }
//     return res;
// }


// float tinh(char a[]){
//     Stack btht;
//     makenullStack(&btht);
//     for(int i=0;a[i]!='\0';i++){
//         if(a[i]<='9' && a[i]>='0'){
//             float u = a[i]-48;
//             push(u,&btht);
//         }
//         else{
//             float m = top(btht);
//             pop(&btht);
//             float n = top(btht);
//             pop(&btht);
//             float t = tinh2(m,n,a[i]);
//             push(t,&btht);
//         }
//     }
//     return top(btht);
// }

// int main(){
//     char a[100];
//     char b[100];
//     scanf("%[^\n]",a);
//     infix2posfix(a,b);
//     for(int i=0;b[i]!='\0';i++) printf("%c ",b[i]);
//     printf("\n");
//     printf("%.2f",tinh(b));;
//     return 0;
// }