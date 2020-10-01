#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

bool isPrime(int number) {
	bool isPrime = true;

	if (number == 1)
		return false;
	else if (number == 2)
		return true;
	else if (number % 2 == 0)
		return false;

	for (int i = 2; i <= sqrt(number); i++){
		if (number% i == 0)
			return false;
	}
	return isPrime;
}

void swap(int *i, int *j) {
	int temp = *i;
	*i = *j;
	*j = temp;
}

void process(int q,int &answer,int T[]) {
	string combi_str;
	string stri[10];
	int iNum = 0;
	bool compare = true;

	for (int i = q - 1; i >= 0; i--) 
		stri[i] = to_string(T[i]);

	for (int i = q - 1; i >= 0; i--)
		combi_str += stri[i];

	iNum = stoi(combi_str);

	if (isPrime(iNum)) {
		answer++;
	}
	
}

/*data[]���� �տ������� n���� ���� �� r���� �����ؼ� ������ ����ϴ� �Լ�. q�� ��� �� ��� ���� ����*/
	void Perm(int iSize_str, int r, int q,int &answer, int data[],int T[]) {
		if (r == 0) {
			process(q, answer, T);
			return;
		}
		for (int i = iSize_str - 1; i >= 0; i--) {
			swap(&data[i], &data[iSize_str - 1]); //n-1�� ��� index�� swap�ؼ� �پ��� ������ �����.
			T[r - 1] = data[iSize_str - 1];		  //T�� �ڿ������� ����� ����	
			Perm(iSize_str - 1, r - 1, q, answer, data, T);		  //����  index�� ���� 	
			swap(&data[i], &data[iSize_str - 1]);

			
		}
	}


int solution(string numbers) {
	int answer = 0;
	int iNum = 0;
	int data[10];
	int check_overlap[5000];
	int aNum[7];
	int T[10];
	int iSize_str = numbers.length();	//���ڸ� �������� Ȯ��

	// ���ڿ��� ������ ��ȯ�Ͽ� iNum�� �Ҵ�
	iNum = atoi(numbers.c_str());	
	
	//������ ������ iNum�� �ڸ��� ���� �ڸ�
	for (int i = 1; iSize_str >= i; i++) {
		aNum[i - 1] = iNum / pow(10, iSize_str - i);
		iNum -= aNum[i - 1] * pow(10, iSize_str - i);
	}
	
	for (int i = 0; i < iSize_str; i++) {
		data[i] = aNum[i];
	}

	//�ɰ� ���ڷ� ����� �ִ� ����� �� ����
	for (int i = 1; i <= iSize_str; i++) {
		Perm(iSize_str, i, i, answer, data, T);
	}


	return answer;
}

int main() {
	string Input;

	cout << "���ڸ� �Է����ּ���: ";

	cin >> Input;

	cout << Input<<"�� PN�� "<<solution(Input) <<"�Դϴ�." << endl;
}