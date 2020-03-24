#include<iostream>
using namespace std;

//Recursive function for calculating the f(x) part in each term of lagranges interpolation formula
float xCalc(int n, int i, float arr[], float x){
	if (n<1)
	{
		return 1;
	}
	else
	{
		if (n!=i)
		{
			return (x-arr[n-1])/(arr[i-1]-arr[n-1])*xCalc(n-1,i,arr,x);
		}
		else
		{
			return xCalc(n-1,i,arr,x);
		}
	}
}

int main()
{
	//Declaration & User input
	int x,num ;
	float arrX[num], arrY[num], res = 0; 
	cout<<"Enter the number of terms \n";
	cin>>num;
	cout<<"Enter the value of x for which y must be calculated \n";
	cin>>x;
	cout<<"Enter the x terms followed by corresponding y terms in sequence (format: x y x y) \n";
	for (int i = 0; i < num; ++i)
	{
		cin>>arrX[i]>>arrY[i];
	}

	//Calculation
	for (int i = 0; i < num; ++i)
	{
		res += xCalc(num,i,arrX,x)*arrY[i];
	}

	cout<<"The required result is "<<res;
}


