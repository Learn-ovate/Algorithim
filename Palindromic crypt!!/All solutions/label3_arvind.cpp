#include<stdio.h>
unsigned long int arr[] = {1,2,3,5,7,11,101,131,151,181,191,313,353,373,383,727,757,787,797,919,929,10301,10501,10601,11311,11411,12421,12721,12821,13331,13831,13931,14341,14741,15451,15551,16061,16361,16561,16661,17471,17971,18181,18481,19391,19891,19991,30103,30203,30403,30703,30803,31013,31513,32323,32423,33533,34543,34843,35053,35153,35353,35753,36263,36563,37273,37573,38083,38183,38783,39293};
int main()
{

	unsigned long int no;
	int i = 0;
	scanf("%ld", &no);
	while(1)
	{
		if(arr[i] >= no)
		{
			printf("%ld\n", arr[i]);
			printf("%ld\n",(arr[i]>>5));
			break;
		}
		i++;
	}

	return 0;
}