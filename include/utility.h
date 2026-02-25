#ifndef UTILITY_H
#define UTILITY_H

#include "type_traits.h"

namespace mystl {

template <typename Ty>
auto Move(Ty&& param) -> RemoveReference<Ty>::Type&& {
	return static_cast<RemoveReference<Ty>::Type&&>(param);
}

}	// namespace mystl

#endif	// UTILITY_H
