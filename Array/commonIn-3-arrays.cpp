//----------------USING EXTRA SPACE------------------------//

vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        unordered_set<int> st1;
        unordered_set<int> st2;
        set<int> st3;
        vector<int> result;
        
        for(int i = 0; i< arr1.size(); i++)
            st1.insert(arr1[i]);
            
        for(int j = 0; j< arr2.size(); j++)
        {
            if(st1.find(arr2[j]) != st1.end())
                st2.insert(arr2[j]);
        }
        
        for(int k = 0; k< arr3.size(); k++)
        {
            if(st2.find(arr3[k]) != st2.end())
                st3.insert(arr3[k]);
        }
        
        for(auto a : st3){
            result.push_back(a);
        }
        
        return result;
    }

//----------------WITHOUT USING EXTRA SPACE(3-pointer approach)------------------------//
vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        int n1 = arr1.size();
        int n2 = arr2.size();
        int n3 = arr3.size();
        vector<int> result;
        
        int i = 0, j= 0, k = 0;
        while(i < n1 && j < n2 && k < n3)
        {
            if(arr1[i] == arr2[j] && arr2[j] == arr3[k])
            {
                result.push_back(arr1[i]);
                i++; j++; k++;
                
                //skipping the duplicates
                while(i< n1 && arr1[i-1] == arr1[i])
                    i++;
                while(j < n2 && arr2[j-1] == arr2[j])
                    j++;
                while(k < n3 && arr3[k-1] == arr3[k])
                    k++;
            }
            
            // If A[i] < B[j], then ith element cannot be common
            else if(arr1[i] < arr2[j])
                i++;
            
            // If B[j] < C[k], then jth element cannot be common
            else if(arr2[j] < arr3[k])
                j++;
            
            //If C[k] is smallest, then kth element cannot be common
            else
                k++;
        }
        return result;
    }