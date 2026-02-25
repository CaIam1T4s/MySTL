#ifndef TYPE_TRAITS_H
#define TYPE_TRAITS_H

namespace mystl {

template <typename Ty>
struct RemoveReference { using Type = Ty; };	// struct RemoveReference

template <typename Ty>
struct RemoveReference<Ty&> { using Type = Ty; };	// struct RemoveReference

template <typename Ty>
struct RemoveReference<Ty&&> { using Type = Ty; };	// struct RemoveReference

}	// namespace mystl

#endif	// TYPE_TRAITS_H
