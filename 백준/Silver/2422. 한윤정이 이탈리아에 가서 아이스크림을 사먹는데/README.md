# [Silver IV] 한윤정이 이탈리아에 가서 아이스크림을 사먹는데 - 2422 
<details>
    <summary>문제보기</summary>
[문제 링크](https://www.acmicpc.net/problem/2422) 

### 성능 요약

메모리: 2060 KB, 시간: 24 ms

### 분류

브루트포스 알고리즘

### 제출 일자

2023년 12월 7일 12:23:09

### 문제 설명

<p>한윤정과 친구들은 이탈리아로 방학 여행을 갔다. 이탈리아는 덥다. 윤정이와 친구들은 아이스크림을 사먹기로 했다. 아이스크림 가게에는 N종류의 아이스크림이 있다. 모든 아이스크림은 1부터 N까지 번호가 매겨져있다. 어떤 종류의 아이스크림을 함께먹으면, 맛이 아주 형편없어진다. 따라서 윤정이는 이러한 경우를 피하면서 아이스크림을 3가지 선택하려고 한다. 이때, 선택하는 방법이 몇 가지인지 구하려고 한다.</p>

### 입력 

 <p>첫째 줄에 정수 N과 M이 주어진다. N은 아이스크림 종류의 수이고, M은 섞어먹으면 안 되는 조합의 개수이다. 아래 M개의 줄에는 섞어먹으면 안 되는 조합의 번호가 주어진다. 같은 조합은 두 번 이상 나오지 않는다. (1 ≤ N ≤ 200, 0 ≤ M ≤ 10,000)</p>

### 출력 

 <p>첫째 줄에, 가능한 방법이 총 몇 개 있는지 출력한다.</p>

</details>

### 문제풀이 1

조합을 구하는 공식은 다음과 같다.   

5개에서 3개의 조합식을 구한다고 가정해보자.   

1. 중복 포함
    (5 + 3 -1)! / 3!(5 - 1)! = 35   

2. 중복 제거
    5! / 3! / (5 - 3)! = 10   

이 문제에서는 중복을 제거한 값을 출력해야하고,   
입력으로 받은 맛없는 조합과 일치하는 조합은 제외하여   
남은 맛있는 조합의 개수를 출력하는 문제다.   

그렇기에 처음에는 해당 공식에   

((N! / 3!) - (맛없는 조합)) / 3! 으로 하려고 하였으나   
최대 입력값인 200이 들어와버리면 오버플로우가 일어나 버려서   
해당 부분을 계산할 수 있는 계산기를 만드는 것 보다는   
다른 방법이 더 낫다는 생각에 빠르게 포기를 했다.   


### 문제풀이 2

브루트 포스 문제의 취지에 맞게 결국 전부 탐색을 진행하여   
같은 숫자가 들어있는 것을 제외한 조합에 중복이 일어나는 부분을    
계산하기 전에 미리 입력받은 맛없는 조합들을 배열에 저장해두고   
각 조합마다 해당 배열을 전부 비교해가며    
맛있는 조합인지 여부를 판단하여 count를 증가시키는 방식을 선택했다.   
그리고 마지막으로 조합의 중복을 제거하기 위해   
3개의 숫자가 가질 수 있는 최대 조합인 3! 를 나누어서 출력한다.   

```c++

for (i = 1 ~ 9 까지) {
    for (j = 1 ~ 9 까지) {
        for (k = 1 ~ 9 까지) {
            if (i, j, k 중복된 숫자가 있으면)
                continue;
            else if (맛없는 조합에 들어가있으면)
                continue;
            else 맛있는 조합이므로
                count++
        }
    }
}

std::cout << count / 3!;

```
