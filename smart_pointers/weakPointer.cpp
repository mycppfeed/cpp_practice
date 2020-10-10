#include <iostream>
#include <memory>

class Son;
class Daughter;

class Mother {
public:
    Mother() { std::cout << "Mother Created\n\n"; }
    ~Mother() { std::cout << "Mother Destroyed\n\n"; }
    void SetSon(const std::shared_ptr<Son> son ) { _son = son; }
    void SetDaughter(const std::shared_ptr<Daughter> daughter ) { _daughter = daughter; }

    std::shared_ptr<const Son> _son;
    std::weak_ptr<const Daughter> _daughter;
};

class Son {
public:
    Son(std::shared_ptr<Mother> mother) : _mother(mother) { std::cout << "Son Created\n\n"; }
    ~Son() { std::cout << "Son Destroyed\n\n"; }

    std::shared_ptr<const Mother> _mother;
};

class Daughter {
public:
   Daughter(std::shared_ptr<Mother> mother) : _mother(mother) { std::cout << "Daughter Created\n\n"; }
    ~Daughter() { std::cout << "Daughter Destroyed\n\n"; }

    std::shared_ptr<const Mother> _mother;
};

#if 1
int main() {
    std::shared_ptr<Mother> mother = std::shared_ptr<Mother>(new Mother);
    std::shared_ptr<Son> son = std::shared_ptr<Son>(new Son(mother));
    std::shared_ptr<Daughter> daughter = std::shared_ptr<Daughter>(new Daughter(mother));
    mother->SetSon(son);
    mother->SetDaughter(daughter);

    return 0;
}
#else

int main() {
  std::cout << std::endl;
  {
    std::shared_ptr<Mother> mother= std::shared_ptr<Mother>(new Mother);
    std::shared_ptr<Son> son= std::shared_ptr<Son>(new Son(mother));
    std::shared_ptr<Daughter> daughter= std::shared_ptr<Daughter>(new Daughter(mother));
    mother->SetSon(son);
    mother->SetDaughter(daughter);
  }
  std::cout << std::endl;
}
#endif
