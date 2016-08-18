#include<stdio.h>
#include<vector>

using std::vector;


int recursive_change(int money , vector<int> coins ){
  int min_num_coins = 1000000; // like infinitum
  if (money == 0){
    return 0;
  }
  for(int i = 0; i < coins.size(); i++){
    int num_coins;
    if (money >= coins[i]){
      num_coins = recursive_change(money - coins[i], coins);
      if(num_coins + 1 < min_num_coins){
        min_num_coins= num_coins + 1 ;
      }
    }
  }
  return min_num_coins;
        

}

int main(){
  int money,coins_max;
  int tmp; // because don't uses cout or cin
  vector<int> coins;
  scanf("%d %d", &money,&coins_max);
  for(int i= 0; i< coins_max; i++){
    scanf("%d", &tmp);
    coins.push_back(tmp);
  }

  printf("%d", recursive_change(money,coins));
  
    


}
