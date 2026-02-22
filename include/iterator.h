namespace mystl {

template <typename Ty>
class BaseIterator {
protected:
	BaseIterator();
private:
	Ty* m_ptr;
};	// class Iterator


template <typename Ty>
class Iterator : public BaseIterator<Ty>{

};	// class Iterator

}	// namespace mystl
