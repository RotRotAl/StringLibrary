#include"stringLibary.h"

int GetStringLength(string str)
{
	//stores the result
	int counter;
	//init var
	counter = 0;
	//if str[counter]!="\0" the loop wil keep on going
	while (str[counter++]);
	return counter - 1;
}


BOOL IsCharPartOfString(string str, char c)
{
	//the IndexOf Func retrun the place of the char in the string if its not part of it its retruns -1
	// so if its retrun -1 i know that it isnt part of the string 
	return (IndexOf(str, c) != -1) ? true : false;
}

int IndexOf(string str, char c)
{
	//will store the result
	int position;
	//initing the val to zero in order to check from the first offset
	position = 0;
	//Check if not EOD and if str[counter] is diffrent then the given char , the result position will get the place after the char
	while (str[position] && str[position++] != c);
	//retruns the position of the char was found, otherwise retruns -1
	return (str[(position)-1] == c) ? position - 1 : -1;
}

unsigned short CountCharInString(string str, char c)
{
	//stores the amount of times that the chars iss in string (result)
	unsigned short counter;
	//strores the place that we are checking in the string
	unsigned short offset;
	//init counter into becuse we dont if the char is part of string yet
	counter = 0;
	//init offset into zero becuse we need to check from the first offset
	offset = 0;
	//if the str[offset]!=\0 (EOD) the loop will go on
	while (str[offset])
	{
		//counter += 1 if current char is the given char else counter +=\0(0)
		counter += (str[offset] == c);
		offset++;
	}
	return counter;
}

BOOL IsEqual(string str1, string str2)
{
	//store the current offset that we are checking
	int counter;
	//init the current digit to check to zero in order 
	counter = 0;
	//compare the current char
	while (str1[counter] == str2[counter] && str2[counter++]);
	//checks that both string reached EOD
	return (str1[(counter)-1] == str2[(counter)-1]);
}

void Copy(string str, string copy)
{
	//tore the offset of current char that we are working on
	int offset;
	//init the offset to zero in order to start from the first cell
	offset = 0;
	//while string as datat, equal to while str[offset] != EOD("\0")
	while (str[offset])
	{
		//assigning the val from str to the copy
		copy[offset] = str[offset];
		//moving the offset to the next cell
		offset++;
	}
	//adding EOD at the cell after the last one in order to symbolise EOD
	copy[offset] = "\0";
}

string concatStrings(string str1, string str2)
{
	string res = (string)malloc(sizeof(char)* STRINGSIZE);
	//store the length of the first string
	int str1Len;
	//init with the length of the first string
	str1Len = GetStringLength(str1);
	//puts str1 inside res
	Copy(str1, res);
	//puts str2 after str1
	Copy(str2, res + str1Len);
}

BOOL IsSubstring(string a, string b)
{
	//store the length of a
	int aLen;
	//store the offset in b
	int counter;
	//store the offset of a
	int innerCounter;
	//store res
	BOOL res;
	//init the length var
	aLen = GetStringLength(a);
	//at the begining we dont know if its true
	res = false;
	//init offset
	counter = 0;
	// while not EOD
	while (b[counter])
	{
		//count how many comman are betwenn b in current offset to a
		for (innerCounter = 0; a[innerCounter] == b[counter + innerCounter] &&
			innerCounter < aLen; innerCounter++);
		//if all the chars are common the strings are equal at that offset
		res = ((innerCounter) == aLen) ? true : res;
		//adding one to the offset
		counter++;
	}

	return res;
}

void Replace(string a, string b, string c)
{
	int counter;
	int seccounter;
	short aLen;
	short bLen;
	int SuBStringPos;
	string res;
	string temp;
	aLen = GetStringLength(a);
	bLen = GetStringLength(b);
	SuBStringPos = PlaceOfAInB(a, b);

	for (counter = 0; counter < SuBStringPos; counter++)
	{
		res[counter] = b[counter];
	}
	for (seccounter = 0; c[seccounter]; seccounter++)
	{
		res[counter++] = c[seccounter];
	}
	seccounter = counter;
	for (counter = SuBStringPos + aLen; counter < bLen; counter++)
	{
		res[seccounter++] = b[counter];
	}

	CopyString(res, b);
}

string StringParseOfInt(int in)
{
	string out = (string)malloc(sizeof(char) * STRINGSIZE);
	int counter;
	counter = 0;
	while (in)
	{
		out[counter++] = (in % 10) + '0';
		in /= 10;

	}
	return out;
}

int IndexInArr(string val, string arr[], int len)
{
	int counter;
	BOOL flag = false;
	for (counter = 0; counter < len & !flag; counter++)
	{
		flag = IsEqual(val, arr[counter]);
	}
	return (flag) ? counter : -1;
}
