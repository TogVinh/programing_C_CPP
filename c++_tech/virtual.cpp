
#include <iostream>
using namespace std;

/**
 * Có thể thấy rõ ràng con trỏ animal1 và animal2 trỏ tới đối tượng cat và đối tượng dog nhưng phương thức được gọi lại không phải là phương thức trong 2 đối tượng này mà là phương thức ở lớp Animal.
 *  Điều này là do khi biên dịch thì trình biên dịch không thể xác định được đối tượng mà con trỏ animal đang trỏ tới là đối tượng thuộc lớp nào, dẫn tới mặc định các phương thức được gọi sẽ là phương thức ở lớp cha. 
 * Để gọi tới được các phương thức ở lớp con thì bạn cần thêm từ khóa virtual vào phương thức ở lớp cha để chỉ rõ cho trình biên dịch biết rằng phương thức cần được gọi sẽ được xác định tại thời điểm runtime (tại thời điểm runtime thì trình dịch có thể xác định được con trỏ animal đang trỏ tới đối tượng thuộc lớp nào => từ đó có thể gọi tới các phương thức tương ứng):
*/


class Animal {
public:
	virtual void sound() {
		cout << "some sound" << endl;
	}
};

class Cat : public Animal {
public:
	void sound() {
		cout << "meow meow" << endl;
	}
};

class Dog : public Animal {
public:
	void sound() {
		cout << "woof woof" << endl;
	}
};

int main() {
	Cat cat;
	Animal* animal1 = &cat;
	animal1->sound();

	Dog dog;
	Animal* animal2 = &dog;
	animal2->sound();
	return 0;
}