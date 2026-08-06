#ifndef LIST_HPP_
#define LIST_HPP_

#include <vector>

class List{
public:
  List();
  int size() const {return list_.size();}

  int check(double number);
  void addNumber(double);
  void removeNumber(double);
  void output();

  List(const List&);
  List& operator=(const List&);
  ~List();

private:
  std::vector<double> list_;
};

#endif /* LIST_HPP_ */