
template <typename C, typename T>
class MutantStack {
private:
	C container;

public:
	MutantStack();
	MutantStack(const MutantStack<T> &rhs);
	const MutantStack<T> &operator=(const MutantStack<T> &);
	~MutantStack();
	void push(const value_type &value);
	void pop();
	const T &top();
	bool empty() const;
	size_type size() const;
};

MutantStack::MutantStack(/* args */) {
}

MutantStack::~MutantStack() {
}
