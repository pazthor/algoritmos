#include<stdio.h>
#include<vector>

using std::vector;


int dp_change(int money , vector<int> coins ){
  vector<int> min_num_coins;
  min_num_coins.push_back(0);
  for(int m = 1; m <= money; m++){
    min_num_coins.push_back(1000000);
    for(int i = 0; i < coins.size(); i++){
      int num_coins;
      if (m  >= coins[i]){
        num_coins = min_num_coins[m - coins[i]] + 1; 
        if(num_coins  < min_num_coins[m]){
          min_num_coins[m]= num_coins ;
        }
      }
    }
  }
  return min_num_coins[money];
        

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

  printf("%d", dp_change(money,coins));
  
    


}
