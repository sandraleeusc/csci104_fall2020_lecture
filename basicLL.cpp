#include <iostream>
#include <memory>

using namespace std;

template <typename T>
   struct Item {
   T val;
   unique_ptr<Item<T>> next;
};

template <typename T>
   class LListBasic {
   public:
   LListBasic() { head_ = NULL; size_ = 0; }
   ~LListBasic();
   bool empty() const { return size_ == 0; }
   int size() const   { return size_; }
   void prepend(const T& val);
   T& get(int loc);

   private:
   unique_ptr<Item<T>> head_;
   int size_;

};



int main()
{
   LListBasic<int> LL;
   for(int i=9; i >= 0; i--){
      LL.prepend(i);  
   }
   cout << "Size is " << LL.size() << endl;
   for(int i=0; i <= 9; i++){
      cout << LL.get(i) << endl;  
   }
   return 0;
}



template <typename T>
   LListBasic<T>::~LListBasic()
   {
      while(head_){
         head_ = move(head_->next);
      }
   }

template <typename T>
   void LListBasic<T>::prepend(const T& val)
   {
      unique_ptr<Item<T>> old_head(move(head_));
      head_ = make_unique<Item<T>>();
      head_->val = val;
      head_->next = move(old_head);
      size_++;
   }

template <typename T>
   T& LListBasic<T>::get(int loc)
   {
      Item<T>* temp= head_.get();
      while(temp  && loc != 0){
         temp = temp->next.get();
         loc--;
      }
      return temp->val;
   }
