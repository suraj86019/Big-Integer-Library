#include<bits/stdc++.h>
using namespace std;

 

vector<int> add_bignumber(vector<int>x,vector<int>y) 
{
	reverse(x.begin(),x.end());
	reverse(y.begin(),y.end());
	
	int length = min(x.size(),y.size());
	
	int carry=0;
	vector<int>answer;
	for(int i = 0 ; i < length ; i++)
	{
		int value = x[i] + y[i] + carry;
		carry = value/10;
		answer.push_back(value%10); 
	}
	if(x.size() > length)
	{
		for(int i = length ; i < x.size() ; i++)
		{
		    int value = x[i] + carry;
		    carry = value/10;
		    answer.push_back(value%10); 
		}
	}
	else if(y.size() > length)
	{
		for(int i = length ; i < y.size() ; i++)
		{
		    int value = y[i] + carry;
		    carry = value/10;
		    answer.push_back(value%10); 
		}
	}
	while(carry > 0)
	{
		answer.push_back(carry%10);
		carry = carry/10;
	}
	reverse(answer.begin(),answer.end());
	return answer;
}





vector<int> subtraction_bignumber(vector<int>x,vector<int>y) 
{
	reverse(x.begin(),x.end());
	reverse(y.begin(),y.end());
	
	int length = y.size();
	vector<int>ans;
	for(int i = 0 ; i < y.size() ; i++)
	{
		if(x[i] < y[i])
		{
			x[i+1]--;
			ans.push_back(10 + x[i] - y[i]);
		}
		else
		{
			ans.push_back(x[i] - y[i]);
		}
	}
	if(x.size() > length)
	{
		for(int i = length ; i < x.size() ; i++)
		{
			if(x[i] < 0)
			{
				x[i+1]--;
				ans.push_back(10 + x[i]);
			}
			else
			{
				ans.push_back(x[i]);
			}
		}
	}
	vector<int>result;
	int i=0;
	reverse(ans.begin(),ans.end());
	while(ans[i] == 0)
	{
		i++;
	}
	for( ; i < ans.size() ; i++)
	{
		result.push_back(ans[i]);
	}
	return result;
}





vector<int> divisionby2(vector<int>x) 

{
	
	vector<int>ans;
	int remainder = 0;
	for(int i = 0 ; i < x.size() ; i++)
	{
		if(remainder == 0)
		{
			if(x[i] < 2)
			{
				remainder = remainder + x[i];
				ans.push_back(0);
			}
			else
			{
				remainder = x[i]%2;
				ans.push_back(x[i]/2);
			}
		}
		else
		{
			remainder = 10*remainder + x[i];
			ans.push_back(remainder/2);
			remainder = remainder%2;
		}
	}
	vector<int>result;
	int i=0;
	while(ans[i] == 0)
	{
		i++;
	}
	for(; i < ans.size() ; i++)
	{
		result.push_back(ans[i]);
	}
	return result;
}



vector<int> multiplication_bignumber(vector<int> num1,vector<int> num2) {

        // Reverse num1 and num2.
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        // Initialize answer as a string of zeros of length N.
        int N = num1.size() + num2.size();
        vector<int> answer(N, 0);
        
        for (int place2 = 0; place2 < num2.size(); place2++) {
            int digit2 = num2[place2] ;
            
            // For each digit in num2 multiply the digit by all digits in num1.
            for (int place1 = 0; place1 < num1.size(); place1++) {
                int digit1 = num1[place1] ;
                
                // The number of zeros from multiplying to digits depends on the 
                // place of digit2 in num2 and the place of the digit1 in num1.
                int numZeros = place1 + place2;
                
                // The digit currently at position numZeros in the answer string
                // is carried over and summed with the current result.
                int carry = answer[numZeros];
                int multiplication = digit1 * digit2 + carry;
                
                // Set the ones place of the multiplication result.
                answer[numZeros] = (multiplication % 10);
                
                // Carry the tens place of the multiplication result by 
                // adding it to the next position in the answer array.
                answer[numZeros + 1] += (multiplication / 10);
            }
        }
        
        if (answer.back() == 0) {
            answer.pop_back();
        }
        reverse(answer.begin(), answer.end());
        return answer;




}






void multiplyfac(vector<int>&ans,int number)
{
	int carry = 0;
	
	for(int i = 0 ; i < ans.size() ; i++)
	{
		int product =  (ans[i]*1LL*number) + carry;
		carry = product/10;
		ans[i] = product%10;
	}
	while(carry > 0)
	{
		ans.push_back(carry%10);
		carry = carry/10;
	}
}






vector<int> factorial(int n)
{
	vector<int>ans;
	
	ans.push_back(1);
	
	for(int i = 2 ; i <= n ; i++)
	{
		multiplyfac(ans,i);
	}
	reverse(ans.begin(),ans.end());
	return ans;
}







int main()
{
   
  
   string a,b;
   cin>>a>>b;
   
   vector<int>v1,v2;
   
   for(int i = 0 ; i < a.size() ; i++)
   {
   	v1.push_back(a[i]-'0');
   }
   for(int i = 0 ; i < b.size() ; i++)
   {
   	v2.push_back(b[i]-'0');
   }




   
   vector<int>sum = add_bignumber(v1,v2);

    cout<<"Addition answer number is  :"<<endl;
   for(int i = 0 ; i < sum.size() ; i++)
   {
   	cout<<sum[i];
   }
   cout<<endl;





   
   vector<int>subtract = subtraction_bignumber(v1,v2);
   
    cout<<"Subtraction answer number is  :"<<endl;
   for(int i = 0 ; i < subtract.size() ; i++)
   {
   	cout<<subtract[i];
   }
   cout<<endl;

int t;
 cout<<" enter the fact number"<<" ";
 cin>>t;

    cout<<"Factorial answer number is  v1 :"<<endl;
    
   vector<int>fact = factorial(t);
   
   for(int i = 0 ; i < fact.size() ; i++)
   {
   	cout<<fact[i];
   }
   cout<<endl;




    



   vector<int>divide = divisionby2(v1);
    cout<<"Division answer number is  :"<<endl;
   
   for(int i = 0; i < divide.size() ; i++)
   {
   	cout<<divide[i];
   }
   cout<<endl;  





    vector<int>multi = multiplication_bignumber(v1,v2);
    cout<<"multiplication answer number is  :"<<endl;
   
   for(int i = 0; i < multi.size() ; i++)
   {
   	cout<<multi[i];
   }
   cout<<endl;  
    return 0;
}