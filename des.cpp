#include<iostream>
#include<string>
#include<bitset>
#include<iomanip>
#include<sstream>
#include<stdlib.h>
using namespace std;

void GHFB(int ke[]){
    string bin="";
    for(int i = 0; i < 48; i++)
    {
        /* code */
        bin += to_string(ke[i]);
    }
    
    int result =0 ;

    for(size_t count = 0; count < bin.length() ; ++count)
    {
        result *=2;
        result += bin[count]=='1'? 1 :0;
    }  

    stringstream ss;
    ss << hex << setw(8) << setfill('0')  << result;

    string hexVal(ss.str());
    cout<< hexVal<<endl;
}


int* GBFH(string sHex)
{
    string sReturn = "";
    static int fullkey[64];
    for (int i = 0; i < sHex.length (); ++i)
    {
        switch (sHex [i])
        {
            case '0': sReturn.append ("0000"); break;
            case '1': sReturn.append ("0001"); break;
            case '2': sReturn.append ("0010"); break;
            case '3': sReturn.append ("0011"); break;
            case '4': sReturn.append ("0100"); break;
            case '5': sReturn.append ("0101"); break;
            case '6': sReturn.append ("0110"); break;
            case '7': sReturn.append ("0111"); break;
            case '8': sReturn.append ("1000"); break;
            case '9': sReturn.append ("1001"); break;
            case 'A': sReturn.append ("1010"); break;
            case 'B': sReturn.append ("1011"); break;
            case 'C': sReturn.append ("1100"); break;
            case 'D': sReturn.append ("1101"); break;
            case 'E': sReturn.append ("1110"); break;
            case 'F': sReturn.append ("1111"); break;
        }
    }
    for(int i = 0; i < 64; i++)
    {
        fullkey[i] = sReturn[i]-'0';
        //cout<<fullkey[i];
    }
    return fullkey;


}


int* shiftleft(int* arr,int round){
    static int temp[28];
    int first;
    if(round==1||round==2||round==9||round==16){
        first=*(arr+0);
        for(int i = 0; i < 27; i++)
        {
            temp[i]=*(arr+i+1);
        }
        temp[27]=first;
    }
    else{
        first=*(arr+0);
        for(int i = 0; i < 27; i++)
        {
            temp[i]=*(arr+i+1);
        }
        temp[27]=first;
        first=temp[0];
        for(int i = 0; i < 27; i++)
        {
            temp[i]=temp[i+1];
        }
        temp[27]=first;
    }
    return temp;
}

int main(){
    int map1[56]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
    int map[48]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};

    string keystr = "A845BFF187651234";
   
    int newkey[56],index;
    int* left=new int;
    int* right=new int;
    int* key = GBFH(keystr);
    for(int i = 0; i < 64; i++)
    {
        cout<< *(key+i);
    }
    
    for(int i = 0; i < 56; i++)
    {
        /* code */
        index = map1[i]-1;
        newkey[i]=*(key+index);
    }

    for(int i = 0; i < 28; i++)
    {
        *(left+i)=newkey[i];
        *(right+i)=newkey[i+28];
    }
    

    for(int i = 1; i < 17; i++)
    {
        left = shiftleft(left,i);
        right = shiftleft(right,i);
        int tempkey[56];
        for(int j = 0; j < 28; j++)
        {
            /* code */
            tempkey[j]=left[j];
            tempkey[j+28]=right[j];
        }
        int pkey[48];
        int temp;
        
        for(int j = 0; j < 48; j++)
        {
            /* code */
            temp = map[j]-1;
            pkey[j]=tempkey[temp];
        }
        cout<<setw(2)<<i<<" round key: ";
        GHFB(pkey);
        

    }
    
    

}