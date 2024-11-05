class Solution {
public:
  
    int calPoints(vector<string>& operations) {
      vector<int>arr(1001,0);
        int top=-1;
        int i=0;
        while(i<operations.size()){

            if(operations[i]=="+"){
                        int a=arr[top];
                        top--;
                        int result=a+arr[top];
                        top++;
                        arr[top]=a;
                        top++;
                        arr[top]=result;
                        i++;
                    }
                    else if(operations[i]=="D"){
                        int d=2*arr[top];
                        top++;
                        arr[top]=d;
                        i++;
                    }
                    else if(operations[i]=="C"){
                        arr[top]=0;
                        top--;
                        i++;
                    }
                    else{
                        top++;
                        arr[top]=stoi(operations[i]);
                        i++;
                    }
        }

        int sum=0;
        int j=0;
        while(j<arr.size()){
            sum=sum+arr[j];
            j++;
        }
     
     return sum;
    }
};
