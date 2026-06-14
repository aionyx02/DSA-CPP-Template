void prefixSum(vector<int>&arr,vector<int>&prefix){
    prefix.resize(arr.size());
    for(int i=0;i<arr.size();++i){
        if(i==0){
            prefix[i] = arr[i];
        }else{
            prefix[i] = prefix[i-1]+arr[i];
        }
    }
}

void suffixSum(vector<int>& arr, vector<int>& suffix) {
    suffix.resize(arr.size());
    for (int i = arr.size() - 1; i >= 0; --i) {
        if (i == arr.size() - 1) {
            suffix[i] = arr[i];
        } else {
            suffix[i] = suffix[i + 1] + arr[i];
        }
    }
}