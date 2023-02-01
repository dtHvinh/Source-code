#include <iostream>
using namespace std;

/*int main()
{
	int arr[] = { 14, 3, 6, 27, 12 };
	for (int item: arr)
	{
		// biến item đại diện cho phần tử mảng ở mỗi vòng lặp
		cout << item << " ";
	}
	cout << endl;

	return 0;
}*/


#include <iostream>
using namespace std;
 
void move(int n,char A,char B,char C)
 {
      if(n==1){
        cout<<A<<" ==> "<<C<<"\n";          // nếu n = 1 thì dịch chuyển từ A -> C
      }
      else {          
        move(n - 1, A, C, B);               // 1. Dịch chuyển n-1 đĩa từ A -> B
        cout<<A<<" ==> "<<C<<"\n";          // 2. Dịch chuyển đĩa thứ n từ A -> C
        move(n - 1, B, A, C);               // 3. Dịch chuyển n-1 đĩa từ B -> C
      }
 }
 
int main() {
  int n;
  cout<<endl<<"So dia: ";
  cin>>n;
  move(n, 'A', 'B', 'C');
}