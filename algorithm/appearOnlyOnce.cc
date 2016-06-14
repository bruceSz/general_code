/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file appearOnlyOnce.cc
 * @author brucesz(zhangsong5@jd.com)
 * @date 2016/06/14 23:06:54
 * @version $Revision$ 
 * @brief 
 *  
 **/

/* vim: set ts=4 sw=4 sts=4 tw=100 */
class Solution {
    public:
        void FindNumsAppearOnce(vector<int>data,int *num1,int *num2){
            int length = data.size();
            if(length < 2){
                *num1 = 0;
                *num2 = 0;
                return ;
            }
            int tmp = 0;
            for (int i =0 ; i< length; i++){
                tmp ^= data[i];
            }
            int index = FindFirstBit1(tmp);
            *num1 = *num2 = 0;
            for(int i = 0; i<length; i++){
                if (IsBit1(data[i], inex))
                    *num1 ^= data[i];
                else
                    *num2 ^= data[i];
            }
        }
    private:
        int FindFirstBit1(int num){
            index = 0;
            while ((num&1)==0 && index < 32)
            {
                index ++;
                num = num >> 1;
            }
            return index;
        }
        bool IsBit1(int num, int index) {
            if ((num >> index) & 1) 
                return true;
            else
                return false;
        }
}
int main(){
    return 1;
}
