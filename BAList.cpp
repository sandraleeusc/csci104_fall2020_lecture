#include <iostream>
#include <memory>
#include <stdexcept>  

using namespace std;

template <typename T>
class BAList {
public:
  BAList(unsigned int cap);
  ~BAList(){}
  bool empty() const  {return size_==0;}
  unsigned int  size() const {return size_;}
  void insert(int pos, const T& val);
  void remove(int pos);
  // Extra exercises
  //int const & get(int loc) const;
  int& get(int loc) { return data_[loc];}
  //void set(int loc, const int& val);
  void push_back(const T& val);
  private:
  unique_ptr<T []> data_;
  unsigned int size_;
  unsigned int cap_;
  
  };



int main()
{
    BAList<int> test(20);
    for (int i = 0; i < 10; i++)
    test.push_back(i);
    
   test.insert(4, 15);
   test.remove(7);
   cout << test.size() << endl;
   for (int j = 0 ; j < test.size(); j++)
       cout << test.get(j) << endl;

    return 0;
}
