# [Silver I] 신입 사원 - 1946 

<details>
    <summary>문제보기</summary>

[문제 링크](https://www.acmicpc.net/problem/1946) 

### 성능 요약

메모리: 4192 KB, 시간: 536 ms

### 분류

그리디 알고리즘, 정렬

### 제출 일자

2023년 12월 17일 13:52:48

### 문제 설명

<p>언제나 최고만을 지향하는 굴지의 대기업 진영 주식회사가 신규 사원 채용을 실시한다. 인재 선발 시험은 1차 서류심사와 2차 면접시험으로 이루어진다. 최고만을 지향한다는 기업의 이념에 따라 그들은 최고의 인재들만을 사원으로 선발하고 싶어 한다.</p>

<p>그래서 진영 주식회사는, 다른 모든 지원자와 비교했을 때 서류심사 성적과 면접시험 성적 중 적어도 하나가 다른 지원자보다 떨어지지 않는 자만 선발한다는 원칙을 세웠다. 즉, 어떤 지원자 A의 성적이 다른 어떤 지원자 B의 성적에 비해 서류 심사 결과와 면접 성적이 모두 떨어진다면 A는 결코 선발되지 않는다.</p>

<p>이러한 조건을 만족시키면서, 진영 주식회사가 이번 신규 사원 채용에서 선발할 수 있는 신입사원의 최대 인원수를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 20)가 주어진다. 각 테스트 케이스의 첫째 줄에 지원자의 숫자 N(1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개 줄에는 각각의 지원자의 서류심사 성적, 면접 성적의 순위가 공백을 사이에 두고 한 줄에 주어진다. 두 성적 순위는 모두 1위부터 N위까지 동석차 없이 결정된다고 가정한다.</p>

### 출력 

 <p>각 테스트 케이스에 대해서 진영 주식회사가 선발할 수 있는 신입사원의 최대 인원수를 한 줄에 하나씩 출력한다.</p>

### 입력 예시
```
2   
5   
3 2   
1 4   
4 1   
2 3   
5 5   
7   
3 6   
7 3   
4 2   
1 4   
5 7   
2 5   
6 1   
```
### 출력 예시
```
4   
3
```

</details>

### 문제요약

- 서류 / 면접 에서 모두 다른 신입사원보다 뒤떨어지지 않는 신입사원의 최대 인원을 구하는 프로그램을 작성하라

1. 순위에 중복값은 주어지지 않는다.  

### 풀이과정 1

정렬하고 전부 쳐내면 될것 같다.

#### 의사코드
1. 서류심사를 기준으로 정렬을 진행하고   
2. 서류심사 1등인 신입사원의 면접심사 순위보다 떨어지는    
신입사원들은 전부 떨어뜨린다.
3. 그리고 다시 면접심사로 정렬을하고   
4. 면접심사 1등인 신입사원보다 서류심사 순위가 떨어지는   
신입사원들을 전부 떨어뜨리고   
5. 남아있는 신입사원의 수를 세면 정답이 될 것이다. 

이렇게되면 N + log(N) 으로 시간이 충분할 것이다.

```c++
int main() {
    신입사원들을 배열로
    sort(서류심사)
    for (int i = 0; i < N; i++) {
        if (서류심사 첫번째보다 면접 순위가 낮으면) {
            삭제
        }
    }
    sort(면접심사)
    for (int i = 0; i < N; i++) {
        if (면접심사 첫번째보다 서류 순위가 낮으면) {
            삭제
        }
    }
}
```

### 풀이과정 2 (시간 초과)
이론상 완벽했으나 vector에서 삭제하는 과정이   
시간을 엄청 잡아먹는것으로 보였다.   
벡터에서 삭제하면 모든 요소들을 앞당기기 때문에   
이 과정에서 시간복잡도가 치솟았을 것이다.   

새롭게 벡터를 선언해서 추가해주는 방식으로 접근했다.   

### 풀이과정 3 (잘못된 접근)

```
1
5
1 5  
2 3
3 4
4 2
5 1
```

의 입력을 받게되면 잘못 된 값을 받게된다.   
그렇다면 서류 순위로 정렬을 진행하고   
각 면접순위를 계속 비교해가며 아래로 내려보도록 해야겠다. 
```  
서류 면접          서류 면접   
 3    2             1   4   
 1    4             2   3   
 4    1   sort ->   3   2     
 2    3             4   1   
 5    5             5   5   
```
여기서 정렬을 하면 오른쪽 서류가 역순으로 정렬이되어야   
뽑을수 있는 사원임을 알 수 있다.   
그렇다면 이 역순을 벗어나는 신입사원은 기준 미달이라는 뜻이다.   
해당 부분을 이용해 코드를 작성하면 되겠다.   
```   
서류 면접   서류 면접              서류 면접   
 1   `4`     1   4                 1   4   
 2   `3`     2  `3`                2   3   
 3    2      3  `2`  compare...    3   2       
 4    1      4   1                 4  `1` ! 문제발생 !   
 5    5      5   5                 5  `5`   
```

#### 의사코드
1. 서류 순위를 기준으로 정렬
2. 가장 맨 위의 서류 1등의 면접 순위를 기록
    1. 아래의 면접순위보다 기록이 높으면 기록 갱신 및 count++
    2. 아래의 면접순위보다 기록이 낮으면 제외
5. 버블정렬의 형태로 완전 탐색

```c++
sort(신입사원의 서류 순위)
기록 = 신입사원[0].면접
for (int i = 1; i < 사원들 수; i++) {
    // 숫자가 낮아야 순위가 높다는 것
    if (신입사원[i].면접 < 기록)
        기록 갱신, count++
}
```

이렇게되면 O(N) 으로 깔끔해진다. 