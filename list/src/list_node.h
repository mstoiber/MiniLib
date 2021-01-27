#pragma once
#include <ml5/ml5.h>

template<typename T>
class list_node : public ml5::object, MI5_DERIVE(list_node<T>, ml5::object) {
	MI5_INJECT(list_node<T>)

private:
	template<typename> friend class list;
	template<typename> friend class list_iterator;

	list_node*	m_next {nullptr};
	T			m_value;

	list_node(const T &value)
		: m_next{nullptr},
		  m_value{value} {}

};

#include "list_node.inl"
