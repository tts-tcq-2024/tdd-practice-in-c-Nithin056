char ListSep[4] = {',','\n',',',NULL};

int outIntArr[1000] ={0};
int NumListSize[100] = {0};
int readArrStart =0;
int TotalNum =0;
int lastidex =0;

const int TensArr[4]={1,10,100,1000};

int CharToInt(const char CutChar)
{
   int value = 0xff;
   value = (CutChar - '0');
   if((value >= 0) && (value <= 9))
   {
    return value;
   }
   else
   {
    return 0xff;
   }
}

int isCharNumNotvalid(int IsInvalidVal)
{
   if(IsInvalidVal == 0xff)
   {
      return 0;
   }
   else
   {
      return IsInvalidVal;
   }
}

int IslengthLessThanOne(const char *inStr,int StrLen,int *OutVal)
{
  if(StrLen <= 1)
  {
    // *OutVal = CharToInt(*inStr);
     *OutVal = isCharNumNotvalid(CharToInt(*inStr));
      return 1;
  }
  else 
  {
    return 0;
  }
}
void CheckIdexthree(const char *inStr)
{
   if(inStr[3] == '\n')
   {
      ListSep[2] = inStr[2];
      readArrStart = 4;
   }
}
void IsUserdefineSeperatorAvl(const char *inStr)
{
   if((inStr[0] == '/')&&(inStr[1] == '/'))
   {
      CheckIdexthree(inStr);
   }
}

void CopylocArrToGArr(int*LArr ,int *numDigit)
{
    int i=0;
    static int lastid =0;
   for( i = 0;i<*numDigit;i++)
   {
      outIntArr[lastid+i] = LArr[i];
   }
   NumListSize[TotalNum] = *numDigit;
   lastid += *numDigit;
   TotalNum++;
   *numDigit = 0;
}

int IsourSep(char Sep)
{

   for(int i =0;i<4;i++)
      {
         if(ListSep[i] == Sep)
         {
            return 1;
         }    
      }
return 0;
}
void localToGarr(char cntchar, int *j,int *loclArr)
{
   if((*j <= 4)&&(IsourSep(cntchar)))
   {
      CopylocArrToGArr(loclArr,j);
   }
}

void StoreTolocArr(char cntChar)
{
   int localNum = 0xff;
   static int loclArr[10]={0},j=0;
   
      localNum = CharToInt(cntChar);
      
      if((0xff != localNum)&&(j<4))
      {
          
         loclArr[j] = localNum;
         //printf("yasi the vlaue j is %d and loc %d\n",j,loclArr[j]);
         j++;
      }
      else
      {
        localToGarr(cntChar,&j,loclArr);
      }
}

void ReadCharArrToint(const char *inStr)
{
   int i=0,len =0;
   inStr = inStr+readArrStart;
   len = strlen(inStr);
   for(;i<=(len+1);i++)
   {
      
      StoreTolocArr(inStr[i]);
   }
   
}
int ArrToNum(int cnt)
{
   
   int sum =0,loc =0;
   for(int i=0;i< cnt;i++)
   {
    loc = (outIntArr[lastidex + i] * TensArr[(cnt-(i+1))]);
    sum +=loc;
   }
   lastidex += cnt;
 
   if(sum>1000)
   {
       return 0;
   }
   else
   {
       return sum;
   }
}

int addFromGarr(void)
{
int outSum =0;
for(int curntNum =0;curntNum <= TotalNum;curntNum++)
{
   outSum += ArrToNum(NumListSize[curntNum]);
}

   return outSum;
}

int AdditionMain(const char *inStr)
{
   IsUserdefineSeperatorAvl(inStr);
   ReadCharArrToint(inStr);
   return addFromGarr();
}

int NoNumCharInStr(const char * input)
{
   for(int i=0;input[i] != NULL ;i++)
   {
      if(0xff != CharToInt(input[i]))
      {
         return 0;
      }
   }
   return 1;
}
int add(const char *input)
{
  int Str_len = 0;
  int returnval = 0;
  Str_len = strlen(input);
  if(IslengthLessThanOne(input,Str_len,&returnval) || NoNumCharInStr(input))
  {
   return (returnval);
  }
  else
  {
    return AdditionMain(input);
  }
}
