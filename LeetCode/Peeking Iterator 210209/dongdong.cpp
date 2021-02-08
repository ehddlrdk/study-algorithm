/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
	// 전체적으로 글로벌 변수를 둬서 체크함.
	Iterator* a;
	int next_num = 0;
	int peek_num = 0;
	bool peek_check = false;

	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.


		Iterator* i = new Iterator(nums); // nums를 인자로 새로운 Iterator인스턴스를 생성 
		a = i;

	}

	// Returns the next element in the iteration without advancing the iterator.
	// peek()는 다음 인덱스를 가리키는데 peek(), peek() 연속으로 나오면 뒤에 peek()은 현재 가리키고 있는 인덱스를 반환
	int peek() {

		if (!peek_check) {
			peek_num = a->next();
			peek_check = true;
		}
		return peek_num;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
  // next()는 peek()에 영향없이 다음 인덱스를 가르켜야함. 그래서 next() peek() next()는 1, 2, 2가 됨 
	int next() {
		if (!peek_check) {
			next_num = a->next();
			return next_num;
		}

		peek_check = false;
		next_num = peek_num;
		return next_num;
	}

	// nums에 다음 인자가 있는지 없는지 판단. peek()에서 마지막 인덱스가 나와도 next()가 불리면 마지막 인덱스를 가리키기에   hasNext()는 true가 나와야함 
	bool hasNext() const {
		return peek_check || a->hasNext();
	}
};