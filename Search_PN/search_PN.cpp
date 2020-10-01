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

/*data[]에서 앞에서부터 n개의 숫자 중 r개를 선택해서 순열을 출력하는 함수. q는 출력 시 출력 갯수 지정*/
	void Perm(int iSize_str, int r, int q,int &answer, int data[],int T[]) {
		if (r == 0) {
			process(q, answer, T);
			return;
		}
		for (int i = iSize_str - 1; i >= 0; i--) {
			swap(&data[i], &data[iSize_str - 1]); //n-1을 모든 index와 swap해서 다양한 순서를 만든다.
			T[r - 1] = data[iSize_str - 1];		  //T의 뒤에서부터 결과값 저장	
			Perm(iSize_str - 1, r - 1, q, answer, data, T);		  //다음  index로 진행 	
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
	int iSize_str = numbers.length();	//몇자리 숫자인지 확인

	// 문자열을 정수로 변환하여 iNum에 할당
	iNum = atoi(numbers.c_str());	
	
	//정수로 저장한 iNum을 자리수 별로 자름
	for (int i = 1; iSize_str >= i; i++) {
		aNum[i - 1] = iNum / pow(10, iSize_str - i);
		iNum -= aNum[i - 1] * pow(10, iSize_str - i);
	}
	
	for (int i = 0; i < iSize_str; i++) {
		data[i] = aNum[i];
	}

	//쪼갠 숫자로 만들수 있는 경우의 수 생성
	for (int i = 1; i <= iSize_str; i++) {
		Perm(iSize_str, i, i, answer, data, T);
	}


	return answer;
}

int main() {
	string Input;

	cout << "숫자를 입력해주세요: ";

	cin >> Input;

	cout << Input<<"의 PN은 "<<solution(Input) <<"입니다." << endl;
}