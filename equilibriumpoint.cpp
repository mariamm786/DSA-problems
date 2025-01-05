 int equilibriumPoint(vector<int> &arr) {
        // code here
        int leftsum=0,totalsum=0;
         int n=arr.size();
         for(int i=0;i<n;i++){
             totalsum+=arr[i];
             
         }
        for(int i=1;i<n;i++){
         
            int rightsum = totalsum-leftsum-arr[i];
            //leftsum+=arr[i];
            //cout<<rightsum<<endl;
        
           //cout<<leftsum<<endl;
            //cout<<endl;
            if(leftsum == rightsum){
                return i+1;
            }
            leftsum+=arr[i];
         }
       return -1;
    }
    
};