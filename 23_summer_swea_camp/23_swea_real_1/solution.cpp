/*
No. 1 [Pro] 가게관리
참여자 11 제출 15 배점 100
Problem제출이력정답
시간 : 25개 테스트케이스를 합쳐서 C/C++의 경우 3초 / Java의 경우 3초
메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
[제한 사항]

 

시간

 25개 테스트케이스를 합쳐서 C++ 의 경우 3초 / Java 의 경우 3초
메모리

 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내
 

※ 본 문제는 임직원의 S/W 문제해결 역량 향상을 위한 Professional 실전형 연습문제이며

함께 제공되는 Testcase 또한 학습을 위한 연습용입니다.

 

  ①   C 또는 C++로 답안을 작성하시는 응시자께서는 검정시스템에 제출 시, Language 에서 C++ 를 선택하신 후 제출하시기 바랍니다.

  ②   Main 과 User Code 부분으로 구성되어 있습니다.

  ㅇ   A.  Main         : 수정할 수 없는 코드이며, 채점 시 비 정상적인 답안 검출 등 평가를 위한 로직이 추가 될 수 있습니다.

  ㅇ   B.  User Code  : 실제 응시자가 작성해야 하는 코드이며, 제출 시에는 표준 입출력 함수가 포함되어 있으면 안 됩니다.

  ③   Local PC 에서 프로그래밍 시 유의 사항

  ㅇ   A.  2개의 파일을 생성하셔야 합니다. ( main.cpp / solution.cpp 또는 Solution.java / UserSolution.java )

  ㅇ   B.  Main 부분의 코드를 main.cpp 또는 Solution.java 에 복사해서 사용하시기 바랍니다.

  ㅇ   C.  sample_input.txt 를 사용하시기 위해서는 Main 부분의 코드 내에

  ㅇ   C.  표준 입력을 파일로 전환하는 코드 ( 주석처리 되어 있음 ) 의 주석을 풀어서 사용하시면 됩니다.

  ㅇ   D.  User Code 부분의 코드를 작성하신 후 서버에 제출하실 때,

  ㅇ   D.  디버깅을 위한 표준 입출력 함수를 모두 삭제 또는 주석 처리해 주셔야 합니다.

  ④   문제 내에 제약조건을 모두 명시하지 않으므로 주어지는 코드를 분석하셔야 합니다.

  ⑤   코드는 개발 언어에 따라 상이할 수 있으므로, 작성할 언어를 기준으로 분석하셔야 합니다.

 

[문제 설명]

가게 관리 시스템이 있다. 가게는 상품을 구매해서 판매한다.

상품을 구매할 때는 구매 ID와 함께 상품 번호, 구매 가격, 수량이 주어진다. 상품 번호는 상품을 구별하는 값으로 동일한 상품 번호로 여러 번 구매가 가능하다.

구매를 취소할 때는, 구매 ID만 주어진다. 구매 ID에 해당하는 상품 수량이 모두 남아 있을 경우에만, 취소가 가능하다.

상품을 판매할 때는 판매 ID와 함께 상품 번호, 판매 가격, 수량이 주어진다. 가장 싸게 구매한 상품부터 판매한다. 가격이 동일한 경우에는 구매 ID 값이 작은 상품부터 판매한다.

판매한 상품을 환불해 줄 때는, 판매 ID만 주어진다. 판매 ID로 판매되었던 모든 상품이 다시 재고가 된다.
 

위와 같이 동작하는 가게 관리 시스템을 구현하여 보자.

아래 API 설명을 참조하여 각 함수를 구현하라.

※ 아래 함수 signature는 C/C++에 대한 것으로 다른 언어에 대해서는 제공되는 Main과 User Code를 참고하라.

아래는 User Code 부분에 작성해야 하는 API 의 설명이다.

 

void init()

각 테스트 케이스의 처음에 호출된다.

재고가 없는 상태가 된다.

int buy(int bId, int mProduct, int mPrice, int mQuantity)

mProduct 상품을 mPrice 가격으로 mQuantity 개 구매한다. 구매 ID는 bId이다.

구매 후에, 가게가 보유 중인 mProduct 상품의 총 개수를 반환한다.

 

Parameters

bId: 구매 ID ( 1 ≤ bId ≤ 1,000,000,000 )

mProduct: 상품 번호 ( 1 ≤ mProduct ≤ 1,000,000,000 )

mPrice: 구매 가격 ( 1,000 ≤ mPrice ≤ 300,000 )

mQuantity: 구매 수량 ( 10 ≤ mQuantity ≤ 100 )

 

Returns

mProduct 상품의 재고 수량을 반환한다.

int cancel(int bId)

구매 ID가 bId인 구매를 취소한다.

bId로 구매했던 상품 수량이 모두 가게에 남아 있을 경우에만, 취소가 가능하다. 한 개라도 부족하다면 취소에 실패하고 -1을 반환한다.

bId로 구매한 상품이 판매 된 적이 있더라도, 환불을 통해 다시 모두 재고가 되었다면 취소가 가능함을 유의하라.

bId로 구매한 내역이 없거나, 이미 취소한 구매 ID라면, 취소에 실패하고 -1을 반환한다.

 

취소가 가능하다면, 재고에서 bId로 구매했던 상품을 삭제하고, 가게에 남아 있는 동일 상품의 개수를 반환한다.

 

Parameters

bId: 구매 ID ( 1 ≤ bId ≤ 1,000,000,000 )

 

Returns

취소에 실패할 경우, -1을 반환한다.

취소에 성공할 경우, 취소된 상품과 동일한 상품이 가게에 얼마나 남아있는지 그 개수를 반환한다.

int sell(int sId, int mProduct, int mPrice, int mQuantity)

mProduct 상품을 mPrice 가격으로 mQuantity 개 판매한다. 판매 ID는 sId이다.

판매 ID와 구매 ID는 서로 독립적인 ID이기 때문에, 판매 ID 값과 구매 ID 값이 서로 동일한 경우도 있다.

mProduct 상품의 재고 수량이 mQuantity 보다 작다면, 판매에 실패하고 -1을 반환한다.

 

판매가 가능하다면, 가장 싸게 구매한 상품부터 판매한다.

가격이 동일한 경우에는 구매 ID 값이 작은 상품부터 판매한다.

판매 후에, 총 판매 수익을 반환한다. 개당 판매 수익은 판매 가격에서 구매 가격을 뺀 값이다.

 

Parameters

sId: 판매 ID ( 1 ≤ sId ≤ 1,000,000,000 )

mProduct: 상품 번호 ( 1 ≤ mProduct ≤ 1,000,000,000 )

mPrice: 판매 가격 ( 2,000 ≤ mPrice ≤ 300,000 )

mQuantity: 판매 수량 ( 1 ≤ mQuantity ≤ 500 )

 

Returns

판매에 실패할 경우, -1을 반환한다.

판매에 성공할 경우, sId 판매로 발생한 총 수익을 반환한다.

int refund(int sId)

sId로 판매한 상품에 대해 환불해 준다.

환불해 준 상품의 총 개수를 반환한다.

환불해 준 상품은 모두 재고로 쌓인다.

 

sId로 판매한 내역이 없거나, 이미 환불해준 판매 ID라면, 환불에 실패하고 -1을 반환한다.

 

Parameters

sId: 판매 ID ( 1 ≤ sId ≤ 1,000,000,000 )

 

Returns

환불에 실패할 경우, -1을 반환한다.

환불에 성공할 경우, 환불해 준 상품의 총 개수를 반환한다.

 

[예제]

아래의 [Table 1]과 같이 요청이 되는 경우를 살펴보자.

 

Order

Function

return

Figure

1

init()

 

 

2

buy(100, 100, 2000, 30)

30

 

3

buy(500, 100, 2500, 50)

80

 

4

buy(200, 300, 1900, 60)

60

 

5

buy(400, 100, 2000, 40)

120

 

6

buy(700, 100, 1800, 20)

140

 

7

buy(600, 100, 1900, 10)

150

Fig. 1

8

sell(200, 100, 3000, 10)

12000

Fig. 2

9

cancel(700)

-1

 

10

cancel(600)

130

Fig. 3

11

sell(500, 300, 2000, 100)

-1

 

12

sell(400, 300, 2000, 30)

3000

Fig. 4

13

sell(100, 100, 3500, 50)

77000

Fig. 5

14

refund(200)

10

Fig. 6

15

sell(300, 100, 2500, 20)

12000

Fig. 7

16

refund(100)

50

Fig. 8

17

cancel(400)

-1

 

18

refund(300)

20

Fig. 9

19

cancel(400)

100

Fig. 10

                                                                [Table 1]

(순서 1) 초기에는 재고가 없다.

 

(순서 2) 100 상품을 개당 가격 2,000으로 30개 구매한다. 구매 ID는 100이다. 100 상품의 재고 수량으로 30을 반환한다.

 

(순서 3) 100 상품을 개당 가격 2,500으로 50개 구매한다. 구매 ID는 500이다. 이전 재고 수량 30에 50개가 추가되므로, 100 상품의 재고 수량으로 80을 반환한다.

 

(순서 4) 300 상품을 개당 가격 1,900으로 60개 구매한다. 구매 ID는 200이다. 300 상품의 재고 수량으로 60을 반환한다.

 

(순서 5) 100 상품을 개당 가격 2,000으로 40개 구매한다. 구매 ID는 400이다. 이전 재고 수량 80에 40개가 추가되므로, 100 상품의 재고 수량으로 120을 반환한다.

 

(순서 6) 100 상품을 개당 가격 1,800으로 20개 구매한다. 구매 ID는 700이다. 이전 재고 수량 120에 20개가 추가되므로, 100 상품의 재고 수량으로 140을 반환한다.

 

(순서 7) 100 상품을 개당 가격 1,900으로 10개 구매한다. 구매 ID는 600이다. 이전 재고 수량 140에 10개가 추가되므로, 100 상품의 재고 수량으로 150을 반환한다. [Fig. 1]은 함수 호출의 결과를 나타낸 그림이다.
 



                                    [Fig. 1]

 

 

(순서 8) 100 상품을 개당 가격 3,000으로 10개 판매한다. 판매 ID는 200이다. 가장 싸게 구매한 100 상품은 700 구매 ID로 구매한 상품으로 20개가 있다. 판매 가격(3,000)에서 구매 가격(1,800)을 빼면 개당 판매 수익은 1,200이다. 10개를 판매하기 때문에, 총 판매 수익으로 12,000을 반환한다. [Fig. 2]은 함수 호출의 결과를 나타낸 그림이다.



                                            [Fig. 2]

 

(순서 9) 구매 ID가 700인 구매를 취소하려고 한다. 700 구매 ID로 주문했던 상품은 모두 20개인데, 재고로 10개만 남아있기 때문에, 취소에 실패하고 -1을 반환한다.

(순서 10) 구매 ID가 600인 구매를 취소하려고 한다. 600 구매 ID로 주문했던 상품은 모두 10개인데, 재고로 모두 남아있기 때문에, 취소에 성공한다. 취소하고 남은 동일 상품의 개수로 130을 반환한다. [Fig. 3]은 함수 호출의 결과를 나타낸 그림이다.

 



                                            [Fig. 3]

 

(순서 11) 300 상품을 개당 가격 2,000으로 100개 판매하려고 한다. 판매 ID는 500이다. 300 상품은 60개밖에 없기 때문에, 판매에 실패하고 -1을 반환한다.

(순서 12) 300 상품을 개당 가격 2,000으로 30개 판매한다. 판매 ID는 400이다. 판매 가격(2,000)에서 구매 가격(1,900)을 빼면 개당 판매 수익은 100이다. 30개를 판매하기 때문에, 총 판매 수익으로 3,000을 반환한다. [Fig. 4]은 함수 호출의 결과를 나타낸 그림이다.



                                                [Fig. 4]

 

(순서 13) 100 상품을 개당 가격 3,500으로 50개 판매한다. 판매 ID는 100이다. 가장 싸게 구매한 순서대로 팔면, 1,800 가격에 구매한 상품 10개(구매 ID=700), 2,000 가격에 구매한 상품 30개(구매 ID=100), 2,000 가격에 구매한 상품 10개(구매 ID=400)를 팔게 된다. 판매 수익은 각각 (3,500 – 1,800) x 10 = 17,000, (3,500 – 2000) x 30 = 45,000, (3,500 – 2000) x 10 = 15,000이다. 총 판매 수익으로 77,000을 반환한다. [Fig. 5]은 함수 호출의 결과를 나타낸 그림이다.

 



                                                [Fig. 5]

 

(순서 14) 200 판매 ID로 판매된 상품을 환불해 준다. 200 판매 ID로 판매된 상품 번호는 100이고 10개가 판매됐다. 10개가 다시 재고가 되고, 환불해 준 상품의 개수로 10을 반환한다. [Fig. 6]은 함수 호출의 결과를 나타낸 그림이다.



                                            [Fig. 6]

(순서 15) 100 상품을 개당 가격 2,500으로 20개 판매한다. 판매 ID는 300이다. 가장 싸게 구매한 순서대로 팔면, 1,800 가격에 구매한 상품 10개(구매 ID=700), 2,000 가격에 구매한 상품 10개(구매 ID=400)를 팔게 된다. 판매 수익은 각각 (2,500 – 1,800) x 10 = 7,000, (2,500 – 2000) x 10 = 5,000이다. 총 판매 수익으로 12,000을 반환한다. [Fig. 7]은 함수 호출의 결과를 나타낸 그림이다.

 



                                            Fig. 7]

 

(순서 16) 100 판매 ID로 판매된 상품을 환불해 준다. 100 판매 ID로 판매된 상품 번호는 100이고 50개가 판매됐다. 50개가 다시 재고가 되고, 환불해 준 상품의 개수로 50을 반환한다. [Fig. 8]은 함수 호출의 결과를 나타낸 그림이다.



                                        [Fig. 8]

 

(순서 17) 구매 ID가 400인 구매를 취소하려고 한다. 400 구매 ID로 주문했던 상품은 모두 40개인데, 재고로 30개만 남아있기 때문에, 취소에 실패하고 -1을 반환한다.

(순서 18) 300 판매 ID로 판매된 상품을 환불해 준다. 300 판매 ID로 판매된 상품 번호는 100이고 20개가 판매됐다. 20개가 다시 재고가 되고, 환불해 준 상품의 개수로 20을 반환한다. [Fig. 9]은 함수 호출의 결과를 나타낸 그림이다.



                                            [Fig. 9]

 

(순서 19) 구매 ID가 400인 구매를 취소하려고 한다. 400 구매 ID로 주문했던 상품은 모두 40개인데, 재고로 모두 남아있기 때문에, 취소에 성공한다. 취소하고 남은 동일 상품의 개수로 100을 반환한다. [Fig. 10]은 함수 호출의 결과를 나타낸 그림이다.



                                            [Fig. 10]

 

[제약사항]

1. 각 테스트 케이스 시작 시 init() 함수가 호출된다.

2. 각 테스트 케이스에서 상품 종류는 600 이하이다.

3. 각 테스트 케이스에서 buy() 함수의 호출 횟수는 30,000 이하이다.

4. 각 테스트 케이스에서 sell() 함수의 호출 횟수는 30,000 이하이다.

5. 각 테스트 케이스에서 모든 함수의 호출 횟수 총합은 80,000 이하이다.

 

[입출력]

입출력은 제공되는 Main 부분의 코드에서 처리하므로 User Code 부분의 코드에서는 별도로 입출력을 처리하지 않는다.

Sample input 에 대한 정답 출력 결과는 “#TC번호 결과” 의 포맷으로 보여지며 결과가 100 일 경우 정답, 0 일 경우 오답을 의미한다.
*/
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;
 

