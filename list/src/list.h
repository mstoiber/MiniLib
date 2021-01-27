#pragma once
#include "list_node.h"

template <typename T>
class list : ml5::container<T>, MI5_DERIVE(list<T>, ml5::container<T>) {
	MI5_INJECT(list<T>)

public:
	~list() noexcept;

	void        add(T value) override;
	void        clear() noexcept override;
	bool        contains(T const& value) const noexcept override;
	void        remove(T const& value) noexcept override;
	std::size_t size() const noexcept override;

	std::unique_ptr <ml5::iterator <T>> make_iterator() override;

private:
	list_node<T>* m_head{ nullptr };
	list_node<T>* m_tail{ nullptr };
	size_t			m_size{ 0 };

};

#include "list.inl"