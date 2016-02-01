#include <vector>
#include <iostream>

class Heap
{
public:
    Heap() : arr( std::vector<int>() ) {}
    void insert(int x)
    {
        arr.push_back(x);
        bubble_up(arr.size()-1);
    }
    int pop()
    {
      int new_elem = arr.back();
      arr.pop_back();
      int top = arr.front();
      arr[0]=new_elem;
      bubble_down(0);
      return top;
    }
    int size()
    {
      return arr.size();
    }
private:
  std::vector<int> arr;
  void bubble_down(int index)
  {
    int c1 = index*2 + 1;
    int c2 = index*2 + 2;

    //check to make sure we have children
    if(c1 >= arr.size()){
      return;
    }

    int max_child = 0;
    if(c2 >= arr.size()){
      max_child = c1;
    } else if(arr[c1]> arr[c2]){
      max_child = c1;
    } else {
      max_child = c2;
    }

    if(arr[max_child] > arr[index]){
      int temp = arr[index];
      arr[index] = arr[max_child];
      arr[max_child] = temp;
      bubble_down(max_child);
    }
    //else we don't have to do anything

  }
  void bubble_up(int index)
  {
    //check base case
    if(index == 0){
      return;
    }

    int parent = 0;
    if(index%2==1){
      parent = (index-1)/2;
    } else {
      parent = (index-2)/2;
    }

    //do a swap if necessary
    if(arr[index]> arr[parent]){
      int temp = arr[index];
      arr[index] = arr[parent];
      arr[parent] = temp;
      bubble_up(parent);
    }
  }
};

int main()
{
  Heap h = Heap();
  h.insert(1);
  h.insert(5);
  h.insert(7);
  h.insert(3);
  h.insert(1);
  int num = h.size();
  for (int i = 0; i < num; ++i)
    std::cout << "[" << h.pop() << "]\n";
}