typedef struct s_buy
{
	int	bid;
	int	product_id;
	int	buy_price;
	int	buy_quantity;
	int	cur_quantity;
}	t_buy;

typedef struct s_sell
{
	int	sid;
	int	product_id;
	int	sell_price;
	int	sell_quantity;
	int	profit;
	vector<int>	bid_list;
	vector<int>	quantity_list;
}	t_sell;

struct my_compare
{
	typedef t_buy*	value_type;
	bool	operator()(const t_buy *a, const t_buy *b) const {
		if (a->buy_price < b->buy_price)
			return (true);
		else if (a->buy_price == b->buy_price) {
			if (a->bid < b->bid)
				return (true);
			else
				return (false);
		}
		else
			return (false);
	}
};

typedef struct s_stock
{
	int	quantity;
	set<t_buy *, my_compare>	buy_list;
}	t_stock;

t_buy	buy_pool[30000];
t_sell	sell_pool[30000];
t_stock	stock_pool[600];
int		buy_pool_cnt;
int		sell_pool_cnt;
int		stock_pool_cnt;

unordered_map<int, t_buy *>		bid_table;
unordered_map<int, t_sell *>	sid_table;
unordered_map<int, t_stock *>	stock_table;

void init() {
	buy_pool_cnt = 0;
	for (int i = 0; i < sell_pool_cnt; ++i) {
		sell_pool[i].bid_list.clear();
		sell_pool[i].quantity_list.clear();
	}
	sell_pool_cnt = 0;
	for (int i = 0; i < stock_pool_cnt; ++i) {
		stock_pool[i].buy_list.clear();
		stock_pool[i].quantity = 0;
	}
	stock_pool_cnt = 0;
	bid_table.clear();
	sid_table.clear();
	stock_table.clear();
	return;
}

