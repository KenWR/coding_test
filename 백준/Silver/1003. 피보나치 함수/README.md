1. [문제](#silver-iii-피보나치-함수---1003)
2. [입 & 출력](#입력)
3. [문제 요약](#문제요약)
4. [풀이](#풀이과정)
    1. [의사코드](#의사코드)
    2. [시간복잡도](#시간-복잡도)
5. [사용 알고리즘](#사용-알고리즘)


# [Silver III] 피보나치 함수 - 1003 

[문제 링크](https://www.acmicpc.net/problem/1003) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2023년 12월 21일 14:48:05

### 문제 설명

<p>다음 소스는 N번째 피보나치 수를 구하는 C++ 함수이다.</p>

<pre>int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n‐1) + fibonacci(n‐2);
    }
}
</pre>

<p><code>fibonacci(3)</code>을 호출하면 다음과 같은 일이 일어난다.</p>

<ul>
	<li><code>fibonacci(3)</code>은 <code>fibonacci(2)</code>와 <code>fibonacci(1)</code> (첫 번째 호출)을 호출한다.</li>
	<li><code>fibonacci(2)</code>는 <code>fibonacci(1)</code> (두 번째 호출)과 <code>fibonacci(0)</code>을 호출한다.</li>
	<li>두 번째 호출한 <code>fibonacci(1)</code>은 1을 출력하고 1을 리턴한다.</li>
	<li><code>fibonacci(0)</code>은 0을 출력하고, 0을 리턴한다.</li>
	<li><code>fibonacci(2)</code>는 <code>fibonacci(1)</code>과 <code>fibonacci(0)</code>의 결과를 얻고, 1을 리턴한다.</li>
	<li>첫 번째 호출한 <code>fibonacci(1)</code>은 1을 출력하고, 1을 리턴한다.</li>
	<li><code>fibonacci(3)</code>은 <code>fibonacci(2)</code>와 <code>fibonacci(1)</code>의 결과를 얻고, 2를 리턴한다.</li>
</ul>

<p>1은 2번 출력되고, 0은 1번 출력된다. N이 주어졌을 때, <code>fibonacci(N)</code>을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 테스트 케이스의 개수 T가 주어진다.</p>

<p>각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. N은 40보다 작거나 같은 자연수 또는 0이다.</p>

### 출력 

 <p>각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.</p>


### 입력 예시
1.
```
3
0
1
3
```
2.
```
2
6
22
```
### 출력 예시
1.
```
1 0
0 1
1 2
```
2.
```
5 8
10946 17711
```
### [문제요약]
피보나치 수열을 재귀로 풀었을 때,   
매개변수의 값이 0 혹은 1이되는 횟수를 구하라.

### [풀이]
다이나믹 프로그래밍의 메모이제이션을 이용하였다.   
메모이제이션이란 단순하게 일정한 반복을 통해 값이 도출될 때,   
그리고 그 값에 특정한 제한이 있을 경우에   
이전 반복들을 미리 저장해 연산속도를 높인 방식이다.   

그렇다면 그 메모이제이션이라는 것을 위의 피보나치에 어떻게 적용하냐면   
문제에 나와있는 피보나치 함수를 보면 (n - 1) 과 (n - 2) 로   
함수가 TREE 구조로 계속 나뉘는 것을 볼 수 있다.   
그리고 그 TREE 구조에서 연산이 먼저 시작되는 부분을   
좌측 노드로 표현하면
ex) 입력값  = 5
```
                    5
            4               3
        3       2       2       1
      2   1   1   0   1   0 
     1 0  
```
이 부분을 조금더 요약하자면
```
                5
            4       3
         3     2
      2    1
    1   0
```
라는 구조가 보인다.
그래도 모르겠다면 해당 구조를 살짝 말로 풀어보겠다.
3은 2의 0, 1의 개수와 1의 0, 1의 개수를 더한것과 같고,   
4는 3과 2의 0, 1의 개수를 더한것과 같으며
그렇게 5의 0, 1의 개수는 4와 3의 0, 1의 개수를 더하면 된다.   
 
그렇기에 우리가 좌측으로부터 1, 2, 3, 4, 5를 연산할때    
각 0, 1의 개수를 메모리에 저장을 해 둔다면   
우리는 다음에 있을 0, 1, 2, 3의 연산을 할 필요없이   
메모리에서 꺼내서 쓸 수 있게된다.   
즉, 단 `한번의 연산이 모든 연산에` 적용이 되는것이다.
또한 함수의 전체적인 연산속도는 늘어날 것이다.    

이렇게 공간비용으로 프로그램의 속도를 높이는 것을
`메모이제이션` 이라고 한다.
그렇다면 위의 피보나치를 어떻게 구현하는지 상상을 해보자   

#### [의사코드]
재귀로 작동을 하므로   
중간에 함수를 (n - 1), (n - 2)로 나뉘게 두고   
마지막에 0과 1의 개수를 저장하는 코드를 쓰면   
계속해서 나누다가 0이나 1을 최소점으로 두며   
각 매개변수의 값을 인덱스로 두어 배열이라는   
메모리 영역에 0, 1의 개수를 저장을 해둔다면   
우리는 그전보다 훨씬 빠른    
피보나치수열 계산법을 가지게 된다. 

1. 기본적으로 저장된 배열에 접근해 값을 출력을 한다.   
    안에 저장된 값이 없다면 해당 값을 매개변수로 함수에 전달한다.    

함수는 다음과 같다.   

1. 0, 1을 만나면 해당 값을 인덱스 값으로 배열에 저장
2. n의 0, 1 개수를 (n - 1) 과 (n - 2)의 개수를 더한 값으로 저장한다.   
    하지만 (n - 1)의 값이나 (n - 2)의 값이 없다면   
    각자 해당 값을 매개변수로 재귀를 호출한다.   
3. 0, 1이 매개변수로 들어오면 연산의 끝이므로 종료한다.   
```c++
0의개수[0] == 1;
1의개수[1] == 1;
if (0의개수[N] == 0 && 1의개수[N] == 0)
	재귀함수(N);
cout << 0의개수[N] << ' '; // 0 개수 출력
cout << 1의개수[N] << '\n'; // 1 개수 출력

void	재귀함수(int n) {
	if (n == 0 || n == 1) {
		return;
	}
	if (0의개수[n - 1] == 0 && 1의개수[n - 1] == 0)
		재귀함수(n - 1);
	if (0의개수[n - 2] == 0 && 1의개수[n - 2] == 0)
		재귀함수(n - 2);
    // 재귀의 끝에서 (n - 1), (n - 2) 존재하면 실행
	0의개수[n] = 0의개수[n - 1] + 0의개수[n - 2];
	1의개수[n] = 1의개수[n - 1] + 1의개수[n - 2];
}
```
#### [시간 복잡도]

Ω(1.6n) 에서 Θ(n) 이 된다.

### [사용 알고리즘]

Dynamic programming