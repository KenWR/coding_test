#include <iostream>
#include <string>
#include <queue>
#define MAX 10000
using namespace std; 			//namespace로 std 명령어 안쓰기

//힙구조의 성질을 가진 노드(구조체) 선언
typedef struct
{
	pair<int, int>val_arr[MAX];
	int	size;					//인덱스, 최대값 예외처리 사용
} t_node;

//데이터 삽입
void	insert_heap(t_node *heap, pair<int, int> val)
{
	int	i;
	int	fir_temp;
	int	sec_temp;

	if (heap->size >= (MAX))	//힙 최대사이즈 예외처리
		return ;
	heap->size++;				//삽입시마다 size 추가
	i = heap->size;				//인덱스번호 1부터 시작
								//1부터 시작하는 이유는 바로 아래에 나올 부모노드를 수월하게 찾기 위해 
	heap->val_arr[i] = val;		//인덱스번호에 맞게 삽입
	//최소힙 정렬
	while (i != 1 && (heap->val_arr[i / 2].first > heap->val_arr[i].first))
	{
		//조건은 다음과같다
		//1. 최상위 노드에 도착하기 전까지
		//2. 부모노드가 자식노드보다 더 큰값을 발견할 때까지
		//위의 2번 조건은 한번만 발동하는데 이유는 다음과 같다.
		//애초에 삽입시 정렬이되어 삽입이 되기때문에 추가적인 정렬은 불필요하기 때문이다.
		fir_temp = heap->val_arr[i / 2].first;
		sec_temp = heap->val_arr[i / 2].second;
		heap->val_arr[i / 2].first = heap->val_arr[i].first;
		heap->val_arr[i / 2].second = heap->val_arr[i].second;
		heap->val_arr[i].first = fir_temp;
		heap->val_arr[i].second = sec_temp;
		i = i / 2;					//부모노드를 계속 찾는다.
	}
	//이지
}

int	main(void)
{
	t_node heap;					//힙을 적용할 노드 선언
	heap.size = 0;					//힙의 크기 초기화
	int	n, x, abs;
	pair <int, int> val;

	ios::sync_with_stdio();			//std stream 동기화 비활성화
    cin.tie(NULL);					//cin, cout 묶여서 순차적으로 실행하는 두 명령어를 동시에 실행 

	cin >> n;
	while (n)
	{
		if (x == 0)					//0을 입력 받았을시
		{
			if (heap.size == 0)		//힙에 아무것도 없을때
				cout << 0 << '\0';	//그냥 0 출력
			else
			{
				if (heap.val_arr[1].first == heap.val_arr[2].first)		//만약 최상위 노드 2개의 절대값이 같을때
					if (heap.val_arr[1].second > heap.val_arr[2].second)//본래 값을 비교하여 출력
						cout << heap.val_arr[2].second << '\n';
					else
						cout << heap.val_arr[1].second << '\n';
			}
		}
		cin >> x;					//x값 입력 받기
		abs = x > 0 ? x:-x;			//절대값 구하기
		val.first = abs;
		val.second = x;
		insert_heap(&heap, val);
		n--;
	}
	cin >> n;
}