int buy(int bId, int mProduct, int mPrice, int mQuantity) {
	int	res;
	unordered_map<int, t_stock *>::iterator	iter;
	t_buy	*new_buy;
	t_stock	*new_stock;
	t_stock	*cur_stock;

	new_buy = &buy_pool[buy_pool_cnt++];
	new_buy->bid = bId;
	new_buy->product_id = mProduct;
	new_buy->buy_price = mPrice;
	new_buy->buy_quantity = mQuantity;
	new_buy->cur_quantity = mQuantity;
	bid_table.insert({bId, new_buy});
	
	iter = stock_table.find(mProduct);
	if (iter == stock_table.end()) {
		new_stock = &stock_pool[stock_pool_cnt++];
		new_stock->quantity = mQuantity;
		new_stock->buy_list.insert(new_buy);
		stock_table.insert({mProduct, new_stock});
		res = new_stock->quantity;
	}
	else {
		cur_stock = iter->second;
		cur_stock->quantity += mQuantity;
		cur_stock->buy_list.insert(new_buy);
		res = cur_stock->quantity;
	}
	return (res);
}

int cancel(int bId) {
	t_buy	*cur_buy;
	t_stock	*cur_stock;
	unordered_map<int, t_buy *>::iterator	bid_iter;
	unordered_map<int, t_stock *>::iterator	stock_iter;

	bid_iter = bid_table.find(bId);
	if (bid_iter == bid_table.end())
		return (-1);
	cur_buy = bid_iter->second;
	if (cur_buy->cur_quantity != cur_buy->buy_quantity)
		return (-1);
	stock_iter = stock_table.find(cur_buy->product_id);
	cur_stock = stock_iter->second;
	cur_stock->buy_list.erase(cur_buy);
	cur_stock->quantity -= cur_buy->buy_quantity;
	bid_table.erase(bId);
	return (cur_stock->quantity);
}

