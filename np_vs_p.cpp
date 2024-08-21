#include <iostream>
#include <vector>

using namespace std;

 

/*
*Calcula de manera recursiva si hay un subconjunto no vacio que sume 0
*
*@param  vector<int>& nums contiene el conjunto total de numeros
*@param  int index indice del elemento a procesar
*@param  int sum suma actual
*@param  vector<int>& nums2 contiene los elementos que conforman el subconjunto solucion
*
* @return bool truo o false si hay solucion
* 
* En tiempo O(2^k)
* En el espacio O(n)
*/
bool hasSubsetWithZeroSum(const vector<int>& nums,int index, int sum,  vector<int>& nums2) {
 
    if (sum == 0  && nums2.size()>0) {
        for (size_t i = 0; i < nums2.size(); ++i) {
            cout << nums2[i] << " ";
        }
        return true;    
    }

    if (index >= nums.size())
        return false;

    else {
      nums2.push_back(nums[index]);
      if (hasSubsetWithZeroSum(nums, index+1, sum + nums[index], nums2))
          return true;
      else {
          nums2.pop_back();
          return (hasSubsetWithZeroSum(nums, index+1, sum, nums2));  
      }
    }
}

int main() {

    locale::global(locale("es_ES.UTF-8"));
    wcout.imbue(locale());
    int n;
    cout << "Introduce el número de elementos: ";
    cin >> n;
    vector<int> nums(n);
    vector<int> nums2;
    cout << "Introduce los " << n << " elementos:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    if (hasSubsetWithZeroSum(nums,0,0,nums2)) {
        cout << "Sí, existe un subconjunto cuya suma es 0." << endl;
    } else {
        cout << "No, no existe ningún subconjunto cuya suma sea 0." << endl;
    }

    return 0;
}
