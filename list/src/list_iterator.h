#pragma once

#include <ml5/ml5.h>
#include "list_node.h"

template <typename T>
class list_iterator : public ml5::iterator<T>, MI5_DERIVE(list_iterator<T>, ml5::iterator<T>) {
	MI5_INJECT(ml5::iterator<T>)

public:
	explicit list_iterator(list_node<T>* node);

	~list_iterator() = default;

	T& get_current() const override;
	bool is_at_end() const noexcept override;
	void to_next() override;

private: 
	list_node<T>* m_node{ nullptr };

};


#include "list_iterator.inl"