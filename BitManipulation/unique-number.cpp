#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief
 * Unique number, given 2N + 1 numbers where every number comes twice expect one number. Find out that unique number
 * we have odd number of numbers, every number shows up twice except one of the numbers, find that number
 * @param input
 * @return int
 */
int FindUniqueNumber(vector<int> input)
{
  int cummulativeXOR = 0;

  for (int i = 0; i < input.size(); i++)
  {
    cummulativeXOR ^= input[i];
  }

  return cummulativeXOR;
}

/**
 * @brief
 * Unique Number - Given 2N + 2 numbers, where every number is coming twice except 2 numbers
 * Find those 2 unique numbers
 * This time we have an even length of container where 2 numbers are unique
 * @param input
 * @return int
 */
pair<int, int> FindUniqueNumber2(vector<int> input)
{
  int cummulativeXOR = 0;

  for (int i = 0; i < input.size(); i++)
  {
    cummulativeXOR ^= input[i];
  }

  // find the first position where the bit is set in the cummulative XOR
  int pos = 0;
  int temp = cummulativeXOR;

  while ((temp & 1) == 0)
  {
    pos++;
    temp >>= 1;
  }

  // filter out the nubmers from the array which has set bit at 'pos'
  int setA = 0;
  int setB = 0;

  int mask = (1 << pos);

  for (int i = 0; i < input.size(); i++)
  {
    if ((input[i] & mask) > 0)
    {
      setA ^= input[i];
    }
    else
    {
      setB ^= input[i];
    }
  }

  return {setA, setB};
}

void UpdateSum(vector<int> &array, int value)
{
  // extract all bits of vlaue
  for (int i = 0; i < 32; i++)
  {
    int ithBit = value & (1 << i);

    if (ithBit)
    {
      array[i]++;
    }
  }
}

int NumberFromBits(vector<int> array)
{
  int num = 0;
  for (int i = 0; i < 32; i++)
  {
    num += array[i] * (1 << i);
  }

  return num;
}

/**
 * @brief
 * Unique number — given 3N + 1 numbers, where very number is coming three times except one number find that unique number
 *
 * @param input
 * @return int
 */
int FindUniqueNumber3(vector<int> input)
{
  // each index of array represents a bit
  // 32 size as this example is for 32 bit integers
  vector<int> sumArray(32, 0);

  for (int value : input)
  {
    UpdateSum(sumArray, value);
  }

  for (int i = 0; i < 32; i++)
  {
    sumArray[i] %= 3;
  }

  // from the array of bits convert it into an integers
  return NumberFromBits(sumArray);
}

int main()
{
  vector<int> array = {1, 3, 4, 4, 1, 5, 3};
  cout << FindUniqueNumber(array) << endl;

  vector<int> array2 = {1, 3, 4, 4, 1, 5, 3, 7};
  cout << FindUniqueNumber2(array2).first << ", " << FindUniqueNumber2(array2).second << endl;

  vector<int> array3 = {1, 2, 4, 4, 2, 3, 1, 1, 2, 4};
  cout << FindUniqueNumber3(array3) << endl;

  return 0;
}