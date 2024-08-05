/* G1_4:
	��������

	�Ӹ�������(���鳤��С��256)���������ݷ���������������ݣ�

	1. ȥ�����������ֵ����Сֵ����������������������ֵ����Сֵ��ƽ��ֵ
		"After del max & min, the max is XXX, the min is YYY, the average is ZZZ"

		���� XXX,YYY Ϊ������ZZZΪ����(��������)
		�������Ϊ ""�����ݣ�������ȫһ����ע��ȫ�ǰ�ǿո�

	2. �����������������������������
		"Sort by asc: XX YY ZZ ..."
		���� XX YY ZZ Ϊ���������
		�������Ϊ ""�����ݣ�������ȫһ����ע��ȫ�ǰ�ǿո�

	3. ������������򣬽���������������
		"Sort by desc: XX YY ZZ ..."
		���� XX YY ZZ Ϊ���������
		�������Ϊ ""�����ݣ�������ȫһ����ע��ȫ�ǰ�ǿո�

	4. ����ȫ�����ݵ�ƽ��ֵ�������ƽ��ֵ��ӽ�������������(ԭ����)���ڵڼ�λ�����������
		"the closer num is XX"
		"the closer num is XX & YY"
		���� XX YY Ϊ����
		�������Ϊ ""�����ݣ�������ȫһ����ע��ȫ�ǰ�ǿո�

	���Ҫ��:
	������������(ʹ��atoi(argv[1])��ȡstep��atoi(argv[2] ��ȡ���鳤��)��argv[3]��ȡ���飬������

	�������� int arr1[10] = {0,2,2,3,3,6,7,8,9,10};    int arr2[10] = {0,1,2,3,4,6,7,8,9,10};

	ִ�б���  gcc G1_4.c -o G1_4
	ִ�в���  .\G1_4.exe 1 10 "0,2,2,3,3,6,7,8,9,10"     �۲���
			  .\G1_4.exe 2 10 "0,2,2,3,3,6,7,8,9,10"     �۲���
			  .\G1_4.exe 3 10 "0,2,2,3,3,6,7,8,9,10"     �۲���
			  .\G1_4.exe 4 10 "0,2,2,3,3,6,7,8,9,10"     �۲���
	ִ�в���  .\G1_4.exe 1 10 "0,1,2,3,4,6,7,8,9,10"     �۲���
			  .\G1_4.exe 2 10 "0,1,2,3,4,6,7,8,9,10"     �۲���
			  .\G1_4.exe 3 10 "0,1,2,3,4,6,7,8,9,10"     �۲���
			  .\G1_4.exe 4 10 "0,1,2,3,4,6,7,8,9,10"     �۲���
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN (256)

void quickSort(int arr[], int left, int right);

void string_to_array(char* str, int* arr, int size)
{
	int inedx = 0;
	for (inedx = 0; inedx < size; inedx++) {
		arr[inedx] = atoi(&str[inedx * 2]);
	}
}

void main()
{


	int step = 4;
	int lenth = 10;
	//int arr[10] = { 0,1,2,3,4,6,7,8,9,10 };
	int arr[10] = { 0,2,2,3,3,6,7,8,9,10 };
	int average = 0, sum = 0;
	int local = 1, closer = 0;
	//string_to_array(argv[3], arr, lenth);

	//printf("stet is %d\n",step);
	//printf("lenth is %d\n",lenth);
	//for(int index=0;index<lenth;index++)
	//{
	//	printf("arr[%d] is %d\n",index,arr[index]);
	//}

	// add code here
	quickSort(arr, 0, lenth - 1);

	if (step == 1) {
		for (int i = 1; i < lenth - 1; i++) {
			sum += arr[i];
		}
		printf("After del max & min, the max is %d, the min is %d, the average is %d\n", arr[lenth - 2], arr[1], sum / (lenth - 2));
	}
	else if (step == 2) {
		printf("Sort by asc: ");

		for (int i = 0; i < lenth; i++) {
			printf(" %d  ", arr[i]);
		}
		printf("\n");
	}
	else if (step == 3) {
		printf("Sort by desc: ");

		for (int i = lenth - 1; i >= 0; i--) {
			printf(" %d  ", arr[i]);
		}
		printf("\n");
	}
	else {
		//string_to_array(argv[3], arr, lenth);

		for (int i = 0; i < lenth; i++) {
			sum += arr[i];
		}
		average = sum / lenth;
		closer = fabs((double)average - (double)arr[0]);

		for (int i = 1; i < lenth; i++) {
			if (closer > fabs((double)average - (double)arr[i])) {
				closer = fabs((double)average - (double)arr[i]);
				local = i + 1;
			}
		}
		printf("the average = %d, closer = %d\n", average, closer);
		printf("the closer num is %d\n", arr[local]);
		printf("the closer num is %d & %d\n", arr[local], local);
	}

	// add code here	
	return;
}

void quickSort(int arr[], int left, int right) {
	int middle = arr[(left + right) / 2];
	int i = left, j = right, temp;

	if (i >= j)
		return;

	while (i <= j) {
		while (arr[i] < middle)
			i++;

		while (arr[j] > middle)
			j--;

		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}

	if (left < j)
		quickSort(arr, left, j);

	if (i < right)
		quickSort(arr, i, right);
}