int sell(int sId, int mProduct, int mPrice, int mQuantity) {
	t_buy	*cur_buy;
	t_sell	*new_sell;
	t_stock	*cur_stock;
	unordered_map<int, t_stock *>::iterator	stock_iter;
	set<t_buy *, my_compare>::iterator	buy_list_iter;

	stock_iter = stock_table.find(mProduct);
	cur_stock = stock_iter->second;
	if (cur_stock->quantity < mQuantity)
		return (-1);
	cur_stock->quantity -= mQuantity;

	new_sell = &sell_pool[sell_pool_cnt++];
	new_sell->sid = sId;
	new_sell->product_id = mProduct;
	new_sell->sell_price = mPrice;
	new_sell->sell_quantity = 0;
	new_sell->profit = 0;
	buy_list_iter = cur_stock->buy_list.begin();
	while (new_sell->sell_quantity < mQuantity) {
		cur_buy = *buy_list_iter;
		new_sell->bid_list.push_back(cur_buy->bid);
		if (cur_buy->cur_quantity > mQuantity - new_sell->sell_quantity) {
			cur_buy->cur_quantity -= mQuantity - new_sell->sell_quantity;
			new_sell->quantity_list.push_back(mQuantity - new_sell->sell_quantity);
			new_sell->profit += (mPrice - cur_buy->buy_price) * \
									(mQuantity - new_sell->sell_quantity);
			new_sell->sell_quantity += mQuantity - new_sell->sell_quantity;
			break ;
		}
		else {
			new_sell->quantity_list.push_back(cur_buy->cur_quantity);
			new_sell->profit += (mPrice - cur_buy->buy_price) * \
										cur_buy->cur_quantity;
			new_sell->sell_quantity += cur_buy->cur_quantity;
			cur_buy->cur_quantity = 0;
			cur_stock->buy_list.erase(cur_buy);
			buy_list_iter = cur_stock->buy_list.begin();
		}
	}
	sid_table.insert({sId, new_sell});
	return (new_sell->profit);
}

int refund(int sId) {
	int	res;
	int	*cur_bid;
	int	*cur_quantity;
	t_buy	*cur_buy;
	t_sell	*cur_sell;
	t_stock	*cur_stock;
	unordered_map<int, t_buy *>::iterator	bid_iter;
	unordered_map<int, t_sell *>::iterator	sid_iter;
	unordered_map<int, t_stock *>::iterator	stock_iter;
	set<t_buy *, my_compare>::iterator	buy_list_iter;

	sid_iter = sid_table.find(sId);
	if (sid_iter == sid_table.end())
		return (-1);
	cur_sell = sid_iter->second;
	res = cur_sell->sell_quantity;
	
	stock_iter = stock_table.find(cur_sell->product_id);
	cur_stock = stock_iter->second;
	cur_stock->quantity += cur_sell->sell_quantity;
	cur_bid = &cur_sell->bid_list[0];
	cur_quantity = &cur_sell->quantity_list[0];
	while (cur_sell->sell_quantity > 0) {
		bid_iter = bid_table.find(*cur_bid);
		cur_buy = bid_iter->second;
		cur_buy->cur_quantity += *cur_quantity;
		cur_sell->sell_quantity -= *cur_quantity;
		buy_list_iter = cur_stock->buy_list.find(cur_buy);
		if (buy_list_iter == cur_stock->buy_list.end())
			cur_stock->buy_list.insert(cur_buy);
		++cur_bid;
		++cur_quantity;
	}
	sid_table.erase(sId);
	return (res);
}